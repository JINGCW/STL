#include <iostream>
#include <string>

using namespace std;

void say_hello()
{
#ifdef IS_INTEL_CXX_COMPILER
    cout<<"hello intel compiler."<<endl;
#elif IS_GNU_CXX_COMPILER
    cout<<"hello gnu compiler."<<endl;
#elif IS_PGI_CXX_COMPILER
    cout<<"hello pgi compiler."<<endl;
#elif IS_MSVC_CXX_COMPILER
    cout<<"hello msvc compiler."<<endl;
#else
    cout << "unknown compiler." << endl;
#endif
}

int main(int argc, char **argv)
{
    say_hello();
    cout << "compiler name is: " << COMPILER_NAME << endl;
    return 0;
}
