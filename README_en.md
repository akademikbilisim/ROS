# Robotics Workshop with ROS

### Install ROS and Gazebo Models

You can either follow instructions from wiki.ros.org/Installation or use one line install from [this repository](https://github.com/incebellipipo/ros-install-script)

#### Via simple install scripts

When installing ROS via script select _Full desktop_ and _Install all qt ros packages_.    

    # ROS
    bash <(curl -fsSL https://git.io/vNgUe) ros_ws kinetic
    
    # Gazebo models
    bash <(curl -fsSL https://git.io/vArbM)

### Deployment

    rosrun ab18ros install-required-packages.sh
    # And you are ready to go
