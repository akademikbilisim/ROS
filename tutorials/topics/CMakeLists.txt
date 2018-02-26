cmake_minimum_required(VERSION 2.8.3)
project(topics)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
)

## Generate messages in the 'msg' folder
add_message_files(
  FILES
  Fancy.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
  )

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES topics
  CATKIN_DEPENDS roscpp std_msgs message_runtime
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(chatter src/chatter.cpp)

add_dependencies(chatter ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(chatter
  ${catkin_LIBRARIES}
)

add_executable(listener src/listener.cpp)

add_dependencies(listener ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(listener
  ${catkin_LIBRARIES}
)

