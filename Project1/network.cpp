#include "Header.h"
#include "NNHelperFunctions.h"
#include "network.h"

network::network(std::vector<int> &layers) {
	nwlayers = layers;
	nlayers = layers.size();
}

void network::train (int x, int y){

		
}

void network::backprop() {

}

void network::update (){

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


