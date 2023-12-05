#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// 1. store all the input
// 2. sort input into sub groups
// 3. calculate the total value of the sub groups
// 4. print out the total calories of the largest sub group

int part_one(std::vector<int>);
int part_two(std::vector<int>);
std::vector<int> get_values();

int main() {

    std::vector<int> values = get_values();
    std::cout << part_one(values) << std::endl;

    return 0;
}

std::vector<int> get_values() {

    std::ifstream inFile("input.txt");
    std::vector<int> container;
    
    std::string tmp;
    while (std::getline(inFile, tmp)) {
        if (tmp != "") {
            container.push_back(std::stoi(tmp));
        }
        else {
            container.push_back(-1);
        }
    }
    inFile.close();

    return container;
}

int part_one(std::vector<int> container) {

    int numElves = 1;

    for (int n : container) {
        if (n == -1) {
            numElves++;
        }
    }

    int totalCalories[numElves];
    std::fill(&totalCalories[0], &totalCalories[numElves], 0);

    int j = 0;
    for (int i = 0; i < container.size(); i++) {
        if (container[i] != -1) {
            totalCalories[j] += container[i];
        }
        else {
            j++;
        }
    } 

    int max = 0;
    for (int i : totalCalories) {
        if (max < i) {
            max = i;
        }
    }
    
    return max;
}

int part_two(std::vector<int> container) {

    return 0;
}