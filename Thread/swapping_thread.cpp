#include <iostream>
#include <thread>

using namespace std;

int main(){
    cout << "hardware_concurrency()= "<< thread::hardware_concurrency() << endl;    

    thread t1([]{cout << "t1 thread "<< this_thread::get_id() << '\n';});
    thread t2([]{cout << "t2 thread "<< this_thread::get_id()<< '\n';});

    cout << "from main t1 thread "<< t1.get_id() << '\n';
    cout << "from main t2 thread "<< t2.get_id() << '\n';

    swap(t1, t2);

    cout << "from main  t1 thread "<< t1.get_id() << '\n';
    cout << "from main  t2 thread "<< t2.get_id() << '\n';


    cout << t1.joinable() << '\n';
    cout << t2.joinable() << '\n';

    t1.join();
    t2.join();


};