#ifndef ALGORITHMTOOLS_H
#define ALGORITHMTOOLS_H

#include <algorithm>
#include <iterator>
#include <string>
#include <utility>
#include <vector>

class AlgorithmTools {

  private:
        
    using pair_of_int = std::pair<int, int>;

    auto split_time(const std::string &schedule_hours) -> pair_of_int;

    auto compare_times(
      const std::string &schedule_hours1, 
      const std::string &schedule_hours2
    ) -> bool;
    
    auto partition(
      std::vector<std::string> &list_of_schedule_hours,
      std::vector<uint32_t>    &list_of_number_of_customer,
      std::vector<std::string> &list_of_store_name,
      std::vector<long double> &list_of_reserved_seat_fee,
      std::vector<std::string> &list_of_reserved_seat_contact,
      int                      low,
      int                      high
    ) -> int;

    auto quick_sort(
      std::vector<std::string> &list_of_schedule_hours,
      std::vector<uint32_t>    &list_of_number_of_customer,
      std::vector<std::string> &list_of_store_name,
      std::vector<long double> &list_of_reserved_seat_fee,
      std::vector<std::string> &list_of_reserved_seat_contact,
      int                      low,
      int                      high
    ) -> void;

    auto linear_search(
      const std::vector<std::string> &list_of_data, 
      const std::string              &data_to_search
    ) const -> int;

  public:

    auto sort_user_reserved_seat_data_am_pm_order(
      std::vector<std::string> &list_of_schedule_hours,
      std::vector<uint32_t>    &list_of_number_of_customer,
      std::vector<std::string> &list_of_store_name,
      std::vector<long double> &list_of_reserved_seat_fee,
      std::vector<std::string> &list_of_reserved_seat_contact
    ) -> void;

    auto search_reserved_seat_contact(
      const std::vector<std::string> &list_of_reserved_seat_contact, 
      const std::string              &reserved_seat_contact_to_search
    ) const -> int;

};

#endif // ALGORITHMTOOLS_H