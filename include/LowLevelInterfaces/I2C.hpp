#ifndef __INCLUDE_LOWLEVELINTERFACES_I2C
#define __INCLUDE_LOWLEVELINTERFACES_I2C

#include <cstdint>

enum I2C_ErrorCode {
    SUCCESS,
    TRANSMISSION_NOT_ACKNOWLEDGED,
    READ_TIMEOUT,
    UNKNOWN_FAILURE,
};

class I2C {

    public:

        virtual I2C_ErrorCode initialize() = 0;

        virtual bool is_device_present(
            std::uint16_t const slave_address
        ) = 0;

        virtual I2C_ErrorCode write_default_register(
            std::uint16_t const slave_address,
            std::uint8_t const* const register_content,
            std::uint16_t const size_byte,
            std::uint16_t const timeout_millis
        ) = 0;

        virtual I2C_ErrorCode write_register(
            std::uint16_t const slave_address,
            std::uint8_t const target_register,
            std::uint16_t const* const register_content,
            std::uint16_t const size_byte,
            std::uint16_t timeout_millis
        ) = 0;

        virtual I2C_ErrorCode read_default_register(
            std::uint8_t const target_register,
            std::uint8_t* const register_content,
            std::uint16_t const size_byte,
            std::uint16_t const timeout_millis
        ) = 0;

        virtual I2C_ErrorCode read_register(
            std::uint16_t const slave_address,
            std::uint8_t const target_register,
            std::uint8_t* const register_content,
            std::uint16_t const size_byte,
            std::uint16_t const timeout_millis
        ) = 0;

};

#endif /* __INCLUDE_LOWLEVELINTERFACES_I2C */
