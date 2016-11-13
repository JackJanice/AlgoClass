#pragma once
#include <iostream>
#include <string>
#include <vector>

class BigInt {
public:
	//constructors
	BigInt();
	BigInt(std::string X);
	BigInt(int X);

	BigInt operator+(BigInt &other);
	BigInt operator*(BigInt &other);

	friend std::ostream &operator<<(std::ostream output, const BigInt &b);

	static std::vector<unsigned int> vecAdd(const std::vector<unsigned int> &a, const std::vector<unsigned int> &b);
	//static std::vector<unsigned int> vecSub(const std::vector<unsigned int> &a, const std::vector<unsigned int> &b);
	static std::vector<unsigned int> vecMul(const std::vector<unsigned int> &a, const std::vector<unsigned int> &b);

	static std::vector<unsigned int> stringToVec(const std::string X);
	static std::vector<unsigned int> intToVec(int x);
	static void PrintVec(std::vector<unsigned int> vec);

private:
	std::vector<unsigned int> vecNum;
	bool isNegative;

	
	



};
