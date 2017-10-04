#include <mariadb/mysql.h>
#include <string>

class mariadbcpp {
  public:
    mariadbcpp();
    ~mariadbcpp();
    bool connect(const char* host,
                 const char* user,
                 const char* pass,
                 const char* db);
    int query(const char* query);
    std::string getSQLState();
    std::string getError();
  private:
    MYSQL* mysql;
};
