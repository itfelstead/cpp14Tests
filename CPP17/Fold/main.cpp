#include <iostream>


// C++17 unary right fold
template<typename...TArgs> 
auto DoSum( TArgs...myArgs) {
    return (myArgs + ...);      // apply operator '+' to pack 'myArgs'
}

// C++17 binary right fold
template<typename...TArgs> 
auto DoBRFSum( TArgs...myArgs) {
    return (myArgs + ... + 0);      // apply operator '+' to pack 'myArgs'
}

int main()
{
    auto r1 = DoSum( 1,2,3,4,5);
    std::cout << "DoSum( 1,2,3,4,5) = " << r1 << std::endl;
    // auto fails = DoSum();

    auto r2 = DoBRFSum( 1,2,3,4,5);
    std::cout << "DoBRFSum( 1,2,3,4,5) = " << r2 << std::endl;

    // binary folds allow us to have no arguments too
    auto r3 = DoBRFSum();
    std::cout << "DoBRFSum( ) = " << r3 << std::endl;

    return 0;
}