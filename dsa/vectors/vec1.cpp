#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec1; 
    vec1={1,2,3}; 
    cout<<vec1[1]<<endl; 
   

    vector<int> vec2(5, 10); 
    vec2.push_back(20);
    vec2.push_back(30);
    vec2.push_back(40);
    vec2.pop_back(); // Removes the last element (40)
    for(int i : vec2) {
        cout << i << " "; 
    }
     return 0; 
}
