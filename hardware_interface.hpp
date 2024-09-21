#ifndef HARDWARE_INTERFACE_HPP
#define HARDWARE_INTERFACE_HPP

#include "hardware_interface/handle.hpp"
#include "hardware_interface/hardware_info.hpp"
#include "hardware_interface/system_interface.hpp"
#include "hardware_interface/types/hardware_interface_return_values.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp/macros.hpp"
#include "rclcpp_lifecycle/node_interfaces/lifecycle_node_interface.hpp"
#include "custom_hardware/visibility_control.h"

namespace hardware_interface {
    class HardwareInterface : public hardware_interface::ActuatorInterface {

        public:
        RCLCPP_SHARED_PTR_DEFINITIONS(HardwareInterface)

// Function definitions and lifecycle state information
        CUSTOM_HARDWARE_PUBLIC
        hardware_interface::CallbackReturn on_init(const hardware_interface::HardwareInfo & info) override;

        CUSTOM_HARDWARE_PUBLIC
        hardware_interface::CallbackReturn on_configure(rclcpp_lifecycle::State & previous_state) override;

        CUSTOM_HARDWARE_PUBLIC
        hardware_interface::CallbackReturn on_activate(rclcpp_lifecycle::State & previous_state) override;

        CUSTOM_HARDWARE_PUBLIC 
        hardware_interface::CallbackReturn on_deactivate(rclcpp_lifecycle::State & previous_state) override;

        CUSTOM_HARDWARE_PUBLIC
        hardware_interface::CallbackReturn on_cleanup(rclcpp_lifecycle::State & previous_state) override;

        CUSTOM_HARDWARE_PUBLIC
        hardware_interface::CallbackReturn on_shutdown(rclcpp_lifecycle::State & previous_state) override;

        CUSTOM_HARDWARE_PUBLIC
        hardware_interface::CallbackReturn on_error(rclcpp_lifecycle::State & previous_state) override;

        CUSTOM_HARDWARE_PUBLIC
        hardware_interface::return_type_read(const rclcpp::Time & time, const rclcpp::Duration & period) override;

        CUSTOM_HARDWARE_PUBLIC
        hardware_interface::return_type_write(const rclcpp::Time & time, const rclcpp::Duration & period) override;

    }
}