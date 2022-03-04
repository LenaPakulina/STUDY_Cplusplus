#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

struct Specialization {
	string m_str;
	explicit Specialization(string str) : m_str(str) {};
};

struct Course {
	string m_str;
	explicit Course(string str) : m_str(str) {};
};

struct Week {
	string m_str;
	explicit Week(string str) : m_str(str) {};
};

struct LectureTitle {
	LectureTitle(Specialization special, Course cour, Week w) {
		specialization = special.m_str;
		course = cour.m_str;
		week = w.m_str;
	}
	string specialization;
	string course;
	string week;
};

//// ПОВТОР
struct Image {
  double quality;
  double freshness;
  double rating;
};

struct Params {
  double a;
  double b;
  double c;
};

class FunctionPart {
public:
	FunctionPart(char t_opertr, double t_value) {
		operation = t_opertr;
		value = t_value;
	}
	double Apply(const double& source_value) const {
		if (operation == '+') {
			return source_value + value;
		} else if (operation == '-') {
			return source_value - value;
		} else if (operation == '*') {
			return source_value * value;
		} else if (operation == '/') {
			return source_value / value;
		}
		return source_value / value;
	}
	void Invert() {
		if (operation == '+') {
			operation = '-';
		} else if (operation == '-') {
			operation = '+';
		} else if (operation == '*') {
			operation = '/';
		} else {
			operation = '*';
		}
	}
private:
	char operation;
	double value;
};

class Function {
public:
	void AddPart(char opertr, double value) {
		parts.push_back({opertr, value});
	}
	double Apply(double value) const {
		for (const FunctionPart &part: parts) {
			value = part.Apply(value);
		}
		return value;
	}
	void Invert() {
		for (FunctionPart &part: parts) {
			part.Invert();
		}
		reverse(parts.begin(), parts.end());
	}
private:
	vector<FunctionPart> parts;
};

Function MakeWeightFunction(const Params& params,
							const Image& image) {
  Function function;
  function.AddPart('*', params.a);
  function.AddPart('-', image.freshness * params.b);
  function.AddPart('+', image.rating * params.c);
  return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
							  const Image& image,
							  double weight) {
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}
// end {ПОВТОР}

void WorkingWithFiles() {
	ifstream input("input.txt");
	ofstream output("output.txt");
	string line;
	while(getline(input, line)) {
//		cout << line << endl;
		output << line << endl;
	}
}

void ConclusionWithPrecision() {
	ifstream input("input.txt");
	double line;
	string str;
	cout << fixed << setprecision(3);
	while(getline(input, str)) {
		input >> line;
		cout << line << endl;
	}
}

void ReadingAndDisplaying() {
//	ifstream input("input.txt");
//	string line;
//	cout << setprecision(3);
//	while(getline(input, line)) {
//		cout << line << endl;
//	}
}

int main() {
//	ReadingAndDisplaying();
	ConclusionWithPrecision();
//	WorkingWithFiles();
//	Image image = {10, 2, 6};
//	Params params = {4, 2, 6};
//	cout << ComputeImageWeight(params, image) << endl;
//	cout << ComputeQualityByWeight(params, image, 52) << endl;

//	LectureTitle title(
//		Specialization("C++"),
//		Course("White belt"),
//		Week("4th")
//	);
	return 0;
}
