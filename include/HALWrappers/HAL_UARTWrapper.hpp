#ifndef __INCLUDE_HALWRAPPERS_HAL_UARTWRAPPER
#define __INCLUDE_HALWRAPPERS_HAL_UARTWRAPPER

#include <cstdint>

#include "main.h"

#include "LowLevelInterfaces/UART.hpp"

class HAL_UARTWrapper : public UART {

    public:

        HAL_UARTWrapper(UART_HandleTypeDef* raw_UART_handle);

        virtual UART_ErrorCode initialize() override;

        virtual UART_ErrorCode send(
            std::uint8_t const* const message,
            std::uint16_t const size_byte,
            std::uint16_t const timeout_millis
        ) override;

        virtual UART_ErrorCode receive(
            std::uint8_t* const buffer,
            std::uint16_t const size_byte,
            std::uint16_t const timeout_millis
        ) override;

    private:

        UART_HandleTypeDef* const raw_UART_handle;

};

#endif /* __INCLUDE_HALWRAPPERS_HAL_UARTWRAPPER */
