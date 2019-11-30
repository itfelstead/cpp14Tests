#include <iostream>

#include <variant>

// Variant access via Visitation
struct Visitor {
    void operator()(const std::string &s) const {
        std::cout << "string: " << s << std::endl;
    }
    void operator()(int n) const {
        std::cout << "int: " << n << std::endl; 
    }
    void operator()(float f) const {
        std::cout << "float: " << f << std::endl;
    }
};
struct ModVisitor {
    void operator()(std::string &s) const {
        s += " modified ";
    }
    void operator()(int n) const {
        n *= 10;
    }
    void operator()(float f) const {
        f = 2.2;
    }
};

int main()
{
    std::variant<std::string, int, float> myVariant;        // would construct variant as string (1sr member)
    std::variant<std::string, int, float> myVariant2{5};    // would construct as int

    // auto val = std::get<7>(myVariant2);      // COMPILE FAIL - index out of range

    std::cout << "Variant holds " << std::get<int>(myVariant2) << std::endl;
    std::cout << "Variant member #2 (pos 1) holds " << std::get<1>(myVariant2) << std::endl;
    // throws std::bad_variant_access is bad index

    std::cout << "current active index is " << myVariant2.index() << std::endl;
 
    std::cout << "get_if on wrong member = " << std::get_if<std::string>(&myVariant2) << std::endl;
    std::cout << "get_if on wrong member = " << std::get_if<0>(&myVariant2) << std::endl;

    std::get<int>(myVariant2) = 99;
    std::cout << "Variant holds " << std::get<int>(myVariant2) << std::endl;

    // Visitation
    std::visit( Visitor{}, myVariant2 );
    myVariant2 = "string active member";
    std::visit( ModVisitor{}, myVariant2 );
    std::visit( Visitor{}, myVariant2 );
    myVariant2 = 3.14f;
    std::visit( Visitor{}, myVariant2 );
}