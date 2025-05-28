#pragma once


#include <map>
#include <string>

class Dictionary {
private:
    std::map<std::string, std::string> words;

public:
    void addWord(const std::string& word, const std::string& translation);
    void deleteWord(const std::string& word);
    void editWord(const std::string& word, const std::string& newTranslation);
    void findWord(const std::string& word) const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void showAllWords() const;
};
