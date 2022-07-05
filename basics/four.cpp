#include<iostream>
#include<thread>
#include<chrono>
#include<string>

static bool lock = true;

void do_work()
{
    using namespace std::literals::chrono_literals;
    
    while(lock){
        std::cout<<"Working..."<<std::endl;
        std::this_thread::sleep_for(2s);
    }
    std::cout<<"Finished!"<<std::endl;
}

void get_input()
{
    std::cin.get();
    
}

void greet(int time)
{
    using namespace std::literals::chrono_literals;
    std::this_thread::sleep_for(std::chrono::seconds(time));
    std::cout<<"Finished work!"<<" Set wait: "<<time<<std::endl;

}

void print(std::string str){
    using namespace std::literals::chrono_literals;
    
    for(int i = 0; i<5; i+=1){
        std::cout<<str[0]<<str[1]<<str[2]<<std::endl;
//        std::this_thread::sleep_for(50ms);
    }
}

int main()
{
//    std::thread worker(do_work);
//    std::thread getter(get_input);
//
//    lock = false;
//
//    if(getter.joinable()){getter.join();}
//    if(worker.joinable()){worker.join();}
//
//    std::thread one(greet, 1);
//    std::thread two(greet, 4);
//    std::thread three(greet, 6);
    
    std::thread one(print, "abc");
    std::thread two(print, "def");
    std::thread three(print, "xyz");
    
    one.join();
    two.join();
    three.join();
    
    std::cin.get();
}
