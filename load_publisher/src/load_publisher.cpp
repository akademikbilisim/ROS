#include <ros/ros.h>
#include <std_msgs/String.h>
#include <load_publisher/Stat.h>
#include <iostream>
#include <string>

using namespace std;

/**
 * def stat_cb(msg):
 *     do_stuff
 */
void stat_cb(const load_publisher::Stat::ConstPtr& msg) {
  // do stuff
  // ROS_INFO_STREAM("olaylar: " << *msg);
}

string getOutput(string cmd) {
  string data;
  FILE* stream;
  const int max_buffer = 256;
  char buffer[max_buffer];

  cmd.append(" 2>&1");
  stream = popen(cmd.c_str(), "r");

  if (stream) {
    while (!feof(stream)) {
      if (fgets(buffer, max_buffer, stream) != nullptr)
        data.append(buffer);
    }

    pclose(stream);
  }

  return data;
}

int main(int argc, char** argv) {

  // rospy.init_node("talker")
  ros::init(argc, argv, "talker");

  ros::NodeHandle nh;

  // rospy.Subsciber("<topic name>", <msg type>, <callback>)
  auto sub = nh.subscribe("/stat", 1000, stat_cb);

  // rospy.Publisher("<topic name>", <msg type>, queue_size=1000)
  auto pub = nh.advertise<load_publisher::Stat>("/stat", 1000);

  auto r = ros::Rate(10);

  // while not rospy.is_shutdown()
  while(ros::ok()){

    load_publisher::Stat msg;
    // ahmet logic start
   
    auto totalMem = stoi(getOutput("free -m | grep Mem | awk '{print $2}'"));
    auto usedMem = stoi(getOutput("free -m | grep Mem | awk '{print $3}'"));
    auto cpuLoad = stof(getOutput("cat /proc/loadavg | awk '{print $1}'"));

    msg.memory = totalMem;
    msg.memory_usage = usedMem;
    msg.load = cpuLoad;

    // ahmet logic end
    pub.publish(msg);
    ros::spinOnce();

    r.sleep();

  }

  return 0;
}
