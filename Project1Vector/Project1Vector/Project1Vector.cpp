// Project1Vector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\..\common\VectorOperation.h"
#include <vector>
bool reverseCut(std::vector<int>& vecOrg, std::vector<int>& vecNew)
{
	std::vector<int>::reverse_iterator riter = vecOrg.rbegin();


	int v = *riter;
	std::cout << "last value=" << v << std::endl;
	for (; riter !=vecOrg.rend(); riter++)
	{
		if (*riter * v <=0)
		{
			std::cout << "break at value=" << *riter << std::endl;
			break;
		}
	}

	// Reverse iterators have a member base() which returns a corresponding forward iterator. 
	// Beware that this isn't an iterator that refers to the same object - it actually refers to the next object in the sequence.
	// This is so that rbegin() corresponds with end() and rend() corresponds with begin().
	// see https://en.cppreference.com/w/cpp/iterator/reverse_iterator
	std::vector<int>::iterator iter = (riter + 1).base();

	vecNew.clear();
	vecNew.insert(vecNew.end(), iter, vecOrg.end());

	vecOrg.erase(iter, vecOrg.end());
	return true;
}

bool CutVec(std::vector<int>& vecOrg, std::vector<int>& vecNew)
{
	std::vector<int>::iterator iter = vecOrg.begin() + vecOrg.size() / 2;

	vecNew.clear();
	vecNew.insert(vecNew.end(), iter, vecOrg.end());

	vecOrg.erase(iter, vecOrg.end());
	return true;
}

bool GetTheSecondHalf(std::vector<int> vecFrom, std::vector<int>& vecTo)
{
	return true;
}

bool ReplaceTheSecondHalf(std::vector<int> vecFrom, std::vector<int>& vecTo)
{
	return true;
}

bool AscendingSort(std::vector<int>& vecTo)
{
	return false;
}
int main()
{
	std::vector<int> originalVec= VectorOperation::GenerateVector(10,-20,20);
	VectorOperation::PrintVector("original vector", originalVec);
	std::vector<int> newVec;

	GetTheSecondHalf(originalVec,newVec);
	VectorOperation::PrintVector("new vector", newVec);
	AscendingSort(newVec);
	VectorOperation::PrintVector("sorted new vector", newVec);
	ReplaceTheSecondHalf(originalVec, newVec);
	VectorOperation::PrintVector("updated original vector", originalVec);

	CutVec(originalVec, newVec);
	VectorOperation::PrintVector("cut original vector", originalVec);
	VectorOperation::PrintVector("cut new vector", newVec);

	
	for (int i = 0; i < 5; i++)
	{
		srand(i);
		std::cout <<std::endl<< "reverse cut:" << i << std::endl;
		originalVec = VectorOperation::GenerateVector(10, -20, 20);
		VectorOperation::PrintVector("original vector", originalVec);
		reverseCut(originalVec, newVec);
		VectorOperation::PrintVector("cut original vector", originalVec);
		VectorOperation::PrintVector("cut new vector", newVec);

	}

	getchar();
    return 0;
}

