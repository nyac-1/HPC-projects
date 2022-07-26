#include<iostream>
#include<mutex>
#include<iostream>
#include<thread>

std::mutex mutex_1;
std::mutex mutex_2;

void func1()
{
    using namespace std::literals;
    
    std::cout<<"Thread 1 locking mutexes..."<<std::endl;
    std::scoped_lock lk(mutex_1, mutex_2);
    std::cout<<"Thread 1 LOCKED mutexes..."<<std::endl;
    std::this_thread::sleep_for(100ms);
    std::cout<<"Thread 1 released mutexes..."<<std::endl;
}


void func2()
{
    using namespace std::literals;
    
    std::cout<<"Thread 2 locking mutexes..."<<std::endl;
    std::scoped_lock lk(mutex_2, mutex_1);
    std::cout<<"Thread 2 LOCKED mutexes..."<<std::endl;
    std::this_thread::sleep_for(100ms);
    std::cout<<"Thread 2 released mutexes..."<<std::endl;
}

int main()
{
    std::thread one(func1);
    std::thread two(func2);
    
    one.join();
    two.join();
}
