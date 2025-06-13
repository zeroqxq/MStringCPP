#include <iostream>
#include "mstring/mstring.h"

int main(int argc, char* argv[]){
    mstring str("test"); // Объект класса modern string c++ (mstring)
    std::cout << str.length() << std::endl; // Длина строки до \0
    std::cout << str.value() << std::endl; // Значение строки
    mstring str2 = "Hello"; // Обьъект класса modern string c++ (mstring)
    std::cout << str2.value() << std::endl; 
    str = str2; // Присваеваем объекту str значение str2
    std::cout << str.value() << std::endl; 
    
    mstring str3 = "Hello";
    mstring str4 = "World";
    mstring str5 = str3 + str4; // Сложение строк
    std::cout << str5.value() << std::endl; 
    return 0;   

    
    
    
}