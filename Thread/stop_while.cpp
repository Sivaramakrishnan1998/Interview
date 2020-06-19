#include "stop_while.h"


void Stop_while::helloFunction(){
    while(running){

        std::cout << count++ << "   "<< this_thread::get_id()<< " hell from function\n";
    }
}

void Stop_while::change_val(){
    std::cout << "inside change val\n";
    running = false;
}


