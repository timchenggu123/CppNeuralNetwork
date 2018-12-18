#ifndef NNHELPERFUNCTIONS_H
#define	NNHELPERFUNCTIONS_H
#include "Header.h"

namespace NNHelper{
	extern std::vector<double> my_exp(std::vector<double> &vec);
	extern std::array<int, 2> shape(std::vector<double> &vec);
	extern int reverseInt(int i);
	extern void read_mnist_images(std::string full_path, std::vector<std::vector<double>> &x);
	extern void read_mnist_labels(std::string full_path, std::vector<std::vector<double>> &y);
}


#endif // !NNHELPERFUNCTIONS_H
#pragma once
