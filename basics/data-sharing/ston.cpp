#include "singleton.h"
#include <iostream>
#include <thread>
#include <vector>

void task()
{
    singleton& s = get_singleton();
    std::cout<<&s<<std::endl;
}

int main()
{
    std::vector<std::thread> threads;
    
    for(int i = 0; i<10; i+=1)
        threads.push_back(std::thread{task});
    
    for(auto& t: threads)
        t.join();
}

