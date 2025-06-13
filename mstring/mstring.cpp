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

mstring& mstring::operator =(const mstring& other){
    if (this->str != nullptr){
        delete[] str;
    }
    int len = length(other.str);
    this->str = new char[len + 1];
    for(int i = 0 ; i < len ; ++i){
        this->str[i] = other.str[i];
    }
    this->str[len] = '\0';
    return *this;
}


mstring::mstring(const mstring& other){
    int len = length(other.str);
    this->str = new char[len + 1];
    for(int i = 0 ; i < len ; i++){
        this->str[i] = other.str[i];
    }
    this->str[len] = '\0';
}

mstring mstring::operator+(const mstring& other){
    mstring newStr;
    newStr.str = new char[length(this->str) + length(other.str) + 1];
    int i = 0;
    for( ; i < length(this->str); i++) {
        newStr.str[i] = this->str[i];
    }
    for (int j = 0; j < length(other.str); i++,j++){
        newStr.str[i] = other.str[j];
    }
    newStr.str[length(this->str) + length(other.str)] = '\0';
    return newStr;

}
