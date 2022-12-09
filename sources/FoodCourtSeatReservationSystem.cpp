#include "AlgorithmTools.hpp"
#include "ConsoleInterface.hpp"
#include "FileHTML.hpp"
#include "FoodCourtSeatReservationSystem.hpp"

#include <algorithm>
#include <fstream>
#include <iterator>
#include <string>
#include <utility>  //REVIEW - For std::move()
#include <vector>

//SECTION - Setter, Getter, and Read for data inputs

auto FoodCourtSeatReservationSystem::set_schedule_hours(std::string schedule_hours) -> void {
  m_schedule_hours = std::move(schedule_hours);
}
auto FoodCourtSeatReservationSystem::get_schedule_hours() -> std::string {
  return m_schedule_hours;
}
auto FoodCourtSeatReservationSystem::read_schedule_hours() const -> READ_STR {
  return m_schedule_hours;
}

auto FoodCourtSeatReservationSystem::set_number_of_customer(uint32_t &number_of_customer) -> void {
  m_number_of_customer = number_of_customer;
}
auto FoodCourtSeatReservationSystem::get_number_of_customer() -> uint32_t {
  return m_number_of_customer;
}
auto FoodCourtSeatReservationSystem::read_number_of_customer() const -> READ_UINT32 {
  return m_number_of_customer;
}

auto FoodCourtSeatReservationSystem::set_store_name(std::string store_name) -> void {
  m_store_name = std::move(store_name);
}
auto FoodCourtSeatReservationSystem::get_store_name() -> std::string {
  return m_store_name;
}
auto FoodCourtSeatReservationSystem::read_store_name() const -> READ_STR {
  return m_store_name;
}

auto FoodCourtSeatReservationSystem::set_reserved_seat_fee(long double &reserved_seat_fee) -> void {
  m_reserved_seat_fee = reserved_seat_fee;
}
auto FoodCourtSeatReservationSystem::get_reserved_seat_fee() -> long double {
  return m_reserved_seat_fee;
}
auto FoodCourtSeatReservationSystem::read_reserved_seat_fee() const -> READ_LONG_DBL {
  return m_reserved_seat_fee;
}

auto FoodCourtSeatReservationSystem::set_reserved_seat_contact(std::string reserved_seat_contact) -> void {
  m_reserved_seat_contact = std::move(reserved_seat_contact);
}
auto FoodCourtSeatReservationSystem::get_reserved_seat_contact() -> std::string {
  return m_reserved_seat_contact;
}
auto FoodCourtSeatReservationSystem::read_reserved_seat_contact() const -> READ_STR {
  return m_reserved_seat_contact;
}

//SECTION - Setter, Getter, and Read for std::vector<TYPE>

auto FoodCourtSeatReservationSystem::set_list_of_schedule_hours(std::vector<std::string> list_of_schedule_hours) -> void {
  m_list_of_schedule_hours = std::move(list_of_schedule_hours);
}
auto FoodCourtSeatReservationSystem::get_list_of_schedule_hours() -> std::vector<std::string> {
  return m_list_of_schedule_hours;
}
auto FoodCourtSeatReservationSystem::read_list_of_schedule_hours() const -> READ_VEC_STR {
  return m_list_of_schedule_hours;
}

auto FoodCourtSeatReservationSystem::set_list_of_number_of_customer(std::vector<uint32_t> list_of_number_of_customer) -> void {
  m_list_of_number_of_customer = std::move(list_of_number_of_customer);
}
auto FoodCourtSeatReservationSystem::get_list_of_number_of_customer() -> std::vector<uint32_t> {
  return m_list_of_number_of_customer;
}
auto FoodCourtSeatReservationSystem::read_list_of_number_of_customer() const -> READ_VEC_UINT32 {
  return m_list_of_number_of_customer;
}

auto FoodCourtSeatReservationSystem::set_list_of_store_name(std::vector<std::string> list_of_store_name) -> void {
  m_list_of_store_name = std::move(list_of_store_name);
}
auto FoodCourtSeatReservationSystem::get_list_of_store_name() -> std::vector<std::string> {
  return m_list_of_store_name;
}
auto FoodCourtSeatReservationSystem::read_list_of_store_name() const -> READ_VEC_STR {
  return m_list_of_store_name;
}

