#include <iostream>
#include <any>

int main()
{
    std::any t1 = 123;  // t1 holds an int
    try {
        std::cout << "t1 as int: " << std::any_cast<int>( t1 ) << std::endl;
        std::cout << "t1 as string: " << std::any_cast<std::string>( t1 ) << std::endl;
    }
    catch( std::exception &ex )
    {
        std::cout << "Hit exception: " << ex.what() << std::endl;
    }
    t1.reset();

    if( !t1.has_value() )
    {
        std::cout << "t1 has_value is false after reset()" << std::endl;
    }

    // t1 = "now holds string";    // would hold a const char *
    t1 = std::string{"now holds string"};
    if( t1.has_value() )
    {
        std::cout << "t1 has_value is true after assign, and is type " << t1.type().name() << std::endl;

        if( t1.type() == typeid(std::string) ) 
        {
            std::cout << " t1 now holds " << std::any_cast<std::string>(t1) << std::endl;
        }
    }
}