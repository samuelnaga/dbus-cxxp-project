#include <unistd.h>
#include <iostream>
#include "struct_dbus.hpp"

int main()
{

      DBus::init();
    DBus::Dispatcher::pointer dispatcher = DBus::Dispatcher::create();
    DBus::Connection::pointer connection = dispatcher->create_connection( DBus::BUS_SESSION );

    DBus::ObjectProxy::pointer object = connection->create_object_proxy("dev.example.example1", "/home/dev/Example");

    DBus::MethodProxy<uint8_t>& status_proxy = *(object->create_method<uint8_t>("dev.example.example1","state"));
    uint8_t answer = status_proxy();
    std::cout << "Status " << static_cast<int>(answer) << std::endl;

    DBus::MethodProxy<void>& proxy1 = *(object->create_method<void>("dev.example.example1","stop"));
    proxy1();
    DBus::MethodProxy<void>& proxy2 = *(object->create_method<void>("dev.example.example1","start"));
    proxy2();

    DBus::MethodProxy<sResult, std::vector<uint8_t>  >& proxy3 = *(object->create_method<sResult, std::vector<uint8_t> >("dev.example.example2", "read"));
    DBus::MethodProxy<std::vector<uint8_t>, std::vector<sBlock> >& proxy4 = *(object->create_method<std::vector<uint8_t>, std::vector<sBlock> >("dev.example.example2", "write"));

    std::vector<uint8_t> aa(5, 5);
    sResult f = proxy3(aa);
    std::cout << "this should be 7 and is " << static_cast<int>(f.res) << std::endl;

    std::vector<sBlock> gg;
    gg.reserve(4);
    sBlock a;
    a.data = aa;
    a.block = 0x09;

    gg.push_back(a);
    gg.push_back(a);
    gg.push_back(a);
    gg.push_back(a);

    std::vector<uint8_t> bb = proxy4(gg);
    std::cout << "this should be 4 and is " << bb.size() << std::endl;

    for (uint j=0;j<bb.size();++j) {
        std::cout << static_cast<int>(bb[j]);
    }
    std::cout  << std::endl;

  return 0;
}
