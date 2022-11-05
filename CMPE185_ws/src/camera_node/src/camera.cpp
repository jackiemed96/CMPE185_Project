#include "camera.hpp"

Camera::Camera()
{
    cap = std::make_shared<cv::VideoCapture>(0, cv::CAP_V4L);


    if (!cap->isOpened())
    {
        std::cout << "Cannot open camera" << std::endl;
    }
}


Camera::~Camera(){}


void Camera::grab()
{

   int return2 = cap->read(data);
   std::cout << return2 << std::endl;
    
}


cv::Mat Camera::get_image_data()
{
    return data;
}

