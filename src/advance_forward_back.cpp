#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include<ctime>

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "advance_time");
  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<geometry_msgs::Twist>
                       ("turtle1/cmd_vel", 1000);
  ros::Rate rate(1);
  int move_seconds = 5;
  time_t time_now;
  time(&time_now);
  time_t time_later;
  time(&time_later);

  geometry_msgs::Twist msg;

  while ( difftime(time_later, time_now) < move_seconds && ros::ok() ) {
    msg.linear.x = 1;
    pub.publish(msg);
    ROS_INFO_STREAM("The difference is "<< difftime(time_later, time_now));
    time(&time_later);
    rate.sleep();
  }

  msg.linear.x = 0;
  msg.angular.z = 0;
  pub.publish(msg);

  return 0;
}
