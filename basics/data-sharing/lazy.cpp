#include<iostream>
#include<mutex>

class some_type
{
    //..
public:
    void do_it()
    {
        //..
    }
};

some_type* ptr{nullptr};
std::mutex process_mutex;

void process()
{
    if(!ptr)
    {
        std::unique_lock<std::mutex> lk(process_mutex);
        ptr = new some_type;
        lk.unlock();
    }

    ptr->do_it();
}

int main()
{
    
}
