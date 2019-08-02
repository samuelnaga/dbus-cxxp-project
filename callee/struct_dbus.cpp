#include "struct_dbus.hpp"


DBus::MessageIterator& operator>>(DBus::MessageIterator& i, struct sBlock& t)
{
    DBus::MessageIterator subiter = i.recurse();
    subiter >> t.data;
    subiter >> t.block;
    return i;
}


DBus::MessageAppendIterator& operator<<(DBus::MessageAppendIterator& i, const struct sBlock& t)
{
    i.open_container(DBus::CONTAINER_STRUCT, std::string());
    i.sub_iterator()->append(t.data);
    i.sub_iterator()->append(t.block);
    i.close_container();
    return i;
}


DBus::MessageIterator& operator>>(DBus::MessageIterator& i, struct sResult& t)
{
    DBus::MessageIterator subiter = i.recurse();
    subiter >> t.res;
    subiter >> t.blocks;
    return i;
}


DBus::MessageAppendIterator& operator<<(DBus::MessageAppendIterator& i, const struct sResult& t)
{
    i.open_container(DBus::CONTAINER_STRUCT, std::string());
    i.sub_iterator()->append(t.res);
    i.sub_iterator()->append(t.blocks);
    i.close_container();
    return i;
}



