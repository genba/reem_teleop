/*
 * Filename: reem_teleop.h
 * Author: Marcus Liebhardt
 * Created: 21.03.2011
 * License: 
 */

#include <string>

#include <kdl/frames.hpp>
#include <kdl/jntarray.hpp>
#include <kdl/jntarrayvel.hpp>
#include <kdl/treeiksolver.hpp>
#include <ros/ros.h>
#include <tf/transform_listener.h>


class ReemTeleop
{
  public:
  ReemTeleop(ros::NodeHandle &nh, KDL::Tree &kdl_tree);
  ~ReemTeleop();
  
  
  ros::NodeHandle nh_;
      
  // ROS subscribers listening for desired endpoints' poses
  ros::Subscriber sub_command_pose_torso_;
  ros::Subscriber sub_command_pose_shoulder_left_;
  ros::Subscriber sub_command_pose_elbow_left_;
  ros::Subscriber sub_command_pose_hand_left_;
  ros::Subscriber sub_command_pose_shoulder_right_;
  ros::Subscriber sub_command_pose_elbow_right_;
  ros::Subscriber sub_command_pose_hand_right_;
  ros::Subscriber sub_command_pose_head_;   
  
  void commandPoseTorsoCB(const geometry_msgs::PoseStamped::ConstPtr &command);
  void commandPoseLeftShoulderCB(const geometry_msgs::PoseStamped::ConstPtr &command);
  void commandPoseLeftElbowCB(const geometry_msgs::PoseStamped::ConstPtr &command);
  void commandPoseLeftHandCB(const geometry_msgs::PoseStamped::ConstPtr &command);
  void commandPoseRightShoulderCB(const geometry_msgs::PoseStamped::ConstPtr &command);
  void commandPoseRightElbowCB(const geometry_msgs::PoseStamped::ConstPtr &command);  
  void commandPoseRightHandCB(const geometry_msgs::PoseStamped::ConstPtr &command);
  void commandPoseHeadCB(const geometry_msgs::PoseStamped::ConstPtr &command);
  
  // tf for transforming geometry_msgs::PoseStamped to KDL::Frame  
  tf::TransformListener tf_;
  
  // The tree's root name for calculatiing transforms by tf
  std::string tree_root_name_;
  
  // Boolean flags indicating if new poses have arrived
  bool new_x_desi_torso_;
  bool new_x_desi_l_shoulder_;
  bool new_x_desi_l_elbow_;
  bool new_x_desi_l_hand_;
  bool new_x_desi_r_shoulder_;
  bool new_x_desi_r_elbow_;
  bool new_x_desi_r_hand_;
  bool new_x_desi_head_;
  
  // KDL variables (which need to be pre-allocated).
  KDL::Tree         kdl_tree_;          
  
  KDL::JntArray     q_;                 // Joint positions
  KDL::JntArray     q_desi_;            // Desired joint positions

  KDL::Frames       x0s_;               // (Map of) Inital frames of the endpoints
  KDL::Frames       xs_;                // (Map of) Frames of the endpoints
  KDL::Frames       xs_desi_;           // (Map of) Desired positions of the endpoints

  KDL::Frame        x0_torso_;          // Torso initial pose 
  KDL::Frame        x_torso_;           // Torso pose
  KDL::Frame        x_desi_torso_;      // Torso desired pose

  KDL::Frame        x0_l_shoulder_;     // Left shoulder initial pose 
  KDL::Frame        x_l_shoulder_;      // Left shoulder pose
  KDL::Frame        x_desi_l_shoulder_; // Left shoulder desired pose

  KDL::Frame        x0_l_elbow_;        // Left elbow initial pose 
  KDL::Frame        x_l_elbow_;         // Left elbow pose
  KDL::Frame        x_desi_l_elbow_;    // Left elbow desired pose

  KDL::Frame        x0_l_hand_;         // Left hand initial pose 
  KDL::Frame        x_l_hand_;          // Left hand pose
  KDL::Frame        x_desi_l_hand_;     // Left hand desired pose

  KDL::Frame        x0_r_shoulder_;     // Right shoulder initial pose   
  KDL::Frame        x_r_shoulder_;      // Right shoulder pose
  KDL::Frame        x_desi_r_shoulder_; // Right shoulder desired pose

  KDL::Frame        x0_r_elbow_;        // Right elbow initial pose   
  KDL::Frame        x_r_elbow_;         // Right elbow pose
  KDL::Frame        x_desi_r_elbow_;    // Right elbow desired pose

  KDL::Frame        x0_r_hand_;         // Right hand initial pose   
  KDL::Frame        x_r_hand_;          // Right hand pose
  KDL::Frame        x_desi_r_hand_;     // Right hand desired pose
  
  KDL::Frame        x0_head_;           // Head initial pose 
  KDL::Frame        x_head_;            // Head pose
  KDL::Frame        x_desi_head_;       // Head desired pose
  private:
};

