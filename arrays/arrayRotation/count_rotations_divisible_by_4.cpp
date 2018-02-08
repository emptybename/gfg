// https://www.geeksforgeeks.org/count-rotations-divisible-4/
#include<iostream>
#include<string>
using namespace std;

int countRotations(string s){
	int len = s.length();
	if(len == 1 && (s[0]- '0') % 4 == 0 ){
		return 1;
	}
	else if(len == 1 && (s[0]- '0') % 4 != 0){
		return 0;
	}
	else{
		int count  = 0;
		int sum = s[0]-'0';
		for(int i = 0;i < len;i++){
			sum = sum*10 + (s[(i+1)%len]-'0');
			sum %= 100;
			if(sum % 4 == 0)count++;
		}
		return count;
	}

}


int main(){
	string s;
	cin>>s;
	cout<<countRotations(s)<<endl;
}