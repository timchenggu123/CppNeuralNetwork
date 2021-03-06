// Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Header.h"
#include "NNHelperFunctions.h"
#include "network.h"


int main()
{

	std::vector<std::vector<double>> x;
	std::vector<std::vector<double>> y;
	NNHelper::read_mnist_images("E:\\Code\\neural-networks-and-deep-learning\\src\\",x);
	NNHelper::read_mnist_labels("E:\\Code\\neural-networks-and-deep-learning\\src\\", y);

	std::vector<std::vector<double>> xx, yy;
	xx = std::vector<std::vector<double>>(x.begin(), x.begin() + 6000);
	yy = std::vector<std::vector<double>>(y.begin(), y.begin() + 6000);

	std::vector<int> layers = { 784, 30, 10 };

	network nw(layers,xx, yy);
	nw.train(1,10,3);
	nw.prediction(x[601], yy[0]);

	std::vector<std::vector<double>> test_y;
	test_y.resize(5);
	for (auto &i : test_y) {
		i.resize(10);
	}
	nw.prediction(x[0], test_y[0]);
	nw.prediction(x[1], test_y[1]);
	nw.prediction(x[2], test_y[2]);
	nw.prediction(x[3], test_y[3]);
	nw.prediction(x[4], test_y[4]);

	int a = 0;
}
	
