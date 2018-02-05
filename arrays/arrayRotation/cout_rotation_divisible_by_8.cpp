//https://www.geeksforgeeks.org/count-rotations-divisible-8/

#include<iostream>
#define f(l,n) for(int i = l;i < n;i++)
#define max 10000
using namespace std;

int getCount(string s){
	int len = s.length();
	int count = 0;
	if(len == 1){
		if(s[0] == '8')
			return 1;
		else
			return 0;
	}
	if(len == 2){
		if(((s[0]-'0')*10+(s[1]-'0'))%8 == 0)count++;
		if(((s[1]-'0')*10+(s[0]-'0'))%8 == 0)count++;
		return count;
	}
	int sum = ((s[0] - '0')*10 + (s[1] - '0'))*10 + (s[2] - '0');
	if(sum%8 == 0)count++;
	f(1,len){
		sum = sum*10 + s[(i+2)%len] - '0';
		sum = sum % 1000;
		if(sum % 8 == 0)count++;
	}
	return count;
}

int main(){
	string s;
	cin>>s;
	cout<<getCount(s);
}