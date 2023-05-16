#ifndef __INCLUDE_PERIPHERALDRIVERS_DELTAPFB0412EN_E
#define __INCLUDE_PERIPHERALDRIVERS_DELTAPFB0412EN_E

#include "LowLevelInterfaces/PWM.hpp"
#include "GenericPeripheralInterfaces/FourWireFan.hpp"

class DeltaPFB0412EN_E : public FourWireFan {

    public:

        DeltaPFB0412EN_E(PWMChannel& channel);

        virtual FourWireFan_ErrorCode set_speed(float percent_max_speed) override;
        virtual float get_virtual_speed() override;

        virtual FourWireFan_ErrorCode verify_speed() override;

    private:

        float virtual_speed;

};

#endif /* __INCLUDE_PERIPHERALDRIVERS_DELTAPFB0412EN_E */
