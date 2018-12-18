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

	std::vector<int> layers = { 784, 30, 10 };

	network nw(layers,x, y);

	nw.train(1,10,3);
	
	int a = 0;
}
	
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
