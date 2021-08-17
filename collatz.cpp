/*
 * g++ collatz.cpp -o collatz.exe -static
 * */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

unsigned long long calculation(unsigned long long, ofstream&, int&);

int main() {

	unsigned long long min;
	unsigned long long max;
	int count = 0;
	string folder;

	cout << "Please enter a min and max space seperated: ";
	cin >> min >> max;
	cin.ignore();
	
	cout << "Enter a folder to store the outputs in: ";
	cin >> folder;
	cin.ignore();

	for (unsigned long long i = min; i <= max; i++) {
		ofstream fileOut(folder + "/"+ to_string(i) + ".txt", ios_base::out);
		
		if (!fileOut) {
			cerr << "File could not be loaded! " << to_string(i) << endl;
			continue;
		}
		cout << "Calculating: " << i << endl;		
		calculation(i, fileOut, count);
		fileOut << " \n" << count << endl;
		
		count = 0;
		
		fileOut.close();
	}

	cout << endl << "---------------" << endl;
	cout << "     DONE!     " << endl;
	cout << "---------------" << endl;

	cin.get();

	return 0;
}

unsigned long long calculation(unsigned long long num, ofstream& output, int& count) {
	
	output << num << endl;
	count++;

	if (num == 1) {
		return 1;
	}

	if (num % 2 == 0) {
		return calculation(num/2, output, count);
	}
	else {
		return calculation( (3*num) + 1, output, count);
	}

}
