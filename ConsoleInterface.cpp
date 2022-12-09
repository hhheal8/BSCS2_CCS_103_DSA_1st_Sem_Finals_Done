#include "ConsoleInterface.hpp"

#include <iostream>
#include <ios>
#include <limits>
#include <string>
#include <vector>

auto ConsoleInterface::display_introduction() const -> void {
  std::cout << m_line_separator;
  std::cout << "Waltermart Candelaria, Quezon Branch - Food Court Seat Reservation System";
  std::cout << m_line_separator;
}

auto ConsoleInterface::display_program_feature(uint32_t &options) const -> void {

  while(true) {
    std::cout << "\n[1] Request seat reservation\n[2] Review seat reservations\n[3] Search reserved seat contact\n[4] Edit seat reservation";
    std::cout << "\n[5] Cancel seat reservation\n[6] Save data (Interactive Webview)\n[7] Exit\n";
    std::cout << "\nSelect from 1 ... 6: ";
    std::cin >> options;

    if(!std::cin || options >= 8) {
      std::cout << m_error_msg;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    }
  }

}

auto ConsoleInterface::display_error_msg() const -> void {
  std::cout << m_error_msg;
}

auto ConsoleInterface::display_exit_msg() const -> void {
  std::cout << m_exit_msg;
}

auto ConsoleInterface::display_in_request_seat_reservation() const -> void {
  system("cls");
  std::cout << m_line_separator;
  std::cout << "Requesting Seat Reservation";
  std::cout << m_line_separator;
}
auto ConsoleInterface::display_in_review_seat_reservation() const -> void {
  system("cls");
  std::cout << m_line_separator;
  std::cout << "Reviewing Seat Reservations";
  std::cout << m_line_separator;
}
auto ConsoleInterface::display_in_search_contact_seat_reservation() const -> void {
  system("cls");
  std::cout << m_line_separator;
  std::cout << "Searching Contact\'s Seat Reservation";
  std::cout << m_line_separator;
}
auto ConsoleInterface::display_in_edit_seat_reservation() const -> void {
  system("cls");
  std::cout << m_line_separator;
  std::cout << "Editing Seat Reservation";
  std::cout << m_line_separator;
}
auto ConsoleInterface::display_in_cancel_seat_reservation() const -> void {
  system("cls");
  std::cout << m_line_separator;
  std::cout << "Canceling Seat Reservation";
  std::cout << m_line_separator;
}
auto ConsoleInterface::display_in_save_data() const -> void {
  system("cls");
  std::cout << m_line_separator;
  std::cout << "Saving Seat Reservation Data";
  std::cout << "\nNOTE - That all data will be sorted according to Schedule Hours order - AM to PM";
  std::cout << m_line_separator;
}

auto ConsoleInterface::input_schedule_hours(std::string &schedule_hours) const -> void {

  constexpr uint32_t max_size{8};

  while(true) {

    uint32_t colon{}, am{}, pm{};

    std::cout << "\nSchedule Hours(Example format - 11:30 AM/13:30 PM)   : ";
    std::getline(std::cin, schedule_hours);

    if(schedule_hours.size() > max_size) {
      std::cerr << m_error_msg << "Example format should be - `11:30 AM/13:30 PM`\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    if(schedule_hours.size() == (max_size - 1)) {
      
      colon = 0U;

      for(size_t i{}; i != schedule_hours.size(); ++i) {
        if(schedule_hours.at(i) == ':') {
          ++colon;
        }
        if(schedule_hours.at(i) == 'A' && schedule_hours.at(i + 1) == 'M') {
          ++am;
        }
      }
      
      if(colon != 1 && am != 1) {
        continue;
      }
      
      if(colon == 1 && am == 1) {
        break;
      }
      
    }
    if(schedule_hours.size() == max_size) {

      colon = 0U;
      am    = 0U;

      for(size_t i{}; i != schedule_hours.size(); ++i) {
        if(schedule_hours.at(i) == ':') {
          ++colon;
        }
        if(schedule_hours.at(i) == 'A' && schedule_hours.at(i + 1) == 'M') {
          ++am;
        }
        if(schedule_hours.at(i) == 'P' && schedule_hours.at(i + 1) == 'M') {
          ++pm;
        }
      }
      
      if(colon != 1 && (am != 1 || pm != 1)) {
        continue;
      }
      
      if(colon == 1 && (am == 1 || pm == 1)) {
        break;
      }

    }
    
  }

}

