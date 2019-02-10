#!/usr/bin/env python2

import rospy
from std_msgs.msg import UInt32

def main():

    rospy.init_node("number_publisher")
    publisher = rospy.Publisher("number", UInt32, queue_size=10)

    n = UInt32()
    n.data = 0
    while not rospy.is_shutdown():
        n.data += 1
        publisher.publish(n)
        rospy.sleep(1)


if __name__ == "__main__":
    main()
