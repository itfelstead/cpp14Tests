#include <iostream>

// In C++17 CTAD means we don't need to 
template<typename T> class MyClass
{
public:
    MyClass(const T &t) {
        std::cout << "MyClass(" << t << ")" << std::endl;
    }
};

// Custom CTAD
MyClass(const char *) -> MyClass<std::string>;

int main()
{
    MyClass<int> cpp11{ 123 };  // prior to C++17 we'd need to specify the typename

    MyClass cpp17{ 123 };       // in C++17 it can be deduced (need -std=c++17)

    MyClass custom{ "compiler would normally use const char *" };
     
    return 0;
}