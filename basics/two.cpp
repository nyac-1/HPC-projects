#include<iostream>
#include<thread>

class thread_guard
{
    std::thread t;
public:
    
    explicit thread_guard(std::thread&& t) :t(std::move(t)){}
    
    ~thread_guard()
    {
        if(t.joinable()) t.join();
    }
    
    //Delete copy operation
    thread_guard(const thread_guard&) = delete;
    thread_guard& operator = (const thread_guard&) = delete;
    
    //Move operator default usage
    thread_guard(thread_guard&&) noexcept = default;
    thread_guard& operator = (thread_guard&&) noexcept = default;
};

int main(){
    std::thread worker([](){std::cout<<"Working..."<<std::endl;});
    
    thread_guard guard(std::move(worker));
}
