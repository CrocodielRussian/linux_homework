#include <iostream>
#include <unistd.h>
#include <sys/syscall.h> 
#include <sys/wait.h>
#include <memory>

using namespace std;

int main() {
  	char** first = environ;
	while (*first){
		string ss = *first;
		size_t found = ss.find("L");
		if(found!=std::string::npos)
    		std::cout << *first << '\n';
    	++first;
	}

	return 0;
}
