#include "mariadb.hpp"

#include <string.h>

using std::string;

mariadbcpp::mariadbcpp(const bool setDebug) {
  if (setDebug) {
    mysql_debug("d:t:O");
  }
  mysql = mysql_init(0);
}

mariadbcpp::~mariadbcpp() {
  mysql_close(mysql);
}

bool mariadbcpp::connect(const char* host,
                         const char* user,
                         const char* pass,
                         const char* db) {
  return mysql_real_connect(mysql,
                            host,
                            user,
                            pass,
                            db,
                            0,
                            "/tmp/mysql.sock",
                            0);
}

int mariadbcpp::query(const char* query) {
  return mysql_real_query(mysql, query, strlen(query));
}

int mariadbcpp::getErrno() {
  return mysql_errno(mysql);
}

string mariadbcpp::getSQLState() {
  return mysql_sqlstate(mysql);
}

string mariadbcpp::getError() {
  return mysql_error(mysql);
}

unsigned long mariadbcpp::getAffectedRows() {
  return mysql_affected_rows(mysql);
}
