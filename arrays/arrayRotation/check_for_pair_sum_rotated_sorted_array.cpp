// https://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/
#include<iostream>
using namespace std;

int FindPivot(int ar[], int n){
	for(int i = 0;i < n-1;i++){
		if(ar[i] > ar[i+1])return i;
	}
	return -1;
}

void PairSum(int ar[], int n, int left, int right, int sum){
	while(left != right){
		if(ar[left] + ar[right] > sum)right = (n+(--right))%n;
		else if(ar[left] + ar[right] < sum)left = (n+(++left))%n;
		else{
			cout<<ar[left]<<" + "<<ar[right]<<endl;
			return;
		}
	}
	cout<<"-1"<<endl;
}

void CheckPairSum(int ar[], int n, int sum){
	int pivot = FindPivot(ar, n);
	int left,right;
	if(pivot == -1){
		left = 0;
		right = n-1;
		// while(left < right){
		// 	if(ar[left] + ar[right] > sum)right--;
		// 	else if(ar[left] + ar[right] < sum)left++;
		// 	else{
		// 		cout<<ar[left]<<" + "<<ar[right]<<endl;
		// 		return;
		// 	}
		// } 
	}
	else{
		left = pivot + 1;
		right = pivot;
		// while(left != right){
		// 	if(ar[left] + ar[right] > sum)right = (n+(--right))%n;
		// 	else if(ar[left] + ar[right] < sum)left = (n+(++left))%n;
		// 	else{
		// 		cout<<ar[left]<<" + "<<ar[right]<<endl;
		// 		return;
		// 	}
		// }
	}
	PairSum(ar, n, left, right, sum);
}

int main(){
	int n;
	cin>>n;
	int ar[n];
	for(int i = 0;i < n;i++)cin>>ar[i];
	int sum;
	cin>>sum;
	CheckPairSum(ar, n, sum);
}
