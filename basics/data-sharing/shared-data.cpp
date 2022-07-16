#include<iostream>
#include<thread>
#include<chrono>
#include<string>
#include<vector>
#include<algorithm>
#include<shared_mutex>



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