auto FoodCourtSeatReservationSystem::set_list_of_reserved_seat_fee(std::vector<long double> list_of_reserved_seat_fee) -> void {
  m_list_of_reserved_seat_fee = std::move(list_of_reserved_seat_fee);
}
auto FoodCourtSeatReservationSystem::get_list_of_reserved_seat_fee() -> std::vector<long double> {
  return m_list_of_reserved_seat_fee;
}
auto FoodCourtSeatReservationSystem::read_list_of_reserved_seat_fee() const -> READ_VEC_LONG_DBL {
  return m_list_of_reserved_seat_fee;
}

auto FoodCourtSeatReservationSystem::set_list_of_reserved_seat_contact(std::vector<std::string> list_of_reserved_seat_contact) -> void {
  m_list_of_reserved_seat_contact = std::move(list_of_reserved_seat_contact);
}
auto FoodCourtSeatReservationSystem::get_list_of_reserved_seat_contact() -> std::vector<std::string> {
  return m_list_of_reserved_seat_contact;
}
auto FoodCourtSeatReservationSystem::read_list_of_reserved_seat_contact() const -> READ_VEC_STR {
  return m_list_of_reserved_seat_contact;
}

//SECTION - Setter, Getter, and Read for User File Name input

auto FoodCourtSeatReservationSystem::set_user_file_name(std::string user_file_name) -> void {
  m_user_file_name = std::move(user_file_name.append(".html"));
}
auto FoodCourtSeatReservationSystem::get_user_file_name() -> std::string {
  return m_user_file_name;
}
auto FoodCourtSeatReservationSystem::read_user_file_name() const -> READ_STR {
  return m_user_file_name;
}

//SECTION - Main program features

auto FoodCourtSeatReservationSystem::request_seat_reservation(
  ConsoleInterface         *user_interface,
  std::string              &schedule_hours,
  uint32_t                 &number_of_customer,
  std::string              &store_name,
  long double              &reserved_seat_fee,
  std::string              &reserved_seat_contact,
  std::vector<std::string> &list_of_schedule_hours,
  std::vector<uint32_t>    &list_of_number_of_customer,
  std::vector<std::string> &list_of_store_name,
  std::vector<long double> &list_of_reserved_seat_fee,
  std::vector<std::string> &list_of_reserved_seat_contact
) -> void {
  
  char prompt_key{};

  user_interface->display_in_request_seat_reservation();

  do {
    
    user_interface->input_schedule_hours(schedule_hours);
    set_schedule_hours(schedule_hours);
    list_of_schedule_hours.emplace_back(read_schedule_hours());

    user_interface->input_number_of_customer(number_of_customer);
    set_number_of_customer(number_of_customer);
    list_of_number_of_customer.emplace_back(read_number_of_customer());

    user_interface->input_store_name(store_name);
    set_store_name(store_name);
    list_of_store_name.emplace_back(read_store_name());

    user_interface->input_reserved_seat_fee(
      read_number_of_customer(),
      reserved_seat_fee
    );
    set_reserved_seat_fee(reserved_seat_fee);
    list_of_reserved_seat_fee.emplace_back(read_reserved_seat_fee());

    user_interface->input_reserved_seat_contact(reserved_seat_contact);
    set_reserved_seat_contact(reserved_seat_contact);
    list_of_reserved_seat_contact.emplace_back(read_reserved_seat_contact());

    user_interface->input_prompt_key(prompt_key);

  } while(prompt_key == 'Y' || prompt_key == 'y');

}

auto FoodCourtSeatReservationSystem::review_seat_reservations(ConsoleInterface *user_interface) const -> void {

  user_interface->display_in_review_seat_reservation();

  user_interface->display_all_seat_reservations(
    read_list_of_schedule_hours(),
    read_list_of_number_of_customer(),
    read_list_of_store_name(),
    read_list_of_reserved_seat_fee(),
    read_list_of_reserved_seat_contact()
  );

}

auto FoodCourtSeatReservationSystem::search_seat_reservation(ConsoleInterface *user_interface) -> void {

  std::string reserved_seat_contact_to_search{};

  user_interface->display_in_search_contact_seat_reservation();

  user_interface->input_reserved_seat_contact_to_search(reserved_seat_contact_to_search);
  
  size_t reserved_seat_index{
    static_cast<size_t>(
      search_reserved_seat_contact(
        read_list_of_reserved_seat_contact(), 
        reserved_seat_contact_to_search
      )
    )
  };

  if(reserved_seat_index >= 0) {
    user_interface->display_searched_reserved_seat_contact(
      reserved_seat_index,
      reserved_seat_contact_to_search,
      read_list_of_schedule_hours(),
      read_list_of_number_of_customer(),
      read_list_of_store_name(),
      read_list_of_reserved_seat_fee()
    );
  }
  else {
    user_interface->display_searching_not_found(reserved_seat_contact_to_search);
  }

}

