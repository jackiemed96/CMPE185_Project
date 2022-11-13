#include "camera_node.hpp"

CameraNode::CameraNode() : Node("camera_node") 
{
    publisher_ = this->create_publisher<sensor_msgs::msg::Image>("raw_image", 10);
    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(33), std::bind(&CameraNode::call_back, this));
    camera = std::make_shared<Camera>();
    
}

void CameraNode::call_back()
{
    camera->grab();
    sensor_msgs::msg::Image::SharedPtr message = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", camera->get_image_data()).toImageMsg();

    publisher_->publish(*message);
}


