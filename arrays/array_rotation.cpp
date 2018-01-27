// Rotate array by d elememts.
// https://www.geeksforgeeks.org/array-rotation/
#include<iostream>
#include<stdio.h>
using namespace std;

void PrintArray(int ar[], int n){
	for(int i = 0;i < n; i++)cout<<ar[i]<<" ";
	cout<<endl;
}

void RotateArraySolution1(int array_to_rotate[], int n, int d){
	//time complexity O(n), space complexity O(d)
	int temp_array[d];
	for(int i = 0;i < d;i++)temp_array[i] = array_to_rotate[i];
	//shift array leftward by d
	for(int i = 0;i+d < n;i++)array_to_rotate[i] = array_to_rotate[i+d];
	for(int i = 0;i < d;i++)array_to_rotate[n-d+i] = temp_array[i];
	//for(int i = 0; i < n;i++)cout<<array_to_rotate[i]<<" ";
	//PrintArray(array_to_rotate, n);
}

void RotateArraySolution2(int array_to_rotate[], int n, int d){
	// time complexity O(nd), space complexity O(1)
	for(int i = 0;i < d; i++){
		int temp = array_to_rotate[0];
		for(int j = 1; j < n;j++)array_to_rotate[j-1] = array_to_rotate[j];
		array_to_rotate[n-1] = temp;
	}
	//PrintArray(array_to_rotate, n);
}

int Gcd(int a, int b){
	if(b == 0)return a;
	return Gcd(b, a%b);
}
// Jungling Algorithm
void RotateArraySolution3(int array_to_rotate[], int n, int d){
	int shift_val = Gcd(n,d);
	for(int i = 0;i < shift_val;i++){
		int temp = array_to_rotate[i];
		int j = i;
		while(1){
			int k = j+d;
			if(k >= n)k = k-n;
			if(k == i) break;
			array_to_rotate[j] = array_to_rotate[k];
			j = k;
		}
		array_to_rotate[j] = temp;
	}
}
// Reversal Algorithm

void ReverseArray(int ar[], int start, int end){
	while(start < end){
		int temp = ar[start];
		ar[start] = ar[end];
		ar[end] = temp;
		start++;
		end--; 
	}
}

void RotateArraySolution4(int array_to_rotate[], int n, int d){
	ReverseArray(array_to_rotate, 0, d-1);
	ReverseArray(array_to_rotate, d, n-1);
	ReverseArray(array_to_rotate, 0, n-1);
}
int main(){
	int n;
	cin>>n;
	int array_to_rotate[n];
	for(int i = 0;i < n;i++)cin>>array_to_rotate[i];
	int d;
	cin>>d;
	//RotateArraySolution1(array_to_rotate,n,d);
	//RotateArraySolution2(array_to_rotate,n,d);
	//RotateArraySolution3(array_to_rotate, n, d);
	RotateArraySolution4(array_to_rotate, n, d);
	PrintArray(array_to_rotate, n);
}

