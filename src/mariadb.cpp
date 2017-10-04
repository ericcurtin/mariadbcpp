#include "mariadb.hpp"

mariadbcpp::mariadbcpp() {
  mysql = mysql_init(0);
}

mariadbcpp::~mariadbcpp() {
  mysql_close(mysql);
}
