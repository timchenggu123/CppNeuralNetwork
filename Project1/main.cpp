// Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Header.h"
#include "NNHelperFunctions.h"
#include "network.h"


int main()
{

	std::vector<double> zed = { 1.0,2.2,3.3 };

	NNHelper::my_exp(zed);

	for (int i = 0 ; i < zed.size(); i++)
		std::cout << zed[i] << std::endl;

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
