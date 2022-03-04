#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
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

class SortedStrings {
public:
  void AddString(const string& s) {
	m_sortedStr.push_back(s);
	std::sort(m_sortedStr.begin(), m_sortedStr.end());
  }
  vector<string> GetSortedStrings() {
	// получить набор из всех добавленных строк в отсортированном порядке
	  return m_sortedStr;
  }
private:
  vector<string> m_sortedStr;
};

class Person {
public:
	Person() = delete;
	Person(string fName, string lName, int year) {
		ChangeFirstName(year, fName);
		ChangeLastName(year, lName);
		m_birthDay = year;
	}
	int getLastYear(int year, const map<int, string>& params) const {
		int lastYear = -1;

		for (auto o: params) {
			if (o.first <= year) {
				lastYear = o.first;
			}
		}

		return lastYear;
	}
	int getPostYear(int year, const map<int, string>& params) const {
		int postYear = -1;
		for (auto o: params) {
			if (o.first > year) {
				postYear = o.first;
				break;
			}
		}

		return postYear;
	}
	string getLastParam(int year, const map<int, string>& params) const {
		int lastYear = getLastYear(year, params);

		if (lastYear == -1) {
			return "";
		}

		return params.at(lastYear);
	}
	string getFullLastParam(int year, const map<int, string>& params) const {
		string retStr = getLastParam(year, params);
		int lastYear = getLastYear(year, params);

		if (lastYear == -1) {
			return "";
		}

		vector<string> historyChange;
		for (auto o: params) {
			if (o.first < lastYear) {
				historyChange.push_back(o.second);
			}
		}

		if (historyChange.size() == 0) {
			return retStr;
		}

		string t_str;
		for (int i = 0; i < historyChange.size(); i++) {
			if (i == (historyChange.size()-1) && historyChange[i] == retStr) {
				continue;
			}
			t_str = historyChange[i] + ", "+ t_str;
		}
		if (t_str.size() > 2) {
			t_str.resize(t_str.size() - 2);
		} else {
			return retStr;
		}

		return retStr + " (" + t_str + ")";
	}
  void ChangeFirstName(int year, const string& first_name) {
	// добавить факт изменения имени на first_name в год year
	  if (year < m_birthDay) {
		  return;
	  }

	  if (getLastParam(year, m_changeFirstName) == first_name) {
		  return;
	  }
//	  int postDate = getPostYear(year, m_changeFirstName);
//	  if (postDate != -1 && m_changeFirstName[postDate] == first_name) {
//		  m_changeFirstName.erase(postDate);
//	  }
	  m_changeFirstName[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
	// добавить факт изменения фамилии на last_name в год year
	  if (year < m_birthDay) {
		  return;
	  }

	  if (getLastParam(year, m_changeLastName) == last_name) {
		  return;
	  }
//	  int postDate = getPostYear(year, m_changeLastName);
//	  if (postDate != -1 && m_changeLastName[postDate] == last_name) {
//		  m_changeLastName.erase(postDate);
//	  }
	  m_changeLastName[year] = last_name;
  }
  string GetFullName(int year) const {
	// получить имя и фамилию по состоянию на конец года year
//	if (m_changeFirstName.size() == 0 || m_changeLastName.size() == 0) {
//		return "Error: 001";
//	}
	  if (year < m_birthDay) {
		  return "No person";
	  }

	string oldFName = getLastParam(year, m_changeFirstName);
	string oldLName = getLastParam(year, m_changeLastName);
	string retstr;

	if (oldFName.size() == 0 && oldLName.size() == 0) {
		retstr = "Incognito";
	} else if (oldFName.size() != 0 && oldLName.size() != 0) {
		retstr = oldFName + " " + oldLName;
	} else if (oldFName.size() == 0) {
		retstr = oldLName + " with unknown first name";
	} else if (oldLName.size() == 0) {
		retstr = oldFName + " with unknown last name";
	}

	return retstr;
  }
  string GetFullNameWithHistory(int year) const {
	  // получить все имена и фамилии по состоянию на конец года year

	  if (year < m_birthDay) {
		  return "No person";
	  }

	  string oldFName = getFullLastParam(year, m_changeFirstName);
	  string oldLName = getFullLastParam(year, m_changeLastName);
	  string retstr;

	  if (oldFName.size() == 0 && oldLName.size() == 0) {
		  retstr = "Incognito";
	  } else if (oldFName.size() != 0 && oldLName.size() != 0) {
		  retstr = oldFName + " " + oldLName;
	  } else if (oldFName.size() == 0) {
		  retstr = oldLName + " with unknown first name";
	  } else if (oldLName.size() == 0) {
		  retstr = oldFName + " with unknown last name";
	  }

	  return retstr;
  }
private:
  // приватные поля
  map<int, string> m_changeFirstName;
  map<int, string> m_changeLastName;
  int m_birthDay;
};

class ReversibleString {
public:
	ReversibleString(string str) : m_str(str) {}
	ReversibleString() {}
	void Reverse() {
		reverse(m_str.begin(), m_str.end());
	}
	string ToString() const {
		return m_str;
	}
private:
	string m_str;
};

class Incognizable {
public:
	Incognizable() {}
	Incognizable(int i) {}
	Incognizable(int i, int g) {}
};

//int main() {
//	Incognizable a;
//	  Incognizable b = {};
//	  Incognizable c = {0};
//	  Incognizable d = {0, 1};

//	Person person("Polina", "Sergeeva", 1960);
//	  for (int year : {1959, 1960}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	  }

//	  person.ChangeFirstName(1965, "Appolinaria");
//	  person.ChangeLastName(1967, "Ivanova");
//	  for (int year : {1965, 1967}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	  }

//	ReversibleString s("live");
//	  s.Reverse();
//	  cout << s.ToString() << endl;

//	  s.Reverse();
//	  const ReversibleString& s_ref = s;
//	  string tmp = s_ref.ToString();
//	  cout << tmp << endl;

//	  ReversibleString empty;
//	  cout << '"' << empty.ToString() << '"' << endl;

//	Person person("Polina", "Sergeeva", 1960);
//	  for (int year : {1959, 1960}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	  }

//	  person.ChangeFirstName(1965, "Appolinaria");
//	  person.ChangeLastName(1967, "Ivanova");
//	  for (int year : {1965, 1967}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	  }

//	Person person;

//	  person.ChangeFirstName(1965, "Polina");
//	  person.ChangeLastName(1967, "Sergeeva");
//	  for (int year : {1900, 1965, 1990}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	  }

//	  person.ChangeFirstName(1970, "Appolinaria");
//	  for (int year : {1969, 1970}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	  }

//	  person.ChangeLastName(1968, "Volkova");
//	  for (int year : {1969, 1970}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	  }

//	  person.ChangeFirstName(1990, "Polina");
//	  person.ChangeLastName(1990, "Volkova-Sergeeva");
//	  cout << person.GetFullNameWithHistory(1990) << endl;

//	  person.ChangeFirstName(1966, "Pauline");
//	  cout << person.GetFullNameWithHistory(1966) << endl;

//	  person.ChangeLastName(1960, "Sergeeva");
//	  for (int year : {1960, 1967}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	  }

//	  person.ChangeLastName(1961, "Ivanova");
//	  cout << person.GetFullNameWithHistory(1967) << endl;

//	Person person;
//	person.ChangeFirstName(1965, "Polina");
//	person.ChangeLastName(1967, "Sergeeva");
//	for (int year : {1900, 1965, 1990}) {
//	cout << person.GetFullName(year) << endl;
//	}

//	person.ChangeFirstName(1970, "Appolinaria");
//	for (int year : {1969, 1970}) {
//	cout << person.GetFullName(year) << endl;
//	}

//	person.ChangeLastName(1968, "Volkova");
//	for (int year : {1969, 1970}) {
//	cout << person.GetFullName(year) << endl;
//	}

//	SortCaseInsensitive();
//	SortNumbers();
//	return 0;
//}
