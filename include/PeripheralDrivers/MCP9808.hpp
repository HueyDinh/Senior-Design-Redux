#ifndef __INCLUDE_PERIPHERALDRIVERS_MCP9808
#define __INCLUDE_PERIPHERALDRIVERS_MCP9808

#include <cstdint>

class MCP9808Address {

    public:
        MCP9808Address(std::uint8_t solder_bridge_configuration);

    private:
        static constexpr std::uint8_t BASE_ADDRESS {0b0011};

        std::uint8_t const constant_bits : 4;
        std::uint8_t solder_bridge_configuration : 3;
};

#endif /* __INCLUDE_PERIPHERALDRIVERS_MCP9808 */
