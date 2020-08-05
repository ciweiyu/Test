// Project1Vector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\..\common\VectorOperation.h"
#include <vector>

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
	std::vector<int> originalVec= VectorOperation::GenerateVector(10,2,30);
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

	getchar();
    return 0;
}

