//https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
#include<iostream>
#include<stdio.h>
using namespace std;

int FindPivot(int arr[], int low, int high){
	if(low > high)return -1;
	int mid = (low+high)/2;
	if(arr[mid] > arr[mid+1])
		return mid;
	if(arr[low] > arr[mid])
		return FindPivot(arr, low, mid-1);
	return FindPivot(arr, mid+1, high);
}

int BinarySearch(int arr[], int low, int high, int element){
	if(low > high)return -1;
	int mid = (low+high)/2;
	if(arr[mid] > element)
		return BinarySearch(arr, low, mid-1, element);
	else if(arr[mid] < element)
		return BinarySearch(arr, mid+1, high, element);
	else
		return mid;
}

int FindElement(int arr[], int size, int element){
	int pivot = FindPivot(arr, 0, size-1);
	if(pivot == -1)return BinarySearch(arr, 0, size-1, element);
	int index = BinarySearch(arr, 0, pivot, element);
	if(index == -1)
		index = BinarySearch(arr, pivot, size-1, element);
	return index;
}

int main(){
	int n;
	cin>>n;
	int rotated_array[n];
	for(int i = 0;i < n;i++)cin>>rotated_array[i];
	int element;
	cin>>element;
	cout<<FindElement(rotated_array, n, element);	
}