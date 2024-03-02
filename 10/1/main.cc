#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <system_error>
int check(int ret){
	if(ret == -1){
		throw std::system_error(errno,  std::generic_category());
	}
	return ret;
}
int main(){
	int fd = check(open("file.txt", O_CREAT|O_WRONLY|O_TRUNC, 0644));
	std::clog<< fd << "\n";
	std::string msg = "Oh! Yeah!\n";
	check(write(fd, msg.data(), msg.size()));
	check(close(fd));
	return 0;
}
