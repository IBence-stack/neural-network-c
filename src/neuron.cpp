#include "neuron.hpp"
#include <numeric>

Neuron::Neuron(const std::vector<float>& initial_weights, float initial_bias)
    : weights(initial_weights), bias(initial_bias) {}

float Neuron::forward(const std::vector<float>& inputs) const {
    float dot_product = std::inner_product(
        weights.begin(), weights.end(), // first range: weights
        inputs.begin(),                 // second range: inputs
        0.0f                            // initial accumulator value
    );

    return dot_product + bias;
}