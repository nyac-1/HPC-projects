#include<iostream>
#include<thread>
#include<chrono>
#include<string>

std::mutex lock;


void print(std::string str)
{
    using namespace std::literals;
    
    for(int i = 0; i<5; i+=1)
    {
        {
//            lock.lock();
            std::unique_lock<std::mutex> u_g (lock);
            std::cout<< str[0] << str[1] << str[2]<< std::endl;
            u_g.unlock();
        }
        std::this_thread::sleep_for(100ms);
    }
}

void print_with_exception(std::string str)
{
    using namespace std::literals;
    
    for(int i = 0; i<5; i+=1)
    {
        try
        {
            std::unique_lock<std::mutex> u_g (lock);
            std::cout<< str[0] << str[1] << str[2]<< std::endl;
            throw std::exception();
            u_g.unlock();
            
            std::this_thread::sleep_for(100ms);
        }
        catch (std::exception& e){}
    }
}


int main()
{
    
    std::thread one(print, "ABC");
    std::thread two(print, "SGX");
//    std::thread three(print, "LSE");
        
    one.join();
    two.join();
//    three.join();
    
    std::cin.get();
}
