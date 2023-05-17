#ifndef __INCLUDE_SUBSYSTEMDRIVERS_CONTROLSUBSYSTEM
#define __INCLUDE_SUBSYSTEMDRIVERS_CONTROLSUBSYSTEM

#include <cstdint>
#include <array>

#include "GenericControlTemplate.hpp"
#include "SystemParameters.hpp"
#include "SubsystemDrivers/HeatingControl/FanSubsystem.hpp"
#include "SubsystemDrivers/HeatingControl/SensorSubsystem.hpp"
#include "Runtime/Polling.hpp"


template <std::size_t input_dimension, std::size_t output_dimension, std::size_t memory_depth>
class DiscreteController : public Controller<input_dimension, std::size_t output_dimension> {

    public:

        DiscreteController(ControllerInputs<input_dimension>* input, ControllerOutputs<output_dimension>* output);

        virtual void update() override;

    private:

        std::array<std::array<float, memory_depth>, input_dimension> discrete_state_buffer {};

        void get_input();
        std::array<float, output_dimension> calculate_output();
        void write_output(std::array<float, output_dimension>& target_outputs);

};

namespace {
    float dummy_input_function() {
        return 0.0;
    }

    std::array<InputFunctionPointer, INPUT_DIMENSION> dummy_input_array_initialization() {
        std::array<InputFunctionPointer, INPUT_DIMENSION> dummy_array{};
        dummy_array.fill(dummy_input_function);
        return dummy_array;
    }

    void dummy_output_function(float argument) {
        return;
    }

    
    std::array<OutputFunctionPointer, OUTPUT_DIMENSION> dummy_output_array_initialization() {
        std::array<OutputFunctionPointer, OUTPUT_DIMENSION> dummy_array{};
        dummy_array.fill(dummy_output_function);
        return dummy_array;
    }
}

class ControlContext : public Polling{

    public:

        ControlContext(FanSubsystem& fan_subsystem, SensorSubsystem& sensor_subsystem);

        void disable_controller();
        void enable_controller();

        virtual void poll() override;

    private:

        const ControllerInputs<INPUT_DIMENSION> dummy_input {dummy_input_array_initialization()};
        const ControllerOutputs<OUTPUT_DIMENSION> dummy_output {dummy_output_array_initialization()};

        ControllerInputs<INPUT_DIMENSION> input;
        ControllerOutputs<OUTPUT_DIMENSION> output;

        DiscreteController<INPUT_DIMENSION, OUTPUT_DIMENSION, 1> controller;

        FanSubsystem& fan_subsystem;
        SensorSubsystem& sensor_subsystem;

        std::array<InputFunctionPointer, INPUT_DIMENSION> input_array_initialization();
        std::array<OutputFunctionPointer, OUTPUT_DIMENSION> output_array_initialization();

};


#endif /* __INCLUDE_SUBSYSTEMDRIVERS_CONTROLSUBSYSTEM */
