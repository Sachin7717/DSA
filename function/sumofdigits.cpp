#include<iostream>
using namespace std;


int sumofdigits(int num){
    int sum=0;

    while(num>0){
        int lastdigit=num%10;
        num=num/10;
        sum+=lastdigit;
    }
    return sum;
}
int main(){
    cout<<sumofdigits(154342);
    return 0;
}