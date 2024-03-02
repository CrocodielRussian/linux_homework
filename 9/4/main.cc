#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/syscall.h> 
#include <sys/wait.h>
#include <memory>

using namespace std;

int child_main(void* ptr) {
  std::string s = "newname";
  sethostname(s.data(), s.size());
  system("hostname");
  return 0;
}

int main() {
	size_t stack_size = 1024*10;
	std::unique_ptr<char[]> child_stack(new char[stack_size]);
	pid_t pid = clone(child_main, child_stack.get() + stack_size, CLONE_NEWUTS | CLONE_NEWUSER | SIGCHLD, 0);
	int status = 0;
	wait(&status);
	system("hostname");
	wait(&status);
	return 0;
}
