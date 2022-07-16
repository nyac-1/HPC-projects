#include<iostream>
#include<thread>
#include<chrono>
#include<string>
#include<vector>
#include<algorithm>
#include<shared_mutex>

std::shared_mutex lock;

void write(int i)
{
    using namespace std::literals;
    
    std::lock_guard<std::shared_mutex> lk(lock);
    std::cout<<"UID Write thread "<<i<<" with exclusive lock"<<std::endl;
    std::this_thread::sleep_for(200ms);
}

void read(int i)
{
    using namespace std::literals;
    
    std::shared_lock<std::shared_mutex> sl(lock);
    std::cout<<"Read thread "<<i<<" with shared lock"<<std::endl;
    std::this_thread::sleep_for(100ms);
}

int main()
{
    std::vector<std::thread> threads;
    for(int i = 0; i<10; i+=1)
        threads.push_back(std::thread{read, i+1});
    
    threads.push_back(std::thread{write, 11});
    
    for(int i = 0; i<10; i+=1)
        threads.push_back(std::thread{read, i+1000000});
    
    for(auto& t: threads)
        t.join();

}

