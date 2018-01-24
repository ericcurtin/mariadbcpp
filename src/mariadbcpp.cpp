#include "mariadbcpp.hpp"

using std::string;

mariadbcpp::mariadbcpp(const bool) {
  mysql_debug("d:t:O");
  mariadbcpp();
}

mariadbcpp::mariadbcpp() : mysql(mysql_init(0)) {}

mariadbcpp::~mariadbcpp() {
  mysql_close(mysql);
}

// true == good, false == error
bool mariadbcpp::connect(const string& host,
                         const string& user,
                         const string& pass,
                         const string& db) {
  return mysql_real_connect(mysql, host.c_str(), user.c_str(), pass.c_str(),
                            db.c_str(), 0, "/tmp/mysql.sock", 0);
}

void mariadbcpp::disconnect() {
  return mysql_close(mysql);
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

bool mariadbcpp::set_auto_commit(const bool auto_mode) {
  return mysql_autocommit(mysql, auto_mode);
}

/*
int mariadbcpp::stmt_prepare(const string& query) {
  stmt = mysql_stmt_init(mysql);
  binds.clear();
  return mysql_stmt_prepare(stmt, query.c_str(), query.size());
}

void mariadbcpp::stmt_set(const string& query) {
  MYSQL_BIND bind;
  bind.buffer = const_cast<void*>(static_cast<const void*>(query.c_str()));
  bind.buffer_type = MYSQL_TYPE_STRING;
  binds.push_back(bind);
}

int mariadbcpp::stmt_execute() {
  const unsigned long array_size = binds.size();
  mysql_stmt_attr_set(stmt, STMT_ATTR_ARRAY_SIZE, &array_size);
  mysql_stmt_bind_param(stmt, &binds[0]);
  return mysql_stmt_execute(stmt);
}

void mariadbcpp::store_result() {
  res = mysql_store_result(mysql);
}
*/
