
#include "variables.hpp"
#include <string>

namespace DBus {
  inline std::string signature(struct sBlock){ return sBlock::DBUS_SIGNATURE; }
  inline std::string signature(struct sResult ){ return sResult ::DBUS_SIGNATURE;    }
}

#include <dbus-cxx.h>

inline std::string type_string( const struct sBlock&  ) { return "Struct"; }
inline DBus::Type type(const struct sBlock&) { return DBus::TYPE_STRUCT; }

DBus::MessageIterator& operator>>(DBus::MessageIterator& i, struct sBlock& t);
DBus::MessageAppendIterator& operator<<(DBus::MessageAppendIterator& i, const struct sBlock& t);

DBus::MessageIterator& operator>>(DBus::MessageIterator& i, struct sResult& t);
DBus::MessageAppendIterator& operator<<(DBus::MessageAppendIterator& i, const struct sResult& t);
