#include <iostream>
#include <numeric>
#include <sstream>
#include <set>
#include <map>
#include <vector>
using namespace std;

class Rational {
public:
	Rational() {
		setDefaulParam();
	}
	Rational(int numerator, int denominator) {
		if (denominator == 0) {
			throw string("Invalid argument");
		}
		if (numerator == 0) {
			setDefaulParam();
			return;
		}
		int my_gcd = gcd(numerator, denominator);
		p = (my_gcd == 1) ? numerator : (numerator / my_gcd);
		q = (my_gcd == 1) ? denominator : (denominator / my_gcd);
		double multi = numerator * denominator;
		if (multi < 0 && p > 0) {
			p *= -1;
			q *= -1;
		}
		if (p < 0 && q < 0) {
			p *= -1;
			q *= -1;
		}
	}
	int Numerator() const {
		return p;
	}
	int Denominator() const {
		return q;
	}
	double GetValue() const {
		return (p * 1.0)/q;
	}
private:
//	Rational = p/q;
	int p;
	int q;

	void setDefaulParam() {
		p = 0;
		q = 1;
	}
};

bool operator==(const Rational& lRation, const Rational& rRation) {
	double value1 = lRation.GetValue();
	double value2 = rRation.GetValue();
	return (value1 == value2);
}

Rational operator+(const Rational& lRation, const Rational& rRation) {
	int my_lcm = lcm(lRation.Denominator(), rRation.Denominator());
	int lDel = my_lcm / lRation.Denominator();
	int rDel = my_lcm / rRation.Denominator();
	return Rational(lRation.Numerator() * lDel + rRation.Numerator() * rDel, my_lcm);
}

Rational operator-(const Rational& lRation, const Rational& rRation) {
	int my_lcm = lcm(lRation.Denominator(), rRation.Denominator());
	int lDel = my_lcm / lRation.Denominator();
	int rDel = my_lcm / rRation.Denominator();
	return Rational(lRation.Numerator() * lDel - rRation.Numerator() * rDel, my_lcm);
}

Rational operator*(const Rational& lRation, const Rational& rRation) {
	return Rational(rRation.Numerator() * lRation.Numerator(),
					rRation.Denominator() * lRation.Denominator());
}

Rational operator/(const Rational& lRation, const Rational& rRation) {
	if (rRation.Numerator() == 0) {
		throw string("Division by zero");
	}
	Rational flipRational = Rational(rRation.Denominator(), rRation.Numerator());
	return lRation * flipRational;
}

ostream& operator<<(ostream& stream, const Rational& ration) {
	stream << ration.Numerator() << "/" << ration.Denominator();
	return stream;
}

istream& operator>>(istream& stream, Rational& ration) {
	int value1 = 0;
	int value2 = 0;
	if (stream >> value1) {
		if (stream.ignore(256,'/')) {
			if (stream >> value2) {
				ration = Rational(value1, value2);
			}
		}
	}
	return stream;
}

bool operator<(const Rational& lRation, const Rational& rRation) {
	return lRation.GetValue() < rRation.GetValue();
}

void skipWhiteScape() {
	while(cin.peek() == ' ') {
		cin.ignore();
	}
}

Rational getRational() {
	int numerator;
	int denominator;
	cin >> numerator;
	if (cin.peek() != '/') {
		throw string("Invalid argument");
	}
	cin.ignore();
	cin >> denominator;
	return Rational(numerator, denominator);
}

void CalculateApp() {
	Rational rat1 = getRational();
	skipWhiteScape();
	char operation = cin.peek();
	if (operation == '+' || operation == '-' || operation == '/' || operation == '*') {
		cin.ignore();
		skipWhiteScape();
		Rational rat2 = getRational();
		if (operation == '+') {
			cout << rat1 + rat2;
		} else if (operation == '-') {
			cout << rat1 - rat2;
		} else if (operation == '*') {
			cout << rat1 * rat2;
		} else if (operation == '/') {
			cout << rat1 / rat2;
		}
	} else {
		throw string("Invalid argument");
	}
}

//string AskTimeServer() {
//	return "  ";
//}

string AskTimeServer();

class TimeServer {
public:
	string GetCurrentTime() {
		string temp;
		try {
			temp = AskTimeServer();
		} catch (system_error& error) {
			return last_fetched_time;
		}
		last_fetched_time = temp;
		return last_fetched_time;
	}

private:
	string last_fetched_time = "00:00:00";
};

