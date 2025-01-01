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

#define N 26

mutex mtx;
int cnt = 0;

void printEven()
{
    while(cnt < N) 
    {
        lock_guard<mutex> lock(mtx);
        if(cnt >= N) break;
        
        if(cnt % 2 == 0) {
            char c = (char)cnt + 'a';
            cout << c << " ";
            cnt++;    
        }
    }
}

void printOdd()
{
    while(cnt < N)
    {
        lock_guard<mutex> lock(mtx);
        if(cnt >= N) break;
        
        if(cnt % 2 == 1) {
            char c = (char) cnt + 'a';
            cout << c << " ";
            cnt++;
        }
    }
}

int main()
{
    thread t1(printEven);
    thread t2(printOdd);
    
    t1.join();
    t2.join();

    return 0;
}