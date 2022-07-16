#ifndef SINGLETON_H
#define SINGLETON_H

#include<iostream>

class singleton
{
    //Delete copy
    singleton(const singleton&) = delete;
    singleton& operator = (const singleton&) = delete;

    //Delete move
    singleton(singleton&&) = delete;
    singleton& operator = (singleton&&) = delete;
    
public:
    singleton()
    {
        std::cout<<"Singleton Initialized"<<std::endl;
    }
};

singleton& get_singleton();

#endif
