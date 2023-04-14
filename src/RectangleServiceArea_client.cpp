#include <ros/ros.h>
#include <ros_service_assignment/RectangleServiceArea.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "RectangleServiceArea_client");

    if(argc != 3)
    {
        ROS_INFO("usage: RectangleServiceArea length width");
        return 1;
    }

    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<ros_service_assignment::RectangleServiceArea>("RectangleServiceArea");
    ROS_INFO("argv[1]:%s", argv[1]);
    ROS_INFO("argv[2]:%s", argv[2]);
    ros_service_assignment::RectangleServiceArea srv;
    srv.request.length = atof(argv[1]);
    srv.request.width = atof(argv[2]);

    ROS_INFO("Length:%lf", atof(argv[1]));
    ROS_INFO("width:%lf", srv.request.width);

    if(client.call(srv))
    {
        ROS_INFO("Area of Rectangle:<%lf>", srv.response.area);
    }
    else
    {
        ROS_ERROR("Unable to reach out to RectangleServiceArea service");
        return 1;
    }

    return 0;
}