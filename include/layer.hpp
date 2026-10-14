#pragma once

#include <vector>
#include <string>
#include "neuron.hpp"

class Layer {
private:
    std::vector<Neuron> neurons;

public:
    // Konstruktor: num_neurons darab neuront hoz létre, mindegyik num_inputs súllyal
    Layer(size_t num_neurons, size_t num_inputs);

    // Forward pass: kiszámítja minden neuron kimenetét a megadott bemenetre
    // activation_type: pl. "relu", "sigmoid", vagy "none"
    std::vector<float> forward(const std::vector<float>& inputs, const std::string& activation = "none") const;

    // Diagnosztika: kiírja a réteg összes neuronjának állapotát
    void print_info() const;
};