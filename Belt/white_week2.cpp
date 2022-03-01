#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool IsPalindrom(std::string str) {
    for (int i = 0; i < (str.size())/2; i++) {
        if (str[i] != str[str.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

int Factorial(int num) {
    if (num < 1) {
        return 1;
    }
    return num * Factorial(num - 1);
}

std::vector<std::string> PalindromFilter(std::vector<std::string> words, int minLength) 
{
    std::vector<std::string> retVect;
    for (std::string str: words) {
        if (IsPalindrom(str) && str.size() >= minLength) {
            retVect.push_back(str);
        }
    }
    return retVect;
}

void UpdateIfGreater(int first, int &second) {
	if (first > second) {
		second = first;
	}
}

void MoveStrings(vector<string>& source, vector<string>& destination) {
	for (const string &str: source) {
		destination.push_back(str);
	}
	source.clear();
}

void Reverse(vector<int>& v) {
	std::reverse(v.begin(), v.end());
}

vector<int> Reversed(const vector<int>& v) {
	vector<int> retV = v;
	Reverse(retV);
	return retV;
}

//template <typename T>
//void PrintVector(const vector<T>& vect) {
//	for () {

//	}
//}

void AverageTemperature() {
	int N = 0;
	cin >> N;
	vector<int> temperature(N);
	double averageTemp = 0;
	for (int &value: temperature) {
		cin >> value;
		averageTemp += value;
	}

	averageTemp /= N;
	int countMax = 0;
	for (int i = 0; i < N; i++) {
		if (temperature[i] > averageTemp) {
			countMax++;
		}
	}
	cout << countMax << endl;
	for (int i = 0; i < N; i++) {
		if (temperature[i] > averageTemp) {
			cout << i << " ";
		}
	}
}

void QueuePeople() {
	int N = 0;
	cin >> N;
	vector<bool> people;

	for (int i = 0; i < N; i++) {
		string operation;
		int value = 0;
		cin >> operation;

		if (operation == "WORRY") {
			cin >> value;
			people[value] = true;
		} else if (operation == "QUIET") {
			cin >> value;
			people[value] = false;
		} else if (operation == "COME") {
			cin >> value;
			people.resize(people.size() + value, false);
		} else if (operation == "WORRY_COUNT") {
			int count = 0;
			for (bool isWorry: people) {
				if (isWorry) {
					count++;
				}
			}
			cout << count << endl;
		}
	}
}

void ToDoList() {
	const vector<int> countDaysInMounth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int currentMounth = 0;
	int N = 0;
	cin >> N;
	vector<vector<string>> goals_for_Day(countDaysInMounth[currentMounth]);

	for (int i = 0; i < N; i++) {
		string operation;
		cin >> operation;

		if (operation == "ADD") {
			int day = 0;
			string tempGoal;
			cin >> day;
			cin >> tempGoal;
			goals_for_Day[day - 1].push_back(tempGoal);
		} else if (operation == "DUMP") {
			int day = 0;
			cin >> day;
			cout << goals_for_Day[day - 1].size() << " ";
			for (auto str: goals_for_Day[day - 1]) {
				cout << str << " ";
			}
			cout << endl;
		} else {
			// NEXT
			const int daysInCurrentMounth = countDaysInMounth[currentMounth];
			if (currentMounth == 11) {
				currentMounth = 0;
			} else {
				currentMounth++;
			}
			const int daysInNewMounth = countDaysInMounth[currentMounth];
			vector<vector<string>> goalsNew(daysInNewMounth);

			int maxDays = std::max(daysInCurrentMounth, daysInNewMounth);
			for (int i = 0; i < maxDays; i++) {
				if (i < daysInNewMounth && i < daysInCurrentMounth) {
					goalsNew[i] = goals_for_Day[i];
				} else if (i < daysInCurrentMounth && i >= daysInNewMounth) {
					// в прошлом месяце было больше дней
					goalsNew[daysInNewMounth-1]
							.insert(goalsNew[daysInNewMounth - 1].end(),
							goals_for_Day[i].begin(),
							goals_for_Day[i].end());
				} else {
//					cout << "Error: 001";
				}
			}

			goals_for_Day = goalsNew;
		}
	}
}

int main() {
//	AverageTemperature();
//	QueuePeople();
//	ToDoList();

    // std::cout << Factorial(0);
    // std::string t_str;
    // std::cin >> t_str;
//    std::cout << "34324";

    return 0;
}
