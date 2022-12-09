#include "AlgorithmTools.hpp"

#include <algorithm>
#include <iterator>
#include <string>
#include <utility>
#include <vector> 

auto AlgorithmTools::split_time(const std::string &schedule_hours) -> pair_of_int {

  size_t colon_position{schedule_hours.find(':')};

  if(colon_position == std::string::npos) {
    return {0, 0};
  }

  std::string hours{schedule_hours.substr(0, colon_position)};
  std::string minutes{schedule_hours.substr(colon_position + 1)};

  return {std::stoi(hours), std::stoi(minutes)};

}

auto AlgorithmTools::compare_times(
  const std::string &schedule_hours1, 
  const std::string &schedule_hours2
) -> bool {

  auto [hours1, minutes1]{split_time(schedule_hours1)}; // Structured Binding available in C++17
  auto [hours2, minutes2]{split_time(schedule_hours2)}; // Structured Binding available in C++17

  if(hours1 != hours2) {
    return hours1 < hours2;
  }

  return minutes1 < minutes2;

}

auto AlgorithmTools::partition(
  std::vector<std::string> &list_of_schedule_hours,
  std::vector<uint32_t>    &list_of_number_of_customer,
  std::vector<std::string> &list_of_store_name,
  std::vector<long double> &list_of_reserved_seat_fee,
  std::vector<std::string> &list_of_reserved_seat_contact,
  int                      low,
  int                      high
) -> int {

  // Choose the first element as the pivot value
  std::string pivot{list_of_schedule_hours.at(low)};

  // Keep track of the pivot value's index
  int pivot_index{low};

  for(int i{low + 1}; i <= high; ++i) {
    
    if(compare_times(list_of_schedule_hours.at(i), pivot)) {
      ++pivot_index;
      std::swap(list_of_schedule_hours.at(i), list_of_schedule_hours.at(pivot_index));
      std::swap(list_of_number_of_customer.at(i), list_of_number_of_customer.at(pivot_index));
      std::swap(list_of_store_name.at(i), list_of_store_name.at(pivot_index));
      std::swap(list_of_reserved_seat_fee.at(i), list_of_reserved_seat_fee.at(pivot_index));
      std::swap(list_of_reserved_seat_contact.at(i), list_of_reserved_seat_contact.at(pivot_index));
    }
  }

  std::swap(list_of_schedule_hours.at(low), list_of_schedule_hours.at(pivot_index));
  std::swap(list_of_number_of_customer.at(low), list_of_number_of_customer.at(pivot_index));
  std::swap(list_of_store_name.at(low), list_of_store_name.at(pivot_index));
  std::swap(list_of_reserved_seat_fee.at(low), list_of_reserved_seat_fee.at(pivot_index));
  std::swap(list_of_reserved_seat_contact.at(low), list_of_reserved_seat_contact.at(pivot_index));

  return pivot_index;
  
}

auto AlgorithmTools::quick_sort(
  std::vector<std::string> &list_of_schedule_hours,
  std::vector<uint32_t>    &list_of_number_of_customer,
  std::vector<std::string> &list_of_store_name,
  std::vector<long double> &list_of_reserved_seat_fee,
  std::vector<std::string> &list_of_reserved_seat_contact,
  int                      low,
  int                      high
) -> void {

  if(low < high) {

    int pivot_index{
      partition(
        list_of_schedule_hours,
        list_of_number_of_customer,
        list_of_store_name,
        list_of_reserved_seat_fee,
        list_of_reserved_seat_contact,
        low,
        high
      )
    };

    quick_sort(
      list_of_schedule_hours,
      list_of_number_of_customer,
      list_of_store_name,
      list_of_reserved_seat_fee,
      list_of_reserved_seat_contact,
      low,
      (pivot_index - 1)
    );

    quick_sort(
      list_of_schedule_hours,
      list_of_number_of_customer,
      list_of_store_name,
      list_of_reserved_seat_fee,
      list_of_reserved_seat_contact,
      (pivot_index + 1),
      high
    );

  }

}

auto AlgorithmTools::linear_search(
  const std::vector<std::string> &list_of_data, 
  const std::string              &data_to_search
) const -> int {

  for(int i{}; i != list_of_data.size(); ++i) {
    if(list_of_data.at(i) == data_to_search) {
      return i;
    }
  }

  return -1;

}

auto AlgorithmTools::sort_user_reserved_seat_data_am_pm_order(
  std::vector<std::string> &list_of_schedule_hours,
  std::vector<uint32_t>    &list_of_number_of_customer,
  std::vector<std::string> &list_of_store_name,
  std::vector<long double> &list_of_reserved_seat_fee,
  std::vector<std::string> &list_of_reserved_seat_contact
) -> void {
  quick_sort(
    list_of_schedule_hours,
    list_of_number_of_customer,
    list_of_store_name,
    list_of_reserved_seat_fee,
    list_of_reserved_seat_contact,
    0,
    (list_of_schedule_hours.size() - 1)
  );
}

auto AlgorithmTools::search_reserved_seat_contact(
  const std::vector<std::string> &list_of_reserved_seat_contact, 
  const std::string              &reserved_seat_contact_to_search
) const -> int {
  return linear_search(
    list_of_reserved_seat_contact, 
    reserved_seat_contact_to_search
  );
}
