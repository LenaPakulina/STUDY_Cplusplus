#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

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

std::map<char, int> BuildCharCounters(const std::string &str) {
	std::map<char, int> charCounters;
	for (const char &ch: str) {
		++charCounters[ch];
	}
	return charCounters;
}

void Anagrams() {
	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		std::string str1;
		std::string str2;
		cin >> str1 >> str2;
		if (BuildCharCounters(str1) == BuildCharCounters(str2)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}

void DirectoryCapitals() {
	int N = 0;
	cin >> N;
	map<string, string> capitalCountry;

	for (int i = 0; i < N; i++) {
		string operation;
		cin >> operation;

		if (operation == "CHANGE_CAPITAL") {
			string country;
			string new_capital;
			cin >> country >> new_capital;
			if (capitalCountry.count(country) == 0) {
				cout << "Introduce new country " << country
					 << " with capital " << new_capital << endl;
			} else if (capitalCountry[country] == new_capital) {
				cout << "Country " << country << " hasn't changed its capital" << endl;
			} else {
				cout << "Country " << country
					 << " has changed its capital from "
					 << capitalCountry[country] << " to " << new_capital << endl;
			}

			capitalCountry[country] = new_capital;
		} else if (operation == "RENAME") {
			string old_country_name;
			string new_country_name;
			cin >> old_country_name >> new_country_name;
			if (old_country_name == new_country_name ||
					capitalCountry.count(old_country_name) == 0 ||
					capitalCountry.count(new_country_name) != 0) {
				cout << "Incorrect rename, skip" << endl;
			} else {
				string t_capital = capitalCountry[old_country_name];
				cout << "Country " << old_country_name << " with capital "
					 << t_capital << " has been renamed to " << new_country_name << endl;
				capitalCountry.erase(old_country_name);
				capitalCountry[new_country_name] = t_capital;
			}
		} else if (operation == "ABOUT") {
			string country ;
			cin >> country;
			if (capitalCountry.count(country) == 0) {
				cout << "Country " << country << " doesn't exist" << endl;
			} else {
				cout << "Country " << country << " has capital "
					 << capitalCountry[country] << endl;
			}
		} else if (operation == "DUMP") {
			if (capitalCountry.size() == 0) {
				cout << "There are no countries in the world" << endl;
			} else {
				for (auto t: capitalCountry) {
					cout << t.first << "/" << t.second << " ";
				}
				cout << endl;
			}
		} else {
			cout << "Error: 002";
		}
	}
}

void BusStation1() {
	int N = 0;
	cin >> N;
	map<string, vector<string>> busStation; // Автобус[остановки]
	map<string, vector<string>> subSequenceBus; // Остановка[автобусы]

	for (int i = 0; i < N; i++) {
		string operation;
		cin >> operation;

		if (operation == "NEW_BUS") {
			string bus;
			int stopCount = 0;
			cin >> bus >> stopCount;
			for (int i = 0; i < stopCount; i++) {
				string stopStation;
				cin >> stopStation;
				busStation[bus].push_back(stopStation);
				subSequenceBus[stopStation].push_back(bus);
			}
		} else if (operation == "BUSES_FOR_STOP") {
			// вывести названия всех маршрутов автобуса, проходящих через остановку stop
			string stopStation;
			cin >> stopStation;
			if (subSequenceBus.count(stopStation) == 0) {
				cout << "No stop" << endl;
				continue;
			} else {
				for (string busName: subSequenceBus[stopStation]) {
					cout << busName << " ";
				}
				cout << endl;
			}
		} else if (operation == "STOPS_FOR_BUS") {
			string bus;
			cin >> bus;
			// вывести названия всех остановок маршрута bus со списком автобусов,
			// на которые можно пересесть на каждой из остановок
			if (busStation.count(bus) == 0) {
				cout << "No bus" << endl;
			} else {
				const vector<string> &stops = busStation[bus];
				for (int i = 0; i < stops.size(); i++) {
					cout << "Stop " << stops[i] << ": " << endl;
					const vector<string> &busesForStop = subSequenceBus[stops[i]];
					if (busesForStop.size() == 1) {
						cout << "no interchange" << endl;
					} else {
						for (int j = 0; j < busesForStop.size(); j++) {
							if (busesForStop[j] != bus) {
								cout << busesForStop[j] << " ";
							}
						}
					}
					cout << endl;
				}
			}
		} else {
			// ALL_BUSES - вывести список всех маршрутов с остановками.
			if (busStation.size() == 0) {
				cout << "No buses" << endl;
				continue;
			}
			for (auto my_pair: busStation) {
				const vector<string> &stops = my_pair.second;
				cout << "Bus " << my_pair.first << ": ";
				for (string stop: stops) {
					cout << stop << " ";
				}
				cout << endl;
			}
		}
	}
}

void BusStation2() {
	int N = 0;
	cin >> N;
	map<vector<string>, int> busInfo; // busInfo[Остановки] = номер автобуса
	int currId = 1;

	for (int i = 0; i < N; i++) {
		int numOperation;
		cin >> numOperation;
		vector<string> busStation;

		for (int j = 0; j < numOperation; j++) {
			string str;
			cin >> str;
			busStation.push_back(str);
		}

		if (busInfo.count(busStation) == 0) {
			busInfo[busStation] = currId;
			cout << "New bus " << currId++ << endl;
		} else {
			cout << "Already exists for " << busInfo[busStation] << endl;
		}
	}
}

void UniqueStr() {
	int N = 0;
	cin >> N;
	set<string> uniqueStr;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		uniqueStr.insert(str);
	}
	cout << uniqueStr.size();
}

set<string> BuildMapValuesSet(const map<int, string>& m) {
	set<string> retSet;
	for (auto my_pair: m) {
		retSet.insert(my_pair.second);
	}
	return retSet;
}

void Synonyms() {
	int N = 0;
	cin >> N;
	map<string, set<string>> sinonyms;

	for (int i = 0; i < N; i++) {
		string operation;
		cin >> operation;

		if (operation == "ADD") {
			string word1, word2;
			cin >> word1 >> word2;
			sinonyms[word1].insert(word2);
			sinonyms[word2].insert(word1);
		} else if (operation == "COUNT") {
			string word;
			cin >> word;
			cout << sinonyms[word].size() << endl;
		} else if (operation == "CHECK") {
			string word1, word2;
			cin >> word1 >> word2;
			if (sinonyms.count(word1) != 0 && sinonyms[word1].count(word2) != 0) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}
}

void setBusStation() {
	int N = 0;
	cin >> N;
	map<set<string>, int> busInfo; // busInfo[Остановки] = номер автобуса
	int currId = 1;

	for (int i = 0; i < N; i++) {
		int numOperation;
		cin >> numOperation;
		set<string> busStation;

		for (int j = 0; j < numOperation; j++) {
			string str;
			cin >> str;
			busStation.insert(str);
		}

		if (busInfo.count(busStation) == 0) {
			busInfo[busStation] = currId;
			cout << "New bus " << currId++ << endl;
		} else {
			cout << "Already exists for " << busInfo[busStation] << endl;
		}
	}
}

//int main() {
//	AverageTemperature();
//	QueuePeople();
//	ToDoList();
//	Anagrams();
//	DirectoryCapitals();
//	BusStation1();
//	BusStation2();
//	UniqueStr();
//	Synonyms();
//	setBusStation();

    // std::cout << Factorial(0);
    // std::string t_str;
    // std::cin >> t_str;
//    std::cout << "34324";

//    return 0;
//}
