#include <mariadb/mysql.h>

class mariadbcpp {
  public:
    mariadbcpp();
    ~mariadbcpp();
  private:
    static MYSQL* mysql;
};
