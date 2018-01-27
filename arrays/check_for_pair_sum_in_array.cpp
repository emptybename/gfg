// https://www.geeksforgeeks.org/write-a-c-program-that-given-a-set-a-of-n-numbers-and-another-number-x-determines-whether-or-not-there-exist-two-elements-in-s-whose-sum-is-exactly-x/
#include<iostream>
#include<algorithm>
using namespace std;

void CheckPair(int ar[], int n, int sum){
	std::sort(ar, ar+n);
	int left = 0;
	int right = n-1;
	// for(int i = 0;i < n;i++)cout<<ar[i]<<" ";
	// cout<<endl;
	while(left < right){
		if(ar[left]+ar[right] > sum)right--;
		else if(ar[left] + ar[right] < sum)left++;
		else{
			cout<<ar[left]<<" + "<<ar[right]<<endl;
			return;
		}
	}
	cout<<"-1"<<endl;
}

int main(){
	int n;
	cin >>n;
	int ar[n];
	for(int i = 0;i<n;i++)cin>>ar[i];
	int sum;
	cin>>sum;
	CheckPair(ar, n, sum);
}