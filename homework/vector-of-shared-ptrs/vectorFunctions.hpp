#ifndef VECTORFUNCTION_HPP
#define VECTORFUNCTION_HPP
#include <string>
#include <vector>
#include <memory>

std::vector<std::shared_ptr<int>> generate(int count);

void print(std::vector<std::shared_ptr<int>> zab);

void add10(std::vector<std::shared_ptr<int>>& vec);

void sub10(const int* n);
void sub10(std::vector<std::shared_ptr<int>> vec);

#endif
