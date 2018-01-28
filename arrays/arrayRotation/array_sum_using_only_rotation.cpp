//  https://www.geeksforgeeks.org/find-maximum-value-of-sum-iarri-with-only-rotations-on-given-array-allowed/
// Find Sum of rotation using previous rotation sum.
// Use Formula :- Rj = Rj-1 + arrSum - n*An-j

#include<iostream>
#define f(l,n) for(int i = l;i < n;i++)
using namespace std;

int CalculateMaxSum(int ar[], int n){
	int arrSum = 0;
	int currentSum = 0;
	f(0,n){
		arrSum += ar[i];
		currentSum += i*ar[i]; 
	}
	int maxSum = currentSum;
	f(1,n){
		int tempSum = currentSum + arrSum - n*ar[n-i];
		if(tempSum > maxSum)maxSum = tempSum;
		currentSum = tempSum;
	}
	return maxSum;
}

int main(){
	int n;
	cin>>n;
	int ar[n];
	f(0,n)cin>>ar[i];
	cout<<CalculateMaxSum(ar, n)<<endl;
}