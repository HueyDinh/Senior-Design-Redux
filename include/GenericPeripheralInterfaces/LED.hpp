#ifndef __INCLUDE_GENERICPERIPHERALINTERFACES_LED
#define __INCLUDE_GENERICPERIPHERALINTERFACES_LED

class LED {

    public:

        virtual void turn_on() = 0;
        virtual void turn_off() = 0;
        virtual void toggle() = 0;
        virtual bool get_virtual_state() = 0;

};

#endif /* __INCLUDE_GENERICPERIPHERALINTERFACES_LED */
