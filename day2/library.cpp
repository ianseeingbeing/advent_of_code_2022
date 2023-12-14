#include <iostream>

int part_one() {

    return 0;
}

int part_two() {

    return 0;
}

char oponent_choice(char input) {
    char choice;
    switch (input) {
        case 'A': choice = 'R'; break;
        case 'B': choice = 'P'; break;
        case 'C': choice = 'S'; break;
        default: choice = 'e'; // error testing
    }
    return choice;
}

char self_choice(char input) {
    char choice;
    switch (input) {
        case 'X': choice = 'R'; break;
        case 'Y': choice = 'P'; break;
        case 'Z': choice = 'S'; break;
        default: choice = 'e'; // error testing
    }
    return choice;
}