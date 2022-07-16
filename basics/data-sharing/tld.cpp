#include<iostream>
#include<thread>
#include<chrono>
#include <random>

using namespace std;
using namespace std::literals;

thread_local mt19937 mt;

void func()
{
    std::uniform_real_distribution<double> dist(0,1);

    for(int i = 0; i<5; i++)
        std::cout<<dist(mt)<<", ";

    std::cout<<std::endl;
}

int main()
{
    std::cout<<"Thread One's outputs: ";
    std::thread one(func);
    one.join();

    std::cout<<"Thread Two's outputs: ";
    std::thread two(func);
    two.join();
}

//#include <random>
//#include <thread>
//#include <iostream>
//
//using namespace std;
//using namespace std::literals;
//
////thread_local
//mt19937 mt;
//
//void func() {
//    uniform_real_distribution<double> dist(0, 1);  // Doubles in the range 0 to 1
//
//    for (int i = 0; i < 10; ++i)                   // Generate 10 random numbers
//        cout << dist(mt) << ", ";
//}
//
//int main() {
//    cout << "Thread 1's random values:" << endl;
//    thread t1{ func };
//    t1.join();
//    std::this_thread::sleep_for(100ms);
//    cout << "\nThread 2's random values:" << endl;
//    thread t2{ func };
//    t2.join();
//    cout << endl;
//}
