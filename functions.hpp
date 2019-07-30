#pragma once

#include "struct_dbus.hpp"


uint8_t state()
{
    return 0;
}



void start()
{
    std::cout << "started \n";
}




void stop()
{
    std::cout << "stoped \n";
}



sResult doRead(std::vector<uint8_t> blockN)
{
    (void)blockN;
    sResult a;
    a.res = 0;
    return a;
}



std::vector<uint8_t> write(std::vector<sBlock> blocks)
{
    std::vector<uint8_t> response(blocks.size(), 0);
    return response;
}







