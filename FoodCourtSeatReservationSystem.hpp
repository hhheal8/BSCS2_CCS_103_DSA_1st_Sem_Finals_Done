#ifndef FOODCOURTSEATRESERVATIONSYSTEM_H
#define FOODCOURTSEATRESERVATIONSYSTEM_H

#include "AlgorithmTools.hpp"
#include "ConsoleInterface.hpp"
#include "FileHTML.hpp"

#include <algorithm>
#include <fstream>
#include <iterator>
#include <string>
#include <utility>  //REVIEW - For std::move()
#include <vector>

class FoodCourtSeatReservationSystem : public AlgorithmTools, public FileHTML {

  private:

    //ANCHOR - Type aliases to maintain code readability

    using READ_STR          = const std::string&;
    using READ_UINT32       = const uint32_t&;
    using READ_VEC_STR      = const std::vector<std::string>&;
    using READ_VEC_UINT32   = const std::vector<uint32_t>&;
    using READ_LONG_DBL     = const long double&;
    using READ_VEC_LONG_DBL = const std::vector<long double>&;

    //SECTION - Data Member Variables

    std::string m_schedule_hours{};
    uint32_t    m_number_of_customer{};
    std::string m_store_name{};
    long double m_reserved_seat_fee{};
    std::string m_reserved_seat_contact{};

    std::vector<std::string> m_list_of_schedule_hours{};
    std::vector<uint32_t>    m_list_of_number_of_customer{};
    std::vector<std::string> m_list_of_store_name{};
    std::vector<long double> m_list_of_reserved_seat_fee{};
    std::vector<std::string> m_list_of_reserved_seat_contact{};

    std::string m_user_file_name{};
    
  public:

    //SECTION - Setter, Getter, and Read Only Data to Encapsulate Data Member Variables

    auto set_schedule_hours(std::string schedule_hours) -> void;
    auto get_schedule_hours() -> std::string;
    auto read_schedule_hours() const -> READ_STR;

    auto set_number_of_customer(uint32_t &number_of_customer) -> void;
    auto get_number_of_customer() -> uint32_t;
    auto read_number_of_customer() const -> READ_UINT32;

    auto set_store_name(std::string store_name) -> void;
    auto get_store_name() -> std::string;
    auto read_store_name() const -> READ_STR;

    auto set_reserved_seat_fee(long double &reserved_seat_fee) -> void;
    auto get_reserved_seat_fee() -> long double;
    auto read_reserved_seat_fee() const -> READ_LONG_DBL;

    auto set_reserved_seat_contact(std::string reserved_seat_contact) -> void;
    auto get_reserved_seat_contact() -> std::string;
    auto read_reserved_seat_contact() const -> READ_STR;

    //SECTION - Setter, Getter, and Read Only Data to Encapsulate List of Data Member Variables

    auto set_list_of_schedule_hours(std::vector<std::string> list_of_schedule_hours) -> void;
    auto get_list_of_schedule_hours() -> std::vector<std::string>;
    auto read_list_of_schedule_hours() const -> READ_VEC_STR;

    auto set_list_of_number_of_customer(std::vector<uint32_t> list_of_number_of_customer) -> void;
    auto get_list_of_number_of_customer() -> std::vector<uint32_t>;
    auto read_list_of_number_of_customer() const -> READ_VEC_UINT32;

    auto set_list_of_store_name(std::vector<std::string> list_of_store_name) -> void;
    auto get_list_of_store_name() -> std::vector<std::string>;
    auto read_list_of_store_name() const -> READ_VEC_STR;

    auto set_list_of_reserved_seat_fee(std::vector<long double> list_of_reserved_seat_fee) -> void;
    auto get_list_of_reserved_seat_fee() -> std::vector<long double>;
    auto read_list_of_reserved_seat_fee() const -> READ_VEC_LONG_DBL;

    auto set_list_of_reserved_seat_contact(std::vector<std::string> list_of_reserved_seat_contact) -> void;
    auto get_list_of_reserved_seat_contact() -> std::vector<std::string>;
    auto read_list_of_reserved_seat_contact() const -> READ_VEC_STR;

    auto set_user_file_name(std::string user_file_name) -> void;
    auto get_user_file_name() -> std::string;
    auto read_user_file_name() const -> READ_STR;

    //SECTION - Main features of the program

    auto request_seat_reservation(
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
    ) -> void;

    auto review_seat_reservations(ConsoleInterface *user_interface) const -> void;

    auto search_seat_reservation(ConsoleInterface *user_interface) -> void;

    auto edit_seat_reservation(
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
    ) -> void;

    auto cancel_seat_reservation(
      ConsoleInterface         *user_interface,
      std::vector<std::string> &list_of_schedule_hours,
      std::vector<uint32_t>    &list_of_number_of_customer,
      std::vector<std::string> &list_of_store_name,
      std::vector<long double> &list_of_reserved_seat_fee,
      std::vector<std::string> &list_of_reserved_seat_contact
    ) -> void;

    auto save_data_interactive_webview(
      ConsoleInterface         *user_interface,
      std::string              &user_file_name,
      std::vector<std::string> &list_of_schedule_hours,
      std::vector<uint32_t>    &list_of_number_of_customer,
      std::vector<std::string> &list_of_store_name,
      std::vector<long double> &list_of_reserved_seat_fee,
      std::vector<std::string> &list_of_reserved_seat_contact,
      std::fstream             &user_file_data
    ) -> void;

};

#endif // FOODCOURTSEATRESERVATIONSYSTEM_H