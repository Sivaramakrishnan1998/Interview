#include<iostream>

using namespace std;

int glob = 10;

int main(){
    int glob = 20;
    std::cout << "inside "<<glob << "\n";{
        int glob = 1000;
        std::cout << "inside "<< glob << "\n";
        std::cout << "global"<< ::glob << "\n";

    }
    std::cout << "global"<< ::glob << "\n";
}