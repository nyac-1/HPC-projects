#include<iostream>
#include<mutex>

class some_type
{
    //..
public:
    void do_it()
    {
        //..
        std::cout<<"Did it"<<std::endl;
    }
};

some_type* ptr{nullptr};
std::once_flag ptr_flag;

void process()
{
    std::call_once(ptr_flag, [](){ptr = new some_type;});
    ptr->do_it();
}

int main()
{
    
}
