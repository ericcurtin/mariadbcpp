#ifndef MARIADBCPP_STMTCPP_HPP_
#define MARIADBCPP_STMTCPP_HPP_

#include <mariadb/mysql.h>

#include "mariadbcpp.hpp"
#include "bindcpp.hpp"

class stmtcpp {
 public:
  stmtcpp(const mariadbcpp& mariadbcpp);
  ~stmtcpp();

  int prepare(const std::string& query);
  int execute();

  template <typename T>
  void push_back(T bind_val) {
    bindcpp_.push_back(bind_val);
  }

 private:
  const mariadbcpp& mariadbcpp_;
  bindcpp bindcpp_;
  MYSQL_STMT* stmt_;
};

#endif
