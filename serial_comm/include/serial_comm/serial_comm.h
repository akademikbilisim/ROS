#ifndef SERIAL_COMM_H_
#define SERIAL_COMM_H_

#include <ros/ros.h>
#include <serial/serial.h>
#include <iostream>
#include <vector>
#include <serial_comm/ArduinoState.h>

namespace serial_comm {

  class SerialComm{
    public:
      SerialComm();
      SerialComm(std::string port, uint32_t baudrate);
      ~SerialComm();

      void init();

      void setBaudrate(uint32_t baudrate);
      uint32_t getBaudrate();

      void setPort(std::string port);
      std::string getPort();

      std::string read();
      bool write(std::string data);

      void run();

    private:
      std::string       port_;
      uint32_t          baudrate_;
      bool              is_initialized_;
      serial::Serial    serial_;
      ros::NodeHandle nh_;
      ros::Publisher state_publisher_;
  };

  class SerialCommException: public std::exception{
    public:
        explicit SerialCommException(const char* message): msg_(message) {}
        explicit SerialCommException(const std::string& message): msg_(message) {}
        virtual ~SerialCommException() throw (){}
        virtual const char* what() const throw (){ return msg_.c_str(); }
    protected:
        std::string msg_;
  };
}

#endif
