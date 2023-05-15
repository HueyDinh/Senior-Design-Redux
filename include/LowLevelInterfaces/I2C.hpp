#ifndef __INCLUDE_STANDARDINTERFACES_I2C
#define __INCLUDE_STANDARDINTERFACES_I2C

#include <cstdint>
#include <array>
#include "ErrorHandling/ErrorCodeAndMessage.hpp"

template <std::uint16_t write_buffer_size = 4, std::uint16_t read_buffer_size = 10>
class I2C {

    public:

        virtual I2C_ErrorCode initialize() = 0;

        virtual bool is_device_present() = 0;

        virtual I2C_ErrorCode write_default_register(
            std::uint16_t slave_address,
            std::array<std::uint8_t, write_buffer_size> const & register_content,
            std::uint16_t timeout_millis
        ) = 0;

        virtual I2C_ErrorCode write_register(
            std::uint16_t slave_address,
            std::uint8_t target_register,
            std::array<std::uint8_t, write_buffer_size> const & register_content,
            std::uint16_t timeout_millis
        ) = 0;

        virtual I2C_ErrorCode read_default_register(
            std::uint8_t target_register,
            std::array<std::uint8_t, read_buffer_size>& register_content,
            std::uint16_t timeout_millis
        ) = 0;

        virtual I2C_ErrorCode read_register(
            std::uint16_t slave_address,
            std::uint8_t target_register,
            std::array<std::uint8_t, read_buffer_size>& register_content,
            std::uint16_t timeout_millis
        ) = 0;

};

#endif /* __INCLUDE_STANDARDINTERFACES_I2C */
