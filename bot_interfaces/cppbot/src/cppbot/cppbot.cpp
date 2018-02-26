#include <cppbot/cppbot.h>

namespace cppbot{

Cppbot::Cppbot(){
  std::string scan_topic;
  std::string odom_topic;
  std::string cmd_vel_topic;

  nh_.param<std::string>("scan", scan_topic, std::string("front_laser/scan") );
  nh_.param("odom", odom_topic, std::string("odom"));
  nh_.param("cmd_vel", cmd_vel_topic, std::string("cmd_vel"));


  cmd_vel_pub_ = nh_.advertise<geometry_msgs::Twist>(cmd_vel_topic, 100);
  scan_sub_ = nh_.subscribe(scan_topic,100, &Cppbot::laser_scan_cb_, this);
  odom_sub_ = nh_.subscribe(odom_topic,1000, &Cppbot::odom_cb_, this);

}

void Cppbot::odom_cb_(const nav_msgs::Odometry::ConstPtr &msg){

  // stamped pose
  pose_stamped_.header = msg->header;
  pose_stamped_.pose = msg->pose.pose;

  // 2d pose
  double roll, pitch, yaw;
  tf::Quaternion quaternion;
  tf::quaternionMsgToTF(msg->pose.pose.orientation, quaternion);
  tf::Matrix3x3(quaternion).getRPY(roll, pitch, yaw);

  pose2d_.x = msg->pose.pose.position.x;
  pose2d_.y = msg->pose.pose.position.y;
  pose2d_.theta = yaw;
}

void Cppbot::laser_scan_cb_(sensor_msgs::LaserScan msg){
  laser_scan_ = msg;
}

void Cppbot::set_speed(float linear, float angular){
  geometry_msgs::Twist t;
  t.linear.x = linear;
  t.angular.z = angular;
  cmd_vel_pub_.publish(t);
}

struct complex_number Helpers::calculate_differance(geometry_msgs::Point point0, geometry_msgs::Point point1){
  float x_diff = point1.x - point0.x;
  float y_diff = point1.y - point0.y;
  struct complex_number result;
  result.distance = sqrt( pow(x_diff, 2) + pow(y_diff, 2) );
  result.angle = atan2(y_diff, x_diff);
  return result;
}

}
