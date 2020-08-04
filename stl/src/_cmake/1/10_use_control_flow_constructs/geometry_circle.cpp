#include "geometry_circle.h"

#include <cmath>

using namespace std;

namespace geometry::area
{
    double circle(double radius)
    {
        return pow(radius, 2) * 3.14;
    }
}
