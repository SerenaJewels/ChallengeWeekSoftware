// Including library header
#include "MotorFunctions/MotorFunctions.h"

// Define functions (and make calls to library functions)
namespace MotorFunctions {

    // on_init function
    hardware_interface::CallbackReturn HardwareInterface::on_init(const hardware_interface::HardwareInfo & info) {
        // If statement condition processes standard values (ex. name)
        // Returns error if not all required parameters are set
        if (hardware_interface::ActuatorInterface::on_init(info) != hardware_interface::CallbackReturn::SUCCESS) {
            return hardware_interface::CallbackReturn()::ERROR;
        }
    }

    hardware_interface::CallbackReturn HardwareInterface::on_configure(const hardware_interface::HardwareInfo & info) {
        return hardware_interface::CallbackReturn()::ERROR;
    }

    // on_activate function: when motor transitions to active state
    hardware_interface::CallbackReturn HardwareInterface::on_activate(rclcpp_lifecycle::State & previous_state) {
        // Call motor functions from library
        MotorFunctions mf;
        mf.stop();
        sleep(5);
        mf.rotate(0xFF);
        sleep(5);
        return hardware_interface::CallbackReturn::SUCCESS;
    }

    // Functions below are left empty
    hardware_interface::CallbackReturn HardwareInterface::on_deactivate(rclcpp_lifecycle::State & previous_state) {
        return hardware_interface::CallbackReturn::SUCCESS;
    }

    hardware_interface::CallbackReturn on_cleanup(rclcpp_lifecycle::State & previous_state) {
        return hardware_interface::CallbackReturn::SUCCESS;
    }

    hardware_interface::CallbackReturn on_shutdown(rclcpp_lifecycle::State & previous_state) {
        return hardware_interface::CallbackReturn::SUCCESS;
    }

    hardware_interface::CallbackReturn on_error(rclcpp_lifecycle::State & previous_state) {
        return hardware_interface::CallbackReturn::ERROR;
    }

    hardware_interface::return_type HardwareInterface::read(const rclcpp::Time & time, const rclcpp::Duration & period) {
        return hardware_interface::return_type::OK;
    }

    hardware_interface::return_type HardwareInterface::write(const rclcpp::Time & time, const rclcpp::Duration & period) {
        return hardware_interface::return_type::OK;
    }
}