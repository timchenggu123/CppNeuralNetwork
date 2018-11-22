#include "Header.h"

class network {
	std::vector<int> nwlayers;

public:
	network(std::vector<int> layers) {
		nwlayers = layers;
	}
	
	void printLayer() {
	
		std::cout << nwlayers.size();
	}
};