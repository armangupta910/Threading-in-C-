#include <iostream>
#include <thread>

using namespace std;

void demo(int x){
    cout<<x<<endl;
}

int main(){
    int x = 10;
    thread t1(demo,x);
    cout<<"Inside Main Before...\n";
    t1.join();
    cout<<"Inside Main After...\n";

    if(t1.joinable()){
        t1.join(); //Now the code will not give abrupt termination.
    }

    t1.detach();

    return 0;
}

/*
By using join, you will se the below output :- 
*/

/*Inside Main Before...
10
Inside Main After...*/
/*
Inside main Before gets executed during the time the Thread was being created by the OS.
*/

/*
If you add join to a thread two times, the program will get terminated after executing the Thread once. If you forget that have you joined the thread before or not, use the joinable() function to get to know if the current thread is joinable or not.
*/

/*
If you use detach function, it will not wait for the thread to complete, just as the main execution reaches the detach statement, the thread will get terminated. This is different from not using join. If you don't use join, the thread will get executed completely and the main execution will go on untill then. But if you use detach, during the execution of the main, just as you encounter the detach function, the Thread gets terminated no matter how much it has been executed.
*/
/*
Detach is not like the Thread will be terminated. It's just that you will not be able to access that thread from the main function. Also when the main function ends, all the Threads are automatically terminated.
*/

