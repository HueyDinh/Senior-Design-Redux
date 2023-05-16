#ifndef __INCLUDE_STANDARDINTERFACES_PWM
#define __INCLUDE_STANDARDINTERFACES_PWM

#include <cstdint>
#include <array>

enum PWM_ErrorCode {
    SUCCESS,
    CONFIGURATION_FAILURE,
    UNKNOWN_FAILURE,
};

class PWM {

    public:

        virtual PWM_ErrorCode initialize() = 0;
        virtual PWM_ErrorCode set_frequency_kHz(std::int16_t const target_frequency) = 0;
        virtual PWM_ErrorCode set_duty_cycle(float const fraction, std::uint8_t const channel_index) = 0;

};

class PWMChannel {

    public:

        virtual PWM_ErrorCode set_duty_cycle(float fraction) = 0;

};

#endif /* __INCLUDE_STANDARDINTERFACES_PWM */
