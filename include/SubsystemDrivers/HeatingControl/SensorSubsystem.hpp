#ifndef __INCLUDE_SUBSYSTEMDRIVERS_HEATINGCONTROL_SENSORSUBSYSTEM
#define __INCLUDE_SUBSYSTEMDRIVERS_HEATINGCONTROL_SENSORSUBSYSTEM

#include <array>

#include "GenericPeripheralInterfaces/DigitalSensor.hpp"
#include "SubsystemDrivers/ContextSwitching/Callbacks.hpp"
#include "SystemParameters.hpp"

class SensorSubsystem : public InputFunctionProvider<INPUT_DIMENSION>, public Polling{

    public:

        SensorSubsystem(
            std::array<DigitalSensor, NUM_SEAT_SENSOR> seat_sensor_array,
            std::array<DigitalSensor, NUM_AMBIENT_SENSOR> ambient_sensor_array,
            std::array<DigitalSensor, NUM_FLOW_TEMP_SENSOR> flow_temp_sensor_array, 
            std::array<DigitalSensor, NUM_FLOW_MOIST_SENSOR> flow_moist_sensor_array,
            HighAmbientTempHandler& high_temp_handler,
            HotSeatHandler& hot_seat_handler
        );

        virtual std::array<InputFunctionPointer, INPUT_DIMENSION> generate_input_function_pointers();

    private:

        std::array<DigitalSensor, NUM_SEAT_SENSOR> seat_sensor_array;
        std::array<DigitalSensor, NUM_AMBIENT_SENSOR> ambient_sensor_array;
        std::array<DigitalSensor, NUM_FLOW_TEMP_SENSOR> flow_temp_sensor_array; 
        std::array<DigitalSensor, NUM_FLOW_MOIST_SENSOR> flow_moist_sensor_array; 

};

#endif /* __INCLUDE_SUBSYSTEMDRIVERS_HEATINGCONTROL_SENSORSUBSYSTEM */
