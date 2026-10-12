#include "activations.hpp"
#include <algorithm>

float relu(float x) {
    return std::max(0.0f, x);
}

float relu_derivative(float x) {
    return (x > 0.0f) ? 1.0f : 0.0f;
}