int main() {

	TimeServer ts;
	try {
		cout << ts.GetCurrentTime() << endl;
	} catch (exception& e) {
		cout << "Exception got: " << e.what() << endl;
	}

//	try {
//		CalculateApp();
//	} catch (exception& e) {
//		cout << e.what();
//	} catch (string& str) {
//		cout << str;
//	}

//	try {
//			Rational r(1, 0);
//			cout << "Doesn't throw in case of zero denominator" << endl;
//			return 1;
//		} catch (invalid_argument&) {
//		}

//		try {
//			auto x = Rational(1, 2) / Rational(0, 1);
//			cout << "Doesn't throw in case of division by zero" << endl;
//			return 2;
//		} catch (domain_error&) {
//		}

//		cout << "OK" << endl;

//	set<Rational> rationals;
//	rationals.insert(Rational(1, 2));
//	rationals.insert(Rational(1, 3));

//	map<Rational, string> name;
//	name[Rational(1, 2)] = "одна вторая";

//	{
//			const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
//			if (rs.size() != 3) {
//				cout << "Wrong amount of items in the set" << endl;
//				return 1;
//			}

//			vector<Rational> v;
//			for (auto x : rs) {
//				v.push_back(x);
//			}
//			if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
//				cout << "Rationals comparison works incorrectly" << endl;
//				return 2;
//			}
//		}

//		{
//			map<Rational, int> count;
//			++count[{1, 2}];
//			++count[{1, 2}];

//			++count[{2, 3}];

//			if (count.size() != 2) {
//				cout << "Wrong amount of items in the map" << endl;
//				return 3;
//			}
//		}

////	Rational r;
////	cin >> r;
////	cout << r;
//	{
//			ostringstream output;
//			output << Rational(-6, 8);
//			string temp = output.str();
//			if (output.str() != "-3/4") {
//				cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
//				return 1;
//			}
//		}

//		{
//			istringstream input("5/7");
//			Rational r;
//			input >> r;
//			bool equal = r == Rational(5, 7);
//			if (!equal) {
//				cout << "5/7 is incorrectly read as " << r << endl;
//				return 2;
//			}
//		}

//		{
//			istringstream input("");
//			Rational r;
//			bool correct = !(input >> r);
//			if (!correct) {
//				cout << "Read from empty stream works incorrectly" << endl;
//				return 3;
//			}
//		}

//		{
//			istringstream input("5/7 10/8");
//			Rational r1, r2;
//			input >> r1 >> r2;
//			bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
//			if (!correct) {
//				cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
//				return 4;
//			}

//			input >> r1;
//			input >> r2;
//			correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
//			if (!correct) {
//				cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
//				return 5;
//			}
//		}

//		{
//			istringstream input1("1*2"), input2("1/"), input3("/4");
//			Rational r1, r2, r3;
//			input1 >> r1;
//			input2 >> r2;
//			input3 >> r3;
//			bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
//			if (!correct) {
//				cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
//					 << r1 << " " << r2 << " " << r3 << endl;

//				return 6;
//			}
//		}

//		{
//			istringstream input("2/4/6/8");
//			Rational r1;
//			input >> r1;
//			bool correct = r1 == Rational(1, 2);
//			if (!correct) {
//				cout << "Multiple-slashed number sequence value read incorrectly: " << r1 << endl;
//				return 7;
//			}
//		}
////	const Rational r = Rational(1, 2) * Rational(1, 3) / Rational(1, 4);
////	if (r == Rational(2, 3)) {
////	  cout << "equal";
////	}
//	{
//			Rational a(2, 3);
//			Rational b(4, 3);
//			Rational c = a * b;
//			bool equal = c == Rational(8, 9);
//			if (!equal) {
//				cout << "2/3 * 4/3 != 8/9" << endl;
//				return 1;
//			}
//		}

//		{
//			Rational a(5, 4);
//			Rational b(15, 8);
//			Rational c = a / b;
//			bool equal = c == Rational(2, 3);
//			if (!equal) {
//				cout << "5/4 / 15/8 != 2/3" << endl;
//				return 2;
//			}
//		}
////	const Rational r = Rational(1, 2) + Rational(1, 3) - Rational(1, 4);
////	if (r == Rational(7, 12)) {
////	  cout << "equal";
////	}
//	{
//			Rational r1(4, 6);
//			Rational r2(2, 3);
//			bool equal = r1 == r2;
//			if (!equal) {
//				cout << "4/6 != 2/3" << endl;
//				return 1;
//			}
//		}

//		{
//			Rational a(2, 3);
//			Rational b(4, 3);
//			Rational c = a + b;
//			bool equal = c == Rational(2, 1);
//			if (!equal) {
//				cout << "2/3 + 4/3 != 2" << endl;
//				return 2;
//			}
//		}

//		{
//			Rational a(5, 7);
//			Rational b(2, 9);
//			Rational c = a - b;
//			bool equal = c == Rational(31, 63);
//			if (!equal) {
//				cout << "5/7 - 2/9 != 31/63" << endl;
//				return 3;
//			}
//		}
//	{
//		const Rational r(3, 10);
//		if (r.Numerator() != 3 || r.Denominator() != 10) {
//			cout << "Rational(3, 10) != 3/10" << endl;
//			return 1;
//		}
//	}

//	{
//		const Rational r(8, 12);
//		if (r.Numerator() != 2 || r.Denominator() != 3) {
//			cout << "Rational(8, 12) != 2/3" << endl;
//			return 2;
//		}
//	}

//	{
//		const Rational r(-4, 6);
//		if (r.Numerator() != -2 || r.Denominator() != 3) {
//			cout << "Rational(-4, 6) != -2/3" << endl;
//			return 3;
//		}
//	}

//	{
//		const Rational r(4, -6);
//		if (r.Numerator() != -2 || r.Denominator() != 3) {
//			cout << "Rational(4, -6) != -2/3" << endl;
//			return 3;
//		}
//	}

//	{
//		const Rational r(0, 15);
//		if (r.Numerator() != 0 || r.Denominator() != 1) {
//			cout << "Rational(0, 15) != 0/1" << endl;
//			return 4;
//		}
//	}

//	{
//		const Rational defaultConstructed;
//		if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
//			cout << "Rational() != 0/1" << endl;
//			return 5;
//		}
//	}

//	cout << "OK" << endl;
	return 0;
}
