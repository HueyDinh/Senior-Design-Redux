#ifndef __INCLUDE_STANDARDINTERFACES_PWM
#define __INCLUDE_STANDARDINTERFACES_PWM

#include <cstdint>
#include <array>

#include "ErrorHandling/ErrorCodeAndMessage.hpp"

class PWM {

    public:

        virtual PWM_ErrorCode initialize() = 0;
        virtual PWM_ErrorCode set_frequency_kHz(std::int16_t target_frequency) = 0;
        virtual PWM_ErrorCode set_duty_cycle(float fraction, std::uint8_t channel_number) = 0;

};

#endif /* __INCLUDE_STANDARDINTERFACES_PWM */
