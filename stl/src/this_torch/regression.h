#ifndef STANDARD_TEMPLATE_LIBRARIES_REGRESSION_H
#define STANDARD_TEMPLATE_LIBRARIES_REGRESSION_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
//#include <pybind11/stl.h>
//#include <Python.h>
#include <torch/torch.h>

namespace this_torch
{
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
        return torch::cat(xs, 1);//32,4
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

// Builds a batch i.e. (x, f(x)) pair.
    pair<torch::Tensor, torch::Tensor> make_batch(
            const torch::Tensor &w,
            const torch::Tensor &b, int64_t batch_size = 32)
    {
        auto _random = torch::randn({batch_size});
        auto _x = make_features(_random);
        auto _y = f(_x, w, b);

        return make_pair(_x, _y);
    }

    void test_regression()
    {
        auto w = torch::randn({POLY_DEGREE, 1}) * 5;
        auto b = torch::randn({1}) * 5;
        //define the model and optimizer
        auto fc = torch::nn::Linear(w.size(0), 1);
        torch::optim::SGD optimizer(fc->parameters(), .1);

        float loss = 0;
        int64_t batch_idx = 0;
        while (++batch_idx)
        {
            //get data
            torch::Tensor batch_x, batch_y;
            tie(batch_x, batch_y) = make_batch(w, b);
        }
    }
}//@namespace this_torch

#endif //STANDARD_TEMPLATE_LIBRARIES_REGRESSION_H
