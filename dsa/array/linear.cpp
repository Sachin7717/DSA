#include<iostream>
using namespace std;

int linear(int arr[], int target){
     for (int i = 0; i < 5; i++)
    {
        if (arr[i]==target)
        {
            cout << "Element found at index: " << i << endl;
           return i; 
        }

    }
    cout << "Element not found" << endl;
    return -1;
}

int main(){
    int arr[5]={10, 4, 24, -10, 15};
    int target = -10;
   
    cout<<linear(arr,target)<<endl;

    return 0;
}