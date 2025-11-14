// * Modern C++ String Class
// * Author: zeroqxq

#include "include/include.h"

class mstring
{
public:
    mstring(const char *str);

    mstring();

    mstring(const mstring &other);

    mstring(mstring &&other);

    ~mstring();

    size_t length(const char *str);

    size_t length();

    char *value();

    mstring &operator=(const mstring &other);

    mstring operator+(const mstring &other);

    mstring operator*(const int times);

    bool operator==(const mstring &other);

    bool operator!=(const mstring &other);

    char &operator[](const int index);

private:
    char *str;
};