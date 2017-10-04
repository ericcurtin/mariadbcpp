#include <mariadb/mysql.h>
#include <string>

class mariadbcpp {
  public:
    mariadbcpp(const bool);
    mariadbcpp();
    ~mariadbcpp();
    bool connect(const char* host,
                 const char* user,
                 const char* pass,
                 const char* db);
    int realQuery(const char* query);
    unsigned int getErrno();
    std::string getSQLState();
    std::string getError();
    unsigned long getAffectedRows();
  private:
    MYSQL* mysql;
};
