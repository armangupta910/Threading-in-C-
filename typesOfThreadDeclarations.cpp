#include <iostream>
#include <thread>

using namespace std;

int demo(int n){
    cout<<n<<endl;
    return 0;
}

class demoClass{
    public:
    int demo(int x){
        cout<<x<<endl;
        return 0;
    }
};

class newDemoClass{
    public:
    static int demo(int x){
        cout<<x<<endl;
        return 0;
    }
};

int main(){
    
    int x = 10;
    thread t1(demo,x); // Function Pointer type Thread Declaration

    auto newFunc = [](int x){
        cout<<x<<endl;

        return 0;
    };

    thread t2(newFunc,x); // Lambda Function type Thread Declaration

    demoClass * hehe = new demoClass();
    thread t3(demoClass::demo,hehe,10); // Create threads to run a non-static function inside a class

    thread t4(&newDemoClass::demo,10); // Create threads to run a static functions inside a class

    return 0;

}