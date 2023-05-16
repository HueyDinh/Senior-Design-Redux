#ifndef __INCLUDE_GENERICPERIPHERALINTERFACES_FOURWIREFAN
#define __INCLUDE_GENERICPERIPHERALINTERFACES_FOURWIREFAN

#include <cstdint>

enum FourWireFan_ErrorCode {
    SUCCESS,
    TACHYON_MISMATCH,
    UNKNOWN_FAILURE,
};

class FourWireFan {

    public:

        virtual FourWireFan_ErrorCode set_speed(float percent_max_speed) = 0;
        virtual float get_virtual_speed() = 0;

        virtual FourWireFan_ErrorCode verify_speed() = 0;

};

#endif /* __INCLUDE_GENERICPERIPHERALINTERFACES_FOURWIREFAN */
