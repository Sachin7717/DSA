#include<iostream>
using namespace std;

int main(){
    int n = 6; 
    int arr[6] = {1, -2, 3, 4, -5, 6};

    int maxsum= INT32_MIN;
    for (int st = 0; st < n; st++)
    {
        int currsum = 0;
        for (int end = st; end < n; end++)
        {
        currsum +=arr[end];
        maxsum = max(maxsum, currsum);
        }
        
    }
    cout << maxsum << endl;

    return 0;
}