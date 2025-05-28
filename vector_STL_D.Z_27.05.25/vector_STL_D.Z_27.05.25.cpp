// vector_STL_D.Z_27.05.25.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "station.h"
#include "dictionary.h"
#include <iostream>
#include <string>

void railwayStationMenu() {


    /*Задание 1
        Написать программу «Автоматизированная информационная система ЖД вокзала».Система содержит : сведения об отправлении поездов дальнего следования.
        Для каждого поезда указываем : номер, время отправления, станцию назначения.
        Обеспечить :
        	Ввод данных в систему.
        	Вывод информации о всех поездах.
        	Вывод информации о запрашиваемом поезде.
        Использовать контейнерный класс vector.*/

    RailwayStation station;
    int choice;

    do {
        std::cout << "\n==== Railway Station Menu ====\n"
            << "1. Add a train\n"
            << "2. Show all trains\n"
            << "3. Find a train by number\n"
            << "4. Show trains after time\n"
            << "0. Back to main menu\n"
            << "Choice: ";
        std::cin >> choice;
        std::cin.ignore();  // Очистка буфера после ввода числа

        switch (choice) {
        case 1: {
            int number;
            std::string time, dest;
            std::cout << "Number: ";
            std::cin >> number;
            std::cin.ignore();
            std::cout << "Departure time (hh:mm): ";
            std::getline(std::cin, time);
            std::cout << "Destination station: ";
            std::getline(std::cin, dest);

            station.addTrain(Train(number, time, dest));
            std::cout << "Train added successfully.\n";
            break;
        }
        case 2:
            station.showAllTrains();
            break;
        case 3: {
            int num;
            std::cout << "Enter train number: ";
            std::cin >> num;
            std::cin.ignore();
            station.findTrainByNumber(num);
            break;
        }
        case 4: {
            std::string time;
            std::cout << "Enter time (hh:mm): ";
            std::getline(std::cin, time);
            station.showTrainsAfterTime(time);
            break;
        }
        case 0:
            std::cout << "Returning to main menu.\n";
            break;
        default:
            std::cout << "Wrong choice.\n";
        }

    } while (choice != 0);
}


//Задание 2
//Используя контейнер map реализовать программу — словарь.
//Основные возможности :
//	поиск слова;
//	добавление, удаление, редактирование слов;
//	чтение и запись словаря в файл.


void dictionaryMenu() {
    Dictionary dict;
    int choice;
    std::string word, translation, filename;

    do {
        std::cout << "\n==== Dictionary Menu ====\n"
            << "1. Add word\n"
            << "2. Delete word\n"
            << "3. Edit word\n"
            << "4. Find word\n"
            << "5. Show all words\n"
            << "6. Load from file\n"
            << "7. Save to file\n"
            << "0. Back to main menu\n"
            << "Choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1:
            std::cout << "Enter word: ";
            std::getline(std::cin, word);
            std::cout << "Enter translation: ";
            std::getline(std::cin, translation);
            dict.addWord(word, translation);
            std::cout << "Word added.\n";
            break;
        case 2:
            std::cout << "Enter word to delete: ";
            std::getline(std::cin, word);
            dict.deleteWord(word);
            std::cout << "Word deleted if existed.\n";
            break;
        case 3:
            std::cout << "Enter word to edit: ";
            std::getline(std::cin, word);
            std::cout << "Enter new translation: ";
            std::getline(std::cin, translation);
            dict.editWord(word, translation);
            break;
        case 4:
            std::cout << "Enter word to find: ";
            std::getline(std::cin, word);
            dict.findWord(word);
            break;
        case 5:
            dict.showAllWords();
            break;
        case 6:
            std::cout << "Enter filename to load: ";
            std::getline(std::cin, filename);
            dict.loadFromFile(filename);
            break;
        case 7:
            std::cout << "Enter filename to save: ";
            std::getline(std::cin, filename);
            dict.saveToFile(filename);
            break;
        case 0:
            std::cout << "Returning to main menu.\n";
            break;
        default:
            std::cout << "Wrong choice.\n";
        }
    } while (choice != 0);
}

int main() {
    int choice;
    do {
        std::cout << "\n=====================================\n";
        std::cout << "             MAIN MENU               \n";
        std::cout << "=====================================\n";
        std::cout << "  1. Railway Station System (Task 1)\n";
        std::cout << "-------------------------------------\n";
        std::cout << "  2. Dictionary (Task 2)             \n";
        std::cout << "-------------------------------------\n";
        std::cout << "  0. Exit                           \n";
        std::cout << "=====================================\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1:
            std::cout << "\n=====================================\n";
            std::cout << "        TASK 1: RAILWAY STATION      \n";
            std::cout << "=====================================\n";
            railwayStationMenu();
            break;

        case 2:
            std::cout << "\n=====================================\n";
            std::cout << "           TASK 2: DICTIONARY        \n";
            std::cout << "=====================================\n";
            dictionaryMenu();
            break;

        case 0:
            std::cout << "Exiting program. Goodbye!\n";
            break;

        default:
            std::cout << "Wrong choice.\n";
        }
    } while (choice != 0);

    return 0;
}