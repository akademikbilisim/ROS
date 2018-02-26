#include <serial_comm/serial_comm.h>

namespace serial_comm {

  SerialComm::SerialComm() : nh_("~"){
    // default constructor

  }

  SerialComm::SerialComm(std::string port, uint32_t baudrate) : nh_("~")
  {
    baudrate_ = baudrate;
    port_ = port;
    init();
  }

  SerialComm::~SerialComm(){
    serial_.close();
    serial_.~Serial();
  }

  void SerialComm::setBaudrate(uint32_t baudrate){
    serial_.setBaudrate(baudrate);
  }

  uint32_t SerialComm::getBaudrate(){
    return serial_.getBaudrate();
  }

  void SerialComm::setPort(std::string port){
    serial_.setPort(port);
  }

  std::string SerialComm::getPort(){
    return serial_.getPort();
  }

  void SerialComm::init(){
    serial_.setBaudrate(baudrate_);
    serial_.setPort(port_);
    state_publisher_ = nh_.advertise<serial_comm::ArduinoState>("/arduino_state",1000);
    try{
      serial_.open();
    } catch (serial::SerialException e){
      ROS_ERROR_STREAM(e.what());
      return;
    } catch (serial::IOException e){
      ROS_ERROR_STREAM(e.what());
      return;
    }
    is_initialized_ = true;
    ros::spinOnce();
  }

  std::string SerialComm::read(){
    if( serial_.available() ){
      return serial_.readline();
    }
  }

  bool SerialComm::write(std::string data){
    return serial_.write(data) == data.size();
  }

  void SerialComm::run(){
    if(!this->is_initialized_){
      throw SerialCommException("Not initialized");
    }
    ros::Rate r(1000);
    std::string res;
    serial_comm::ArduinoState arduino_state;
    while(ros::ok()){
      if(serial_.available() > 0){
        res.append(serial_.read());
        if('\n' == res.back()){
          std::stringstream ss(res);
          std::vector<int> vect;
          int i;
          while(ss >> i){
            vect.push_back(i);
            if(ss.peek() == ';'){
              ss.ignore();
            }
          }
          if(vect.size() >= 6){
            arduino_state.button_states.btn1_state = bool(vect.at(0));
            arduino_state.button_states.btn2_state = bool(vect.at(1));
            arduino_state.button_states.btn3_state = bool(vect.at(2));
            arduino_state.counter_states.counter1_state = vect.at(3);
            arduino_state.counter_states.counter2_state = vect.at(4);
            arduino_state.counter_states.counter3_state = vect.at(5);
            state_publisher_.publish(arduino_state);
          }
          res.clear();
        }
      }
    }
  }

} // end namespace
