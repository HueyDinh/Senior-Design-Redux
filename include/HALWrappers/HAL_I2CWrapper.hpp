#ifndef __INCLUDE_HALWRAPPERS_HAL_I2CWRAPPER
#define __INCLUDE_HALWRAPPERS_HAL_I2CWRAPPER

#include <cstdint>

#include "main.h"

#include "LowLevelInterfaces/I2C.hpp"


class HAL_I2CWrapper : public I2C {

    public:

        HAL_I2CWrapper(I2C_HandleTypeDef* raw_I2C_handle);
        
        virtual I2C_ErrorCode initialize() = 0;

        virtual bool is_device_present(
            std::uint16_t const slave_address
        ) override;

        virtual I2C_ErrorCode write_default_register(
            std::uint16_t const slave_address,
            std::uint8_t const* const register_content,
            std::uint16_t const size_byte,
            std::uint16_t const timeout_millis
        ) override;

        virtual I2C_ErrorCode write_register(
            std::uint16_t const slave_address,
            std::uint8_t const target_register,
            std::uint16_t const* const register_content,
            std::uint16_t const size_byte,
            std::uint16_t timeout_millis
        ) override;

        virtual I2C_ErrorCode read_default_register(
            std::uint8_t const target_register,
            std::uint8_t* const register_content,
            std::uint16_t const size_byte,
            std::uint16_t const timeout_millis
        ) override;

        virtual I2C_ErrorCode read_register(
            std::uint16_t const slave_address,
            std::uint8_t const target_register,
            std::uint8_t* const register_content,
            std::uint16_t const size_byte,
            std::uint16_t const timeout_millis
        ) override;        

    private:
        static constexpr std::uint32_t TIMEOUT_MILLIS {2000};

        I2C_HandleTypeDef* const raw_I2C_handle;

};

#endif /* __INCLUDE_HALWRAPPERS_HAL_I2CWRAPPER */
