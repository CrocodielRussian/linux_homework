#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
	string s = "find anybody";
	string ss = "x";
	
	size_t found = s.find(ss);
	if (found!=std::string::npos)
		cout << found << "\n";

	return 0;
}
