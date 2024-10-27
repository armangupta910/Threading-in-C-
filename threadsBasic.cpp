/*
So the normal code runs on a single thread (Like the main function).
Suppose you create a thread in the main function, that thread will start executing itself and the execution of the main function will continue even after that. This will reduce the overall computation time of the program.
*/

#include <iostream>
#include <thread>

using namespace std;

int demo(){
    cout<<"Inside the thread...\n";
    return 10;
}

int main(){
    thread t1(demo);
    t1.join(); //Used to tell the main function to wait for the thread to be executed completely.

    thread t2(demo);
    t2.join();
    cout<<"Outside the Thread...\n";

    return 0;
}

/*
So in this code, the demo function keeps executing while the main function is also executing. If you want to make the main function wait fot the demo function to be completed, add join function as shown.
*/

/*
If you use Join, you get an output something like this...

Inside the thread...
Outside the Thread...

If you don't use thread, you get an output something like this...

Outside the Thread...
libc++abi: terminating
Inside the thread...
zsh: abort      ./a.out

*/

/*
Note :- If you create multiple threads at a time, you cannot predict which thread gets created first i.e. you never knwo which thread is executed first.
As in the above code, you can't be sure if t1 will be created first. It may happen that t2 gets created first.
*/