#include "message.h"
#include "geometry_circle.h"

using namespace geometry::area;

int main(int argc, char **argv)
{
    message _msg1("hello world");
    cout << _msg1 << endl;
    cout << circle(4) << endl;

    return EXIT_SUCCESS;
}
