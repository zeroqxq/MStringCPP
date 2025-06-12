// * Modern C++ String Class
// * Author: zeroqxq

class mstring {
    public:

    mstring(const char *str);
    mstring();
    ~mstring();
    size_t length(const char *str);
    size_t length();
    char* value();

    private:
    char *str;

};