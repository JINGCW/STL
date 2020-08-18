#ifndef STANDARD_TEMPLATE_LIBRARIES_REGRESSION_H
#define STANDARD_TEMPLATE_LIBRARIES_REGRESSION_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
//#include <pybind11/stl.h>
#include <torch/torch.h>

using namespace std;

#define POLY_DEGREE 4

// Builds features i.e. a matrix with columns [x, x^2, x^3, x^4].
torch::Tensor make_features(torch::Tensor x)
{
    x = x.unsqueeze(1);
    vector<torch::Tensor> xs;
    for (auto i = 0; i < POLY_DEGREE; ++i)
    {
        xs.push_back(x.pow(i + 1));
    }
    return torch::cat(xs, 1);
}

// Approximated function.
torch::Tensor f(const torch::Tensor &x, const torch::Tensor &w,
                const torch::Tensor &b)
{
    return x.mm(w) + b.item();
}

string poly_desc(const torch::Tensor &w, const torch::Tensor &b)
{
    auto size = w.size(0);
    ostringstream stream;

    stream << "y = ";
    for (auto i = 0; i < size; ++i)
        stream << w[i].item<float>() << " x^" << size - 1 << " ";
    stream << " + " << b[0].item<float>();

    return stream.str();
}

#endif //STANDARD_TEMPLATE_LIBRARIES_REGRESSION_H
