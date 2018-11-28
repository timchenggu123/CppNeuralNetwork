#ifndef NETWORK_H
#define NETWORK_H

class network {
public:
	network(std::vector<int> &layers);
	void SGD(int x, int y);
	void backprop();
	void update();
	void feedforward();
	std::vector<double> sigmoid(std::vector<double> &z);
	std::vector<double> dsigmoid(std::vector<double> &z);
	void printLayers();
private:
	std::vector<int> nwlayers;
	std::vector<int> biases;
	std::vector<int> weights;
	int nlayers;

};

#endif
