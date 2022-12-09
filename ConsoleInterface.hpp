#ifndef CONSOLEINTERFACE_H
#define CONSOLEINTERFACE_H

#include <iostream>
#include <ios>      //REVIEW - For std::streamsize
#include <limits>   //REVIEW - For std::numeric_limits
#include <string>
#include <vector>
 
class ConsoleInterface {

  private:

    const char *m_line_separator{"\n========================================================================\n"};
    const char *m_error_msg{"\nInvalid Input/Format. Please Try Again.\n"};
    const char *m_exit_msg{"\nExit...\n"};

  public:

    ConsoleInterface() = default;

    auto display_introduction() const -> void;
    auto display_program_feature(uint32_t &options) const -> void;

    auto display_error_msg() const -> void;
    auto display_exit_msg() const -> void;

    auto display_in_request_seat_reservation() const -> void;
    auto display_in_review_seat_reservation() const -> void;
    auto display_in_search_contact_seat_reservation() const -> void;
    auto display_in_edit_seat_reservation() const -> void;
    auto display_in_cancel_seat_reservation() const -> void;
    auto display_in_save_data() const -> void;

    auto input_schedule_hours(std::string &schedule_hours) const -> void;
    auto input_number_of_customer(uint32_t &number_of_customer) const -> void;
    auto input_store_name(std::string &store_name) const -> void;
    auto input_reserved_seat_fee(
      const uint32_t &number_of_customer, 
      long double    &reserved_seat_fee
    ) const -> void;
    auto input_reserved_seat_contact(std::string &reserved_seat_contact) const -> void;
    auto input_prompt_key(char &prompt_key) const -> void;
    auto input_home_exit_key(char &home_exit_key) const -> void;
    
    auto display_all_seat_reservations(
      const std::vector<std::string> &list_of_schedule_hours,
      const std::vector<uint32_t>    &list_of_number_of_customer,
      const std::vector<std::string> &list_of_store_name,
      const std::vector<long double> &list_of_reserved_seat_fee,
      const std::vector<std::string> &list_of_reserved_seat_contact
    ) const -> void;

    auto input_reserved_seat_contact_to_search(std::string &reserved_seat_contact_to_search) const -> void;

    auto display_searched_reserved_seat_contact(
      const size_t                   &reserved_seat_index,
      const std::string              &reserved_seat_contact_to_search,
      const std::vector<std::string> &list_of_schedule_hours,
      const std::vector<uint32_t>    &list_of_number_of_customer,
      const std::vector<std::string> &list_of_store_name,
      const std::vector<long double> &list_of_reserved_seat_fee
    ) const -> void;

    auto display_searching_not_found(const std::string &reserved_seat_contact_to_search) const -> void;

    auto display_reserved_seat(
      const size_t                   &reserved_seat_index,
      const std::vector<std::string> &list_of_schedule_hours,
      const std::vector<uint32_t>    &list_of_number_of_customer,
      const std::vector<std::string> &list_of_store_name,
      const std::vector<long double> &list_of_reserved_seat_fee,
      const std::vector<std::string> &list_of_reserved_seat_contact
    ) const -> void;

    auto input_reserved_seat_index_to_edit(
      size_t       &reserved_seat_index,
      const size_t &number_of_data
    ) const -> void;

    auto input_prompt_key_to_edit(char &prompt_key_to_edit) const -> void;

    auto display_reserved_seat_cancellation_success(const size_t &reserved_seat_index) const -> void;

    auto display_list_of_schedule_hours_to_edit(
      const size_t                   &reserved_seat_index,
      const std::vector<std::string> &list_of_schedule_hours
    ) const -> void;

    auto display_list_of_number_of_customer_to_edit(
      const size_t                &reserved_seat_index,
      const std::vector<uint32_t> &list_of_number_of_customer
    ) const -> void;

    auto display_list_of_store_name_to_edit(
      const size_t                   &reserved_seat_index,
      const std::vector<std::string> &list_of_store_name
    ) const -> void;

    auto display_list_of_reserved_seat_fee_to_edit(
      const size_t                   &reserved_seat_index,
      const std::vector<long double> &list_of_reserved_seat_fee
    ) const -> void;

    auto display_list_of_reserved_seat_contact_to_edit(
      const size_t                   &reserved_seat_index,
      const std::vector<std::string> &list_of_reserved_seat_contact
    ) const -> void;

    auto input_file_name_to_save_data(std::string &user_file_name) const -> void;

    auto display_all_sorted_seat_reservations(
      const std::vector<std::string> &list_of_schedule_hours,
      const std::vector<uint32_t>    &list_of_number_of_customer,
      const std::vector<std::string> &list_of_store_name,
      const std::vector<long double> &list_of_reserved_seat_fee,
      const std::vector<std::string> &list_of_reserved_seat_contact
    ) const -> void;

    //SECTION - 

    auto display_saving_data_in_html() const -> void;
    auto display_saving_data_success(const std::string &user_file_name) const -> void;
    
    ~ConsoleInterface() {}

};

#endif // CONSOLEINTERFACE_H