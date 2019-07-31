#include "functions.hpp"
#include <unistd.h> // sleep

int main()
{
    int ret;
    DBus::init();
    DBus::Dispatcher::pointer dispatcher = DBus::Dispatcher::create();
    DBus::Connection::pointer conn = dispatcher->create_connection(DBus::BUS_SESSION);
    ret = conn->request_name( "dev.example.example1", DBUS_NAME_FLAG_REPLACE_EXISTING );
    if (DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER != ret) return 1;

    DBus::Object::pointer object = conn->create_object("/home/dev/Example");
    object->create_method<uint8_t>("dev.example.example1", "state", sigc::ptr_fun(state) );
    object->create_method<void>("dev.example.example1", "start", sigc::ptr_fun(start) );
    object->create_method<void>("dev.example.example1", "stop", sigc::ptr_fun(stop) );

    object->create_method<sResult, std::vector<uint8_t> >("dev.example.example2", "read", sigc::ptr_fun(doRead) );
    object->create_method<std::vector<uint8_t>, std::vector<sBlock> >("dev.example.example2", "write", sigc::ptr_fun(doWrite));

    sleep(10);

    return 0;
}
