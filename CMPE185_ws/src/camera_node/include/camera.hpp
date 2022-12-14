#include <iostream>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/videoio.hpp>

class Camera
{
    public:
        Camera();
        ~Camera();

        void grab();
        cv::Mat get_image_data();


    private:
        std::shared_ptr<cv::VideoCapture> cap;
        cv::Mat data;

};