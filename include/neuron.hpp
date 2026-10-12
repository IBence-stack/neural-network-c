#pragma once
#include <vector>


class Neuron {
    private:
        std::vector<float> weights;
        float bias;
    public:
        Neuron(const std::vector<float>& inital_weights, float initial_bias);
        float forward(const std::vector<float>& inputs) const;
};
