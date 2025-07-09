#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Neuron {
    private:
        vector<double> weights;
        double bias;

        //sigmoid
        double sigmoid(double x) {
            return 1.0 / (1.0 + exp(-x));
        }

    public:
    //constructor init weights and bias
        Neuron(vector<double> w, double b) {
            weights = w;
            bias = b;
    }

    //forward pass computes output of neuron
    double activate(const vector<double>& inputs) {
        if (inputs.size() != weights.size()) {
            cerr << "Error: input and weight vector sizes do not match" << endl;
            return 0.0;
        }

        double z = 0.0;
            for(size_t i = 0; i < inputs.size(); i++) {
                z += inputs[i] * weights[i];
            }
            z += bias;
    return sigmoid(z);
    }
};

int main() {
    vector<double> weights = {0.4, 0.6, 0.1};
    double bias = -1.5;
    Neuron n(weights, bias);

    //test input
    vector<double> input = {3, 1, 2};

    //fire the neuron
    double output = n.activate(input);
    cout << "Neron Output: " << output << endl;

    return 0;
}
