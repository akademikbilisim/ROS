#include <cppbot/cppbot.h>

geometry_msgs::Point global_goal;


std::map<std::string, float> go_to_point(geometry_msgs::Pose2D robot_pose, geometry_msgs::Point goal){

  std::map<std::string, float> vel;

  geometry_msgs::Point robot_as_point;
  robot_as_point.x = robot_pose.x;
  robot_as_point.y = robot_pose.y;

  struct cppbot::complex_number diff;
  diff = cppbot::Helpers::calculate_differance(robot_as_point, goal);

  float error_angle = diff.angle - robot_pose.theta;
  error_angle = atan2(sin(error_angle), cos(error_angle));
  vel["angular"] = error_angle;

  diff.distance = diff.distance > 0.1 ? diff.distance : 0.0;
  vel["linear"] = diff.distance > 0.5 ? 0.5 : diff.distance / 2.0;

  return vel;

}

void goal_cb(const geometry_msgs::Point::ConstPtr &msg){
  global_goal = *msg;
  ROS_INFO_STREAM("Robot is now goint to: \n" << global_goal);
}


int main(int argc, char** argv){

  ros::init(argc, argv, "cppbot");
  ros::NodeHandle nh;
  ros::Subscriber goal_sub = nh.subscribe<geometry_msgs::Point>("goal",1000,goal_cb);

  cppbot::Cppbot my_bot;
  ros::Rate r(10);

  while(ros::ok()){
    std::map<std::string, float> t = go_to_point(my_bot.get_pose_2d(), global_goal);
    my_bot.set_speed(
            t["linear"],
            t["angular"]
          );
    r.sleep();
    ros::spinOnce();
  }




  return 0;
}
