#include <chrono>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "cv_bridge/cv_bridge.h"
#include "camera.hpp"

class CameraNode : public rclcpp::Node
{
    public:
        CameraNode();

    private:
        void call_back();
        std::shared_ptr<Camera> camera;

        rclcpp::TimerBase::SharedPtr timer_;
        rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisher_;

};