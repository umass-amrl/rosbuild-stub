#include <ros/ros.h>
#include "RosbuildStub/DemoMsg.h"

int main(int argc, char* argv[]) {
  ros::init(argc, argv, "rosbuild-stub");
  ros::NodeHandle n;
  ros::Publisher pub = 
      n.advertise<RosbuildStub::DemoMsg>("stub-pub", 10);
  ros::Rate rate(30);
  while (ros::ok()) {
    RosbuildStub::DemoMsg msg;
    msg.text = "Hello World";
    pub.publish(msg);
    rate.sleep();
  }
  return 0;
}
