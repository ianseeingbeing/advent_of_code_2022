#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// 1. store all the input
// 2. sort input into sub groups
// 3. calculate the total value of the sub groups
// 4. print out the total calories of the largest sub group

int part_one();

int main() {

    std::cout << part_one() << std::endl;

    return 0;
}

int part_one() {
    std::ifstream inFile("input.txt");

    std::vector<int> container;
    int numElves = 1;
    
    std::string tmp;
    while (std::getline(inFile, tmp)) {
        if (tmp != "") {
            container.push_back(std::stoi(tmp));
        }
        else {
            numElves++;
            container.push_back(-1);
        }
    }
    inFile.close();

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