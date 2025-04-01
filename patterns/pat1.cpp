#include<iostream>
using namespace std;

void pat(int n){
    int i,j;
    for(i=1;i<=n;i++){
        
        for ( j = 0; j < n; j++)
        {
            cout<<"*";
        }
        cout<<endl;
        

        
    }
    
}

int main(){
    int n;
    cin>>n;
   pat(n);
    
    return 0;
}