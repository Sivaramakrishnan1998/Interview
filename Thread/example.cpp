#include <iostream>
#include <thread>
using namespace std;

void helloFunction(){
    std::cout << this_thread::get_id()<< " hell from function\n";
}

class HelloFunctionObject{
    public:
        void operator()() const{
            std::cout << this_thread::get_id()<< " hello from class\n";
        }
};

int main(){
    thread t1(helloFunction);
    HelloFunctionObject helloFunctionObj;

    thread t2(helloFunctionObj);

    thread t3([]{cout << this_thread::get_id()<< " hello from lambda\n";});

    t1.join();
    t2.join();
    t3.join();

    
};