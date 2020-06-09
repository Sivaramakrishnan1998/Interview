#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr;
    int count = 10;
    while(count){
        arr.reserve(1); // makes push back in a lesser time/..
        arr.push_back(100);
        count--;
    }
    return 0;
}