#include "FileCSS.hpp"
#include "FileHTML.hpp"

#include <fstream>
#include <string>
#include <utility>
#include <vector>

template<typename ...DATA>
auto FileHTML::write_in_file(
  std::fstream     &user_file_data,
  DATA             &&...data 
) const -> void {
  (user_file_data << ... << std::forward<DATA>(data));
}

auto FileHTML::create_html_file(
  const std::string              &user_file_name,
  std::fstream                   &user_file_data,
  const std::vector<std::string> &list_of_schedule_hours,
  const std::vector<uint32_t>    &list_of_number_of_customer,
  const std::vector<std::string> &list_of_store_name,
  const std::vector<long double> &list_of_reserved_seat_fee,
  const std::vector<std::string> &list_of_reserved_seat_contact
) const -> void {

  const std::string user_file_path{"data/" + user_file_name};

  user_file_data.open(user_file_path, std::ios::out|std::ios::trunc);

  write_in_file(user_file_data,

    "<!DOCTYPE html>\n",
    "<html lang=\"en\">",
    "\n",
    "<head>\n",
    "\t<meta charset=\"UTF-8\">\n",
    "\t<meta name=\"Author\" content=\"https://github.com/hhheal8\">\n",
    "\t<meta name=\"BSCS2 1st Sem Finals\" content=\"Food Court Seat Reservation System\">\n",
    "\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n",
    "\n",

    "\t<title>",
    "Waltermart Candelaria, Quezon - Branch Food Court Seat Reservation System",
    "</title>\n",
    "\n",
    "\t<link href=\"", read_css_file_link(), "\" media=\"screen\" type=\"text/css\" rel=\"stylesheet\">\n",
    "</head>\n",
    "\n",

    "<body>\n",
    "<h1>",
    "<span class=\"blue\">", "&lt;", "</span>",
    "Waltermart Candelaria",
    "<span class=\"blue\">", "&gt;", "</span>"

    "<span class=\"yellow\">",
    "Food Court Seat Reservation System",
    "</span>",
    "</h1>",
    "\n",

    "<h2>",
    "Created with love by ", 
    "<a href =\"https://www.facebook.com/profile.php?id=100087582249741\" target=\"_blank\">",
    "Gil and Hazel",
    "</a>",
    "</h2>",
    "\n",

    "\n",
    "<table class=\"container\">\n",
    "\t<thead>\n",
    "\t\t<tr>\n",
    "\t\t\t<th>", "<h1>", "Schedule Hours", "</h1>", "</th>\n",
    "\t\t\t<th>", "<h1>", "Number of Customers", "</h1>", "</th>\n",
    "\t\t\t<th>", "<h1>", "Reserved Seat for Customer of", "</h1>", "</th>\n",
    "\t\t\t<th>", "<h1>", "Reserved Seat Fees", "</h1>", "</th>\n",
    "\t\t\t<th>", "<h1>", "Reserved Seat Contacts", "</h1>", "</th>\n",
    "\t\t</tr>\n",
    "\t</thead>\n",
    "\n"
  );

  write_in_file(user_file_data, 
    "\t<tbody>\n"
  );
  for(size_t i{}; i != list_of_schedule_hours.size(); ++i) {
    write_in_file(user_file_data, 
      "\t\t<tr>\n"
    );
    write_in_file(
      user_file_data,
      "\t\t\t<td>", list_of_schedule_hours.at(i), "</td>\n",
      "\t\t\t<td>", list_of_number_of_customer.at(i), "</td>\n",
      "\t\t\t<td>", list_of_store_name.at(i), "</td>\n",
      "\t\t\t<td>", list_of_reserved_seat_fee.at(i), "</td>\n",
      "\t\t\t<td>", list_of_reserved_seat_contact.at(i), "</td>\n"
    );
    write_in_file(user_file_data, 
      "\t\t</tr>\n"
    );
  }
  write_in_file(user_file_data,
    "\t</tbody>\n",
    "</table>\n",
    "\n",

    "</body>\n",
    "\n",

    "</html>\n"
  );
  
  user_file_data.close();

}

auto FileHTML::create_html_file_data(
  const std::string              &user_file_name,
  std::fstream                   &user_file_data,
  const std::vector<std::string> &list_of_schedule_hours,
  const std::vector<uint32_t>    &list_of_number_of_customer,
  const std::vector<std::string> &list_of_store_name,
  const std::vector<long double> &list_of_reserved_seat_fee,
  const std::vector<std::string> &list_of_reserved_seat_contact
) const -> void {
  create_css_file_data(user_file_data);
  create_html_file(
    user_file_name,
    user_file_data,
    list_of_schedule_hours,
    list_of_number_of_customer,
    list_of_store_name,
    list_of_reserved_seat_fee,
    list_of_reserved_seat_contact
  );
}
