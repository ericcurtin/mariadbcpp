#include "mariadb.hpp"

using std::string;

mariadbcpp::mariadbcpp(const bool) {
  mysql_debug("d:t:O");
  mariadbcpp();
}

mariadbcpp::mariadbcpp() : mysql(mysql_init(0)) {}

mariadbcpp::~mariadbcpp() {
  mysql_close(mysql);
}

bool mariadbcpp::connect(const char* host,
                         const char* user,
                         const char* pass,
                         const char* db) {
  return mysql_real_connect(mysql, host, user, pass, db, 0, "/tmp/mysql.sock",
                            0);
}

int mariadbcpp::realQuery(const string& query) {
  return mysql_real_query(mysql, query.c_str(), query.size());
}

unsigned int mariadbcpp::getErrno() {
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
