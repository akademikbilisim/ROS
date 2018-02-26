#include <ros/ros.h> 
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>
#include <math.h>

#define _2_M_PI M_PI * 2.0

int main(int argc, char** argv){

  ros::init(argc, argv, "tf_madness_node");

  static tf2_ros::TransformBroadcaster br;

  std::vector<geometry_msgs::TransformStamped> transforms;

  geometry_msgs::TransformStamped tfs0;
  tfs0.header.frame_id = "globe";
  tfs0.child_frame_id = "";
  tfs0.transform.translation.x = 1;
  tfs0.transform.translation.y = 1;
  tfs0.transform.translation.z = 1;


  geometry_msgs::TransformStamped tfs1;
  tfs1.header.frame_id = "globe";
  tfs1.child_frame_id = "tfs1";
  tfs1.transform.translation.x = 1;
  tfs1.transform.translation.y = 1;
  tfs1.transform.translation.z = 1;


  geometry_msgs::TransformStamped tfs2;
  tfs2.header.frame_id = "globe";
  tfs2.child_frame_id = "tfs2";
  tfs2.transform.translation.x = 0.0;
  tfs2.transform.translation.y = 0.0;
  tfs2.transform.translation.z = 1;


  geometry_msgs::TransformStamped tfs3;
  tfs3.header.frame_id = "globe";
  tfs3.child_frame_id = "tfs3";
  tfs3.transform.translation.x = 1;
  tfs3.transform.translation.y = 0.0;
  tfs3.transform.translation.z = 0.0;


  geometry_msgs::TransformStamped tfs4;
  tfs4.header.frame_id = "globe";
  tfs4.child_frame_id = "tfs4";
  tfs4.transform.translation.x = 0.0;
  tfs4.transform.translation.y = 1;
  tfs4.transform.translation.z = 0.0;

  geometry_msgs::TransformStamped tfs5;
  tfs5.header.frame_id = "tfs2";
  tfs5.child_frame_id = "tfs5";
  tfs5.transform.translation.x = 1.0;
  tfs5.transform.translation.y = 0.0;
  tfs5.transform.translation.z = 0.0;


  geometry_msgs::TransformStamped tfs6;
  tfs5.header.frame_id = "universe";
  tfs5.child_frame_id = "globe";
  tfs5.transform.translation.x = 1.0;
  tfs5.transform.translation.y = 0.0;
  tfs5.transform.translation.z = 1.0;



  transforms.push_back(tfs0);
  transforms.push_back(tfs1);
  transforms.push_back(tfs2);
  transforms.push_back(tfs3);
  transforms.push_back(tfs4);
  transforms.push_back(tfs5);
  transforms.push_back(tfs6);

  ros::NodeHandle nh("~");
  ros::Rate r(50);
  float angle = 0;
  while(ros::ok()){
    for(auto tfs: transforms){
      tf2::Quaternion q;
      q.setRPY(
          angle * tfs.transform.translation.x,
          angle * tfs.transform.translation.y,
          angle * tfs.transform.translation.z
          );
      tfs.transform.rotation.x = q.x();
      tfs.transform.rotation.y = q.y();
      tfs.transform.rotation.z = q.z();
      tfs.transform.rotation.w = q.w();
      br.sendTransform(tfs);
    }
    
    angle = angle > _2_M_PI ? 0 : angle +  0.03490658503988659;
    r.sleep();
  }

  return 0;
}
