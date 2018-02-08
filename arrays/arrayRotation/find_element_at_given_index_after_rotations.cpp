// https://www.geeksforgeeks.org/find-element-given-index-number-rotations/
/* just use pen paper and try to think you will see that its like stack. 
   Reverse all the rotation from last to first and you will get the original array
*/
#include<iostream>
#define f(l,n) for(int i = 0;i < n;i++)
#define fr(l,n) for(int i = n-1; i >= l;i--)

using namespace std;

struct node{
	int x;
	int y;
};


int findElement(int ar[], int n, struct node ranges[], int numOfRotation, int index){
	fr(0,numOfRotation){
		//cout<<ranges[i].x<<" "<<ranges[i].y;
		//cout<<endl;
		if(ranges[i].x <= index && ranges[i].y >= index){
			if(ranges[i].x == index)
				index = ranges[i].y;
			else
				index--;
			//cout<<index<<endl;
		}
	}
	return ar[index];
}

int main(){
	int n;
	cin>>n;
	int ar[n];
	f(0,n)cin>>ar[i];
	int numOfRotation;
	cin>>numOfRotation;
	struct node ranges[numOfRotation]; 
	f(0,numOfRotation)cin>>ranges[i].x>>ranges[i].y;
	int index;
	cin>>index;
	cout<<findElement(ar, n, ranges, numOfRotation, index)<<endl;

}