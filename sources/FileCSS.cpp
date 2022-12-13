#include "FileCSS.hpp"

#include <fstream>
#include <string>
#include <utility>

template<typename ...DATA>
auto FileCSS::write_in_file(
  std::fstream     &user_file_data,
  DATA             &&...data 
) const -> void {
  (user_file_data << ... << std::forward<DATA>(data));
}

auto FileCSS::create_css_file(std::fstream &user_file_data) const -> void {

  const std::string css_file_path_data{"../data/" + css_file_path};
  
  user_file_data.open(css_file_path_data, std::ios::out|std::ios::trunc);

  write_in_file(user_file_data,
    "@import url(http://fonts.googleapis.com/css?family=Open+Sans:300,400,700);\n",
    "\n",

    "body {\n",
    "\tfont-family: 'Open Sans', sans-serif;\n",
    "\tfont-weight: 300;\n",
    "\tline-height: 1.42em;\n",
    "\tcolor:#A7A1AE;\n",
    "\tbackground-color:#1F2739;\n",
    "}\n",
    "\n",

    "h1 {\n",
    "\tfont-size:3em;\n",
    "\tfont-weight: 200;\n",
    "\tline-height:1em;\n",
    "\ttext-align: center;\n",
    "\tcolor: #4DC3FA;\n",
    "}\n",
    "\n",

    "h2 {\n",
    "\tfont-size:1em; \n",
    "\tfont-weight: 200;\n",
    "\ttext-align: center;\n",
    "\tdisplay: block;\n",
    "\tline-height:1em;\n",
    "\tpadding-bottom: 2em;\n",
    "\tcolor: #FB667A;\n",
    "}\n",
    "\n",

    "h2 a {\n",
    "\tfont-weight: 700;\n",
    "\tcolor: #FB667A;\n",
    "\ttext-decoration: none;\n",
    "}\n",
    "\n",

    ".blue { color: #185875; }\n",
    ".yellow { color: #FFF842; }\n",
    "\n",

    ".container th h1 {\n",
    "\tfont-weight: bold;\n",
    "\tfont-size: 1em;\n",
    "\ttext-align: left;\n",
    "\tcolor: #185875;\n",
    "}\n",
    "\n",

    ".container td {\n",
    "\tfont-weight       : normal;\n",
    "\tfont-size         : 1em;\n",
    "\t-webkit-box-shadow: 0 2px 2px -2px #0E1119;\n",
    "\t-moz-box-shadow   : 0 2px 2px -2px #0E1119;\n",
    "\tbox-shadow        : 0 2px 2px -2px #0E1119;\n",
    "}\n",
    "\n",

    ".container {\n",
    "\ttext-align: left;\n",
    "\toverflow: hidden;\n",
    "\twidth: 75%;\n",
    "\tmargin: 0 auto;\n",
    "\tdisplay: table;\n",
    "\tpadding: 0 0 7em 0;\n",
    "}\n",
    "\n",

    ".container td, .container th {\n",
    "\tpadding-bottom: 2%;\n",
    "\tpadding-top: 2%;\n",
    "\tpadding-left:2%;  \n",
    "}\n",
    "\n",

    "/* Background-color of the odd rows */\n",
    ".container tr:nth-child(odd) {\n",
    "\tbackground-color: #323C50;\n",
    "}\n",
    "\n",

    "/* Background-color of the even rows */\n",
    ".container tr:nth-child(even) {\n",
    "\tbackground-color: #2C3446;\n",
    "}\n",
    "\n",

    ".container th {\n",
    "\tbackground-color: #1F2739;\n",
    "}\n",
    "\n",

    ".container td:first-child {\n",
    "\tcolor: #FB667A;\n",
    "}\n",
    "\n",

    ".container tr:hover {\n",
    "\tbackground-color: #464A52;\n",
    "\t-webkit-box-shadow: 0 6px 6px -6px #0E1119;\n",
    "\t-moz-box-shadow: 0 6px 6px -6px #0E1119;\n",
    "\tbox-shadow: 0 6px 6px -6px #0E1119;\n",
    "}\n",
    "\n",

    ".container td:hover {\n",
    "\tbackground-color: #FFF842;\n",
    "\tcolor: #403E10;\n",
    "\tfont-weight: bold;\n",
    "\n",
      
    "\tbox-shadow: #7F7C21 -1px 1px, #7F7C21 -2px 2px, #7F7C21 -3px 3px, #7F7C21 -4px 4px, #7F7C21 -5px 5px, #7F7C21 -6px 6px;\n",
    "\ttransform: translate3d(6px, -6px, 0);\n",
    "\n",
      
    "\ttransition-delay: 0s;\n",
    "\ttransition-duration: 0.4s;\n",
    "\ttransition-property: all;\n",
    "\ttransition-timing-function: line;\n",
    "}\n",
    "\n",

    "@media (max-width: 800px) {\n",
    "\t.container td:nth-child(4),\n",
    "\t.container th:nth-child(4) {\n",
    "\t\tdisplay: none;\n",
    "\t}\n",
    "}\n"
  );

  user_file_data.close();

}

auto FileCSS::read_css_file_link() const -> const std::string& {
  return css_file_path;
}

auto FileCSS::create_css_file_data(std::fstream &user_file_data) const -> void{
  create_css_file(user_file_data);
}
