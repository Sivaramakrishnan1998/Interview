#include "stop_while.h"

static vector<thread> abc;

std::vector<Stop_while> test_space_list; 



void initialize(int value){
    for(auto index = 0; index < value; index++){
            Stop_while slot;
            test_space_list.emplace_back(slot);
    }
}

Stop_while s;

void thread_run(){
    thread t1 = thread(&Stop_while::helloFunction, &test_space_list[1]);
    abc.push_back(std::move(t1));
}

void thread_break(){
    thread t2 = thread(&Stop_while::change_val, &test_space_list[1]);
    abc.push_back(std::move(t2));
}

int main(){
    initialize(8);

    thread_run();
    thread_break();

    //abc.push_back(std::move(t3));
   // t1.join();
    
    for(std::thread & th: abc){
        th.join();
    }

};