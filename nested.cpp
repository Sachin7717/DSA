#include<iostream>
using namespace std;

int main(){
    int age;
    cin>>age;

    if (age<18)
    {
       cout<<"your are not eligible for job";
    }
    else if (age<=54)
    {
       cout<<"you are eligible for job";
    }
    else if (age<57)
    {
        cout<<"you are eligible for job";
        if (age>=54)
        {
        cout<<" but soon retirement";
        }   
    }
    else
    {
        cout<<"retirement time";
    }
    

    

    
    return 0;
}