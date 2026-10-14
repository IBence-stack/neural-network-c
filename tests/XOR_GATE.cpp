#include <iostream>
#include <vector>
#include <iomanip>
#include "activations.hpp"
#include "neuron.hpp"
#include <cstdlib>
#include "layer.hpp"
#include <algorithm>

/*Xor logic operation neural network*/
int main() {
    std::srand(42);

    // XOR adatok: 2 bemenet, 1 elvárt kimenet
    std::vector<std::vector<float>> X = {
        {0.0f, 0.0f},
        {0.0f, 1.0f},
        {1.0f, 0.0f},
        {1.0f, 1.0f}
    };
    std::vector<float> y = {0.0f, 1.0f, 1.0f, 0.0f};


    Layer hidden_layer(4, 2);
    Layer output_layer(1, 4);

    std::cout << "Rejtett réteg felépítése:\n";
    hidden_layer.print_info();

    std::cout << "\nKimeneti réteg felépítése:\n";
    output_layer.print_info();

    std::cout << "\n--- Forward Pass ---\n";
    std::vector<float> predictions;
    predictions.reserve(X.size());
    std::vector<float> a2;
    a2.reserve(X.size());
    

    std::cout << "--- Forward Pass & Becslések ---\n";
    for (size_t i = 0; i < X.size(); ++i) {
        // Rejtett réteg (tanh) -> Kimeneti réteg (sigmoid)
        std::vector<float> a1 = hidden_layer.forward(X[i], "tanh");
        std::vector<float> out = output_layer.forward(a1, "sigmoid");

        predictions.push_back(out[0]);

        std::cout << "Input: [" << X[i][0] << ", " << X[i][1] << "] "
                  << "| Elvárt: " << y[i] 
                  << " | Becslés: " << out[0] << "\n";
    }

    float loss = binary_cross_entropy_loss(y, predictions);
    std::cout << "\nÖsszesített Binary Cross-Entropy Loss: " << loss << "\n";


    std::vector<float> grad(predictions.size());

    std::transform(
        predictions.begin(), predictions.end(), 
        y.begin(),                              
        grad.begin(),                           
        [](float p, float target) { return p - target; } 
    );  

    for (size_t i = 0; i < grad.size(); ++i)
    {
         std::cout << grad[i] << "\n";
    }
    
    return 0;
}