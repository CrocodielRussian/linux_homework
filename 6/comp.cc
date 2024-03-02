#include<cmath>

int main(){
	int* ptr = nullptr;
	float s = 0;
	for(int i = 0; i < 10000000; i++)
		s += std::sin(i / 1000.f);

}


