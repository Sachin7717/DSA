#include<iostream>
using namespace std;


void change(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        arr[i]=3*arr[i];
    }
    
}

int main(){
    int arr[]={5,6,4};
    change(arr,3);
    for (int i = 0; i < 3; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}