#include "Header.h"

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

	double sigmoid(std::vector<double> z) {
		return 1/(1+exp
	}
	
	void printLayers() {
		std::cout << nwlayers.size();
	}
};