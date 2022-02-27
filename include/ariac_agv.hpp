/** @file include/ariac_agv.hpp
 *  A class to represent one AGV. This includes some constant description of
 *  the AGV, as well as its interface to the ROS network.
 */

#include <ros/subscriber.h>
#include <ros/service_client.h>
#include <std_msgs/String.h>

#include <string>

// Forward declare
namespace ros {
    class NodeHandle;
}

/** A class to represent one AGV. This includes some constant description of
 *  the AGV, as well as its interface to the ROS network.
 */
class AriacAgv
{
protected:
    /** The AGV number, the numeric portion of the AGV ID used in the ARIAC
     *  competition. This is constant and unique to this AGV.
     */
    const int number;

    // A subscriber for string updates on this AGV's state.
    ros::Subscriber state_sub;
    // A subscriber for string updates on the station this AGV's currently at.
    ros::Subscriber station_sub;
    // A client used to request shipments with this AGV.
    ros::ServiceClient submit_shipment_scl;

    // The last received state update of this AGV.
    std::string curr_state;
    // The last received station update of this AGV.
    std::string curr_station;

    /** Subscriber callback for @a state_sub to update @a curr_state.
     *  @param msg The updated state.
     */
    void state_callback(const std_msgs::String::ConstPtr& msg);
    /** Subscriber callback for @a station_sub to update @a curr_station.
     *  @param msg The updated station.
     */
    void station_callback(const std_msgs::String::ConstPtr& msg);

public:
    /** Constructor. Populates @a number and creates all ROS connections.
     *  @param nh A pointer to the node's handle, used to create the ROS
     *  connections managed by this object.
     *  @param agv_number The numeric portion of the AGV ID.
     */
    AriacAgv(ros::NodeHandle* const nh, const int agv_number);
    // Destructor.
    ~AriacAgv();

    /** Submit a shipment for this AGV, given the contents of an order.
     *  @param assembly_station_name The name of the assembly station to ship
     *  to, according to the order.
     *  @param shipment_type The type of shipment, according to the order.
     *  @return Whether the submission request was successfully placed and the
     *  submission itself was successful.
     */
    bool submit_shipment(const std::string& assembly_station_name,
                         const std::string& shipment_type);
};
