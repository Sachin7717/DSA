#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    cout<< vec1.size() << endl; //3
    cout<< vec1.capacity() << endl; //4
    return 0;
}