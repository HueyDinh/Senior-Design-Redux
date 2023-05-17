#ifndef __INCLUDE_MASTERCONTROL_SYSTEMPARAMETERS
#define __INCLUDE_MASTERCONTROL_SYSTEMPARAMETERS

#include <cstdint>

static constexpr std::size_t NUM_SEAT_SENSOR {4};
static constexpr std::size_t NUM_AMBIENT_SENSOR {1};
static constexpr std::size_t NUM_FANS {2};
static constexpr std::size_t NUM_FLOW_TEMP_SENSOR{1};
static constexpr std::size_t NUM_FLOW_MOIST_SENSOR{1};


static constexpr std::size_t INPUT_DIMENSION {NUM_SEAT_SENSOR + NUM_AMBIENT_SENSOR};
static constexpr std::size_t OUTPUT_DIMENSION {NUM_FANS};

enum MCP9808_SENSOR_SOLDER_BRIDGE_CONFIG : std::uint8_t {
    SENSOR_TOP_LEFT = 0b000,
    SENSOR_TOP_RIGHT = 0b001,
    SENSOR_BOTTOM_LEFT = 0b010,
    SENSOR_BOTTOM_RIGHT = 0b011,
    SENSOR_AMBIENT = 0b111,
};

static constexpr int CONTROL_LOOP_UPDATE_PERIOD_MILISECONDS {5000};







#endif /* __INCLUDE_MASTERCONTROL_SYSTEMPARAMETERS */
