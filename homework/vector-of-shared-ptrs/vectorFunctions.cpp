#include "vectorFunctions.hpp"
#include <iostream>

std::vector<std::shared_ptr<int>> generate(int count) {
	std::vector<std::shared_ptr<int>> vec;
	for (int i = 0; i <= count - 1; i++) {
		vec.push_back(std::make_shared<int>(i));
	}
	return vec;
}

void print(std::vector<std::shared_ptr<int>> zab) {
	for (std::shared_ptr<int> n : zab) {
		std::cout << *n<<std::endl;
	}
}

void add10(std::vector<std::shared_ptr<int>>& vec) {
	for (std::shared_ptr<int> n : vec) {
		if (n != nullptr) { 
			*n += 10;
		}
	}
}

void sub10(int * const n) {
	if (n != nullptr) {
		*n -= 10;
	}
}
void sub10(std::vector<std::shared_ptr<int>> vec) {
	for (std::shared_ptr<int> n : vec) {
		sub10(n.get());
	}

}
