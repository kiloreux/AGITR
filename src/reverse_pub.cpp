#include <ros/ros.h>
#include <geometry_msgs/Twist.h>


ros::Publisher *pubPtr;

void ReversePub(const geometry_msgs::Twist& msgIn) {
  geometry_msgs::Twist msgOut;
  msgOut.linear.x = -msgIn.linear.x;
  msgOut.angular.z = -msgIn.angular.z;
  pubPtr->publish(msgOut);
}


int main(int argc, char *argv[]) {
  ros::init(argc, argv, "reverse_keyboard_commands");
  ros::NodeHandle nh;

  pubPtr = new ros::Publisher(nh.advertise<geometry_msgs::Twist>
                              ("turtle1/cmd_vel_reversed",
                               1000));

  ros::Subscriber sub = nh.subscribe("turtle1/cmd_vel", 1000,
                                     &ReversePub);
  ros::spin();
  delete pubPtr;

  return 0;
}
