#pragma once

#include <vector>

class Neuron {
private:
    std::vector<float> weights;
    float bias;

public:
    // Konstruktorok
    Neuron(const std::vector<float>& initial_weights, float initial_bias);
    explicit Neuron(size_t num_inputs);

    // Forward pass
    float forward(const std::vector<float>& inputs) const;

    // Diagnosztika / kiíratás
    void print_info() const;
};