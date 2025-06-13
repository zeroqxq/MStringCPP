// * Modern C++ String Class
// * Author: zeroqxq

class mstring {
    public:
        mstring(const char *str);
        mstring();
        mstring(const mstring& other);
        ~mstring();
        size_t length(const char *str);
        size_t length();
        char* value();
        mstring& operator =(const mstring& other);
        mstring operator +(const mstring& other);

    private:
        char *str;

};