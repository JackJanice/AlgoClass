#include "BigInt.h"

BigInt::BigInt() {
	this->isNegative = false;

};

BigInt::BigInt(std::string X) {
	stringToVec(X);
};

BigInt::BigInt(int X) {
	intToVec(X);
};

std::vector<unsigned int> BigInt::stringToVec(const std::string X) {
	std::vector<unsigned int> out;

	int i = 0;

	while (i < X.length()) {
		out.push_back(X[i++] - 48);
	}
	return out;
};

std::vector<unsigned int> BigInt::intToVec(int x) {
	std::vector<unsigned int> out;
	
	if (x == 0) {
		out.push_back(x);
		return out;
	}

	std::vector<int> temp;
	while (x > 0) {
		temp.push_back(x % 10);
		x = x / 10;
	}

	for (int i = temp.size() - 1; i >= 0; i--)
		out.push_back(temp[i]);

	return out;
};



BigInt BigInt::operator +(BigInt &other) {
	BigInt result(0);
	if (!this->isNegative && !other.isNegative) {
		result.vecNum = vecAdd(this->vecNum, other.vecNum);
		return result;
	}
/*
	if (!this->isNegative && other.isNegative) {
		BigInt temp = other;
		temp.isNegative = false;
		result.vecNum = vecSub(this->vecNum, temp.vecNum);
		return result;
	}

	if (this->isNegative && !other.isNegative) {
		result.vecNum = vecSub(other.vecNum, this->vecNum);
		return result;
	}

	if (this->isNegative && other.isNegative) {
		result.vecNum = vecAdd(this->vecNum, other.vecNum);
		result.isNegative = true;
		return result;
	}
	*/
}
;

std::ostream &operator<<(std::ostream output, const BigInt& b) {
	bool leadingZero = true;
	if (b.isNegative)
		std::cout << "-";
	for (int i = 0; i<b.vecNum.size(); i++) {
		if (b.vecNum[i] == 0 && leadingZero) {
			;
		}
		else {
			leadingZero = false;
			std::cout << b.vecNum[i];
		}
	}
	return output;
};

std::vector<unsigned int> BigInt::vecAdd(const std::vector<unsigned int> &v1, const std::vector<unsigned int> &v2) {

	std::vector<unsigned int> out;
	std::vector<unsigned int> temp;
	int idx1 = v1.size() - 1;
	int idx2 = v2.size() - 1;
	int Incr = 0;
	int sum = 0;
	while (idx1 >= 0 || idx2 >= 0) {
		sum = 0;

		if (idx1 >= 0)
			sum += v1[idx1];

		if (idx2 >= 0)
			sum += v2[idx2];

		sum += Incr;
		if (sum >= 10) {
			Incr = 1;
			sum = sum - 10;
		}
		else {
			Incr = 0;
		}

		temp.push_back(sum);
		idx1--;
		idx2--;
	}

	if (Incr == 1)
		temp.push_back(1);

	//reverse out
	for (int i = temp.size() - 1; i >= 0; i--)
		out.push_back(temp[i]);

	return out;

};



std::vector<unsigned int> VecSub(const std::vector<unsigned int> v1, const std::vector<unsigned int> v2) {
	std::vector<unsigned int> out;
	std::vector<unsigned int> temp;
	for (int i = 0; i<v2.size(); i++)
		temp.push_back(-1 * v2[i]);
	return BigInt::vecAdd(v1, temp);
}


void BigInt::PrintVec(std::vector<unsigned int> vec) {
	bool leadingZero = true;
	
	for (int i = 0; i<vec.size(); i++) {
		if (vec[i] == 0 && leadingZero) {
			;
		}
		else {
			leadingZero = false;
			std::cout << vec[i];
		}
	}
};

std::vector<unsigned int> BigInt::vecMul(const std::vector<unsigned int> &v1, const std::vector<unsigned int> &v2) {
	std::vector<unsigned int> out;
	if (v1.size() == 1 && v2.size() == 1) {
		int z = v1[0] * v2[0];
		out = BigInt::intToVec(z);
		return out;
	}

	int n = (v1.size() >= v2.size() ? v1.size() : v2.size());
	int lenDiff = v1.size() - v2.size();

	std::vector<unsigned int> a;
	std::vector<unsigned int> b;
	std::vector<unsigned int> c;
	std::vector<unsigned int> d;
	int idx1 = 0;
	int idx2 = 0;

	for (int i = 0; i<n; i++) {
		if (i < n / 2) {
			if (lenDiff<0) {  //means v1 is shorter than v2
				a.push_back(0);
				c.push_back(v2[idx2++]);
				lenDiff++;
			}
			else if (lenDiff>0) { //means v2 is longer than v2
				a.push_back(v1[idx1++]);
				c.push_back(0);
				lenDiff--;
			}
			else {
				a.push_back(v1[idx1++]);
				c.push_back(v2[idx2++]);
			}
		}
		else {
			if (lenDiff<0) {  //means v1 is shorter than v2
				b.push_back(0);
				d.push_back(v2[idx2++]);
				lenDiff++;
			}
			else if (lenDiff>0) { //means v2 is longer than v2
				b.push_back(v1[idx1++]);
				d.push_back(0);
				lenDiff--;
			}
			else {
				b.push_back(v1[idx1++]);
				d.push_back(v2[idx2++]);
			}
		}
	}

	std::vector<unsigned int> ac = BigInt::vecMul(a, c);
	std::vector<unsigned int> bd = BigInt::vecMul(b, d);
	std::vector<unsigned int> ad = BigInt::vecMul(a, d);
	std::vector<unsigned int> bc = BigInt::vecMul(b, c);
	std::vector<unsigned int> adplusbc = BigInt::vecAdd(ad, bc);

	/*std::vector<unsigned int> aplusb = VecAdd(a, b);
	std::vector<unsigned int> cplusd = VecAdd(c, d);
	std::vector<unsigned int> axdplusbxc = VecMultiply(aplusb, cplusd);
	axdplusbxc = VecSubtract(axdplusbxc, axc);
	axdplusbxc = VecSubtract(axdplusbxc, bxd);*/

	for (int i = 0; i<n; i++)
		ac.push_back(0);

	for (int i = 0; i<n / 2; i++)
		adplusbc.push_back(0);

	out = BigInt::vecAdd(ac, adplusbc);
	out = BigInt::vecAdd(out, bd);
	return out;
}