#ifndef MARIADBCPP_RESCPP_HPP_
#define MARIADBCPP_RESCPP_HPP_

#include <mariadb/mysql.h>

#include <string>
#include <map>

class mariadbcpp;

class rescpp {
 public:
  rescpp(const mariadbcpp& mariadbcpp);
  ~rescpp();

  bool next();
  std::string get_string(const std::string& key);

 private:
  MYSQL_RES* res_;
  MYSQL_ROW row_;
  unsigned int num_fields_;
  std::map<std::string, unsigned int> fields_;
};

#endif
