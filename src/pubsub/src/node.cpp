#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include "interfaces/msg/command.hpp"

using namespace std::chrono_literals;
using namespace std::placeholders;

class Publisher : public rclcpp::Node
{
    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr sub;
    rclcpp::Publisher<interfaces::msg::Command>::SharedPtr pub;

    float change_axis(float input, float initial_min, float initial_max, float scaled_min, float scaled_max)
    {
        float a=(input-initial_min)/(initial_max-initial_min);
        float b=a*(scaled_max-scaled_min);
        return scaled_min+b;
    }

    void fungsi_subscribe(const sensor_msgs::msg::Joy &msg)
    {
        auto cmd = interfaces::msg::Command();
        float stick_x_left=msg.axes[0];
        float stick_y_left=msg.axes[1];
        float stick_x_right=msg.axes[3];
        // float stick_y_right=msg.axes[4];
        // float crosskey_x=msg.axes[6];
        // float crosskey_y=msg.axes[7];
        float lt=msg.axes[2];
        // float rt=msg.axes[5];

        cmd.x_cmd=change_axis(stick_x_left, -1.0f, 1.0f, -250.0f, 250.0f);
        cmd.y_cmd=change_axis(stick_y_left, -1.0f, 1.0f, -250.0f, 250.0f);
        cmd.yaw=change_axis(stick_x_right, -1.0f, 1.0f, -250.0f, 250.0f);
        cmd.depth=change_axis(lt, 0.0f, 1.0f, 0.0f, 10.0f);

        cmd.x_cmd = std::max(-250.0f, std::min(250.0f, cmd.x_cmd));
        cmd.y_cmd = std::max(-250.0f, std::min(250.0f, cmd.y_cmd));
        cmd.yaw = std::max(-180.0f, std::min(180.0f, cmd.yaw));
        cmd.depth = std::max(0.0f, std::min(10.0f, cmd.depth));

        pub->publish(cmd);
    }

public:
    Publisher() : Node("node")
    {
        sub = this->create_subscription<sensor_msgs::msg::Joy>(
            "joy", 10, std::bind(&Publisher::fungsi_subscribe, this, _1));
        pub = this->create_publisher<interfaces::msg::Command>("cmd_vel", 10);
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Publisher>());
    rclcpp::shutdown();
    return 0;
}