#!/usr/bin/env python2

import rospy
import cv2
from cv_bridge import CvBridge
from sensor_msgs.msg import Image

bridge = CvBridge()

def image_callback(msg):
    try:
        image = bridge.imgmsg_to_cv2(msg, 'bgr8')
    except:
        return
        
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    blur = cv2.GaussianBlur(gray, (5, 5), 0)
    edge = cv2.Canny(blur, 33, 165)
        
    cv2.imshow("Robot Kamerasi", edge)
    cv2.waitKey(1)
    
    
def main():
    rospy.init_node("camera", anonymous=False)
    
    sub = rospy.Subscriber("/camera/rgb/image_raw", Image, image_callback, queue_size=1)
    
    rospy.spin()
    
    
if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass
