#include "dictionary.h"
#include <iostream>
#include <fstream>

void Dictionary::addWord(const std::string& word, const std::string& translation) {
    words[word] = translation;
}

void Dictionary::deleteWord(const std::string& word) {
    auto it = words.find(word);
    if (it != words.end()) {
        words.erase(it);
        std::cout << "Word deleted.\n";
    }
    else {
        std::cout << "Word not found.\n";
    }
}

void Dictionary::editWord(const std::string& word, const std::string& newTranslation) {
    auto it = words.find(word);
    if (it != words.end()) {
        it->second = newTranslation;
        std::cout << "Word updated.\n";
    }
    else {
        std::cout << "Word not found.\n";
    }
}
void Dictionary::findWord(const std::string& word) const {
    auto it = words.find(word);
    if (it != words.end()) {
        std::cout << "Translation: " << it->second << "\n";
    }
    else {
        std::cout << "Word not found.\n";
    }
}

void Dictionary::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) {
        std::cout << "Cannot open file for writing.\n";
        return;
    }
    for (const auto& pair : words) {
        out << pair.first << ";" << pair.second << "\n";
    }
    std::cout << "Dictionary saved to file.\n";
}
void Dictionary::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) {
        std::cout << "Cannot open file for reading.\n";
        return;
    }
    words.clear();  // очищаем перед загрузкой
    std::string line;
    while (std::getline(in, line)) {
        auto delimiterPos = line.find(';');
        if (delimiterPos != std::string::npos) {
            std::string word = line.substr(0, delimiterPos);
            std::string translation = line.substr(delimiterPos + 1);
            words[word] = translation;
        }
    }
    std::cout << "Dictionary loaded from file.\n";
}

void Dictionary::showAllWords() const {
    for (const auto& pair : words) {
        std::cout << pair.first << " — " << pair.second << "\n";
    }
}