auto FoodCourtSeatReservationSystem::edit_seat_reservation(
  ConsoleInterface         *user_interface,
  std::string              &schedule_hours,
  uint32_t                 &number_of_customer,
  std::string              &store_name,
  long double              &reserved_seat_fee,
  std::string              &reserved_seat_contact,
  std::vector<std::string> &list_of_schedule_hours,
  std::vector<uint32_t>    &list_of_number_of_customer,
  std::vector<std::string> &list_of_store_name,
  std::vector<long double> &list_of_reserved_seat_fee,
  std::vector<std::string> &list_of_reserved_seat_contact
) -> void {

  size_t reserved_seat_index{};
  const size_t number_of_data{read_list_of_schedule_hours().size()};
  char prompt_key_to_edit{};

  user_interface->display_in_edit_seat_reservation();

  user_interface->display_all_seat_reservations(
    read_list_of_schedule_hours(),
    read_list_of_number_of_customer(),
    read_list_of_store_name(),
    read_list_of_reserved_seat_fee(),
    read_list_of_reserved_seat_contact()
  );

  user_interface->input_reserved_seat_index_to_edit(
    reserved_seat_index,
    number_of_data
  );

  if(reserved_seat_index != 0) {

    --reserved_seat_index;

    user_interface->display_reserved_seat(
      reserved_seat_index,
      read_list_of_schedule_hours(),
      read_list_of_number_of_customer(),
      read_list_of_store_name(),
      read_list_of_reserved_seat_fee(),
      read_list_of_reserved_seat_contact()
    );

    user_interface->input_prompt_key_to_edit(prompt_key_to_edit);
    if(prompt_key_to_edit == 'Y' || prompt_key_to_edit == 'y') {
      
      //SECTION - Editing Schedule Hours
      user_interface->display_list_of_schedule_hours_to_edit(
        reserved_seat_index, 
        read_list_of_schedule_hours()
      );
      user_interface->input_schedule_hours(schedule_hours);
      set_schedule_hours(schedule_hours);
      list_of_schedule_hours.at(reserved_seat_index) = read_schedule_hours();

      //SECTION - Editing Number of Customer
      user_interface->display_list_of_number_of_customer_to_edit(
        reserved_seat_index, 
        read_list_of_number_of_customer()
      );
      user_interface->input_number_of_customer(number_of_customer);
      set_number_of_customer(number_of_customer);
      list_of_number_of_customer.at(reserved_seat_index) = read_number_of_customer();

      //SECTION - Editing Store Name
      user_interface->display_list_of_store_name_to_edit(
        reserved_seat_index, 
        read_list_of_store_name()
      );
      user_interface->input_store_name(store_name);
      set_store_name(store_name);
      list_of_store_name.at(reserved_seat_index) = read_store_name();

      //SECTION - Editing Reserved Seat Fee
      user_interface->display_list_of_reserved_seat_fee_to_edit(
        reserved_seat_index, 
        read_list_of_reserved_seat_fee()
      );
      user_interface->input_reserved_seat_fee(
        read_number_of_customer(),
        reserved_seat_fee
      );
      set_reserved_seat_fee(reserved_seat_fee);
      list_of_reserved_seat_fee.at(reserved_seat_index) = read_reserved_seat_fee();

      //SECTION - Editing Reserved Seat Contact
      user_interface->display_list_of_reserved_seat_contact_to_edit(
        reserved_seat_index, 
        read_list_of_reserved_seat_contact()
      );
      user_interface->input_reserved_seat_contact(reserved_seat_contact);
      set_reserved_seat_contact(reserved_seat_contact);
      list_of_reserved_seat_contact.at(reserved_seat_index) = read_reserved_seat_contact();

    }

  }

}

