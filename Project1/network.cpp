#include "Header.h"
#include "NNHelperFunctions.h"

class network {
	std::vector<int> nwlayers;
	std::vector<int> biases;
	std::vector<int> weights;
	int nlayers; //number of layers in the network

	network(std::vector<int> &layers) {
		nwlayers = layers;
		nlayers = layers.size();
	}

	void SGD (int x, int y){

		
	}

	void backprop() {

	}

	void update (){

	}

	void feedforward() {

	}


	std::vector<double> sigmoid(std::vector<double> &z) {
		//This function applies sigmoid neuron calcuations given a vector of z values.
		std::vector<double> output(z.size(), 0); // This vector will hold the function output values

		for (int i = 0; i < z.size();i++) {
			output.at(i) = 1.0 / (1.0 + exp(z[i]));
		}

		return output;
	}

	std::vector<double> dsigmoid(std::vector<double> &z) {
		//This is the derivative of the sigmoid function 
		std::vector<double> output(z.size(), 0);

		for (int i = 0; i < z.size(); i++) {
			output.at(i) = (1.0 / (1.0 + exp(z[i]))) / (1 - (1.0 / (1.0 + exp(z[i]))));
		}

		return output;
	}
	
	void printLayers() {
		std::cout << nwlayers.size();
	}
};

