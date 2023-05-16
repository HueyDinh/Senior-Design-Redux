#ifndef __INCLUDE_STANDARDINTERFACES_UART
#define __INCLUDE_STANDARDINTERFACES_UART

#include <cstdint>

enum UART_ErrorCode {
    SUCCESS,
    CONFIGURATION_FAILURE,
    READ_TIMEOUT,
    UNKNOWN_FAILURE,
};

class UART {

    public:

        virtual UART_ErrorCode initialize() = 0;

        virtual UART_ErrorCode send(
            std::uint8_t const* const message,
            std::uint16_t const size_byte,
            std::uint16_t const timeout_millis
        ) = 0;

        virtual UART_ErrorCode receive(
            std::uint8_t* const buffer,
            std::uint16_t const size_byte,
            std::uint16_t const timeout_millis
        ) = 0;

};

#endif /* __INCLUDE_STANDARDINTERFACES_UART */
