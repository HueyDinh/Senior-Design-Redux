#ifndef __INCLUDE_HALWRAPPERS_HAL_TIMERWRAPPER
#define __INCLUDE_HALWRAPPERS_HAL_TIMERWRAPPER

#include <cstdint>

#include "main.h"

#include <LowLevelInterfaces/GlobalTimer.hpp>

class HAL_TimerWrapper : public GlobalTimer {

    public:

        HAL_TimerWrapper(RTC_HandleTypeDef* raw_RCC_handle);

        virtual void sleep_millis(std::uint32_t const time) override;
        virtual std::uint32_t get_time_since_boot_millis() override;

        virtual GlobalTimer_ErrorCode set_date(Date const & date) override;
        virtual GlobalTimer_ErrorCode get_date(Date & date) override;

        virtual GlobalTimer_ErrorCode set_time(Time const & date) override;
        virtual GlobalTimer_ErrorCode get_time(Time & date) override;
    
    private:
        RTC_HandleTypeDef* const raw_RCC_handle;

};

#endif /* __INCLUDE_HALWRAPPERS_HAL_TIMERWRAPPER */
