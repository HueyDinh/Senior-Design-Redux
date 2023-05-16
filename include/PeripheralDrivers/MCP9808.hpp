#ifndef __INCLUDE_PERIPHERALDRIVERS_MCP9808
#define __INCLUDE_PERIPHERALDRIVERS_MCP9808

#include <cstdint>
#include <array>

#include "LowLevelInterfaces/I2C.hpp"
#include "GenericPeripheralInterfaces/DigitalSensor.hpp"
#include "GenericPeripheralInterfaces/StaleCacheCallback.hpp"

class MCP9808Address {

    public:
        MCP9808Address(std::uint8_t solder_bridge_configuration);

    private:
        static constexpr std::uint8_t BASE_ADDRESS {0b0011};

        std::uint8_t const constant_bits : 4;
        std::uint8_t solder_bridge_configuration : 3;
};

template <std::size_t read_buffer_size = 4, std::size_t write_buffer_size = 2>
class MCP9808 : public DigitalSensor, public StaleCacheCallback {

    public:

        MCP9808(I2C& I2C_bus, MCP9808Address& address);

        virtual bool check_device_presence() override;
        virtual DigitalSensor_ErrorCode initialize() override;
        virtual RawBinaryReturnType read_raw_binary() override;
        virtual std::uint32_t parse_raw_binary(std::uint32_t raw_binary_value) override;
        virtual ConvertedReturnType read_converted() override;

        virtual void update();

    private:

        static constexpr uint8_t CONFIGURATION_REGISTER {0b0001};
        static constexpr uint8_t TEMPERATURE_REGISTER {0b0101};
        static constexpr uint8_t MANUFACTURER_REGISTER {0b0110};
        static constexpr uint16_t MANUFACTURER_REGISTER_CONTENT {0x0054};

        bool time_advanced_flag {true};
        I2C& I2C_bus;
        std::uint8_t const address;
        std::array<std::uint8_t, read_buffer_size> read_buffer {};
        std::array<std::uint8_t, write_buffer_size> write_buffer {};
        std::uint16_t raw_binary_reading_cache {0};
        float converted_reading_cache {0};

};

#endif /* __INCLUDE_PERIPHERALDRIVERS_MCP9808 */
