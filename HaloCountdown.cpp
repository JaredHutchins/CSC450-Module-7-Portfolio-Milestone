/**
 * Halo Countdown Protocol
 * Demonstrates basic concurrency using std::thread.
 * Thread 1 (Master Chief) counts up to 20.
 * Thread 2 (Cortana) counts down from 20 after arming is complete.
 */

#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

using namespace std;

atomic<bool> havokArmed(false);

/**
 * Simulates arming process by Master Chief.
 * Counts from 1 to 20 with a brief delay.
 */
void armHavok() {
    for (int i = 1; i <= 20; ++i) {
        cout << "[Master Chief] Arming HAVOK... Progress: " << i << "%" << endl;
        this_thread::sleep_for(chrono::milliseconds(250));
    }
    havokArmed = true;
}

/**
 * Waits for arming to complete, then counts down from 20.
 */
void detonateSequence() {
    while (!havokArmed) {
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    for (int i = 20; i >= 0; --i) {
        cout << "[Cortana] Countdown to detonation: T-minus " << i << " seconds" << endl;
        this_thread::sleep_for(chrono::milliseconds(250));
    }

    cout << "[Cortana] Detonation complete. Mission success." << endl;
}

int main() {
    cout << "=== Halo Countdown Protocol ===" << endl;

    thread chiefThread(armHavok);
    thread cortanaThread(detonateSequence);

    chiefThread.join();
    cortanaThread.join();

    cout << "=== Program complete ===" << endl;
    return 0;
}