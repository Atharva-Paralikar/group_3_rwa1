#include "ros/ros.h"
#include "std_msgs/String.h"
#include <nist_gear/AGVToAssemblyStation.h>
#include <std_srvs/Trigger.h>
#include<string>

namespace ros{
    class NodeHandle;
}
class Ariac_Agv{
public:
Ariac_Agv(ros::NodeHandle*  n, int agv_no);
~Ariac_Agv();

};