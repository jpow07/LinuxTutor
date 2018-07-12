#include <iostream>
#include <unistd.h>
#include <stdlib.h>

int main(){
  //create fork process
  pid_t pid = fork();
  //store command
  std::string command;
  int returnCode;

  while (std::cin >> command) {

    if (command == "exit")
      break;
    returnCode = system(command.c_str());
    
  }

  exit(1);
  
  return 0;
}
