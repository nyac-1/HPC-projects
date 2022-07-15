#include<iostream>
#include<thread>
#include<chrono>
#include<string>

std::recursive_mutex lock;
//std::mutex lock;

int bad_factorial(int n)
{
    if(n<=1)
    {
        std::cout<<"Returning 1"<<std::endl;
        return 1;
    }
    
    std::lock_guard<std::recursive_mutex> lk(lock);
//    std::lock_guard<std::mutex> lk(lock);
    int return_val = n * bad_factorial(n-1);
    std::cout<<"Returning "<<return_val<<std::endl;
    return return_val;
}

int main()
{
    std::thread one(bad_factorial, 5);
    
    one.join();
    
    
    return 0;
}
