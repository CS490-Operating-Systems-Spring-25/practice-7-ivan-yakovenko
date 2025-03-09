#include <iostream>
#include <filesystem>
#include <fstream>

bool fileExists(const std::string &filename)
{
    if (std::filesystem::exists(filename))
    {
        return true;
    }
    return false;
}

int main()
{
    std::string filename1, filename2;
    std::cout << "Enter two filenames: \n";
    std::cin >> filename1 >> filename2;

    if (!fileExists(filename1))
    {
        std::cerr << "File " << filename1 << " does not exist in this directory\n";
        return -1;
    }

    if (!fileExists(filename2))
    {
        std::cerr << "File " << filename2 << " does not exist in this directory\n";
        return -1;
    }

    std::ifstream fin1(filename1);
    std::ifstream fin2(filename2);

    if (!fin1.is_open())
    {
        std::cerr << "Error while opening file " << filename1 << "\n";
        return -1;
    }

    if (!fin2.is_open())
    {
        std::cerr << "Error while opening file " << filename2 << "\n";
        return -1;
    }

    std::string line1, line2;

    while (std::getline(fin1, line1) && std::getline(fin2, line2))
    {
        if (line1 != line2)
        {
            std::cout << "\nDifferent lines:\n\n"
                      << filename1 << ":" << line1 << "\n\n"
                      << filename2 << ":" << line2 << "\n";
        }
        else
        {
            std::cout << "No different lines in these two files\n";
        }
    }
}