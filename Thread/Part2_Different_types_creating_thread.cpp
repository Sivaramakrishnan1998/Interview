#include <iostream>
#include <thread>

using namespace std;


// (1) USING FUNCTION POINTER

void func(int x){
    std::cout << "value is "<< x<<" called using function pointer\n";
}
int main(){
thread t(func, 9);
t.join();
};


// (2) USING  LAMBDA FUNCTION

auto func = [](int x){
    std::cout << "value is "<< x<<" called using lambda function\n";
};


int main(){
    thread t(func, 10);
    thread t2(

        [](int x){
            std::cout << "value is "<< x<<" called using lambda function while creating thread\n";
        }, 11
    );
    t.join();
    t2.join();
};



// (3) USING FUNCTION OBJECT
class Base{
    public:
        void operator()(int x){
            while(x-- >0){
                cout << x << " called using functor\n";
            }
        }
};


int main(){
    thread t1((Base()), 5);
    t1.join();

};

// (4) NON STATIC MEMBER FUNCTION OF THE CLASS

class Base{
    public:

    void run_val(int x){
        while(x-- > 0){
            cout << x << " called using non static member function()\n";
        }
    }

};

int main(){
    Base b;
    // thread thread_obj(addr(class)::function_name, addr(obj), params)
    thread t1(&Base::run_val,&b,6);
    t1.join();
};


// (5) USING STATIC MEMBER FUNCTION

class Base{
    public:
    static void run(int x){
        while(x-- > 0){
            cout << x << " called using  static member function()\n";

        }
    }
};

int main(){
    thread t1(&Base::run, 6);
    t1.join();
};
