#include <iostream>
#include "mstring/mstring.h"

int main(int argc, char* argv[]){
    mstring str("test"); // Объект класса modern string c++ (mstring)
    std::cout << str.length() << std::endl; // Длина строки до \0
    std::cout << str.value() << std::endl; // Значение строки
    return 0;   
}