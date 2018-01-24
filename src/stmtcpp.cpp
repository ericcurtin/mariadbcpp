#include "stmtcpp.hpp"

#include <limits.h>

using std::string;

stmtcpp::stmtcpp(const mariadbcpp& mariadbcpp) : mariadbcpp_(mariadbcpp) {}

stmtcpp::~stmtcpp() {
  mysql_stmt_close(stmt_);
}

int stmtcpp::prepare(const string& query) {
  bindcpp_.bind_.clear();
  return mysql_stmt_prepare(stmt_, query.c_str(), ULONG_MAX);
}

int stmtcpp::execute() {
  return mysql_stmt_execute(stmt_);
}
