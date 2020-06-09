#include<iostream>
using namespace std;

int main(){
    int *arr, size;
    cin >>size;

    arr = new int[size];
    delete []arr;

    return 0;
}
