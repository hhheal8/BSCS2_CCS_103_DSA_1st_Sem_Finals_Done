#ifndef FILEHTML_H
#define FILEHTML_H

#include "FileCSS.hpp"

#include <fstream>
#include <string>
#include <utility>
#include <vector>

class FileHTML : public FileCSS {

  private:

    template<typename ...DATA>
    auto write_in_file(
      std::fstream     &user_file_data,
      DATA             &&...data
    ) const -> void;

    auto create_html_file(
      const std::string              &user_file_name,
      std::fstream                   &user_file_data,
      const std::vector<std::string> &list_of_schedule_hours,
      const std::vector<uint32_t>    &list_of_number_of_customer,
      const std::vector<std::string> &list_of_store_name,
      const std::vector<long double> &list_of_reserved_seat_fee,
      const std::vector<std::string> &list_of_reserved_seat_contact
    ) const -> void;

  public:

    FileHTML() = default;

    auto create_html_file_data(
      const std::string              &user_file_name,
      std::fstream                   &user_file_data,
      const std::vector<std::string> &list_of_schedule_hours,
      const std::vector<uint32_t>    &list_of_number_of_customer,
      const std::vector<std::string> &list_of_store_name,
      const std::vector<long double> &list_of_reserved_seat_fee,
      const std::vector<std::string> &list_of_reserved_seat_contact
    ) const -> void;

    ~FileHTML() {};

};

#endif // FILEHTML_H