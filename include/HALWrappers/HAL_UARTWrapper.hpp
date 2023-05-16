#ifndef __INCLUDE_HALWRAPPERS_HAL_UARTWRAPPER
#define __INCLUDE_HALWRAPPERS_HAL_UARTWRAPPER

#include <array>
#include <cstdint>

#include "main.h"
#include "LowLevelInterfaces/UART.hpp"

class HAL_UARTWrapper : public UART<> {

    public:

        HAL_UARTWrapper(UART_HandleTypeDef* raw_UART_handle);

        virtual UART_ErrorCode initialize() override;

        virtual UART_ErrorCode send(
            std::array<std::uint8_t, WRITE_BUFFER_SIZE> const & message
        ) override;

        virtual UART_ErrorCode receive(
            std::array<std::uint8_t, READ_BUFFER_SIZE>& buffer,
            std::uint16_t timeout_millis
        ) override;

    private:

        UART_HandleTypeDef* const raw_UART_handle;

};

#endif /* __INCLUDE_HALWRAPPERS_HAL_UARTWRAPPER */
