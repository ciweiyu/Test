#pragma once

#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include <vector>
#include <string>

class VectorOperation
{
public:
	VectorOperation();
	~VectorOperation();
	
	static std::vector<int> GenerateVector(int size, int minv, int maxv);
	static void PrintVector(std::string name,std::vector<int>& vec);
};

