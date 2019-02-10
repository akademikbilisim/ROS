import rospy
from nav_msgs.msg import Odometry
from gazebo_msgs.srv import SetModelState
from gazebo_msgs.msg import ModelState

class Robot:
    def __init__(self):
        self.odom = None 
        self.past_odom = None

        rospy.Subscriber("/odom", Odometry, self.odom_cb)

        self.replacement = 0

    def odom_cb(self, msg):
        self.past_odom = self.odom
        self.odom = msg

        if self.past_odom is not None:
            px = self.past_odom.pose.pose.position.x
            py = self.past_odom.pose.pose.position.y
            
            cx = self.odom.pose.pose.position.x
            cy = self.odom.pose.pose.position.y
            
            self.replacement += ((px - cx)**2 + (py - cy)**2)**(1/2.0)

        print self.replacement
        if self.replacement > 1:
            self.reset()

    def reset(self):
        self.replacement = 0
        rospy.wait_for_service('/gazebo/set_model_state')
        try:
            m = ModelState()
            m.model_name = "mobile_base"
            reset_model = rospy.ServiceProxy('/gazebo/set_model_state', 
                    SetModelState)
            reset_model(m)
        except rospy.ServiceException, e:
            print "Service call failed: %s"%e


