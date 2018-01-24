#include "bindcpp.hpp"

#include <sstream>

template <typename T>
std::string to_string(T Number) {
  std::ostringstream ss;
  ss << Number;
  return ss.str();
}

bindcpp::bindcpp() {}

bindcpp::~bindcpp() {}

void bindcpp::push_back(const std::string& bind_val) {
  MYSQL_BIND this_bind;
  this_bind.buffer = const_cast<char*>(bind_val.c_str());
  this_bind.buffer_type = MYSQL_TYPE_STRING;
  bind_.push_back(this_bind);
}

void bindcpp::push_back(const int bind_val) {
  MYSQL_BIND this_bind;
  this_bind.buffer = const_cast<char*>(to_string(bind_val).c_str());
  this_bind.buffer_type = MYSQL_TYPE_LONG;
  bind_.push_back(this_bind);
}
