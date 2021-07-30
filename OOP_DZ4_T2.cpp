#include <iostream>
#include <vector>
using namespace std;

int dif(vector<int> arr, int size) {
	bool d = true;
	int count = size;
	for (int i = 0; i <= size - 2; ++i) {
		for (int j = i + 1; j <= size - 1; ++j) {
			if (arr[i] == arr[j]) d = false;
		}
		if (!d) --count;
		d = true;
	}
	return count;
}

int main() {
	vector<int> vec{ 211, 111, 11, 121, 311, 211 };
	
	cout << dif(vec, vec.size()) << endl;


}