auto FoodCourtSeatReservationSystem::cancel_seat_reservation(
  ConsoleInterface         *user_interface,
  std::vector<std::string> &list_of_schedule_hours,
  std::vector<uint32_t>    &list_of_number_of_customer,
  std::vector<std::string> &list_of_store_name,
  std::vector<long double> &list_of_reserved_seat_fee,
  std::vector<std::string> &list_of_reserved_seat_contact
) -> void {

  size_t reserved_seat_index{};
  const size_t number_of_data{read_list_of_schedule_hours().size()};
  char prompt_key_to_edit{};

  user_interface->display_in_cancel_seat_reservation();

  user_interface->display_all_seat_reservations(
    read_list_of_schedule_hours(),
    read_list_of_number_of_customer(),
    read_list_of_store_name(),
    read_list_of_reserved_seat_fee(),
    read_list_of_reserved_seat_contact()
  );

  user_interface->input_reserved_seat_index_to_edit(
    reserved_seat_index,
    number_of_data
  );

  if(reserved_seat_index != 0) {
    
    --reserved_seat_index;

    user_interface->display_reserved_seat(
      reserved_seat_index,
      read_list_of_schedule_hours(),
      read_list_of_number_of_customer(),
      read_list_of_store_name(),
      read_list_of_reserved_seat_fee(),
      read_list_of_reserved_seat_contact()
    );

    const auto selected_seat_schedule_hours        = list_of_schedule_hours.begin() + reserved_seat_index;
    const auto selected_seat_number_of_customer    = list_of_number_of_customer.begin() + reserved_seat_index;
    const auto selected_seat_store_name            = list_of_store_name.begin() + reserved_seat_index;
    const auto selected_seat_reserved_seat_fee     = list_of_reserved_seat_fee.begin() + reserved_seat_index;
    const auto selected_seat_reserved_seat_contact = list_of_reserved_seat_contact.begin() + reserved_seat_index;

    user_interface->input_prompt_key_to_edit(prompt_key_to_edit);
    if(prompt_key_to_edit == 'Y' || prompt_key_to_edit == 'y') {
      list_of_schedule_hours.erase(selected_seat_schedule_hours);
      list_of_number_of_customer.erase(selected_seat_number_of_customer);
      list_of_store_name.erase(selected_seat_store_name);
      list_of_reserved_seat_fee.erase(selected_seat_reserved_seat_fee);
      list_of_reserved_seat_contact.erase(selected_seat_reserved_seat_contact);
      
      user_interface->display_reserved_seat_cancellation_success(reserved_seat_index);
    }

  }

}

auto FoodCourtSeatReservationSystem::save_data_interactive_webview(
  ConsoleInterface         *user_interface,
  std::string              &user_file_name,
  std::vector<std::string> &list_of_schedule_hours,
  std::vector<uint32_t>    &list_of_number_of_customer,
  std::vector<std::string> &list_of_store_name,
  std::vector<long double> &list_of_reserved_seat_fee,
  std::vector<std::string> &list_of_reserved_seat_contact,
  std::fstream             &user_file_data
) -> void {

  std::string html_lang{};
  std::string html_name{};
  std::string html_content{};
  std::string html_css_link{};
  uint32_t    html_heading_size{};
  std::string html_span_class_name{};
  std::string html_a_link{};
  std::string html_a_target{};
  std::string html_table_class_name{};

  user_interface->display_in_save_data();
  user_interface->display_saving_data_in_html();

  user_interface->input_file_name_to_save_data(user_file_name);
  set_user_file_name(user_file_name);

  sort_user_reserved_seat_data_am_pm_order(
    list_of_schedule_hours,
    list_of_number_of_customer,
    list_of_store_name,
    list_of_reserved_seat_fee,
    list_of_reserved_seat_contact
  );

  set_list_of_schedule_hours(list_of_schedule_hours);
  set_list_of_number_of_customer(list_of_number_of_customer);
  set_list_of_store_name(list_of_store_name);
  set_list_of_reserved_seat_fee(list_of_reserved_seat_fee);
  set_list_of_reserved_seat_contact(list_of_reserved_seat_contact);

  user_interface->display_all_sorted_seat_reservations(
    read_list_of_schedule_hours(),
    read_list_of_number_of_customer(),
    read_list_of_store_name(),
    read_list_of_reserved_seat_fee(),
    read_list_of_reserved_seat_contact()
  );

  create_html_file_data(
    read_user_file_name(),
    user_file_data,
    read_list_of_schedule_hours(),
    read_list_of_number_of_customer(),
    read_list_of_store_name(),
    read_list_of_reserved_seat_fee(),
    read_list_of_reserved_seat_contact()
  ); 

  user_interface->display_saving_data_success(read_user_file_name());

}
