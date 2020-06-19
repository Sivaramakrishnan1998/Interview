#include "stop_while.h"

static vector<thread> abc;


Stop_while s;

void thread_run(){
    thread t1 = thread(&Stop_while::helloFunction, &s);
    abc.push_back(std::move(t1));
}

void thread_break(){
    thread t2 = thread(&Stop_while::change_val, &s);
    abc.push_back(std::move(t2));
}

int main(){
    
    thread_run();
    thread_break();

    //abc.push_back(std::move(t3));
   // t1.join();
    
    for(std::thread & th: abc){
        th.join();
    }

};