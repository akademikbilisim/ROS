#!/usr/bin/env python2

import rospy
from geometry_msgs.msg import Twist


def main():
    rospy.init_node("rotate", anonymous=True)
    
    pub = rospy.Publisher("/cmd_vel_mux/input/teleop", Twist, queue_size=1)
    
    rate = rospy.Rate(10)
    
    while not rospy.is_shutdown():
        msg = Twist()
        msg.linear.x = 0.25
        msg.angular.z = 0.5
        pub.publish(msg)
        rate.sleep()
    
    
    
if __name__ == "__main__":
    try:
        main()
    except rospy.ROSInterruptException:
        pass
