// This file tests the module
#include <iostream>
#include <fstream>
#include <string>
#include "Censer.h"

int main(void)
{
	std::string in, out;
	std::cout << "Input in_file: ";
	std::cin >> in;
	std::cout << "Input out_file: ";
	std::cin >> out;
	Censer::Text text(out, in);

	while (text.WritePath());
	
	return 0;
}