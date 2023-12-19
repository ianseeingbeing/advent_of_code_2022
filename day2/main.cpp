#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// rock 1pt
// paper 2pt
// scissors 3pt
// win 6pt
// draw 3pt
// lose 0pt

// calculate the total.

const int ROCK = 1;
const int PAPER = 2;
const int SCISSORS = 3;
const int WIN = 6;
const int TIE = 3;
const int LOSS = 0;

void part_one(std::vector<std::vector<char>>);
void part_two(std::vector<std::vector<char>>);
std::vector<std::vector<char>> get_input();
int char_to_val(char);

int main() {

    std::vector<std::vector<char>> rpsInput = get_input();
    part_one(rpsInput);

    return 0;
}
void part_one(std::vector<std::vector<char>> input) {

    int opScore = 0;
    int selfScore = 0;

    for (std::vector<char> vec : input) {

        int op = char_to_val(vec[0]);
        int self = char_to_val(vec[1]);

        if (op == self) {
            opScore += TIE + op;
            selfScore += TIE + self;
        }
        else if (op == ROCK && self == SCISSORS) {
            opScore += WIN + op;
            selfScore += LOSS + self; 
        }
        else if (op == PAPER && self == ROCK) {
            opScore += WIN + op;
            selfScore += LOSS + self;
        }
        else if (op == SCISSORS && self == PAPER) {
            opScore += WIN + op;
            selfScore += LOSS + self;
        }
        else {
            opScore += LOSS + op;
            selfScore += WIN + self;
        }
    }

    std::cout << "Oponent Score: " << opScore << "\nSelf Score: " << selfScore << std::endl;

}

void part_two(std::vector<std::vector<char>> input) {

}

std::vector<std::vector<char>> get_input() {
    std::vector<std::vector<char>> input;

    std::ifstream inFile("input.txt");

    std::string tmp;
    while (std::getline(inFile, tmp)) {
        input.push_back({tmp[0], tmp[2]});
    } 
    
    return input; 
}

int char_to_val(char input) {
    int choice;
    switch (input) {
        // op
        case 'A': choice = 1; break;
        case 'B': choice = 2; break;
        case 'C': choice = 3; break;
        // self
        case 'X': choice = 1; break;
        case 'Y': choice = 2; break;
        case 'Z': choice = 3; break;
        // error testing
        default: choice = -1;
    }
    return choice;
}