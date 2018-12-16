#include "Header.h"
#include "NNHelperFunctions.h"
#include "network.h"

network::network(std::vector<int> &layers, std::vector<std::vector<double>> &data, std::vector<std::vector<double>> &values ) {
	x = data;
	y = values;
	nwlayers = layers;
	nlayers = layers.size();

	//allocating biases 
	biases.resize(layers.size() - 1); // -1 here because the first layer is an input layer
	for (int i = 1; i < (layers.size()); i++) { // index starts at one because first layer is input layer
		biases[i - 1].resize(layers[i]); //i - 1 here because we set i to be the layer we want to target, and i starts at 1 instead of 0
	}

	// allocating weights
	weights.resize(layers.size() - 1);
	for (int i = 1; i < (layers.size()); i++) { // index starts at one because first layer is input layer 
		weights[i - 1].resize(layers[i]);
		for (auto &element : weights[i - 1]) {
			element.resize(layers[i - 1]);
		}

	}
	//allocating die_b and die_w as zeor matrices with dimensions same as weights and biases
	die_b.resize(biases.size());
	for (int i = 0; i < biases.size(); i++) {
		die_b[i].resize(biases[i].size());
	}

	die_w.resize(weights.size());
	for (int i = 0; i < weights.size(); i++) {
		die_w[i].resize(weights[i].size());
		for (int j = 0; j < weights[i].size(); j++) {
			die_w[i][j].resize(weights[i][j].size());
		}
	}

	//allcating z matrix
	z.resize(biases.size());
	for (int i = 0; i < biases.size(); i++) {
		z[i].resize(biases[i].size());
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
		for (int j = 0; j < weights[i].size(); j++) {
			for (int k = 0; k < weights[i][j].size(); k++) {
				weights[i][j][k] = nd(rng);
			}
		}
	}
	//initializing activations matrix, which should have the same dimensions as our networ layers
	activations.resize(nlayers);
	for (int i = 0; i < nlayers; i++) {
		activations[i].resize(layers[i]);
	}
}


void network::train ( int epochs, int batch_size, double eta ){
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
	
	int *batch = new int[batch_size]; //initialize a batch vector of use-specified length containing elements from the index vector
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

void network::backprop(std::vector<double> &xx, std::vector<double> &yy) {
	//a copy of xx is made here instead of a reference since will be changing the values of the vector in this function

	//Activate all neurons
	double wx = 0, zz = 0, w = 0, b = 0, x = 0;
	activations[0] = xx;

	for (int i = 0; i < weights.size(); i++) {
		//each layer
		for (int j = 0; j < weights[i].size(); j++) {
			//each neuron
			wx = 0; //initializing sigma_z
			std::vector<double> &ws = weights[i][j];
			b = biases[i][j];

			for (int k = 0; k < ws.size(); k++) {
				//each weight
				w = ws[k];
				x = activations[i][k];
				wx += w * x;

			}

			zz = wx + b;
			z[i][j] = zz; //store zz in z matix.
			activations[i + 1][j] = sigmoid(zz);
		}
	}

	//backward pass
	std::vector<double> delta(yy.size(), 0);

	for (int i = 0; i < delta.size(); i++) {
		if (!(z.empty() && activations.empty())) {
			zz = z[z.size() - 1][i];
			delta[i] = (yy[i] - activations[activations.size() - 1][i]) * dsigmoid(zz);
		}
	}

	//intialize die_b and die_w values
	die_b[die_b.size() - 1] = delta;
	for (int i = 0; i < die_w[die_w.size() - 1].size(); i++) {
		for (int j = 0; j < die_w[die_w.size() -1][i].size(); j++) {
			die_w[die_w.size() - 1][i][j] = delta[i]*activations[activations.size()-2][j];
		}
	}

	int stop = 1; //stop here
	
}


void network::prediction() {

}


double network::sigmoid(double z) {
	//This function applies sigmoid neuron calcuations given a vector of z values.
	double output; // This vector will hold the function output values

	output = 1.0 / (1.0 + z);

	return output;
}

double network::dsigmoid(double z) {
	//This is the derivative of the sigmoid function 
	double output;

	output = (1.0 / (1.0 + z)) / (1 - (1.0 / (1.0 + z)));


	return output;
}
	
void network::printLayers() {
	std::cout << nwlayers.size();
}

void network::getBiases() {

	for (auto i : biases) {
		for (auto j : i) {
			std::cout << j;
		}
		std::cout << std::endl;
	}
}


