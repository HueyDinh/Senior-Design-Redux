#ifndef __INCLUDE_HALWRAPPERS_HAL_I2CWRAPPER
#define __INCLUDE_HALWRAPPERS_HAL_I2CWRAPPER

#include <cstdint>

#include "main.h"

#include "LowLevelInterfaces/I2C.hpp"


class HAL_I2CWrapper : public I2C {

    public:

        HAL_I2CWrapper(I2C_HandleTypeDef* raw_I2C_handle);
        
        virtual I2C_ErrorCode initialize() override;

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
            std::uint8_t const* const register_content,
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

HAL_I2CWrapper::HAL_I2CWrapper(I2C_HandleTypeDef* raw_I2C_handle):
    raw_I2C_handle{raw_I2C_handle}
{}

I2C_ErrorCode HAL_I2CWrapper::initialize() {
    //TODO: Add the generated function call after finishing wrapper
    return I2C_ErrorCode::SUCCESS;
}

bool HAL_I2CWrapper::is_device_present(std::uint16_t const slave_address) {

    return (HAL_I2C_IsDeviceReady(raw_I2C_handle, slave_address, 2, TIMEOUT_MILLIS) == HAL_OK);
}

I2C_ErrorCode HAL_I2CWrapper::write_default_register(
    std::uint16_t const slave_address,
    std::uint8_t const* const register_content,
    std::uint16_t const size_byte,
    std::uint16_t const timeout_millis
) {
    HAL_StatusTypeDef write_status {
        HAL_I2C_Master_Transmit(
            raw_I2C_handle,
            slave_address,
            const_cast<std::uint8_t *>(register_content),
            size_byte,
            timeout_millis
        )
    };

    if (write_status == HAL_OK) {
        return I2C_ErrorCode::SUCCESS;
    } else {
        return I2C_ErrorCode::TRANSMISSION_NOT_ACKNOWLEDGED;
    }

}

I2C_ErrorCode HAL_I2CWrapper::write_register(
    std::uint16_t const slave_address,
    std::uint8_t const target_register,
    std::uint8_t const* const register_content,
    std::uint16_t const size_byte,
    std::uint16_t timeout_millis
) {
    HAL_StatusTypeDef write_status {
        HAL_I2C_Mem_Write(
            raw_I2C_handle,
            slave_address,
            target_register,
            size_byte,
            const_cast<std::uint8_t *>(register_content),
            size_byte,
            timeout_millis
        )
    };

    if (write_status == HAL_OK) {
        return I2C_ErrorCode::SUCCESS;
    } else {
        return I2C_ErrorCode::TRANSMISSION_NOT_ACKNOWLEDGED;
    }
}

I2C_ErrorCode HAL_I2CWrapper::read_default_register(
    std::uint8_t const target_register,
    std::uint8_t* const register_content,
    std::uint16_t const size_byte,
    std::uint16_t const timeout_millis
) {
    
};

        virtual I2C_ErrorCode read_register(
            std::uint16_t const slave_address,
            std::uint8_t const target_register,
            std::uint8_t* const register_content,
            std::uint16_t const size_byte,
            std::uint16_t const timeout_millis
        ) override;    




#endif /* __INCLUDE_HALWRAPPERS_HAL_I2CWRAPPER */
