#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void part_one(std::vector<std::string>);
void part_two(std::vector<std::string>);
std::vector<std::string> get_input();
int get_priotiry(char);

int main() {

    std::vector<std::string> input = get_input();
    part_one(input);

    return 0;
}

void part_one(std::vector<std::string> input) {

    int totalPriority = 0;
    std::vector<int> priorities = {};
    
    for (std::string sack : input) {
        for (int i = 0; i < sack.length() / 2; i++) {
            bool escape = false;
            for (int j = sack.length() - 1; j > (sack.length() / 2) - 1; j--) {
                if (sack[i] == sack[j]) {
                    priorities.push_back(get_priotiry(sack[i]));
                    escape = true;
                    break;
                }
            }
            if (escape == true) break;
        }
    }

    for (int n : priorities) {
        totalPriority += n;
    }

    std::cout << "Sum: " << totalPriority << std::endl;
}

void part_two(std::vector<std::string> input) {

}

std::vector<std::string> get_input() {
    std::vector<std::string> input = {};

    std::ifstream inFile("input.txt");

    std::string tmp;
    while (inFile >> tmp) {
        input.push_back(tmp);
    }

    return input;
}

int get_priotiry(char alpha) {
    int num = -1;

    if (alpha >= 'a' && alpha <= 'z')
        num = alpha - 'a' + 1;
    if (alpha >= 'A' && alpha <= 'Z')
        num = alpha - 'A' + 27;

    return num;
}