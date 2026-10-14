#include "activations.hpp"
#include <cmath>
#include <algorithm>

float relu(float x) {
    return std::max(0.0f, x);
}

float relu_derivative(float x) {
    return (x > 0.0f) ? 1.0f : 0.0f;
}

float sigmoid(float x) {
    return 1.0f / (1.0f + std::exp(-x));
}

float sigmoid_derivative(float x) {
    float s = sigmoid(x);
    return s * (1.0f - s);
}

float tanh_act(float x) {
    return std::tanh(x);
}

float tanh_derivative(float x) {
    float t = std::tanh(x);
    return 1.0f - (t * t);
}

float binary_cross_entropy(float y_true, float y_pred) {
    const float epsilon = 1e-7f;
    float p = std::clamp(y_pred, epsilon, 1.0f - epsilon);

    return -(y_true * std::log(p) + (1.0f - y_true) * std::log(1.0f - p));
}

float binary_cross_entropy_loss(const std::vector<float>& y_true, const std::vector<float>& y_pred) {
    float total_loss = 0.0f;
    size_t n = y_true.size();

    for (size_t i = 0; i < n; ++i) {
        total_loss += binary_cross_entropy(y_true[i], y_pred[i]);
    }

    return total_loss / static_cast<float>(n); // -mean(...)
}