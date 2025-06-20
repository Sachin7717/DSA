#include<iostream>
using namespace std;

int main(){
    int nums[5]={10,4,24,-10,15};
    int smallest= INT16_MAX;
    int largest= INT16_MIN;
    for (int i = 0; i < 5; i++)
    {
        if (nums[i]< smallest)
        {
            smallest=nums[i];
        }

        if (nums[i]> largest)
        {
            largest=nums[i];
        }
        
        
    }
    cout<<smallest<<endl;
    cout<<largest;

    return 0;
}