#include<iostream>
using namespace std;

int main(){
    int i;
    // for (int i = 0; i < 40; i++)
    // {
    //     cout<<i<<endl;
    //     if (i==4)
    //     {
           
    //         break;
    //     }
        
    // }
     for (int i = 0; i < 40; i++)
{
    cout << i << endl;
    if (i == 4)
    {
        continue;
    }
    cout << i << endl;
}

    return 0;
}
    
    
