// https://www.geeksforgeeks.org/rotate-matrix-180-degree/ 
#include<iostream>
#include<stdio.h>
#define f(l,n) for(int i = l;i < n;i++)
#define N 100
#define M 100
using namespace std;

void transpose(int ar[N][M], int n, int m){
	int br[N][M];
	f(0,m)
		for(int j = 0;j < n; j++){
			br[i][j] = ar[j][i];
		}
	f(0,m)
		for(int j = 0;j < n;j++)
			ar[i][j] = br[i][j];
}

void reverse(int ar[N][M], int n, int m){
	f(0,n/2)
		for(int j = 0;j < m;j++){
			int temp = ar[i][j];
			ar[i][j] = ar[n-1-i][j];
			ar[n-1-i][j] = temp;
		}
}

void rotateArrayBy180(int ar[N][M], int n, int m){
	transpose(ar, n, m);
	reverse(ar, m, n);
	transpose(ar, m, n);
	reverse(ar, n, m);
}

int main(){
	int n,m;
	cin>>n>>m;
	int ar[N][M];
	f(0,n)
		for(int j = 0;j < m;j++)cin>>ar[i][j];
	rotateArrayBy180(ar, n ,m);
	cout<<"Rotate: 180 degree"<<endl;
	f(0,n){
		for(int j = 0;j < m;j++){
			cout<<ar[i][j]<<" ";
		}
		cout<<endl;
	}
}