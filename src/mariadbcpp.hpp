#ifndef MARIADBCPP_MARIADBCPP_HPP_
#define MARIADBCPP_MARIADBCPP_HPP_

#include <mariadb/mysql.h>
#include <string>
#include <vector>

class mariadbcpp {
 public:
  mariadbcpp(const bool);
  mariadbcpp();
  ~mariadbcpp();
  bool connect(const std::string& host,
               const std::string& user,
               const std::string& pass,
               const std::string& db);
  void disconnect();
  int realQuery(const std::string& query);
  unsigned int getErrno();
  std::string getSQLState();
  std::string getError();
  unsigned long getAffectedRows();
  int stmt_prepare(const std::string& query);
  void stmt_set(const std::string& query);
  int stmt_execute();
  void store_result();
  bool set_auto_commit(const bool auto_mode);

  MYSQL* mysql;

 private:
  MYSQL_STMT* stmt;
  MYSQL_RES* res;
  std::vector<MYSQL_BIND> binds;
};

#endif
