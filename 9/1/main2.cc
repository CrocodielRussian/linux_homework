#include <iostream>
#include <unistd.h>
#include <sys/syscall.h> 
#include <sys/wait.h>

using namespace std;

int main(){
	pid_t pid = fork();
	
	if(pid == 0){
		const char* c = "expr";
		execlp(c, c, "2", "+", "2", "*", "2", 0);
		exit(0);
	}

	int status = 0;
	wait(&status);
	return 0;	
}
