#ifndef __INCLUDE_STANDARDINTERFACES_UART
#define __INCLUDE_STANDARDINTERFACES_UART

#include <cstdint>
#include "ErrorHandling/ErrorCodeAndMessage.hpp"
#include <array>

template <std::uint16_t send_buffer_size = 60, std::uint16_t read_buffer_size = 60>
class UART {

    public:

        virtual UART_ErrorCode initialize() = 0;

        virtual UART_ErrorCode send(
            std::array<std::uint8_t, send_buffer_size> const & message
        ) = 0;

        virtual UART_ErrorCode receive(
            std::array<std::uint8_t, read_buffer_size>& buffer,
            std::uint16_t timeout_millis
        ) = 0;

};

#endif /* __INCLUDE_STANDARDINTERFACES_UART */
