#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

#define N 20

mutex mtx;
int cnt = 0;

void printEven()
{
    while(cnt < N) {
        lock_guard<mutex> lock(mtx);
        if(cnt > N) break;
        if(cnt % 2 == 0) {
            cout << cnt++ << " ";
        }    
    }
    
}

void printOdd()
{
    while(cnt < N) {
        lock_guard<mutex> lock(mtx);
        if(cnt > N) break;
        if(cnt % 2 == 1) {
            cout << cnt++ << " ";
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