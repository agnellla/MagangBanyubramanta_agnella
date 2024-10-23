// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/Command.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__COMMAND__STRUCT_H_
#define INTERFACES__MSG__DETAIL__COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Command in the package interfaces.
typedef struct interfaces__msg__Command
{
  float x_cmd;
  float y_cmd;
  float yaw;
  float depth;
} interfaces__msg__Command;

// Struct for a sequence of interfaces__msg__Command.
typedef struct interfaces__msg__Command__Sequence
{
  interfaces__msg__Command * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__Command__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__COMMAND__STRUCT_H_
