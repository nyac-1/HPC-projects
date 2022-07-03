#include<iostream>
#include<vector>
#include<iterator>

void do_smth(const std::vector<int>& arr, void(*func)(int)){
    for(auto itr = arr.begin(); itr!=arr.end(); itr++){
        func(*itr);
    }
}

int main(){
    std::vector<int> v = {4,7,7,7,6,0,6};
    
    do_smth(v, [](int value){std::cout<<"Value is: "<<value<<std::endl;});
    
    std::cin.get();
    
    return 0;
}
