#include <iostream>
#include <unistd.h>
#include <stdlib.h>

int main(){
  //create fork process
  //pid_t pid = fork();
  
  //store command
  std::string command;
  int returnCode;

  do{
  
    
    //Print prompt
    std::cout << "\e[34musername\e[0m\e[33m@\e[0m\e[31mhostname \e[0m " << get_current_dir_name() << " $ ";
    
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

  

  exit(1);
  
  return 0;
}
