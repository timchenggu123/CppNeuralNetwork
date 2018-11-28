#ifndef NNHELPERFUNCTIONS_CPP
#define NNHELPERFUNCTIONS_CPP
#include "Header.h"

namespace NNHelper {

	std::vector<double> my_exp(std::vector<double> &vec) {
		/*a custom exp function. Note this function modifies
		the ORIGNIAL argument directly and returns it. If
		you wish to retain an original copy of the argument,	
		please make a copy of it before passing it to this
		function */

		for ( int i = 0; i < (vec.size()); i++) {
			double &temp = vec.at(i);
			vec.at(i) = exp(temp);
		}

		return vec;
	}

	std::array<int, 2> shape(std::vector < std::vector<double> > &vec) {
		/* This is a function that takes a two dimensional std::vector<double> and return the
		size of it in a tuple. */
		
		std::array<int, 2> output = { 0,0};

		return output;	
	}

}

#endif


