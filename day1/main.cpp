#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

// 1. store all the input
// 2. sort input into sub groups
// 3. calculate the total value of the sub groups
// 4. print out the total calories of the largest sub group

int part_one(std::vector<int>);
int part_two(std::vector<int>);
std::vector<int> get_values();
std::vector<int> get_sorted_values(std::vector<int>);

int main() {

    std::vector<int> values = get_values();
    std::vector<int> sortedValues = get_sorted_values(values);
    std::cout << part_one(sortedValues) << std::endl;
    std::cout << part_two(sortedValues) << std::endl;

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

std::vector<int> get_sorted_values(std::vector<int> container) {

    int numElves = 1;
    std::vector<int> totalCalories = {};

    for (int n : container) {
        if (n == -1) {
            numElves++;
        }
    }

    totalCalories.push_back(0);
    int j = 0;
    for (int i = 0; i < container.size(); i++) {
        if (container[i] != -1) {
            totalCalories[j] += container[i];
        }
        else {
            totalCalories.push_back(0);
            j++;
        }
    }

    return totalCalories;
}

int part_one(std::vector<int> container) {

    int max = 0;
    for (int i : container) {
        if (max < i) {
            max = i;
        }
    }
    
    return max;
}

// find sum of the three largest number of calories

int part_two(std::vector<int> container) {

    int ans;
    int size = container.size();
    std::sort(container.begin(), container.end());
    ans = container[size - 1] + container[size - 2] + container[size - 3]; 

    return ans;
}