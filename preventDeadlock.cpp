/*
Race Condition :- Condition where two or more threads try to change the value of the same variable at the same time leading to a fight. The section of the code where this can happen is called a critical section. We have to protect this critical section and this we need some function.
*/

//Method :- 1
// Mutex :- Mutual Exclusion

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

mutex demo;
if(demo.try_lock()){
    count++;
    demo.unlock();
}

/*
Locking Multiple Threads at a time.
If all the threads get locked, it return -1. If not, it unlocks all the Threads it locked during the process.
*/

demo.try_lock(t1,t2,t3,t4,t5);

//Types of Lock Guards

mutex m1,m2,m3;
//General Lock Guard
/*
Sometimes, you may forget to release a locked critical section. This can cause disasters. So we have another type of guard for this :- lock_guard
*/

void demo(){
    std::lock_guard<std::mutex> guard(m1);
    /*
    Not this lock will automatically be released once the function call finishes. Remeber that the lock cannot be released anywhere in between the function execution. This can be thought as one of the disadvantages of using lock_guard.
    */
}

//Scoped Lock guard
/*
This is similar to lock_gurad except that you can pass in multiple mutexes inside this function
*/

void demo(){
    std::scoped_lock<std::mutex, std::mutex> guard(m1, m2);
}

//Unique Lock Guard
/*
Similar to lock_gurad excewpt that it can be returned froma function and thus a single mutex can be used to lock multiple sections

Note :- You can use all the functions here as lock_guard
*/

std::mutex mtx;

std::unique_lock<std::mutex> getLock() {
    std::unique_lock<std::mutex> lock(mtx); // Lock acquired
    // Do some setup work
    return lock; // Move lock to the caller
}

void callerFunction() {
    auto lock = getLock(); // Lock is now owned by this function
    std::cout << "Mutex is locked in callerFunction.\n";
    
    // Do some operations while the lock is held

    // Optionally, you can unlock it manually if needed
    // lock.unlock(); // Uncomment to unlock before going out of scope

    // Lock will be released automatically when lock goes out of scope
}

//Shared Lock Guard
/*
Similar to unique guard except that it enables the critical section to be accessed by multiple threads at a time. We use it in scenarios when read operations are very frequent.

Code remains similar tp unique_guard

You have to make sure that you use shared lock only in functions where only read is taking place. If you use shared lock in the function where you you are writing, it will cause disasters.
*/

//Method :- 2

//Use atomic variables

/*
If you make a variable as atomic, you can be sure that only one of reading and writing to a variable will take place at once. It will not happen that reading of a variable takes place during the writing process of that variable.
*/

std::atomic<int> counter(0); // Atomic counter

void incrementCounter() {
    for (int i = 0; i < 1000; ++i) {
        ++counter; // Atomic increment
    }
}

int main() {
    std::thread t1(incrementCounter);
    std::thread t2(incrementCounter);

    t1.join();
    t2.join();

    std::cout << "Final counter value: " << counter.load() << std::endl;
    return 0;
}

// Here, the final value of the Counter variable will be 2000 since the loop will wait for the counter to be free and hence we will not miss any iteration. If we'd have used locks, we'd have missed some iterations for sure and thus not getting the final result as 2000.
