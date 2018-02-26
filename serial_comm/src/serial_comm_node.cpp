#include <serial_comm/serial_comm.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "serial_comm");
  ros::NodeHandle nh("~");
  std::string port_name;
  int baudrate;

  nh.param<std::string>("port_name", port_name, "/dev/ttyUSB0");
  nh.param<int>("baudrate", baudrate, 9600);

  ROS_INFO_STREAM("PORT: " << port_name);
  ROS_INFO_STREAM("BAUD: " << baudrate);
  serial_comm::SerialComm serialComm(port_name, baudrate);

  try{
    serialComm.run();
  } catch ( const std::exception& e){
    ROS_ERROR_STREAM(e.what());
  }
  return 0;
}
