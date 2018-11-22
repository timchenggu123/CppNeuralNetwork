#include "Header.h"

class network {
	int *ptr_layer;
	int layer_size;

public:
	network(int *layer, int size) {
		ptr_layer = layer;
		layer_size = size;
	}
	
	void printLayer() {
	
		std::cout << ptr_layer[1];

	}
};