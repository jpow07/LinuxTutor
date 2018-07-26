#include <string>

namespace fgColor {
  //38;5; is the prefix for 256-color support for the foreground
  //48;5; is the prefix for 256-color support for the background
  std::string RESET    = "\e[0m";
  std::string BLACK    = "\e[38;5;16m";
  std::string ORANGE   = "\e[38;5;208m";
  std::string BLUE     = "\e[38;5;19m";
  std::string RED      = "\e[38;5;1m";
  std::string GREEN    = "\e[38;5;2m";
  std::string GREY     = "\e[38;5;7m";
  std::string WHITE    = "\e[38;5;231m";

}

namespace bgColor {
  //48;5; is the prefix for 256-color support for the background
  std::string RESET    = "\e[0m";
  std::string BLACK    = "\e[48;5;16m";
  std::string ORANGE   = "\e[48;5;208m";
  std::string BLUE     = "\e[48;5;19m";
  std::string RED      = "\e[48;5;1m";
  std::string GREEN    = "\e[48;5;2m";
  std::string GREY     = "\e[48;5;7m";
  std::string WHITE    = "\e[48;5;231m";
}
