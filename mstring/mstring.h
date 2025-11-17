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

    const char *value() const;

    mstring &operator=(const mstring &other);

    mstring operator+(const mstring &other);

    mstring operator*(const int times);

    bool operator==(const mstring &other);

    bool operator!=(const mstring &other);

    char &operator[](const int index);

    friend std::ostream &operator<<(std::ostream &stream, const mstring &obj);
    friend std::istream &operator>>(std::istream &stream, mstring &obj);

private:
    char *str;
};

std::ostream &operator<<(std::ostream &stream, const mstring &obj);
std::istream &operator>>(std::istream &stream, const mstring &obj);