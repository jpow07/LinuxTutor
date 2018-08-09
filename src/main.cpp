#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <fstream>
#include "color.hpp"


int main(){

  //Print Logo read from file
  std::ifstream istr;
  istr.open("locale/en/logo.txt");
  std::string output;
  while (!istr.eof()) {
    
    std::getline(istr, output);
    std::cout << fgColor::ORANGE << output << std::endl;
  }

  //Reset the color values
  std::cout << fgColor::RESET << std::endl;
    
  //get hostname from system
  char hostname[100];
  gethostname(hostname, 100);

  //get login name from system
  char loginName[100];
  cuserid(loginName);

  //store command
  std::string command;
   
  do{
  
    
    //Print prompt
    std::cout << fgColor::RED << loginName << fgColor::GREEN << "@" << hostname << " " << fgColor::WHITE << get_current_dir_name() << fgColor::GREY << " $ ";
    
    //read input
    std::getline(std::cin, command);
    
    if(command == "cd") {
      std::cin >> command;
      chdir(command.c_str());
    }else {
      system(command.c_str());
      std::string addMargin = "\t\t\t\t\t";
      if(command == "ls")
      std::cout << bgColor::GREEN << addMargin << "Great Work" << addMargin << bgColor::RESET << std::endl;
      else
      std::cout << bgColor::RED << addMargin << "Try Again" << addMargin << bgColor::RESET << std::endl;
    }

    
  }while (command != "exit");

  //exit the program
  exit(1);
  
  return 0;
}
