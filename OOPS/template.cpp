
// why use template

#include<iostream>
using namespace std;

class vectorr{

    int *v;
    int size;

    public:
        vectorr (int m){
            cout << "inside null vector";
            v = new int[size = m];
            for(int i=0; i< size; i++)
                v[i]=0;
        }

        vectorr(int *a){
            for(int i=0; i< size;i++)
                v[i] = *(a + i);
        }

        int operator*(vectorr &y){
            int sum =0;
            for(int i=0; i<size; i++){
                sum += this->v[i] * y.v[i]; 
            }
            return sum;
        }
};


int main(){
    int x[3] = {1, 2, 3};
    int y[3] = {4, 5, 6};

    vectorr v1(3);
    vectorr v2(3);

    v1 = x;
    v2 = y;

    int res = v1.operator*(v2); 
    cout << res << "is result \n ";
    return 0;
}