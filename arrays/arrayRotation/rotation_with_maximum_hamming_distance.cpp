// https://www.geeksforgeeks.org/find-a-rotation-with-maximum-hamming-distance/
#include<iostream>
#define f(l,n) for(int i = l;i < n;i++)
using namespace std;

int calculateHammingDistance(int ar[], int n, int br[]){
	int sum = 0;
	f(0,n){
		if(ar[i] != br[i])sum++;
	}
	return sum;
}

void RotateArrayWithMaximumHammingDistace(int ar[], int n){
	int br[2*n];
	f(0,2*n)br[i] = ar[i%n];
	int start = 0;
	int end = 0;
	int maxDistance = 0;
	f(0,n){
		int temp = calculateHammingDistance(ar, n, br+i);
		if(temp > maxDistance)start = i;
	}
	f(start, start+n)cout<<br[i]<<" ";
	cout<<endl;
}

int main(){
	int n;
	cin>>n;
	int ar[n];
	f(0,n)cin>>ar[i];
	RotateArrayWithMaximumHammingDistace(ar, n);
}