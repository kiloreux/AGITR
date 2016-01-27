#include <ros/ros.h>

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "logger");
  ros::NodeHandle nh;

  ros::Rate rate(10);

  for (int i = 0 ; ros::ok(), i < 50 ; i++) {
    if (i%2 == 0) {
      ROS_INFO_STREAM("The value of i which is " << i << " is divisble by 2");
    }
    if (i%3 == 0) {
      ROS_DEBUG_STREAM("The value of i which is " << i << " is divisible by 3");
    }
    if (i%5 == 0) {
      ROS_ERROR_STREAM("The value of i which is " << i << " is divisble by 5");
    }
    if (i%10 == 0) {
      ROS_FATAL_STREAM("-_- Sorry ");
    }
    rate.sleep();
  }
  return 0;
}
