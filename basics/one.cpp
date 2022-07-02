#include<iostream>
#include<thread>
#include<string>

using namespace std;

//void say_hello(){
//    std::cout<<"Hello Threaded World!"<<std::endl;
//}
//
//void say_hello_next(string str){
//    std::cout<<str<<std::endl;
//}

void func(string& str){
    str = "Manipulated";
}

void ownership_functionn(string&& value){
    std::cout<<"Ownership of value: "<<value<<" has been tranfered!"<<endl;
}

class greeter{
public:
    void hello(){
        std::cout<<"Hello, Member Function!"<<std::endl;
    }
};

int main(){

    greeter greet;
    thread t1(&greeter::hello, &greet);
    
//    string str = "Initial value";
//    thread t1(func, std::ref(str));
    t1.join();
    
//    thread t2(ownership_functionn, std::move(str));
//    t2.join();
    
}

