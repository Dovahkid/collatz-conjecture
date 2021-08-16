/*
 * g++ collatz.cpp -o collatz.exe -static
 * */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

unsigned long long calculation(unsigned long long, ofstream&);

int main() {

	unsigned long long min;
	unsigned long long max;

	cout << "Please enter a min a max space seperated: ";
	cin >> min >> max;

	for (unsigned long long i = min; i <= max; i++) {
		ofstream fileOut("./collatz output/"+ to_string(i) + ".txt", ios_base::app);
		
		if (!fileOut) {
			cerr << "File could not be loaded! " << to_string(i) << endl;
			continue;
		}
		cout << "Calculating: " << i << endl;		
		calculation(i, fileOut);
		fileOut << " " << endl;
		
		fileOut.close();
	}

	cout << endl << "---------------" << endl;
	cout << "     DONE!     " << endl;
	cout << "---------------" << endl;

	return 0;
}

unsigned long long calculation(unsigned long long num, ofstream& output) {
	
	output << num << endl;

	if (num == 1) {
		return 1;
	}

	if (num % 2 == 0) {
		return calculation(num/2, output);
	}
	else {
		return calculation( (3*num) + 1, output);
	}

}
