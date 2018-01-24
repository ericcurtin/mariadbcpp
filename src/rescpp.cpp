#include "rescpp.hpp"

#include "mariadbcpp.hpp"

using std::string;

rescpp::rescpp(const mariadbcpp& mariadbcpp)
    : res_(mysql_store_result(mariadbcpp.mysql)) {
  num_fields_ = mysql_num_fields(res_);
  MYSQL_FIELD* field;
  for (unsigned int i = 0; (field = mysql_fetch_field(res_)); ++i) {
    fields_[field->name] = i;
  }
}

rescpp::~rescpp() {
  mysql_free_result(res_);
}

bool rescpp::next() {
  row_ = mysql_fetch_row(res_);
  return row_;
}

string rescpp::get_string(const string& val) {
  const unsigned int i = fields_[val];
  return row_[i];
}
