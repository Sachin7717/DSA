#include<iostream>
#include<vector>
using namespace std;

vector<int> pairsum(vector<int> nums, int target){
    vector<int> ans;
    int n= nums.size();

    int i=0, j=n-1;
    while (i<j)
    {
        int pairsum=nums[i] + nums[j];
        if (pairsum>target)
        {
            j--;
        }
        else if(pairsum<target){
            i++;
        }
        else
        {
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
                return ans;
            
        }
        
    }
    
}

int main(){
    vector<int> nums= {2,7,11,15};
    int target =18;

    cout<<"The pair is: ";
    vector<int> ans = pairsum(nums, target);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}