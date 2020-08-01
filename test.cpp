#include <iostream>
#include <cstring>
using namespace std;

class Student {
	string surname;
	int roll;
public:
	Student() {};
	Student(string n, int r) {
		surname = n;
		roll =r;
	}
	friend ostream& operator<<(ostream& os, const Student& source) {
		os << source.surname << endl;
		os << "Roll No. : "<< source.roll << endl;
		return os;
	}
	~Student() {};
};

template <typename Data, typename Explaination>
class Dictionary {
	Data index;
	Explaination name;
public:
	Dictionary(Data, Explaination);
	Dictionary() {};
	Dictionary& operator=(const Dictionary&);
	friend ostream& operator<<(ostream& os, const Dictionary& source) {
		os << "Data: " << source.index << endl;
		os << "Explaination: " << source.name << endl;
		// cout << s1;
		return os;
	}
	// void print();
	~Dictionary() {};
};

template <typename Data, typename Explaination>
Dictionary<Data, Explaination>::Dictionary(Data d, Explaination e) {
	index = d;
	name = e;
}

// template <typename Data, typename Explaination>
// void Dictionary<Data, Explaination>::print() {
// 	cout << index << endl << name << endl;
// }

template <typename Data, typename Explaination>
Dictionary<Data, Explaination> &Dictionary<Data, Explaination>::operator=(const Dictionary& source) {
	index = source.index;
	name = source.name;
	return *this;
}

int main () { 
	Student s1("keshav",21);
	Dictionary<int, Student> d1(2, s1), d2, d3;
	d3 = d1;
	cout << d3 << endl << d1;
  	return 0;
}