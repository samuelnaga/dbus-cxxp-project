#pragma once

#include <vector>
#include <stdint.h>


struct sBlock{
    static constexpr const char* BLOCK_SIGNATURE = "(yay)";
    uint8_t block;
    std::vector<uint8_t> data;
};


struct sResult {
    static constexpr const char* RESULT_SIGNATURE = "(ya(yay))";
    uint8_t res;
    std::vector<sBlock> blocks;
};

static constexpr const char* BLOCK_ARRAY_SIGNATURE = "(a(yay))";
