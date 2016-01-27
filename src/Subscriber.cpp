#include<ros/ros.h>
#include<turtlesim/Pose.h>
#include<iomanip>


void poseReport(const turtlesim::Pose& msg) {
  ROS_INFO_STREAM(std::setprecision(2) << std::fixed <<
                  " position= ("<< msg.x << "," <<  msg.y << ")" << " direction= " << msg.theta);
}


int main(int argc, char *argv[]) {
  ros::init(argc, argv, "subscriber");
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe("turtle1/pose", 1000, &poseReport);
  ros::spin();
  return 0;
}
