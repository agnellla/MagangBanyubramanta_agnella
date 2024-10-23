// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/Command.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__COMMAND__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__interfaces__msg__Command __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__Command __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Command_
{
  using Type = Command_<ContainerAllocator>;

  explicit Command_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_cmd = 0.0f;
      this->y_cmd = 0.0f;
      this->yaw = 0.0f;
      this->depth = 0.0f;
    }
  }

  explicit Command_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_cmd = 0.0f;
      this->y_cmd = 0.0f;
      this->yaw = 0.0f;
      this->depth = 0.0f;
    }
  }

  // field types and members
  using _x_cmd_type =
    float;
  _x_cmd_type x_cmd;
  using _y_cmd_type =
    float;
  _y_cmd_type y_cmd;
  using _yaw_type =
    float;
  _yaw_type yaw;
  using _depth_type =
    float;
  _depth_type depth;

  // setters for named parameter idiom
  Type & set__x_cmd(
    const float & _arg)
  {
    this->x_cmd = _arg;
    return *this;
  }
  Type & set__y_cmd(
    const float & _arg)
  {
    this->y_cmd = _arg;
    return *this;
  }
  Type & set__yaw(
    const float & _arg)
  {
    this->yaw = _arg;
    return *this;
  }
  Type & set__depth(
    const float & _arg)
  {
    this->depth = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::Command_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::Command_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::Command_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::Command_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::Command_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::Command_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::Command_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::Command_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::Command_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::Command_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__Command
    std::shared_ptr<interfaces::msg::Command_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__Command
    std::shared_ptr<interfaces::msg::Command_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Command_ & other) const
  {
    if (this->x_cmd != other.x_cmd) {
      return false;
    }
    if (this->y_cmd != other.y_cmd) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    if (this->depth != other.depth) {
      return false;
    }
    return true;
  }
  bool operator!=(const Command_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Command_

// alias to use template instance with default allocator
using Command =
  interfaces::msg::Command_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__COMMAND__STRUCT_HPP_