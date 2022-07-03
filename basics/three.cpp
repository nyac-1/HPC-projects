#include<iostream>
#include<thread>

static bool lock = true;

void do_work()
{
    using namespace std::literals::chrono_literals;
    
    while(lock)
    {
        std::cout<<"Working (Thread id: "<<std::this_thread::get_id()<<") ..."<<std::endl;
        std::this_thread::sleep_for(2s);
    }
}

int main()
{
//    std::thread worker_two(do_work);
    std::thread worker_one(do_work);
    

    std::cin.get();
    lock = false;
    
    if(worker_one.joinable()){ worker_one.join(); }
//    if(worker_two.joinable()){ worker_two.join(); }
    
    std::cin.get();
    
    return 0;
}
