#include "ros/ros.h"
#include "std_msgs/String.h"
#include <nist_gear/AGVToAssemblyStation.h>
#include <std_srvs/Trigger.h>
#include "../include/agv_service.hpp"
#include<string>

Ariac_Agv::Ariac_Agv(ros::NodeHandle* n,  int agv_no){
    const std::string service_name = std::string("/ariac/agv")+std::to_string(agv_no)+ std::string("/submit_shipment");
    ros::ServiceClient client = n->serviceClient<nist_gear::AGVToAssemblyStation>(service_name);
    nist_gear::AGVToAssemblyStation srv;
    
    const std::string station_name=std::string("as")+std::to_string(agv_no);
    
    srv.request.assembly_station_name = station_name;
    srv.request.shipment_type = "order_0_kitting_shipment_0";
    
    
    
    if(client.call(srv)) 
    {
        if(srv.response.success){
            ROS_INFO( "sucess :%s",srv.response.message.c_str());}
        else
        {
            ROS_INFO("Failure: %s",srv.response.message.c_str());
        }
    }
}
Ariac_Agv::~Ariac_Agv(){}

int main(int argc, char **argv){
ros::init(argc, argv, "agv_assembly_station");
    ros::NodeHandle n;
    for(int i =1;i<=4;i++){
        Ariac_Agv(&n,i);
    }
    
    


}