#ifndef __INCLUDE_SUBSYSTEMDRIVERS_INTERVENTION_HIBERNATIONSUBSYSTEM
#define __INCLUDE_SUBSYSTEMDRIVERS_INTERVENTION_HIBERNATIONSUBSYSTEM

class HighAmbientTempHandler {

    public:

        virtual void high_ambient_temp_callback() = 0;    

};

class HotSeatHandler {

    public:

        virtual void hot_seat_callback() = 0;

};

#endif /* __INCLUDE_SUBSYSTEMDRIVERS_INTERVENTION_HIBERNATIONSUBSYSTEM */
