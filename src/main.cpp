#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  while(true) { 
    std::cout << "$ ";
  
    std::string user_input;
    std::getline(std::cin, user_input);
    std::stringstream ss(user_input);

    // std::string token;
    // while (std::getline(ss, token, ' ')) {
    //   if (token == "exit") {
    //     return 0;
    //   }
    //   else if (token == "echo") {
    //     std::cout << "echo" << std::endl;
    //   }
    //   else {
    //     std::cout << token << ": command not found" << std::endl;
    //   }
    // }

    std::string command = user_input.substr(0, user_input.find(" "));
    if (command == "exit") {
      return 0;
    }
    else if (command == "echo") {
      std::cout << user_input.substr(5) << std::endl;
    }
    else {
      std::cout << user_input << ": command not found" << std::endl;
    }
  }
}
