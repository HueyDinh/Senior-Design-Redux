#ifndef __INCLUDE_STANDARDINTERFACES_TIMER
#define __INCLUDE_STANDARDINTERFACES_TIMER

#include <cstdint>

enum GlobalTimer_ErrorCode {
    SUCCESS,
    CONFIGURATION_FAILURE,
    UNKNOWN_FAILURE,
};

struct Date {
    std::uint8_t day;
    std::uint8_t month;
    std::uint16_t year;
};

struct Time {
    std::uint8_t hour;
    std::uint8_t minute;
    std::uint8_t second;
};

class GlobalTimer {

    public:

        virtual void sleep_millis(std::uint32_t const time) = 0;
        virtual std::uint32_t get_time_since_boot_millis() = 0;

        virtual GlobalTimer_ErrorCode set_date(Date const & date) = 0;
        virtual GlobalTimer_ErrorCode get_date(Date & date) = 0;

        virtual GlobalTimer_ErrorCode set_time(Time const & date) = 0;
        virtual GlobalTimer_ErrorCode get_time(Time & date) = 0;

};

#endif /* __INCLUDE_STANDARDINTERFACES_TIMER */