auto ConsoleInterface::input_number_of_customer(uint32_t &number_of_customer) const -> void {

  while(true) {
    std::cout << "Number of Customer                                   : ";
    std::cin >> number_of_customer;

    if(!std::cin) {
      std::cerr << m_error_msg;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    else {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    }
  }
  
}

auto ConsoleInterface::input_store_name(std::string &store_name) const -> void {
  std::cout << "Reserve Customer Seat for (Input Store Name)         : ";
  std::getline(std::cin, store_name);
}

auto ConsoleInterface::input_reserved_seat_fee(
  const uint32_t &number_of_customer,
  long double    &reserved_seat_fee
) const -> void {

  while(true) {
    if(number_of_customer <= 9) {
      std::cout << "Reserved Seat Fee for " << number_of_customer << " Customers - 20.00PHP         : ";
      std::cin >> reserved_seat_fee;
    }
    if(number_of_customer >= 10 && number_of_customer <= 50) {
      std::cout << "Reserved Seat Fee for " << number_of_customer << " Customers - 40.00PHP        : ";
      std::cin >> reserved_seat_fee;
    }

    if(!std::cin || reserved_seat_fee <= 0.0L) {
      std::cerr << m_error_msg;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    else if(number_of_customer >= 51) {
      std::cerr << m_error_msg << "Seat Reservation is only valid for max 50 Customers only\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    else {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    }
  }

}

auto ConsoleInterface::input_reserved_seat_contact(std::string &reserved_seat_contact) const -> void {
  std::cout << "Contact (Social Media Account Profile Link, Other...): ";
  std::getline(std::cin, reserved_seat_contact);
}

auto ConsoleInterface::input_prompt_key(char &prompt_key) const -> void {

  while(true) {
    std::cout << "\nRequest for another seat reservation?\nInput [Y/y] for YES and [N/n] for NO: ";
    std::cin >> prompt_key;

    if(!std::cin || prompt_key != 'Y' && prompt_key != 'y' && prompt_key != 'N' && prompt_key != 'n') {    
      std::cerr << m_error_msg;

      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    else {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    }
  }

}

auto ConsoleInterface::input_home_exit_key(char &home_exit_key) const -> void {
  while(true) {
    std::cout << "\nBack Home or Exit?";
    std::cout << "\nInput [Y/y] for Home and [N/n] for Exit: ";
    std::cin >> home_exit_key;

    if(!std::cin || home_exit_key != 'Y' && home_exit_key != 'y' && home_exit_key != 'N' && home_exit_key != 'n') {    
      std::cerr << m_error_msg;

      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    else {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    }
  }
}

auto ConsoleInterface::display_all_seat_reservations(
  const std::vector<std::string> &list_of_schedule_hours,
  const std::vector<uint32_t>    &list_of_number_of_customer,
  const std::vector<std::string> &list_of_store_name,
  const std::vector<long double> &list_of_reserved_seat_fee,
  const std::vector<std::string> &list_of_reserved_seat_contact
) const -> void {

  for(size_t i{}; i != list_of_schedule_hours.size(); ++i) {
    std::cout << m_line_separator;
    std::cout << "Reserved Seat [" << (i + 1) << "]";
    std::cout << m_line_separator;
    std::cout << "Schedule Hours          : " << list_of_schedule_hours.at(i);
    std::cout << "\nNumber of Customer      : " << list_of_number_of_customer.at(i);
    std::cout << "\nReserved for Customer of: " << list_of_store_name.at(i);
    std::cout << "\nReservation Fee         : " << list_of_reserved_seat_fee.at(i);
    std::cout << "\nReserved Seat Contact   : " << list_of_reserved_seat_contact.at(i);
  }

  std::cout << std::endl;

}

auto ConsoleInterface::input_reserved_seat_contact_to_search(std::string &reserved_seat_contact_to_search) const -> void {
  std::cout << "\nSearch Contact: ";
  std::getline(std::cin, reserved_seat_contact_to_search);
}

auto ConsoleInterface::display_searched_reserved_seat_contact(
  const size_t                   &reserved_seat_index,
  const std::string              &reserved_seat_contact_to_search,
  const std::vector<std::string> &list_of_schedule_hours,
  const std::vector<uint32_t>    &list_of_number_of_customer,
  const std::vector<std::string> &list_of_store_name,
  const std::vector<long double> &list_of_reserved_seat_fee
) const -> void {

  std::cout << m_line_separator;
  std::cout << reserved_seat_contact_to_search << "\'s Reserved Seat [" << (reserved_seat_index + 1) << "]";
  std::cout << m_line_separator;
  std::cout << "Schedule Hours           : " << list_of_schedule_hours.at(reserved_seat_index);
  std::cout << "\nNumber of Customer       : " << list_of_number_of_customer.at(reserved_seat_index);
  std::cout << "\nReserved for Customer of : " << list_of_store_name.at(reserved_seat_index);
  std::cout << "\nReservation Fee          : " << list_of_reserved_seat_fee.at(reserved_seat_index) << "\n";

}

auto ConsoleInterface::display_searching_not_found(const std::string &reserved_seat_contact_to_search) const -> void {
  std::cout << m_line_separator;
  std::cout << reserved_seat_contact_to_search << "\'s Reserved Seat [IS NOT FOUND!] = FAILED";
  std::cout << m_line_separator;
}

auto ConsoleInterface::display_reserved_seat(
  const size_t                   &reserved_seat_index,
  const std::vector<std::string> &list_of_schedule_hours,
  const std::vector<uint32_t>    &list_of_number_of_customer,
  const std::vector<std::string> &list_of_store_name,
  const std::vector<long double> &list_of_reserved_seat_fee,
  const std::vector<std::string> &list_of_reserved_seat_contact
) const -> void {

  std::cout << m_line_separator;
  std::cout << "Editing Reserved Seat [" << (reserved_seat_index + 1) << "]";
  std::cout << m_line_separator;
  std::cout << "Rewrite/Overwrite/Write New Schedule Hours           : " << list_of_schedule_hours.at(reserved_seat_index) << "?";
  std::cout << "\nRewrite/Overwrite/Write New Number of Customer       : " << list_of_number_of_customer.at(reserved_seat_index) << "?";
  std::cout << "\nRewrite/Overwrite/Write New Reserved for Customer of : " << list_of_store_name.at(reserved_seat_index) << "?";
  std::cout << "\nRewrite/Overwrite/Write New Reservation Fee          : " << list_of_reserved_seat_fee.at(reserved_seat_index) << "?";
  std::cout << "\nRewrite/Overwrite/Write New Reserved Seat Contact    : " << list_of_reserved_seat_contact.at(reserved_seat_index) << "?\n";

}

auto ConsoleInterface::input_reserved_seat_index_to_edit(
  size_t       &reserved_seat_index,
  const size_t &number_of_data
) const -> void {

  while(true) {
    std::cout << "\nSelect Reserved Seat No. (Input 0 to leave) : ";
    std::cin >> reserved_seat_index;

    if(!std::cin || reserved_seat_index > number_of_data) {
      std::cerr << m_error_msg;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    else if(reserved_seat_index == 0) {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    }
    else {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    }
  }

}

auto ConsoleInterface::input_prompt_key_to_edit(char &prompt_key_to_edit) const -> void {

  while(true) {
    std::cout << "\nEdit Reserved Seat?\nInput [Y/y] for YES and [N/n] for NO: ";
    std::cin >> prompt_key_to_edit;

    if(!std::cin || prompt_key_to_edit != 'Y' && prompt_key_to_edit != 'y' && prompt_key_to_edit != 'N' && prompt_key_to_edit != 'n') {
      std::cerr << m_error_msg;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    else {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    }
  }

}

auto ConsoleInterface::display_reserved_seat_cancellation_success(const size_t &reserved_seat_index) const -> void {
  std::cout << m_line_separator;
  std::cout << "Result of Cancellation of Reserved Seat [" << (reserved_seat_index + 1) << "] = SUCCESS";
  std::cout << m_line_separator;
}

auto ConsoleInterface::display_list_of_schedule_hours_to_edit(
  const size_t                   &reserved_seat_index,
  const std::vector<std::string> &list_of_schedule_hours
) const -> void {
  std::cout << "\nRewrite/Overwrite/Write New - [" << list_of_schedule_hours.at(reserved_seat_index) << "]?";
}

auto ConsoleInterface::display_list_of_number_of_customer_to_edit(
  const size_t                &reserved_seat_index,
  const std::vector<uint32_t> &list_of_number_of_customer
) const -> void {
  std::cout << "\nRewrite/Overwrite/Write New - [" << list_of_number_of_customer.at(reserved_seat_index) << "]?\n";
}

auto ConsoleInterface::display_list_of_store_name_to_edit(
  const size_t                   &reserved_seat_index,
  const std::vector<std::string> &list_of_store_name
) const -> void {
  std::cout << "\nRewrite/Overwrite/Write New - [" << list_of_store_name.at(reserved_seat_index) << "]?\n";
}

auto ConsoleInterface::display_list_of_reserved_seat_fee_to_edit(
  const size_t                   &reserved_seat_index,
  const std::vector<long double> &list_of_reserved_seat_fee
) const -> void {
  std::cout << "\nRewrite/Overwrite/Write New - [" << list_of_reserved_seat_fee.at(reserved_seat_index) << "]?\n";
}

auto ConsoleInterface::display_list_of_reserved_seat_contact_to_edit(
  const size_t                   &reserved_seat_index,
  const std::vector<std::string> &list_of_reserved_seat_contact
) const -> void {
  std::cout << "\nRewrite/Overwrite/Write New - [" << list_of_reserved_seat_contact.at(reserved_seat_index) << "]?\n";
}

auto ConsoleInterface::input_file_name_to_save_data(std::string &user_file_name) const -> void {
  std::cout << "\nFile name: ";
  std::getline(std::cin, user_file_name);
}

auto ConsoleInterface::display_all_sorted_seat_reservations(
  const std::vector<std::string> &list_of_schedule_hours,
  const std::vector<uint32_t>    &list_of_number_of_customer,
  const std::vector<std::string> &list_of_store_name,
  const std::vector<long double> &list_of_reserved_seat_fee,
  const std::vector<std::string> &list_of_reserved_seat_contact
) const -> void {

  for(size_t i{}; i != list_of_schedule_hours.size(); ++i) {
    std::cout << m_line_separator;
    std::cout << "Saved Seat Data [" << (i + 1) << "]";
    std::cout << m_line_separator;
    std::cout << "Schedule Hours          : " << list_of_schedule_hours.at(i);
    std::cout << "\nNumber of Customer      : " << list_of_number_of_customer.at(i);
    std::cout << "\nReserved for Customer of: " << list_of_store_name.at(i);
    std::cout << "\nReservation Fee         : " << list_of_reserved_seat_fee.at(i);
    std::cout << "\nReserved Seat Contact   : " << list_of_reserved_seat_contact.at(i);
  }

  std::cout << std::endl;

}

auto ConsoleInterface::display_saving_data_in_html() const -> void {
  std::cout << "\n!!!YOU'RE SAVING DATA IN AN INTERACTIVE WEBVIEW (.HTML FILE FORMAT)!!!\n!!!PLEASE FILL UP THE NECESSARRY INFORMATION BELOW!!!\n";
}

auto ConsoleInterface::display_saving_data_success(const std::string &user_file_name) const -> void {
  std::cout << m_line_separator;
  std::cout << "!!!DATA SUCCESSFULLY SAVED TO = [data/" << user_file_name << "]!!!";
  std::cout << m_line_separator;
}

