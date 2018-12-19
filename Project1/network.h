#ifndef NETWORK_H
#define NETWORK_H

class network {
public:
	network(std::vector<int>& layers, std::vector<std::vector<double>>& data, std::vector<std::vector<double>>& values);
	void train(int  epochs, int batch_size, double eta);
	void updateNetwork(int * batch, int batch_size, double eta);
	void backprop(std::vector<double>& xx, std::vector<double>& yy);
	void prediction(std::vector<double>& xx, std::vector<double>& yy);
	double sigmoid(double sigma_z);
	double dsigmoid(double sigma_z);
	void printLayers();
	void getBiases();
private:
	std::vector<int> nwlayers;
	std::vector<std::vector<double>>  biases; //storing all biases for each sigmoid neuron, layer by layer
	std::vector<std::vector<std::vector<double> > > weights; //storing all weights for each sigmoid neuron, layer by layer
	std::vector<std::vector<double>> x; // A vector storing all the initial x inputs
	std::vector<std::vector<double>> y; //A vector storing all the corresponding y's for each x
	std::vector<std::vector<double>> z; //a matrix storign all the z activation values layer by layer. Should have same dimensions as biases.
	std::vector<std::vector<double>> die_b; //storing the resulting gradient descent vector for b 
	std::vector<std::vector<std::vector<double>>> die_w; //storing the resulting gradient desdcent vector for w
	std::vector<std::vector<double>> activations; //storing all the neuron actionvations in the backprop() function
	std::vector<std::vector<std::vector<double>>> sum_die_w; //used in update minibatch function. Holds updated weights
	std::vector<std::vector<double>> sum_die_b; //used in update minibatch function. Holds updated biases
	int nlayers;


};

#endif
