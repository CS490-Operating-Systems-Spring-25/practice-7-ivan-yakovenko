#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

int main() {
    std::ofstream fout("test.txt");

    for (int i = 0; i < 1000; i++) {
        std::string line = "Line #" + std::to_string(i) + "\n";
        fout << line;
        fout.flush();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
