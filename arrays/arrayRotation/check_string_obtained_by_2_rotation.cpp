// https://www.geeksforgeeks.org/check-string-can-obtained-rotating-another-string-2-places/

#include<iostream>
#include<cmath>
#include<string>

using namespace std;
bool compareString(string x, string y, int len, int ax, int by){
	for(int i = 0;i<len;i++){
		if(x[ax%len] != y[by%len]){
			return false;
		}
	}
	return true;
}

bool isRotatedByTwo(string x, string y){
	int len = x.length();
	if(len != y.length())return false;
	bool f = true;
	f = compareString(x, y, len, 2, 0);
	if(f)
		return true;
	else{
		f = compareString(x, y, len, abs(len-2), 0);
	}
	return f;
}

int main(){
	string x,y;
	cin>>x>>y;
	if(isRotatedByTwo(x,y))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}