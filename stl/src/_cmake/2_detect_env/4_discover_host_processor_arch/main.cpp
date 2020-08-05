#include <string>
#include <iostream>

using namespace std;


#define stringify(x) #x
#define to_string(x) stringify(x)

string say_hello()
{
    string arch_info(to_string(ARCHITECTURE));
    arch_info += " architecture. ";
#ifdef IS_32_BIT_ARCH
    return arch_info+" compile with 32bit architecture.";
#elif IS_64_BIT_ARCH
    return arch_info+" compile with 64bit architecture. ";
#else
    return arch_info + "neither 32 or 64bit...";
#endif
}

int main(int argc, char **argv)
{
    cout << say_hello() << endl;
    return 0;
}
