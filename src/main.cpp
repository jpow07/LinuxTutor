#include <iostream>
#include <utility>
#include <unistd.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <sys/ioctl.h>
#include "color.hpp"

void displayLogo();
void feedbackMessage(const std::string &message, const std::string &color);
int getColumnWidth();

int main(){

  //  printf ("lines %d\n", w.ws_row);
  //  printf ("columns %d\n", w.ws_col); 
    
  displayLogo();

  //get hostname from system
  char hostname[100];
  gethostname(hostname, 100);

  //get login name from system
  char loginName[100];
  cuserid(loginName);

  //store command
  std::string command;
  std::vector<std::string> substr;

  do{ 
     
      
    //Dispay Prompt
    std::cout << fgColor::RED << loginName
              << fgColor::GREEN << "@" << hostname << " "
              << fgColor::WHITE << get_current_dir_name()
              << fgColor::GREY << " $ ";
    
    //read input
    std::getline(std::cin, command);

    //Break command into segments//////////////////////////
    std::istringstream iss(command);
    std::string sub;
    iss >> sub;
    std::string firstArg = sub;
    
    std::fflush;
    

    if(firstArg == "exit") break;
    if(firstArg == "cd") {
      iss >> sub;
      chdir(sub.c_str());

    } else {
      
      if(firstArg == "ls") {
        feedbackMessage("Great Work", "green");
      } else {
        feedbackMessage("Try Again", "red");
      }
      
      system(command.c_str());

    }

    
  }while (command != "exit");

  //exit the program
  exit(1);
  
  return 0;
}

void displayLogo() {
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
}

void feedbackMessage(const std::string &message, const std::string &color) {
  
  int margin = getColumnWidth()/2;
  if (color == "green") std::cout << bgColor::GREEN;
  if (color == "red")  std::cout << bgColor::RED;
  
  for (int i = 0; i < margin - message.size(); i++)
    std::cout << " ";
  
  std::cout << message;
  
  for (int i = 0; i < margin; i++)
    std::cout << " ";
  
  std::cout << bgColor::RESET << std::endl;

}
int getColumnWidth() {
    //Grabs terminal height and width
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    return w.ws_col;

}
