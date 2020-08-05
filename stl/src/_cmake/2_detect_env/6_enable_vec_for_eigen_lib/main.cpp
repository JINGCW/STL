#include <chrono>
#include <iostream>
#include <Eigen/Dense>

using namespace std;

EIGEN_DONT_INLINE double eigen_dot(Eigen::VectorXd &va, Eigen::VectorXd &vb)
{
    return va.dot(vb);
}

int main(int argc, char **argv)
{
    int len = 100, repeat = 10000;
    Eigen::VectorXd va = Eigen::VectorXd::Random(len);
    Eigen::VectorXd vb = Eigen::VectorXd::Random(len);

    double res;
    auto start = chrono::system_clock::now();
    for (auto i = 0; i < repeat; ++i)
    {
        res = eigen_dot(va, vb);
    }
    auto end = chrono::system_clock::now();
    auto elapsed_seconds = end - start;

    cout << "res: " << res << endl;
    cout << "elapsed_seconds: " << elapsed_seconds.count() << endl;

    return EXIT_SUCCESS;
}
