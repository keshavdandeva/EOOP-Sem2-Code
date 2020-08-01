#include <iostream>
#include <cstring>
#include <exception>
using namespace std;

class customException : public std::exception {
protected:
	int value;
	int index;
public:
	customException(){};
	customException(int v, int i) {
		value = v;
		index = i;
	}
	 const char * what() const throw () {	
		string error = to_string(value)+ " found at " + to_string(index);
		return error.c_str();
	}
	~customException(){};
};

int total(int tab[], int n) {
	int total_sum = 0;
	for (int i = 0; i < n; ++i) {
		try {
			if(tab[i] < 0)			
				throw customException(tab[i], i);
		} catch(customException &objec) {
			cout << objec.what() << endl;
		}
		total_sum += tab[i];
	}
	return total_sum;
} 

int main() {

	int arr[10] = { 1, 5, 23, 6, 12, -12, 2, -5, 0, 3 };
	
	cout << "Total: " << total(arr, 10) << endl;
	return 0;	
}