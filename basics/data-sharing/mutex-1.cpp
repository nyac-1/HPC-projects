#include<iostream>
#include<chrono>
#include<thread>
#include<string>

using namespace std;
using namespace std::literals;

mutex print_mutex;

void print(string str)
{
    for(int i = 0; i<5; i+=1)
    {
//        print_mutex.lock();
        cout << str[0]<<str[1]<<str[2]<<endl;
//        print_mutex.unlock();
        std::this_thread::sleep_for(50ms);
    }
}

int main()
{
    std::thread thread_one(print, "sam");
    std::thread thread_two(print, "abc");
    std::thread thread_three(print, "gfj");
    
    return 0;
}
