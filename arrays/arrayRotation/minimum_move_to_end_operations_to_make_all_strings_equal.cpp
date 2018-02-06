// https://www.geeksforgeeks.org/minimum-move-end-operations-make-strings-equal/
#include<iostream>
#include<string>
#define f(l,n) for(int i = l;i < n;i++)
using namespace std;
int n;
int ar[1000][1000];

int numberOfRotation(string a, string b){
	int aLen = a.length();
	int bLen = b.length();
	if(aLen != bLen)return -1;
	a += a;
	return a.find(b);

}

void makeEveryRotation(int sLen){
	f(1,n){
		for(int j = 0;j < n;j++){
			if(i == j)
				ar[i][j] = 0;
			else if(j < i){
				ar[i][j] = sLen - ar[j][i];
			}
			else{
				ar[i][j] = (ar[i-1][j] - ar[i-1][i] + sLen) % sLen;
			}
		}
	}
}

int minRotationCount(){
	int min = INT_MAX;
	f(0,n){
		int temp = 0;
		for(int j = 0;j < n; j++){
			temp += ar[j][i];
		}
		if(temp < min)min = temp;
	}
	return min;
}

int main(){
	//int n;
	cin>>n;
	string s[n];
	f(0,n)cin>>s[i];
	//int ar[n][n];
	ar[0][0] = 0;
	int sLen = n > 0 ? s[0].length() : 0; 
	f(1,n){
		ar[0][i] = numberOfRotation(s[0],s[i]);
		if(ar[0][i] == -1){
			cout<<"-1"<<endl;
			return 0;
		}
	}
	makeEveryRotation(sLen);
	f(0,n){
		for(int j = 0;j<n;j++)cout<<ar[i][j]<<" ";
		cout<<endl;
	}
	cout<<minRotationCount()<<endl;
}