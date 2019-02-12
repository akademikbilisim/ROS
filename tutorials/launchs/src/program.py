#!/usr/bin/env python2

import sys
import rospy

def main():
    rospy.init_node("program")

    rospy.logerr(sys.argv)

if __name__ == "__main__":
    main()
