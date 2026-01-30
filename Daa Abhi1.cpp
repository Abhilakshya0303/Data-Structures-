#include<iostream>
using namespace std;

//question 1
int main(){
	int arr[]={2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
	int low=0;
	int high=9;
	int target=23;
	while(high>=low){
		int mid=(high+low)/2;
		if(arr[mid]==target){
			cout<<"Found the target at: "<<mid;
			break;
		}
		else if(arr[mid]>target){
			high=mid;
		}
		else{
			low=mid;
		}
	}
}



//Q2
void merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(int i=0;i<n1;i++) L[i] = arr[l+i];
    for(int j=0;j<n2;j++) R[j] = arr[m+1+j];

    int i=0,j=0,k=l;

    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if(l < r){
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main(){
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n1 = 6;

    mergeSort(arr, 0, n1-1);
    for(int i=0;i<n1;i++) cout<<arr[i]<<" ";
    cout<<endl;

    int arr2[] = {38, 27, 43, 3, 9, 82, 10};
    int n2 = 7;

    mergeSort(arr2, 0, n2-1);
    for(int i=0;i<n2;i++) cout<<arr2[i]<<" ";
}



//Q3
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j=low;j<high;j++){
        if(arr[j] <= pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return i+1;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main(){
    int arr[] = {4, 2, 6, 9, 2};
    int n = 5;

    quickSort(arr, 0, n-1);

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}


//Q4
int main(){
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = 8;

    int maxSum = arr[0];
    int currSum = arr[0];

    for(int i=1;i<n;i++){
        if(currSum + arr[i] > arr[i])
            currSum = currSum + arr[i];
        else
            currSum = arr[i];

        if(currSum > maxSum)
            maxSum = currSum;
    }

    cout<<"Maximum subarray sum: "<<maxSum;
}


