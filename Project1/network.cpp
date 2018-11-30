#include "Header.h"
#include "NNHelperFunctions.h"
#include "network.h"

network::network(std::vector<int> &layers, std::vector<std::vector<int>> &data, std::vector<int> &values ) {
	x = data;
	y = values;
	nwlayers = layers;
	nlayers = layers.size();
}

void network::train ( int &epochs, int batch_size, double eta ){
	// some description of the function goes here

	if (x.size() != y.size())
		throw "Error in network.train(): input vector x and y must be the same length";

	int n = x.size();
	std::vector<int> index(n, 0); //This holds the indices for our input vector x and output vector y
	
	//randomly shuffles the vector -------------------------------------------------------------
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::shuffle(index.begin(), index.end(), rng);
	
	int *batch = new int[batch_size];
	for (int i = 0 - batch_size; i < n; i += batch_size) {
		

		for (int j = i + batch_size, int k = 0; j < i + batch_size * 2; j++, k++) {
			// This loop populates the batch array with each element from the index
			// j loops through each corresponding elements in index
			// k loops through each batch element instead
			batch[k] = index[j];
			/*for testing purposes*/ std::cout << batch[1] << std::endl
		}
		this->updateNetwork(batch, batch_size,eta);

		
	}
	delete[] batch;

}

void network::updateNetwork(int *batch, int batch_size, double eta) {
	
	for (int i = 0; i < batch_size; i++) {
		
	}


}

void network::backprop(std::vector<std::vector<int>> &x, std::vector<int> &y) {
	//

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


