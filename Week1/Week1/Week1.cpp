#include <iostream>
#include "BigInt.h"


void main()
{
	std::string strX;
	std::string strY;
	std::cout << "Input the 1st number:" << std::endl;
	std::cin >> strX;
	std::cout << "Input the 2nd number:" << std::endl;
	std::cin >> strY;

	std::vector<unsigned int> vecX;
	std::vector<unsigned int> vecY;
	vecX = BigInt::stringToVec(strX);
	vecY = BigInt::stringToVec(strY);

	std::cout << "1st Number: " << std::endl;
	BigInt::PrintVec(vecX);
	std::cout << "2nd Number: " << std::endl;
	BigInt::PrintVec(vecY);


	std::vector<unsigned int> vecM = BigInt::vecMul(vecX, vecY);
	std::cout << "Multiply: " << std::endl;
	BigInt::PrintVec(vecM);

}