#include<iostream>
#include<thread>
#include<chrono>
#include<string>

std::mutex lock;


void task_one()
{
    using namespace std::literals;
    
    std::cout<<"Task one trying to get lock"<<std::endl;
    lock.lock();
    std::cout<<"Task one has the lock"<<std::endl;
    std::this_thread::sleep_for(300ms);
    std::cout<<"Task one released the lock"<<std::endl;
    lock.unlock();
}
void task_two()
{
    using namespace std::literals;
    
    std::this_thread::sleep_for(100ms);
    std::cout<<"Task two trying to get lock"<<std::endl;
    
    while(!lock.try_lock())
    {
        std::cout<< "Task two couldn't get the lock"<<std::endl;
        std::this_thread::sleep_for(10ms);
    }
    
    std::cout<<"Task two has the lock"<<std::endl;
    lock.unlock();
}

int main()
{
    
    std::thread one(task_one);
    std::thread two(task_two);
    
    one.join();
    two.join();
    
    std::cin.get();
}
