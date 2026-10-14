#pragma once

#include <vector>

// Meglévő aktivációk...
float relu(float x);
float relu_derivative(float x);
float sigmoid(float x);
float sigmoid_derivative(float x);
float tanh_act(float x);
float tanh_derivative(float x);

// Binary Cross-Entropy Loss
// Egyetlen mintára (single sample loss)
float binary_cross_entropy(float y_true, float y_pred);

// A teljes adathalmazra átlagolva (mean loss)
float binary_cross_entropy_loss(const std::vector<float>& y_true, const std::vector<float>& y_pred);