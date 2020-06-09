#include <iostream>

using namespace std;

class item{
    int number, cost;

    public:
        void get_data(int a , int b);

        void put_data(void){
            cout << number << '\n'<< cost << '\n';
        }
        void display_value(void){
            cout<< number * cost <<'\n';
        }
};

void item::get_data(int a, int b){
    number = a;
    cost   = b;
}

int main(int argc, char** argv){
    item obj;
    obj.get_data(33,3);
    obj.put_data();
    obj.display_value();
    return 0;
}