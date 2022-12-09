#include "ConsoleInterface.hpp"
#include "FoodCourtSeatReservationSystem.hpp"

#include <cstdlib>  //REVIEW - For std::exit(0)
#include <string>
#include <vector>

enum PROGRAM_FEATURES {
  REQUEST_SEAT_RESERVATION = 1,
  REVIEW_SEAT_RESERVATION,
  SEARCH_SEAT_RESERVATION,
  EDIT_SEAT_RESERVATION,
  CANCEL_SEAT_RESERVATION,
  SAVE_DATA_INTERACTIVE_WEBVIEW,
  EXIT_SYSTEM
};

auto main(int argc, char **argv) -> decltype(argc) {

  ConsoleInterface *user_interface = new ConsoleInterface{};
  FoodCourtSeatReservationSystem *waltermart_candelaria = new FoodCourtSeatReservationSystem{};

  std::string schedule_hours{};
  uint32_t    number_of_customer{};
  std::string store_name{};
  long double reserved_seat_fee{};
  std::string reserved_seat_contact{};

  std::vector<std::string> list_of_schedule_hours{};
  std::vector<uint32_t>    list_of_number_of_customer{};
  std::vector<std::string> list_of_store_name{};
  std::vector<long double> list_of_reserved_seat_fee{};
  std::vector<std::string> list_of_reserved_seat_contact{};

  std::string  user_file_name{};
  std::fstream user_file_data{};

  uint32_t options{};
  char     home_exit_key{};

  user_interface->display_introduction();
  do {

    user_interface->display_program_feature(options);
    switch(options) {
      case REQUEST_SEAT_RESERVATION:
        waltermart_candelaria->request_seat_reservation(
          user_interface,
          schedule_hours,
          number_of_customer,
          store_name,
          reserved_seat_fee,
          reserved_seat_contact,
          list_of_schedule_hours,
          list_of_number_of_customer,
          list_of_store_name,
          list_of_reserved_seat_fee,
          list_of_reserved_seat_contact
        );
        waltermart_candelaria->set_list_of_schedule_hours(list_of_schedule_hours);
        waltermart_candelaria->set_list_of_number_of_customer(list_of_number_of_customer);
        waltermart_candelaria->set_list_of_store_name(list_of_store_name);
        waltermart_candelaria->set_list_of_reserved_seat_fee(list_of_reserved_seat_fee);
        waltermart_candelaria->set_list_of_reserved_seat_contact(list_of_reserved_seat_contact);
      break;

      case REVIEW_SEAT_RESERVATION:
        waltermart_candelaria->review_seat_reservations(user_interface);
      break;

      case SEARCH_SEAT_RESERVATION:
        waltermart_candelaria->search_seat_reservation(user_interface);
      break;

      case EDIT_SEAT_RESERVATION:
        waltermart_candelaria->edit_seat_reservation(
          user_interface,
          schedule_hours,
          number_of_customer,
          store_name,
          reserved_seat_fee,
          reserved_seat_contact,
          list_of_schedule_hours,
          list_of_number_of_customer,
          list_of_store_name,
          list_of_reserved_seat_fee,
          list_of_reserved_seat_contact
        );
        waltermart_candelaria->set_list_of_schedule_hours(list_of_schedule_hours);
        waltermart_candelaria->set_list_of_number_of_customer(list_of_number_of_customer);
        waltermart_candelaria->set_list_of_store_name(list_of_store_name);
        waltermart_candelaria->set_list_of_reserved_seat_fee(list_of_reserved_seat_fee);
        waltermart_candelaria->set_list_of_reserved_seat_contact(list_of_reserved_seat_contact);
      break;

      case CANCEL_SEAT_RESERVATION:
        waltermart_candelaria->cancel_seat_reservation(
          user_interface,
          list_of_schedule_hours,
          list_of_number_of_customer,
          list_of_store_name,
          list_of_reserved_seat_fee,
          list_of_reserved_seat_contact
        );
        waltermart_candelaria->set_list_of_schedule_hours(list_of_schedule_hours);
        waltermart_candelaria->set_list_of_number_of_customer(list_of_number_of_customer);
        waltermart_candelaria->set_list_of_store_name(list_of_store_name);
        waltermart_candelaria->set_list_of_reserved_seat_fee(list_of_reserved_seat_fee);
        waltermart_candelaria->set_list_of_reserved_seat_contact(list_of_reserved_seat_contact);
      break;

      case SAVE_DATA_INTERACTIVE_WEBVIEW:
        waltermart_candelaria->save_data_interactive_webview(
          user_interface,
          user_file_name,
          list_of_schedule_hours,
          list_of_number_of_customer,
          list_of_store_name,
          list_of_reserved_seat_fee,
          list_of_reserved_seat_contact,
          user_file_data
        );
      break;

      case EXIT_SYSTEM:
        user_interface->display_exit_msg();

        delete user_interface;
        user_interface = nullptr;

        delete waltermart_candelaria;
        waltermart_candelaria = nullptr;

        std::exit(0);
      break;
    }

    user_interface->input_home_exit_key(home_exit_key);

  } while(home_exit_key == 'Y' || home_exit_key == 'y' || options >= 8);

  user_interface->display_exit_msg();

  delete user_interface;
  user_interface = nullptr;

  delete waltermart_candelaria;
  waltermart_candelaria = nullptr;

  std::exit(0);
  
}