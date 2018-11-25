#include "Header.h"
#include "NNHelperFunctions.h"

class network {
	std::vector<int> nwlayers;
	int nlayers,biases,weights;

public:
	network(std::vector<int> &layers) {
		nwlayers = layers;
		nlayers = layers.size();
	}

	void SGD (){
		
	}



	std::vector<double> sigmoid(std::vector<double> &z) {
		//This function should be quite self-explainatory
		std::vector<double> output(z.size(), 0); // This vector will hold the function output values

		for (int i = 0; i < z.size();i++) {
			output.at(i) = 1.0 / (1.0 + exp(z[i]));
		}

		return output;
	}

	std::vector<double> dsigmoid(std::vector<double> &z) {
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