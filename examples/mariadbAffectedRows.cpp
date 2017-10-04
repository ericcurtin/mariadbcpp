#include "../src/mariadb.hpp"

#include <iostream>
#include <stdlib.h>

using std::cout;

mariadbcpp mariadbcpp;

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

  if (mariadbcpp.query("DROP TABLE IF EXISTS affected_rows")) {
    showError();
  }

  if (mariadbcpp.query("CREATE TABLE affected_rows (id int not null, my_name varchar(50),"
                       "PRIMARY KEY(id))")) {
    showError();
  }

  if (mariadbcpp.query("INSERT INTO affected_rows VALUES (1, \"First value\"),"
                       "(2, \"Second value\")")) {
    showError();
  }

  if (mariadbcpp.query("INSERT INTO affected_rows VALUES (1, \"First value\"),"
                       "(2, \"Second value\")")) {
    showError();
  }
  cout << "Affected_rows after INSERT: "
       << mariadbcpp.getAffectedRows()
       << "\n";

  if (mariadbcpp.query("REPLACE INTO affected_rows VALUES (1, \"First value\"),"
                       "(2, \"Second value\")")) {
    showError();
  }
  cout << "Affected_rows after REPLACE: "
       << mariadbcpp.getAffectedRows()
       << "\n";

  if (mariadbcpp.query("UPDATE affected_rows SET id=1 WHERE id=1")) {
    showError();
  }
  cout << "Affected_rows after UPDATE: "
       << mariadbcpp.getAffectedRows()
       << "\n";

  if (mariadbcpp.query("UPDATE affected_rows SET my_name=\"Monty\" WHERE id=1")) {
    showError();
  }
  cout << "Affected_rows after UPDATE: "
       << mariadbcpp.getAffectedRows()
       << "\n";

  if (mariadbcpp.query("SELECT id, my_name FROM affected_rows")) {
    showError();
  }
  cout << "Affected_rows after SELECT and storing result set: "
       << mariadbcpp.getAffectedRows()
       << "\n";

  if (mariadbcpp.query("DELETE FROM affected_rows")) {
    showError();
  }
  cout << "Affected_rows after DELETE: "
       << mariadbcpp.getAffectedRows()
       << "\n";

  return 0;
}

