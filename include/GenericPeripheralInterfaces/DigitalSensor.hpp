#ifndef __INCLUDE_GENERICPERIPHERALINTERFACES_DIGITALSENSOR
#define __INCLUDE_GENERICPERIPHERALINTERFACES_DIGITALSENSOR

#include <cstdint>

enum DigitalSensor_ErrorCode {
    SUCCESS,
    DEVICE_NOT_DETECTED,
    CONFIGURATION_FAILURE,
    READ_FAILURE,
    UNKNOWN_FAILURE,
};

union RawBinaryReturnType {
    std::uint32_t value;
    DigitalSensor_ErrorCode error;
};

union ConvertedReturnType {
    std::uint32_t value;
    DigitalSensor_ErrorCode error;
};

class DigitalSensor {
    
    public:

        virtual bool check_device_presence() = 0;

        virtual DigitalSensor_ErrorCode initialize() = 0;

        virtual RawBinaryReturnType read_raw_binary() = 0;
        
        virtual std::uint32_t parse_raw_binary(std::uint32_t raw_binary_value) = 0;

        virtual ConvertedReturnType read_converted() = 0;

};

#endif /* __INCLUDE_GENERICPERIPHERALINTERFACES_DIGITALSENSOR */
