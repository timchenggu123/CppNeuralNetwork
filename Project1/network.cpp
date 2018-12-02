#include "Header.h"
#include "NNHelperFunctions.h"
#include "network.h"

network::network(std::vector<std::vector<int>> &layers, std::vector<std::vector<double>> &data, std::vector<double> &values ) {
	x = data;
	y = values;
	nwlayers = layers;
	nlayers = layers.size();

	//initializing biases 
	biases.resize(layers.size() - 1); // -1 here because the first layer is an input layer
	for (int i = 1; i < (layers.size()); i++) { // index starts at one because first layer is input layer
		biases[i - 1].resize(layers[i].size());
	}

	// initializing weights
	weights.resize(layers.size() - 1);
	for (int i = 1; i < (layers.size()); i++) { // index starts at one because first layer is input layer 
		weights[i - 1].resize(layers[i].size());
		for (auto &element : weights[i - 1]) {
			element.resize(layers[i - 1].size());
		}

	}

	//randomly assign values the biases and wieghts
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::normal_distribution<> nd(0, 1);

	//intializing biases
	for (int i = 0; i < biases.size(); i++) {
		for (int j = 0; j < biases[i].size(); j++) {
			biases[i][j] = nd(rng);
		}
	}
	//intializing weights
	for (int i = 0; i < weights.size(); i++) {
		for (int j = 0; i < weights[i].size(); j++) {
			for (int k = 0; k < weights[i][j].size(); k++) {
				weights[i][j][k] = nd(rng);
			}
		}
	}
}


void network::train ( int &epochs, int batch_size, double eta ){
	// some description of the function goes here

	if (x.size() != y.size()) {
		throw "Error in network.train(): input vector x and y must be the same length";
	}
	int n = x.size();
	std::vector<int> index(n, 0); //This holds the indices for our input vector x and output vector y
	
	//randomly shuffles the vector
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::shuffle(index.begin(), index.end(), rng);
	
	int *batch = new int[batch_size];
	for (int i = 0 - batch_size; i < n; i += batch_size) {
		

		for (int j = i + batch_size, k = 0; j < i + batch_size * 2; j++, k++) {
			// This loop populates the batch array with each element from the index
			// j loops through each corresponding elements in index
			// k loops through each batch element instead
			batch[k] = index[j];
			/*for testing purposes*/ std::cout << batch[1] << std::endl;
		}
		this->updateNetwork(batch, batch_size,eta);

		
	}
	delete[] batch;

}

void network::updateNetwork(int *batch, int batch_size, double eta) {
	
	for (int i = 0; i < batch_size; i++) {
		this->backprop(x[batch[i]], y[batch[i]]);

	}


}

void network::backprop(std::vector<double> &xx,  double &yy) {
	//xx and yy are elements of the vector x and y respectively
	
}


void network::prediction() {

}


std::vector<double> network::sigmoid(std::vector<double> &z) {
	//This function applies sigmoid neuron calcuations given a vector of z values.
	std::vector<double> output(z.size(), 0); // This vector will hold the function output values

	for (int i = 0; i < z.size();i++) {
		output.at(i) = 1.0 / (1.0 + exp(z[i]));
	}

	return output;
}

std::vector<double> network::dsigmoid(std::vector<double> &z) {
	//This is the derivative of the sigmoid function 
	std::vector<double> output(z.size(), 0);

	for (int i = 0; i < z.size(); i++) {
		output.at(i) = (1.0 / (1.0 + exp(z[i]))) / (1 - (1.0 / (1.0 + exp(z[i]))));
	}

	return output;
}
	
void network::printLayers() {
	std::cout << nwlayers.size();
}


