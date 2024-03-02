#include <iostream>
#include <unistd.h>
#include <sys/syscall.h> 

using namespace std;

int main(){
// 	pid_t pid = fork();
	/*
	if(pid == 0){
		clog << "getpid() = " << getpid() << "\n";
		pid_t tid = syscall(SYS_gettid);
		clog << "syscall() = " << tid << "\n";
	}
*/	
	clog << " getpid() = " << getpid() << "\n";
	pid_t tid = syscall(SYS_gettid);
	clog << "syscall() = " << tid << "\n";

	return 0;
}
