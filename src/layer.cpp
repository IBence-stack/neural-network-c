#include "layer.hpp"
#include "activations.hpp"
#include <iostream>

Layer::Layer(size_t num_neurons, size_t num_inputs) {
    neurons.reserve(num_neurons);
    for (size_t i = 0; i < num_neurons; ++i) {
        neurons.emplace_back(num_inputs); // Meghívja a Neuron(num_inputs) véletlen konstruktort
    }
}

std::vector<float> Layer::forward(const std::vector<float>& inputs, const std::string& activation) const {
    std::vector<float> outputs;
    outputs.reserve(neurons.size());

    for (const auto& neuron : neurons) {
        float z = neuron.forward(inputs);

        if (activation == "relu") {
            outputs.push_back(relu(z));
        } else if (activation == "sigmoid") {
            outputs.push_back(sigmoid(z));
        } else if (activation == "tanh") {
            outputs.push_back(tanh_act(z)); 
        } else {
            outputs.push_back(z);
        }
    }

    return outputs;
}

void Layer::print_info() const {
    std::cout << "--- Layer (" << neurons.size() << " neurons) ---\n";
    for (size_t i = 0; i < neurons.size(); ++i) {
        std::cout << "  #" << i << " ";
        neurons[i].print_info();
    }
}