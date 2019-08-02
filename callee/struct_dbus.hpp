
#include "variables.hpp"
#include <string>
#include <dbus-cxx/types.h>

namespace DBus {
  inline std::string signature(struct sBlock){ return sBlock::BLOCK_SIGNATURE; }
  inline std::string signature(struct sResult ){ return sResult::RESULT_SIGNATURE; }
  inline std::string signature(std::vector<sBlock>) { return BLOCK_ARRAY_SIGNATURE; }

  inline std::string type_string(const struct sBlock&) { return "Struct"; }
  inline std::string type_string(const struct sResult&)    { return "Struct"; }

  inline DBus::Type type(const struct sBlock&) { return DBus::TYPE_STRUCT; }
  inline DBus::Type type(const struct sResult&)    { return DBus::TYPE_STRUCT; }
}

#include <dbus-cxx.h>

DBus::MessageIterator& operator>>(DBus::MessageIterator& i, struct sBlock& t);
DBus::MessageAppendIterator& operator<<(DBus::MessageAppendIterator& i, const struct sBlock& t);

DBus::MessageIterator& operator>>(DBus::MessageIterator& i, struct sResult& t);
DBus::MessageAppendIterator& operator<<(DBus::MessageAppendIterator& i, const struct sResult& t);
