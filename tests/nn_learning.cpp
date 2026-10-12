#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include "activations.hpp"
#include "neuron.hpp"

int main() {
    std::vector<float> inputs  = {2.0f, 3.0f, 4.0f};
    std::vector<float> weights = {0.5f, 0.2f, 0.8f};
    float bias = 1.0f;

    Neuron n1(weights, bias);

    float z = n1.forward(inputs);

    std::cout << "Neuron sum (z): " << z << std::endl;

    return 0;
}