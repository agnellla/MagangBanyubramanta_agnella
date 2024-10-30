#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "std_msgs/msg/header.hpp"
#include <chrono>
#include <cv_bridge/cv_bridge.h> 
#include <opencv2/opencv.hpp> 

using namespace std::chrono_literals;
using namespace cv;
using namespace std;

class MinimalImagePublisher : public rclcpp::Node {
public:
  MinimalImagePublisher() : Node("opencv_image_publisher"), count_(0) {
    publisher1_ =
        this->create_publisher<sensor_msgs::msg::Image>("camera", 10);
    publisher2_ = this->create_publisher<sensor_msgs::msg::Image>("mask", 10);
    timer_ = this->create_wall_timer(
        500ms, std::bind(&MinimalImagePublisher::timer_callback, this));
  }

private:
  void timer_callback() {
    VideoCapture cap("third.mp4");
    if (!cap.isOpened()) {
        cerr << "Error" << endl;
    }

    int hue = 15;      
    int thresh = 10; 

    Scalar minHSV = Scalar(hue - thresh, 0, 0); 
    Scalar maxHSV = Scalar(hue + thresh, 255, 255); 

    while (true) {
        Mat frame;
        cap >> frame;
        if (frame.empty()) break; 

        Mat hsv;
        cvtColor(frame, hsv, COLOR_BGR2HSV);

        Mat maskHSV;
        inRange(hsv, minHSV, maxHSV, maskHSV);

        Mat result = frame.clone();
        result.setTo(Scalar(255, 255, 255), maskHSV); 

        imshow("camera", frame);
        imshow("mask", maskHSV);
        
        if (waitKey(30) == 'q') break;

    msg_ = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", frame)
    .toImageMsg();
    publisher1_->publish(*msg_.get());

    msg_ = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", maskHSV)
    .toImageMsg();
    publisher2_->publish(*msg_.get());
    }
    
  }
  rclcpp::TimerBase::SharedPtr timer_;
  sensor_msgs::msg::Image::SharedPtr msg_;
  rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisher1_;
rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisher2_;
  size_t count_;
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);

  auto node = std::make_shared<MinimalImagePublisher>();

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}