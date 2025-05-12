// Learning C++ 
// Challenge 01_03
// Console Interaction, by Eduardo Corpeño 

#include <iostream>
#include <string>

int main(){
    std::cout << "Please enter your name: " << std::flush;

    std::string str;
    std::cin >> str;
    std::cout << "Hello there, " << str << "!" << std::endl;

    std::cout << std::endl << std::endl;
    return (0);
}
