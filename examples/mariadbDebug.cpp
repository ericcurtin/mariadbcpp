#include "../src/mariadb.hpp"

#include <iostream>
#include <stdlib.h>

using std::cout;

mariadbcpp mariadbcpp(true);

void showError() {
  cout << "Error("
       << mariadbcpp.getErrno()
       << ") ["
       << mariadbcpp.getSQLState()
       << "] \""
       << mariadbcpp.getError()
       << "\"";
  exit(-1);
}

int main() {
  if (!mariadbcpp.connect("localhost", "example", "example_pw", "example_db")) {
    showError();
  }

  if (mariadbcpp.query("DROP TABLE IF EXISTS debug_example")) {
    showError();
  }

  if (mariadbcpp.query("CREATE TABLE debug_example (id int not null,"
                       "my_name varchar(50),"
                       "PRIMARY KEY(id))")) {
    showError();
  }

  return 0;
}

