#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <system_error>
using namespace std;
class File{
	private:
		int _fd = -1;
		std::string _name = "";
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
		~File(){
			//clog << "Close" << "\n";
			_check(close(_fd));
		}
		void cover_write(std::string &&msg){
			_check(write(_fd, msg.data(), msg.size()));
		}
		void set_position(int pos){
			_check(lseek(_fd, pos, SEEK_SET));
		}
		int get_position(){
			return _check(lseek(_fd, 0, SEEK_CUR));
		}
		std::string cover_read(int size){
			char buf[size+1];
			_check(lseek(_fd, 0, SEEK_SET));
			_check(read(_fd, buf, size));
			
			//clog <<"read"<<"\n";
			return (string)buf;
		}
	
};
void func(){
	File file("hello.txt");

	cout << file.cover_read(5) << "\n";
	file.cover_write("hello1\n");
	file.set_position(0);
	std::clog << file.get_position() << "\n";

}
int main(){
	func();
	return 0;	
}
