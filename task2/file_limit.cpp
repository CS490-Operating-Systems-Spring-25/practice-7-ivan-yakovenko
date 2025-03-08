#include <fstream>
#include <vector>
#include <filesystem>
#include <thread>
#include <chrono>
#include <iostream>

int main() {

    std::vector<std::ofstream> files;

    std::string folderName = "subtask2";
    std::filesystem::create_directory(folderName);

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 1000; j++) {
            std::string fileName = folderName + "/file" + std::to_string(i * 1000 + j) + ".txt";
            files.emplace_back(fileName);
            if (files.back().is_open()) {
                for (int k = 0; k < 5; k++) {
                    std::string line = "Line #" + std::to_string(k) + "\n";
                    files.back() << line;
                    files.back().flush();
                }
            } else {
                std::cerr << "Failed to open file\n";
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

}
