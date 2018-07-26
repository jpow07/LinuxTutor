#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include "color.hpp"


int main(){
  //store command
  std::string command;
  int returnCode;

  std::cout << "User ID: " << getuid() << std::endl;
  std::cout << "Process ID: " << getpid() << std::endl;

  do{
  
    
    //Print prompt
    std::cout << fgColor::ORANGE << "username" << fgColor::GREEN << "@hostname " << fgColor::RED << get_current_dir_name() << fgColor::GREY << " $ ";
    
    //read input
    std::cin >> command;

    if(command == "cd") {
      std::cin >> command;
      chdir(command.c_str());
    }else {
      system(command.c_str());
    }

    
  }while (command != "exit");

  //exit the program
  exit(1);
  
  return 0;
}
