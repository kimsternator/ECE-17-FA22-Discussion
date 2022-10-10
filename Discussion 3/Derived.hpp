//
// Created by steph on 10/10/2022.
//

#ifndef DISCUSSION_3_DERIVED_HPP
#define DISCUSSION_3_DERIVED_HPP

#include <iostream>

#include "Base.hpp"

class Derived : public Base {
public:
	void printHere() {
		std::cout << "Here" << std::endl;
	}
};

#endif //DISCUSSION_3_DERIVED_HPP
