#include <fstream>
#include <vector>
#include <filesystem>
#include <thread>
#include <iostream>

int main() {

    std::vector<std::ofstream> files;

    std::string folderName = "subtask2";
    std::filesystem::create_directory(folderName);

    for (int i = 0; i < 40; i++) {
        std::string fileName = folderName + "/file" + std::to_string(i) + ".txt";
        files.emplace_back(fileName);
        if (files.back().is_open()) {
            for (int j = 0; j < 5; j++) {
                std::string line = "Line #" + std::to_string(j) + "\n";
                files.back() << line;
                files.back().flush();
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        } else {
            std::cerr << "Failed to open file\n";
        }
    }

}
