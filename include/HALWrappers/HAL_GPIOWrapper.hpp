#ifndef __INCLUDE_HALWRAPPERS_HAL_GPIOWRAPPER
#define __INCLUDE_HALWRAPPERS_HAL_GPIOWRAPPER

#include <cstdint>

#include "main.h"

#include "LowLevelInterfaces/GPIO.hpp"

class HAL_GPIO_Wrapper : public GPIO {

    public:

        HAL_GPIO_Wrapper(GPIO_TypeDef* bank, std::uint16_t pin);

        virtual void set_high() override;
        virtual void set_low() override;
        virtual void toggle() override;
    
    private:

        GPIO_TypeDef* const bank;
        std::uint16_t const pin;
        bool virtual_state;

};

#endif /* __INCLUDE_HALWRAPPERS_HAL_GPIOWRAPPER */
