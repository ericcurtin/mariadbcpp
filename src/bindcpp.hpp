#ifndef MARIADBCPP_BINDCPP_HPP_
#define MARIADBCPP_BINDCPP_HPP_

#include <mariadb/mysql.h>

#include <string>
#include <vector>

class bindcpp {
 public:
  bindcpp();
  ~bindcpp();

  void push_back(const std::string& bind_val);
  void push_back(const int bind_val);

  std::vector<MYSQL_BIND> bind_;
};

#endif
