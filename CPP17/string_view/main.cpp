#include <iostream>
#include <string_view>

using std::cout;
using std::endl;

int main()
{
    using namespace std::string_view_literals;

    std::string s1{"a std::string "};
    std::string_view t1 = s1;
    cout << "t1 (" << t1.length() << " characters): " << t1 << endl;

    // Danger - string_view supports null embedded strings (and may lack null terminator)
    // Note: has to use sv here, otherwise the string would only be stored up to \0
    std::string_view t2 = "Won't print\0 this"sv;

    cout << "t2 supports embedded null, so cause issues with cstring functions: " << t2 << endl;
    // note: .data won't print after \0
    cout << "t2 supports embedded null, so cause issues with cstring functions: " << t2.data() << endl;

    // Access chars
    cout << "char 5 is " << t2.at(4) << endl;   // .at() will throw if you use out of range index
    cout << "char 5 is " << t2[4] << endl;      // [] is undefined if out of range index

    // Search via find
    auto idx = t2.find("thi");
    if( idx == std::string::npos )
    {
        cout << "failed to find 'thi'... Did your string get truncated when you initialises string_view?" << endl;
    }
    else
    {
        cout << "found 'thi' as position " << idx << endl;
    }

    // .remove_prefix(#) - remove # chars from the string (moves pointer)
    // .remove_suffix(#) - remove # chars from the string end (reduced length)
    // .substr(pox, len) - retuns a new string view
    // don't use data() to print string, as will pront whole thing
    std::string_view t3 = "I'm not a pheasant plucker";
    t3.remove_prefix(10);
    t3.remove_suffix(8);
    cout << "t3 is " << t3 << endl;
    auto t4 = t3.substr(0,2);
    cout << "t4 is " << t4 << ", t4 data() is " << t4.data() << endl;
}