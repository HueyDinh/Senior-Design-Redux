#ifndef __INCLUDE_HALWRAPPERS_HAL_PWMWRAPPER
#define __INCLUDE_HALWRAPPERS_HAL_PWMWRAPPER

#include <cstdint>
#include <array>

#include "main.h"

#include "LowLevelInterfaces/PWM.hpp"

class HAL_ChannelWrapper : PWMChannel {

    public:

        HAL_ChannelWrapper();

        virtual PWM_ErrorCode set_duty_cycle(float fraction) override;
    
    private:
        TIM_OC_InitTypeDef raw_channel_struct;

        PWM_ErrorCode write_config();

};

template <std::uint8_t channel_number>
class HAL_PWMWrapper : public PWM {

    public:

        HAL_PWMWrapper(TIM_HandleTypeDef* raw_TIM_handle);

        virtual PWM_ErrorCode initialize() override;
        virtual PWM_ErrorCode set_frequency_kHz(std::int16_t const target_frequency) override;
        virtual PWM_ErrorCode set_duty_cycle(float const fraction, std::uint8_t const channel_index) override;      

    private:

        TIM_HandleTypeDef* const raw_TIM_handle;
        std::array<HAL_ChannelWrapper, channel_number> channels;

        PWM_ErrorCode write_config();

};

#endif /* __INCLUDE_HALWRAPPERS_HAL_PWMWRAPPER */
