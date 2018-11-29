#ifndef NETWORK_H
#define NETWORK_H

class network {
public:
	network(std::vector<int> &layers);
	void train(int x, int y);
	void backprop();
	void update();
	void prediction();
	std::vector<double> sigmoid(std::vector<double> &z);
	std::vector<double> dsigmoid(std::vector<double> &z);
	void printLayers();
private:
	std::vector<int> nwlayers;
	std::vector<int> biases;
	std::vector<int> weights;
	std::vector<std::vector<int>> x; // A vector storing all the initial x inputs
	std::vector<int> y; //A vector storing all the corresponding y's for each x
	int nlayers;

};

#endif
