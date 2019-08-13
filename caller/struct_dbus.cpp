#include "struct_dbus.hpp"


DBus::MessageIterator& operator>>(DBus::MessageIterator& i, struct sBlock& t)
{
    DBus::MessageIterator subiter = i.recurse();
    subiter >> t.block;
    subiter >> t.data;

    return i;
}


DBus::MessageAppendIterator& operator<<(DBus::MessageAppendIterator& i, const struct sBlock& t)
{
    i.open_container(DBus::CONTAINER_STRUCT, std::string());
    i.sub_iterator()->append(t.block);
    i.sub_iterator()->append(t.data);
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

DBus::MessageIterator& operator>>(DBus::MessageIterator& i, std::vector<sBlock>& t)
{
    t = i.get_array_complex<sBlock>();
    return i;
}


DBus::MessageAppendIterator& operator<<(DBus::MessageAppendIterator& i, const std::vector<sBlock>& t)
{
    i.open_container(DBus::CONTAINER_ARRAY, BLOCK_SIGNATURE);

    for (sBlock blk : t)
    {
        i.sub_iterator()->open_container(DBus::CONTAINER_STRUCT, std::string());
        i.sub_iterator()->sub_iterator()->append(blk.block);
        i.sub_iterator()->sub_iterator()->append(blk.data);
        i.sub_iterator()->close_container();
    }
    
    i.close_container();
    
    return i;
}

