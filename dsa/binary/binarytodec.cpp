#include<iostream>
using namespace std;


int binarytodec(int binum){
    int ans=0, pow=1;
    while(binum>0){
        int rem=binum%10;
        ans+=rem*pow;
        binum=binum/10;
        pow*=2;

    }
    return ans;
}
int main(){
    int binum=1011101111;
    cout<<binarytodec(binum);
    return 0;
}