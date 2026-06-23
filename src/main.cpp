#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

int main() {
  std::string builtins[3]{"echo", "exit", "type"};

  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  while (true) {
    std::cout << "$ ";

    std::string user_input;
    std::getline(std::cin, user_input);
    std::stringstream ss(user_input);

    std::string command;
    std::getline(ss, command, ' ');

    std::string token;
    if (command == "exit") {
      return 0;
    } else if (command == "type") {
      std::getline(ss, token, ' ');
      if (std::find(std::begin(builtins), std::end(builtins), token) !=
          std::end(builtins)) {
        std::cout << token << " is a shell builtin" << std::endl;
      } else {
        std::cout << token << ": command not found" << std::endl;
      }
    } else if (command == "echo") {
      std::cout << user_input.substr(5) << std::endl;
    } else {
      std::cout << user_input << ": command not found" << std::endl;
    }

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

    // std::string command = user_input.substr(0, user_input.find(" "));
    // if (command == "exit") {
    //   return 0;
    // } else if (command == "type") {

    // } else if (command == "echo") {
    //   std::cout << user_input.substr(5) << std::endl;
    // } else {
    //   std::cout << user_input << ": command not found" << std::endl;
    // }
  }
}
