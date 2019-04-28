#include<iostream>
using namespace std;


int main(){
	int a ;
	int *b = &a;
	std::cout << sizeof(int) << std::endl;
	std::cout << sizeof(int*) << std::endl;

	return 0;
}
