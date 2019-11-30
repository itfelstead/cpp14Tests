#include <iostream>
#include <optional>

std::optional<std::string> SomeFunction( bool doSomething )
{
    if( doSomething )
    {
        return "something";
    }
    else
    {
        return std::nullopt;
    }
}

int main()
{
    std::optional<int> myValue{5};
    // could have also left type out thanks to compile time argument type deduction
    //   std::optional myValue{5}; 
    // or
    //   auto myValue = std::make_optional(5);

    if(myValue)     // check via bool operator
    {
        std::cout << "Got value " << *myValue << std::endl;
    }
    if(myValue.has_value())
    {
        std::cout << "Got value " << myValue.value() << std::endl;
    }

    auto t1 = SomeFunction(true);
    std::cout << "t1 = " << t1.value_or("didn't get anything") << std::endl;

    auto t2 = SomeFunction(false);
    std::cout << "t2 = " << t2.value_or("didn't get anything") << std::endl;

    return 0;
}