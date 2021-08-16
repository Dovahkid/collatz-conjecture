#include <iostream>
#include <fstream>
#include <string>

using namespace std;

unsigned long long calculation(unsigned long long, ofstream&);

int main() {
	
	for (unsigned long long i = 1; i <= 1000000; i++) {
		ofstream fileOut("./collatz output/"+ to_string(i) + ".txt", ios_base::app);
		
		if (!fileOut) {
			cerr << "File could not be loaded! " << to_string(i) << endl;
			continue;
		}
		
		calculation(i, fileOut);
		fileOut << " " << endl;
		
		fileOut.close();
	}

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
