#include<iostream>
#include<thread>
#include<chrono>
#include<string>

std::mutex lock;

void print(std::string str){
    using namespace std::literals::chrono_literals;
    
    for(int i = 0; i<5; i+=1){
        lock.lock();
        {
            std::cout<<str[0]<<str[1]<<str[2]<<std::endl;
        }
        lock.unlock();
        std::this_thread::sleep_for(50ms);
    }
}

int main()
{
    
    std::thread one(print, "abc");
    std::thread two(print, "def");
    std::thread three(print, "xyz");
    
    one.join();
    two.join();
    three.join();
    
    std::cin.get();
}
