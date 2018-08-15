#include <iostream>
#include <utility>
#include <unistd.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <sys/ioctl.h>
#include "color.hpp"

//Declarations
void displayLogo();
std::string getPrompt();
void feedbackMessage(const std::string &message, const std::string &color);
int getColumnWidth();
std::vector<std::string> getModule() {

int main(){
  
  displayLogo();
  //store command
  std::string command;
  
  do{ 
     
    std::cout << getPrompt();
    
    //read input
    std::getline(std::cin, command);

    //Break command into segments//////////////////////////
    std::istringstream iss(command);
    std::string sub;
    iss >> sub;
    std::string firstArg = sub;

    if(firstArg == "exit") break;
    if(firstArg == "logo") displayLogo();
    if(firstArg == "cd") {
      iss >> sub;
      chdir(sub.c_str());

    } else {
      
      if(firstArg == "ls") {
        feedbackMessage("Correct!", "green");
      } else {
        feedbackMessage("Incorrect, Try Again", "red");
      }
      
      system(command.c_str());
      
    }

    
  }while (command != "exit");

  //exit the program
  exit(1);
  
  return 0;
}

//Functions//
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

std::string getPrompt() {

  //get hostname from system
  char hostname[50];
  gethostname(hostname, 50);

  //get login name from system
  char loginName[20];
  cuserid(loginName);
  std::string prompt;
  prompt.append(fgColor::RED);
  prompt.append(loginName);
  prompt.append("@");
  prompt.append(hostname);
  prompt.append(fgColor::ORANGE);
  prompt.append(" ");
  prompt.append(get_current_dir_name());
  prompt.append(" $ ");
  prompt.append(fgColor::RESET);
  
  return prompt;
}

void feedbackMessage(const std::string &message, const std::string &color) {
  
  int margin = getColumnWidth() - 2;
  if (color == "green") std::cout << fgColor::GREEN;
  if (color == "red")  std::cout << fgColor::RED;

  // std::string checkmark = (color == "green")? "\u2714" : "\u2718";  
  // std::cout << checkmark << " " << message;
  
  //Contents of message
  for (int i = 0; i < (margin/2) - (message.size() + 2)/2; i ++){
    std::cout << "-";
  } 
  std::string checkmark = (color == "green")? "\u2714" : "\u2718";  
  std::cout << " " << checkmark << " " << message << " ";
  
  for (int i = 0; i < (margin/2) - (message.size() + 2)/2; i ++){
    std::cout << "-";
  } 
  std::cout << fgColor::RESET << std::endl;

}

int getColumnWidth() {
    //Grabs terminal height and width
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    return w.ws_col;

}


std::vector<std::string> getModule() {
  

  
}
