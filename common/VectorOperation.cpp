#include "VectorOperation.h"



VectorOperation::VectorOperation()
{
}


VectorOperation::~VectorOperation()
{
}

std::vector<int> VectorOperation::GenerateVector(int size, int minv, int maxv)
{
	std::vector<int> vec(size);
	int l = maxv - minv;
	for (int i = 0; i < size; i++)
	{
		vec[i] = rand() % l + minv;
	}
	return vec;
}

void VectorOperation::PrintVector(std::string name, std::vector<int>& vec)
{
	std::string str = name + "=[";
	if (vec.size()>0)
	{
		str += std::to_string(vec[0]);
		for (size_t i = 1; i < vec.size(); i++)
		{
			str += ","+std::to_string(vec[i]);
		}
	}
	str += "]";
	std::cout << str << std::endl;
}
