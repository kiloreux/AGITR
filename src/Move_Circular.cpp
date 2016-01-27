#include<ros/ros.h>
#include<geometry_msgs/Twist.h>

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "move_circular");
  ros::NodeHandle nh;

  ros::Publisher pub = nh.advertise<geometry_msgs::Twist>
                       ("turtle1/cmd_vel", 1000);
  ros::Rate rate(8);
  while (ros::ok()) {
    geometry_msgs::Twist msg;
    msg.linear.x = 1;
    msg.angular.z = 0.5;
    pub.publish(msg);
    rate.sleep();
  }
  return 0;
}
