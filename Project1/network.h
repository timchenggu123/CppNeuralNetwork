#ifndef NETWORK_H
#define NETWORK_H

class network {
public:
	network(std::vector<int>& layers, std::vector<std::vector<int>>& data, std::vector<int>& values);
	void backprop(std::vector<std::vector<int>>& x, std::vector<int>& y);
	void train(int & epochs, int batch_size, double eta);
	void updateNetwork(int * batch, int batch_size, double eta);
	void prediction();
	std::vector<double> sigmoid(std::vector<double> &z);
	std::vector<double> dsigmoid(std::vector<double> &z);
	void printLayers();
private:
	std::vector<int> nwlayers;
	std::vector<std::vector<double>> biases; //storing all biases for each sigmoid neuron, layer by layer
	std::vector<std::vector<double>> weights; //storing all weights for each sigmoid neuron, layer by layer
	std::vector<std::vector<int>> x; // A vector storing all the initial x inputs
	std::vector<int> y; //A vector storing all the corresponding y's for each x
	std::vector<std::vector<double>> die_b; //storing the resulting gradient descent vector for b 
	std::vector<std::vector<double>> die_n; //storing the resulting gradient desdcent vector for n
	int nlayers;


};

#endif
