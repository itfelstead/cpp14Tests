#include <iostream>

// Common Compiler Attributes


// Attribute: [[depricated]]
//
// in g++;
//      warning: ‘depricated’ attribute directive ignored [-Wattributes]
[[deprecated("avoid use of this function")]]
void AnOldFunction(int x)
{
    std::cout << "Called but warned" << std::endl;
}

class [[deprecated("avoid use of this class")]] AnOldClass
{
public:
    void Dump() {
        std::cout << "empty" << std::endl;
    }
};

// Attribute: [[nodiscard]]
// Note: can also use at class level to apply to all member functions
[[nodiscard]] int *AllocateMemory(int size) 
{
    return new int[size];
}

int main()
{
    // (deprecated)
    // g++;
    //      warning: ‘void AnOldFunction(int)’ is deprecated: avoid use of this function [-Wdeprecated-declarations]
    AnOldFunction(1);
    
    // g++;
    //      warning: ‘AnOldClass’ is deprecated: avoid use of this class [-Wdeprecated-declarations]
    AnOldClass c;
    c.Dump();

    // (nodiscard)
    //
    int *test = AllocateMemory(1);
    delete[] test;
    test = nullptr;
    // g++;
    //       warning: ignoring return value of ‘int* AllocateMemory(int)’, declared with attribute nodiscard [-Wunused-result]
    AllocateMemory(2);
}