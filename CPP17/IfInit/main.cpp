#include <iostream>
#include <fstream>

int TestSomething()
{
    return 1;
}

int main()
{
    // C++17 - allows initialization inside the if statement
    // g++; compile with -std=c++17
    if( int x = TestSomething(); x > 0 )
    {
        std::cout << x << " is > 0" << std::endl;
    }
    else
    {
        std::cout << x << " is <= 0" << std::endl;
    }

    // error: ‘x’ was not declared in this scope
    //std::cout << x << " is not accessible!" << std::endl;

    int errorCode = 5;
    switch( std::ofstream file("test.txt"); errorCode )
    {
        case 1:
            file << "was 1" << std::endl;
            break;
        case 5:
            file << "was 5" << std::endl;
            break;
        default:
            file << "was other" << std::endl;
    }
    // file not accessible here

    return 0; 
}