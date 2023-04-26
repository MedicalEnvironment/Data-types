#include <iostream>
#include <string>

enum Note {
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

std::string noteToString(int note) {
    std::string result;

    if (note & DO) {
        result += "DO ";
    }
    if (note & RE) {
        result += "RE ";
    }
    if (note & MI) {
        result += "MI ";
    }
    if (note & FA) {
        result += "FA ";
    }
    if (note & SOL) {
        result += "SOL ";
    }
    if (note & LA) {
        result += "LA ";
    }
    if (note & SI) {
        result += "SI ";
    }

    return result;
}

int main() {
    int melody[12];

    for (int i = 0; i < 12; i++) {
        std::string input;
        std::cout << "Enter a combination of notes for position " << (i + 1) << ": ";
        std::cin >> input;

        int notes = 0;
        for (char c : input) {
            int noteIndex = c - '1';
            notes |= (1 << noteIndex);
        }

        melody[i] = notes;
    }

    std::cout << "The entered melody is:" << std::endl;
    for (int i = 0; i < 12; i++) {
        std::string noteNames = noteToString(melody[i]);
        std::cout << "Combination " << (i + 1) << ": " << noteNames << std::endl;
    }

    return 0;
}
