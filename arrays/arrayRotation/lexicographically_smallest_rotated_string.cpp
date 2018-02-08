// https://www.geeksforgeeks.org/lexicographically-smallest-rotated-sequence-set-2/
#include<iostream>
#include<string>
#define f(l,n) for(int i = l;i < n;i++)
#define c(n) cin>>n
using namespace std;

bool compareString(string s, int len, int a, int b){
	f(0,len){
		if(s[a] > s[b])
			return true;
		else if(s[b] > s[a])
			return false;
		a = (a+1) % len;
		b = (b+1) % len;
	}
	return false;
}

int getIndex(string s, int len){
	int min = 0; 
	f(1,len){
		if(compareString(s, len, min, i))
			min = i;
	}
	return min;
}

void printLexicographicallySmallest(string s){
	int len = s.length();
	int index = getIndex(s, len);
	f(0,len){
		cout<<s[index++];
		index %= len;
	}
	cout<<endl;
}

int main(){
	string s;
	c(s);
	printLexicographicallySmallest(s);
}