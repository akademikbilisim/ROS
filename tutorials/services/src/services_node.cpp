#include <ros/ros.h>
#include <services/FancyServices.h>

bool add(services::FancyServices::Request  &req,
         services::FancyServices::Response &res)
{
  res.result = req.input.a + req.input.b;
  ROS_INFO_STREAM("request: \n" << req.input);
  ROS_INFO_STREAM("sending back response: " << res.result);
  return true;
}

bool sub(services::FancyServices::Request  &req,
         services::FancyServices::Response &res)
{
  res.result = req.input.a - req.input.b;
  ROS_INFO_STREAM("request: \n" << req.input);
  ROS_INFO_STREAM("sending back response: " << res.result);
  return true;
}

bool div(services::FancyServices::Request  &req,
         services::FancyServices::Response &res)
{
  res.result = req.input.a / req.input.b;
  ROS_INFO_STREAM("request: \n" << req.input);
  ROS_INFO_STREAM("sending back response: " << res.result);
  return true;
}

bool mul(services::FancyServices::Request  &req,
         services::FancyServices::Response &res)
{
  res.result = req.input.a * req.input.b;
  ROS_INFO_STREAM("request: \n" << req.input);
  ROS_INFO_STREAM("sending back response: " << res.result);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_server");
  ros::NodeHandle n;

  ros::ServiceServer adds = n.advertiseService("add", add);
  ros::ServiceServer subs = n.advertiseService("sub", sub);
  ros::ServiceServer muls = n.advertiseService("mul", mul);
  ros::ServiceServer divs = n.advertiseService("div", div);

  ros::spin();

  return 0;
}
