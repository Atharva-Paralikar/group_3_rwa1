
#include "ros/ros.h"
#include "std_msgs/String.h"

void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO(" Competition State is [%s]", msg->data.c_str());
}

int main(int argc, char **argv)

{
ros::init(argc, argv,"competition_state");
ros::NodeHandle n;

ros::Subscriber sub = n.subscribe("/ariac/competition_state", 1000, chatterCallback);
ros::spin();
return 0;
}
