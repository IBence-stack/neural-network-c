#include "neuron.hpp"
#include <cstdlib>
#include <iostream>

Neuron::Neuron(const std::vector<float>& initial_weights, float initial_bias)
    : weights(initial_weights), bias(initial_bias) {}

Neuron::Neuron(size_t num_inputs) : bias(0.0f) {
    weights.resize(num_inputs);
    for (size_t i = 0; i < num_inputs; ++i) {
        float r = static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX);
        weights[i] = r * 2.0f - 1.0f; // [-1.0, 1.0] tartomány
    }
}

float Neuron::forward(const std::vector<float>& inputs) const {
    float dot_product = 0.0f;
    for (size_t i = 0; i < weights.size(); ++i) {
        dot_product += inputs[i] * weights[i];
    }
    return dot_product + bias;
}

void Neuron::print_info() const {
    std::cout << "Neuron [Weights: (";
    for (size_t i = 0; i < weights.size(); ++i) {
        std::cout << weights[i];
        if (i + 1 < weights.size()) {
            std::cout << ", ";
        }
    }
    std::cout << ") | Bias: " << bias << "]\n";
}