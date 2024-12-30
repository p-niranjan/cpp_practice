/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex m1, m2;
void thread1()
{
    lock_guard<mutex> lock1(m1);
    cout << "thread1 acquired lock1" << endl;
    
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    
    lock_guard<mutex> lock2(m2);
    cout << "thread1 acquired lock2" << endl;
}

void thread2()
{
    lock_guard<mutex> lock1(m1);
    cout << "thread2 acquired lock1" << endl;
    
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    
    lock_guard<mutex> lock2(m2);
    cout << "thread2 acquired lock2" << endl;
}

int main()
{
    thread t1(thread1);
    thread t2(thread2);
    
    t1.join();
    t2.join();

    return 0;
}