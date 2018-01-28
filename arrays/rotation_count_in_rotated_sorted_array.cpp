// https://www.geeksforgeeks.org/find-rotation-count-rotated-sorted-array/

#include<iostream>
#define f(l,n) for(int i = l;i < n;i++)
using namespace std;

//Iterative Approach to find pivot
int FindPivot(int ar[], int left, int right){
	int mid;
	while(left <= right){
		//cout<<left<< " "<<right<<endl;
		mid = (left + right)/2;
		if(ar[mid] > ar[mid+1])return mid;
		if(ar[left] > ar[mid]){
			right = mid-1;
			continue;
		}
		left = mid+1;
	}
	return -1;
}


int CountRotation(int ar[], int n){
	int pivot = FindPivot(ar, 0, n-1);
	return pivot+1;
}

int main(){
	int n;
	cin>>n;
	int ar[n];
	f(0,n)cin>>ar[i];
	cout<<CountRotation(ar, n)<<endl;
}