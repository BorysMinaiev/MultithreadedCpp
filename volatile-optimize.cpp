#include <iostream>
#include <thread>
#include <chrono>

// should be volatile
bool first_thread_done = false;

void first_thread() {
    std::cerr << "first start" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    first_thread_done = true;
    std::cerr << "first end" << std::endl;
}


void second_thread() {
    // I hoped this variable will be optimized out and this cycle will run forever
    while (!first_thread_done) {
        std::cerr << "second waited ..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cerr << "second done!" << std::endl;
}

int main() {
    std::thread t1(first_thread);
    std::thread t2(second_thread);

    t1.join();
    t2.join();
    return 0;
}
