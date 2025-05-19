#include<iostream>
using namespace std;

int main(){
    int nums[]={10,4,24,-10,15};
    int size=6;

    int smallest= INT16_MAX;
for (int i = 0; i < size; i++)
{
    if (nums[i]<smallest)
    {
       smallest=nums[i];
    }
    
}
cout<<smallest;


    return 0;
}