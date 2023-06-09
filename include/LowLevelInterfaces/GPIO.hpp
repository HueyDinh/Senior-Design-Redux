#ifndef __INCLUDE_STANDARDINTERFACES_GPIO
#define __INCLUDE_STANDARDINTERFACES_GPIO

enum GPIO_ErrorCode {
    SUCCESS,
    CONFIGURATION_FAILURE,
    UNKNOWN_FAILURE,
};

class GPIO {

    public:
        
        virtual void set_high() = 0;
        virtual void set_low() = 0;
        virtual void toggle() = 0;

};

#endif /* __INCLUDE_STANDARDINTERFACES_GPIO */
