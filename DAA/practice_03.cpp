#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr,int low,int high)
{
    int pivot,p,q;
    pivot=arr[low];
    p=low+1;
    q=high;

    do{
        while(p<=q && arr[p]<=pivot)
        {
            p++;
        }
        while(arr[q]>pivot)
        {
            q--;
        }
        if(p<q)
        {
            swap(arr[p],arr[q]);
        }
    }while(p<q);

    swap(arr[low],arr[q]);
    return q;
}

void quicksort(vector<int> &arr,int low,int high)
{
    if(low<high)
    {
        int k=partition(arr,low,high);
        quicksort(arr,low,k-1);
        quicksort(arr,k+1,high);
    }
}

void printArray(const vector<int>& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {

    vector<int> arr = {12, 4, 5, 6, 7, 3, 1, 15, 2, 8};
    
    cout << "Original array: ";
    printArray(arr);

    quicksort(arr,0,arr.size());
    printArray(arr);

    return 0;
}
