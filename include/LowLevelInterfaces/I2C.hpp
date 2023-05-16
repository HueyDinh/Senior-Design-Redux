#ifndef __INCLUDE_LOWLEVELINTERFACES_I2C
#define __INCLUDE_LOWLEVELINTERFACES_I2C

#include <cstdint>
#include <array>
#include "ErrorHandling/ErrorCodeAndMessage.hpp"

template <std::uint16_t read_buffer_size = 10, std::uint16_t write_buffer_size = 4>
class I2C {

    public:

        static constexpr uint16_t READ_BUFFER_SIZE {read_buffer_size};
        static constexpr uint16_t WRITE_BUFFER_SIZE {write_buffer_size};

        virtual I2C_ErrorCode initialize() = 0;

        virtual bool is_device_present(
            std::uint16_t slave_address
        ) = 0;

        virtual I2C_ErrorCode write_default_register(
            std::uint16_t slave_address,
            std::array<std::uint8_t, WRITE_BUFFER_SIZE> const & register_content,
            std::uint16_t timeout_millis
        ) = 0;

        virtual I2C_ErrorCode write_register(
            std::uint16_t slave_address,
            std::uint8_t target_register,
            std::array<std::uint8_t, WRITE_BUFFER_SIZE> const & register_content,
            std::uint16_t timeout_millis
        ) = 0;

        virtual I2C_ErrorCode read_default_register(
            std::uint8_t target_register,
            std::array<std::uint8_t, READ_BUFFER_SIZE>& register_content,
            std::uint16_t timeout_millis
        ) = 0;

        virtual I2C_ErrorCode read_register(
            std::uint16_t slave_address,
            std::uint8_t target_register,
            std::array<std::uint8_t, READ_BUFFER_SIZE>& register_content,
            std::uint16_t timeout_millis
        ) = 0;


};

#endif /* __INCLUDE_LOWLEVELINTERFACES_I2C */
