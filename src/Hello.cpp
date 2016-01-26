#include<ros/ros.h>

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "Hello_world");
  ros::NodeHandle nh;
  ROS_INFO_STREAM("Hello ROS world");
  return 0;
}
