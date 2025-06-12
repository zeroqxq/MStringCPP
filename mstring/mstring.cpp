#include "mstring.h"
#include "include/stdafx.h"


mstring::mstring(const char *str){
    size_t len = length(str);
    this->str = new char[len + 1];
    for (int i = 0 ; i < len ; ++i){
        this->str[i] = str[i];
    }
    this->str[len] = '\0';
}

mstring::mstring(){
    this->str = nullptr;
}

size_t mstring::length(const char *str) {
    size_t length = 0;
    while (str[length] != '\0') {      
        length++;
    }
    return length;
}

size_t mstring::length() {
    return length(this->str);
}

mstring::~mstring(){
    delete [] this->str;
}

char* mstring::value(){
    return this->str;
}