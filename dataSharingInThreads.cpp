#include <iostream>
#include <thread>

using namespace std;

// Point Number :- 1

/*
When you create a function and want to use it in a thread, the arguments passed to the function will always be pass by value no matter you've defined them by value or by by reference in the function definition.
*/

/*
Here, x will be passed by value and not by reference. If you want to change x inside the thread and want to see it getting reflected outside the thread as well, consider using
1. Global Variable
2. ref(x) function during the thread function call.
*/

void demo(int &x,int y){
    x++;
    y=x;

    return ;
}


/*
Here, x will be passed by value and not by reference. If you want to change x inside the thread and want to see it getting reflected outside the thread as well, consider using
1. Global Variable
2. ref(x) function during the thread function call.
*/

int main(){
    int x = 10;
    int y;
    thread t1(demo,ref(x),y);
}

//Point Number :- 2

/*
If you declare a static variable inside a thread, it will be static to the whole code and not just that single thread. The static processing will take place during compile time and no relation to runtime. So if you want to use variables that are local to only that specific thread, consider using :- 
            thread_local
*/

void newDemo(){
    thread_local int x = 10;
    x++;

    return ;
}