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
const int DRAW = 3;
const int LOSE = 0;

void part_one(std::vector<std::vector<char>>);
void part_two(std::vector<std::vector<char>>);
std::vector<std::vector<char>> get_input();
int char_to_val(char);
std::string find_rps_outcome(char);

int main() {

    std::vector<std::vector<char>> rpsInput = get_input();
    // part_one(rpsInput);
    part_two(rpsInput);

    return 0;
}

void part_one(std::vector<std::vector<char>> input) {

    int opScore = 0;
    int selfScore = 0;

    for (std::vector<char> vec : input) {

        int op = char_to_val(vec[0]);
        int self = char_to_val(vec[1]);

        if (op == self) {
            opScore += DRAW + op;
            selfScore += DRAW + self;
        }
        else if (op == ROCK && self == SCISSORS) {
            opScore += WIN + op;
            selfScore += LOSE + self; 
        }
        else if (op == PAPER && self == ROCK) {
            opScore += WIN + op;
            selfScore += LOSE + self;
        }
        else if (op == SCISSORS && self == PAPER) {
            opScore += WIN + op;
            selfScore += LOSE + self;
        }
        else {
            opScore += LOSE + op;
            selfScore += WIN + self;
        }
    }

    std::cout << "Oponent Score: " << opScore << "\nSelf Score: " << selfScore << std::endl;

}

// X -> Lose
// Y -> draw
// Z -> win
void part_two(std::vector<std::vector<char>> input) {

    int opScore = 0;
    int selfScore = 0;

    for (std::vector<char> vec : input) {

        int op = char_to_val(vec[0]);
        std::string outcome = find_rps_outcome(vec[1]);

        if (outcome == "draw") {
            opScore += DRAW + op;
            selfScore += DRAW + op;
        }
        else if (outcome == "win") {
            switch (op) {
                case ROCK:
                    opScore += LOSE + op;
                    selfScore += WIN + PAPER;
                    break;
                case PAPER:
                    opScore += LOSE + op;
                    selfScore += WIN + SCISSORS;
                    break;
                case SCISSORS:
                    opScore += LOSE + op;
                    selfScore += WIN + ROCK;
                    break;
            }
        }
        else if (outcome == "lose") {
            switch (op) {
                case ROCK:
                    opScore += WIN + op;
                    selfScore += LOSE + SCISSORS;
                    break;
                case PAPER:
                    opScore += WIN + op;
                    selfScore += LOSE + ROCK;
                    break;
                case SCISSORS:
                    opScore += WIN + op;
                    selfScore += LOSE + PAPER;
                    break;
            }
        } 
    }

    std::cout << "Opponent Score: " << opScore << "\nSelf Score: " << selfScore << std::endl;
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

std::string find_rps_outcome(char input) {
    std::string outcome = "";
    switch (input) {
        case 'X': outcome = "lose"; break;
        case 'Y': outcome = "draw"; break;
        case 'Z': outcome = "win"; break;
    }
    return outcome;
}