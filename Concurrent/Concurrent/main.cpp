//
//  main.cpp
//  Concurrent
//
//  Created by Ya-Di Ma on 2019/9/17.
//  Copyright © 2019 MA YADI. All rights reserved.
//

#include <iostream>
#include <thread>
using namespace std;

volatile int counter(0);
mutex mtx;

void attempt_10k_increase(){
    for (int i = 0; i < 10000; ++i) {
        if (mtx.try_lock()) {
            ++counter;
            mtx.unlock();
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    thread threads[10];
    for (int i = 0; i < 10; ++i) {
        threads[i] = thread(attempt_10k_increase);
    }
    
    for (auto& th:threads) {
        th.join();
    }
    
    cout << counter << " successful increases of the counter." << endl;
    return 0;
}
