#include <ros/ros.h>
#include <turtlesim/Spawn.h>

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "spawning");
  ros::NodeHandle nh;

  ros::ServiceClient spawnClient
      = nh.serviceClient<turtlesim::Spawn>("spawn");

  turtlesim::Spawn::Request req;
  turtlesim::Spawn::Response res;

  req.x = 2;
  req.y = 3;
  req.theta = M_PI/2;
  req.name = "Leo";

  bool success = spawnClient.call(req, res);
  if (success) {
    ROS_INFO_STREAM("Spawned a turtle named" << res.name);
  } else {
    ROS_ERROR_STREAM("Failed to spawn");
  }
  return 0;
}
