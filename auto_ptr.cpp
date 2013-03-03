#include<iostream>
#include<memory>
using namespace std;

class Simple {
    public:
    Simple(int param = 0) : number(param){
        cout<<"Simple:" <<number<<endl;
    }
    ~Simple() {
        cout<<"~Simple:"<<number<<endl; 
    }
    void PrintSomething() {
        cout<<"PrintSomething:"<<infor_extend.c_str()<<endl;
    }

    std::string infor_extend;
    int number;
};

void TestAutoPtr() {
    std::auto_ptr<Simple> my_memory(new Simple(1));
    if (my_memory.get()) {
        my_memory->PrintSomething();
	my_memory.get()->infor_extend = "Addition";
	my_memory->PrintSomething();
	(*my_memory).infor_extend += "other";
	my_memory->PrintSomething();
    }
}

int main()
{
    TestAutoPtr();
    return 0;
}

