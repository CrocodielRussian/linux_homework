#include <iostream>
#include <utility>
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <system_error>
#include <sys/types.h>

using namespace std;
class File{
	private:
		int _fd = -1;
		std::string _name = nullptr;
		int _check(int result){
			if(result == -1)
				throw std::system_error(errno, std::generic_category());
			return result;
		}
	public:
		File(std::string&& name):
			_name(name){
				_name = name;
				_fd = _check(open(_name.data(), O_CREAT|O_RDWR, 0644));
				//clog << "Open" << "\n";
			}

		File(File& x): _name(x._name), _fd(x._fd){
			_fd = dup(_fd);
		}
		File(File&& x):_name(x._name),_fd(x._fd){
			x._fd = -1;
			x._name = nullptr;
		}
		~File(){
			clog << "Close" << "\n";
			_check(close(_fd));
		}
		File& operator=(File& x){
			_fd = dup2(_fd, x._fd);
			File tmp(x);
			std::swap(_fd, tmp._fd);
			std::swap(_name, tmp._name);
			return *this;
		}
		File& operator=(File&& x){
			File tmp(std::move(x));
			std::swap(_fd, tmp._fd);
			std::swap(_name, tmp._name);
			return *this;
		}
		void cover_write(std::string &&msg){
			_check(write(_fd, msg.data(), msg.size()));
		}
		std::string cover_read(int size){
			char buf[size+1];
			_check(lseek(_fd, 0, SEEK_SET));
			_check(read(_fd, buf, size));
			buf[size] = '\0';
		//	clog <<"read"<<"\n";
			return (string)buf;
		}
	
};
void func(){
	File file("hello.txt");

	file.cover_write("HO1igeeasdsdasdsadsa\n");
	
	cout << file.cover_read(5) << "\n";
	File file1 = File(file);
	//file1.cover_write("AA\n");
	cout <<	file1.cover_read(7) << "\n";

}
int main(){
	func();
	return 0;	
}
