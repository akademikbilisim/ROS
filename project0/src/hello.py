#!/usr/bin/env python2
import rospy
from std_msgs.msg import String


class robot():
    def __init__(self):
        self.robot_name = None
        rospy.Subscriber("/set_robot_name", 
                String,
                self.name_callback)
    
    def name_callback(self, msg):
        self.robot_name = msg.data
        rospy.loginfo("my name is: %s" % self.robot_name)


def main():
    rospy.init_node("hello_node")

    r = robot()
    rospy.spin()

if __name__ == "__main__":
    main()

