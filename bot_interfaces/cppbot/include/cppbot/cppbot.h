#ifndef CPPBOT_H_
#define CPPBOT_H_

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose2D.h>
#include <geometry_msgs/PoseStamped.h>
#include <tf/transform_broadcaster.h>
#include <sensor_msgs/LaserScan.h>
#include <nav_msgs/Odometry.h>
#include <math.h>

namespace cppbot{

  class Cppbot{
    public:
    Cppbot();

    void set_speed(float linear, float angular);

    geometry_msgs::Pose2D get_pose_2d(){return pose2d_;}
    geometry_msgs::PoseStamped get_pose_stamped(){return pose_stamped_;}
    sensor_msgs::LaserScan get_laser_scan(){return laser_scan_;}

  
    private:
    ros::NodeHandle nh_;
    geometry_msgs::Pose2D pose2d_;
    geometry_msgs::PoseStamped pose_stamped_;
    sensor_msgs::LaserScan laser_scan_;

    ros::Subscriber scan_sub_;
    ros::Subscriber odom_sub_;
    ros::Publisher cmd_vel_pub_;

    void odom_cb_(const nav_msgs::Odometry::ConstPtr& msg);
    void laser_scan_cb_(sensor_msgs::LaserScan msg);

  };

  struct complex_number{
    float distance;
    float angle;
  };

  class Helpers{
  public:
    static struct complex_number calculate_differance(geometry_msgs::Point point0, geometry_msgs::Point point1);
  };


} // end namespace cppbot

#endif
