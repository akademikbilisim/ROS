cmake_minimum_required(VERSION 2.8.3)
project(serial_comm)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  nav_msgs
  roscpp
  rospy
  sensor_msgs
  serial
  std_msgs
  message_generation
)

# find_package(Boost REQUIRED COMPONENTS system)
add_message_files(
  FILES
  ArduinoState.msg
  ButtonStates.msg
  CounterStates.msg
)

generate_messages(
    DEPENDENCIES
    std_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES serial_comm
  CATKIN_DEPENDS geometry_msgs nav_msgs roscpp rospy sensor_msgs serial std_msgs message_runtime
  DEPENDS system_lib
)





include_directories(
 include
 ${catkin_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME}
  src/${PROJECT_NAME}/serial_comm.cpp
)
add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
)

add_executable(${PROJECT_NAME}_node src/serial_comm_node.cpp)
add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
  ${PROJECT_NAME}
)
