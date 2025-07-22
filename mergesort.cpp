#include<iostream>
using namespace std;
#include<vector>
void mergesort(int arr[], int start, int end, int mid) {
	vector<int>temp;
	int i,j;
	i = start;
	j = mid + 1;
	while (i <=mid && j <= end) {
		if (arr[i] < arr[j]) {
			temp.push_back(arr[i]);
			i++;
		}
		else {
			temp.push_back(arr[j]);
			j++;
		}
	}
	for (int i = 0;i < temp.size();i++) {
		arr[start + i] = temp.at(i);
	}
}
void merge(int arr[], int start, int end) {
	int mid = start + (end - start) / 2;
	if (start < end) {
		merge(arr, start, mid);//left
		merge(arr, mid + 1, end);//right;
	}
	mergesort(arr,start, end,  mid);

}
int main(){
	int arr[6] = { 1,6,5,8,9,3 };
	merge(arr, 0, 5);
	for (int i = 0;i < 6;i++) {
		cout << arr[i] << ",";
	}

}