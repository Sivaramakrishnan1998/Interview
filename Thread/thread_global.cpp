#include <iostream>
#include <thread>
#include <vector>
using namespace std;


static vector<thread> abc;

thread t1;
thread t2;
thread t3;

static bool running = true;
static int count = 1;
void helloFunction(){
    while(running){

        std::cout << count++ << "   "<< this_thread::get_id()<< " hell from function\n";
    }
}

class HelloFunctionObject{
    public:
        void operator()() const{
            std::cout << this_thread::get_id()<< " hello from class\n";
        }
};

void remove_all(){
    for(std::thread & th: abc){
        th.join();
    }
}

int main(){
    
    t1 = thread(helloFunction);
    t1.detach();
    HelloFunctionObject helloFunctionObj;

    t2 = thread(helloFunctionObj);
    
    t3 = thread([]{cout << this_thread::get_id()<< " hello from lambda\n";});
    

    //abc.push_back(std::move(t1));
    abc.push_back(std::move(t2));
    abc.push_back(std::move(t3));
   // t1.join();
    
    remove_all();

};