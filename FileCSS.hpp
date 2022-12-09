#ifndef FILECSS_H
#define FILECSS_H

#include <fstream>
#include <string>
#include <utility>

class FileCSS {

  private:

    const std::string css_file_path{"../data/style/style.css"};

    template<typename ...DATA>
    auto write_in_file(
      std::fstream     &user_file_data,
      DATA             &&...data
    ) const -> void;

    auto create_css_file(std::fstream &user_file_data) const -> void;

  public:

    auto create_css_file_data(std::fstream &user_file_data) const -> void;

};

#endif // FILECSS_H