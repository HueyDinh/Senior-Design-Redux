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

HAL_GPIO_Wrapper::HAL_GPIO_Wrapper(GPIO_TypeDef* bank, std::uint16_t pin):

    bank{bank},
    pin{pin}

{}

void HAL_GPIO_Wrapper::set_high() {
    HAL_GPIO_WritePin(bank, pin, GPIO_PIN_SET);
    virtual_state = static_cast<bool>(GPIO_PIN_SET);
}

void HAL_GPIO_Wrapper::set_low() {
    HAL_GPIO_WritePin(bank, pin, GPIO_PIN_RESET);
    virtual_state = static_cast<bool>(GPIO_PIN_RESET);
}

void HAL_GPIO_Wrapper::toggle() {
    HAL_GPIO_TogglePin(bank, pin);
    virtual_state != virtual_state;
}

#endif /* __INCLUDE_HALWRAPPERS_HAL_GPIOWRAPPER */
