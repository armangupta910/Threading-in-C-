// Mutex :- Mutual Exclusion

/*
Race Condition :- Condition where two or more threads try to change the value of the same variable at the same time leading to a fight. The section of the code where this can happen is called a critical section. We have to protect this critical section and this we need some function.
*/

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex m;

int x = 0;
void demo(){
    m.lock();
    //Critical Section Begins
    x++;
    //Critical Section Ends
    m.unlock();
}

int main(){
    cout<<"Initial Value of x is :- "<<x<<endl;

    thread t1(demo);
    thread t2(demo);

    t1.join();
    t2.join();

    cout<<"Final value of x is :- "<<x<<endl;
    return 0;
}

/*
As you can see, we identified a critical section and used lock() and unlock() functions to avoid the Race condition.
*/

/*
To check if the thread you are trying to lock is already locked or not, use try_lock() (similar to joinable)
*/