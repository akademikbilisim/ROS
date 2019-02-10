#!/usr/bin/env python2

import rospy
from robot import Robot

def main():
    rospy.init_node("replacement_node")

    r = Robot()

    rospy.spin()

if __name__ == "__main__":
    main()
