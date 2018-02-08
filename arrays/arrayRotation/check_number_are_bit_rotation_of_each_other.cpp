// https://www.geeksforgeeks.org/check-two-numbers-bit-rotations-not/
#include<iostream>
using namespace std;

bool isRotated(unsigned int a, unsigned int b){
	unsigned long long int x = a | ((unsigned long long int)a << 32);
	while(x >= b){
		if(unsigned(x) == b)return true;
		x >>= 1;
	}
	return false;
}

int main(){
	unsigned int a, b;
	cin>>a>>b;
	if(isRotated(a, b))
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
}