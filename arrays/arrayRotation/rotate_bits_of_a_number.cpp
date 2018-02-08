// https://www.geeksforgeeks.org/rotate-bits-of-an-integer/

#include<iostream>
#define INT_BITS 32

using namespace std;

int calculateRemainingBits(int n){
	int i = 0;
	while(i < INT_BITS && !(n & (1U<<(31-i))))
		i++;
	return i;
}

int leftRotate(unsigned int n, int d){
	int i = calculateRemainingBits(n);
	return ((n<<(i+d))>>i) | (n>>(INT_BITS-(d+i)));
}

int rightRotate(unsigned int n, int d){
	int i = calculateRemainingBits(n);
	return ((n<<(INT_BITS-d)))>>i | n>>d;
}

int main(){
	int n,d;
	cin>>n>>d;
	cout<<rightRotate(n,d)<<endl;
	cout<<leftRotate(n,d)<<endl;
	
}