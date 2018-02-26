cmake_minimum_required(VERSION 2.8.3)
project(py3dx_gazebo)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
    amcl
    control_msgs
    controller_interface
    controller_manager
    dwa_local_planner
    gazebo_plugins
    gazebo_ros_control
    gazebo_ros
    robot_controllers
    geometry_msgs
    global_planner
    joint_state_controller
    joint_state_publisher
    joy
    joy_teleop
    move_base
    map_server
    navfn
    robot_controllers_interface
    robot_controllers_msgs
    robot_pose_publisher
    robot_state_publisher
    roslaunch
    teleop_twist_joy
    urdf
    xacro
)

catkin_package()
