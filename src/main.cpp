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
    std::cout << "username@hostname " << " $ ";

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
