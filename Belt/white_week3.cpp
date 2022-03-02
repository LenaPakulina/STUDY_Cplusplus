#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>

using namespace std;

template <typename T>
void PrintVector(const vector<T>& vector) {
	for (const T &elem: vector) {
		cout << elem << " ";
	}
	cout << endl;
}

void SortNumbers() {
	int N = 0;
	cin >> N;
	vector<int> numvers(N);

	for (int &temp: numvers) {
		cin >> temp;
	}

	sort(numvers.begin(), numvers.end(), [&](int i1, int i2){
		return abs(i1) < abs(i2);
	});
	PrintVector(numvers);
}

bool caseInsensitiveStringCompare( const std::string& str1, const std::string& str2 ) {
	std::string str1Cpy( str1 );
	std::string str2Cpy( str2 );
	std::transform( str1Cpy.begin(), str1Cpy.end(), str1Cpy.begin(), ::tolower );
	std::transform( str2Cpy.begin(), str2Cpy.end(), str2Cpy.begin(), ::tolower );
	return ( str1Cpy < str2Cpy );
}

void SortCaseInsensitive() {
	int N = 0;
	cin >> N;
	vector<string> values(N);

	for (string &temp: values) {
		cin >> temp;
	}

	sort(values.begin(), values.end(), caseInsensitiveStringCompare);
	PrintVector(values);
}

int main() {
	SortCaseInsensitive();
//	SortNumbers();
	return 0;
}
