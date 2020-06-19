#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

static bool val = false;

std::atomic<bool> printFinished { false };
std::atomic<bool> shouldPrintRun { true };

void print()
{
    if (shouldPrintRun.load() /* && your normal stop condition*/)
    {
        //work..
        std::cout <<"inside should print on ";
    }
    printFinished.store(true);
}


int main()
{
    std::thread t(print);
    std::this_thread::sleep_for(std::chrono::seconds(10));
    if (!printFinished.load())
    {
        shouldPrintRun.store(false);
        t.join();
        std::cout << "help!";
    }
    return 0;
}
