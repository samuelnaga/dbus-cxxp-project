#pragma once

#include <vector>
#include <stdint.h>

static constexpr const char* BLOCK_SIGNATURE = "(yay)";

struct sBlock{

    uint8_t block;
    std::vector<uint8_t> data;
};

static constexpr const char* RESULT_SIGNATURE = "(ya(yay))";

struct sResult {
    uint8_t res;
    std::vector<sBlock> blocks;
};

static constexpr const char* BLOCK_ARRAY_SIGNATURE = "a(yay)";
