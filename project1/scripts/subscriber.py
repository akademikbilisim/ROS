#!/usr/bin/env python2

import rospy
from std_msgs.msg import UInt32

def isEven(n):
    return (n % 2 == 0)

def number_callback(msg):
    if isEven(msg.data):
        print "heck yea: {0}".format(msg.data)

def main():
    rospy.init_node("number_subscriber")
    rospy.Subscriber("number", UInt32, number_callback) 
    rospy.spin()

if __name__ == "__main__":
    main()
