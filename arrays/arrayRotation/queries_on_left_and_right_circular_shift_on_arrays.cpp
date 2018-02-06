// https://www.geeksforgeeks.org/queries-left-right-circular-shift-array/

#include<iostream>
#define f(l,n) for(int i = l;i < n;i++)

using namespace std;

void queryToRotate(int *toRotate, int arSize, int type, int shift){
	if(type == 1){
		shift = arSize - shift%arSize;
		*toRotate = ((*toRotate) + shift) % arSize;
	}
	else{
		*toRotate = ((*toRotate) + shift) % arSize;
	}
}

int queryToGetSum( int *toRotate, int l, int r, int ar[], int arSize){
	l = (l+(*toRotate))%arSize;
	r = (r+(*toRotate))%arSize;
	int sum = 0;
	if(l > r){
		sum += ar[arSize-1]-ar[l-1] + ar[r];
	}
	else{

		sum += ar[r];
		if(l > 0)
			sum -= ar[l-1];
	}
	return sum;
}


int main(){
	int n;
	cin>>n;
	int presum[n];
	f(0,n){
		int x;
		cin>>x;
		if(i == 0)
			presum[i] = x;
		else
			presum[i] = presum[i-1] + x;
	}
	int toRotate = 0;
	int type;
	int shift;
	int l,r;
	while(1){
		cin>>type;
		if(type == 1 || type == 2){
			cin>>shift;
			// Query To Rotate
			queryToRotate(&toRotate, n, type, shift);
		}
		else if(type == 3){
			cin>>l>>r;
			//Get sum of l ot r from rotated Array
			cout<<queryToGetSum(&toRotate, l, r, presum, n)<<endl;
		}
		else
			break;
	}


}