#include <ros/ros.h>
#include <ros_service_assignment/RectangleServiceArea.h>

bool rectangleArea(ros_service_assignment::RectangleServiceArea::Request &req, 
                    ros_service_assignment::RectangleServiceArea::Response &res )
{
    res.area = req.length * req.width;
    ROS_INFO("Received: Length:<%lf> Width:<%lf>", req.length, req.width);
    ROS_INFO("sending back the calculated area: <%lf>", res.area);    
    return true;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "RectangleServiceArea_server");
    ros::NodeHandle nh;

    ros::ServiceServer srv = nh.advertiseService("RectangleServiceArea", rectangleArea);
    ROS_INFO("RectanleServiceArea Service is ready to serve");
    ros::spin();
    return 0;
}