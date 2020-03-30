#include "ros/ros.h"
#include "sstream"
#include "ros_fibonaci/fibo.h"

using namespace std;

bool service_callback(ros_fibonaci::fibo::Request &req, ros_fibonaci::fibo::Response &res){


ROS_INFO("request: x=%ld, y=%ld", (int)req.index, (int)req.length);
ROS_INFO("sending back response: [%ld]", (long int)res.out);
return true;
}
int main(int argc, char **argv)
{
  ros::init(argc, argv, "fibo_server");
  ros::NodeHandle nh;

int i;
int f[req.index];
 f[0] = 0;
 f[1] = 1;
if (req.length >= 0)
    {
    for(i=2; i= req.index + req.length; i++)
     {
       f[i] = f[i-1] + f[i-2];
    }
   for (i=req.index; i= req.index + req.length ; i++)
   {
   res.out = f[i];
   }
else
  {
  ROS_ERROR("length should be positive");
return 1;
}}

ros::ServiceServer service = nh.advertiseService("fibonaci_sequence", res.out);
ROS_INFO("Ready to get two ints.");
ros::spin();
}
return 0;
}


 













