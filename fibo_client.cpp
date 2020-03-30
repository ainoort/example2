#include "ros/ros.h"
#include <sstream>
#include "ros_fibonaci/fibo.h"
#include <iostream>

using namespace std;

int main( int argc,char** argv)
{
 ros::init(argc, argv, "fibo_client");
 ros::NodeHandle nh;
ros::ServiceClient client = nh.serviceClient<ros_fibonaci::fibo>("fibonaci_sequence");
 ros_fibonaci::fibo srv;
srv.request.index = atoll(argv[1]);
srv.request.length = atoll(argv[2]);
if (client.call(srv))
{
ROS_INFO("fibo: %ld", (int)srv.response.fibonaci_sequence);
}
else
{
ROS_ERROR("Failed to call service add_two_ints");
return 1;
}
return 0;
}

