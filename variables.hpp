#pragma once

#include <vector>
#include <stdint.h>


struct sBlock{
    static constexpr const char* DBUS_SIGNATURE = "(ya)";
    uint8_t block;
    std::vector<uint8_t> data;
};


struct sResult {
    static constexpr const char* DBUS_SIGNATURE = "(yr)";
    uint8_t res;
    std::vector<sBlock> blocks;
};
