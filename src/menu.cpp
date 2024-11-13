#include "menu.h"
#include "manager.h"
#include <iostream>
#include <limits>

void Menu::mainMenu(){
    int input;

    while(true){

        std::cout << "Choose one of the following (1/2/3):" << std::endl;
        std::cout << "1. View all information" << std::endl;
        std::cout << "2. Create new..." << std::endl;
        std::cout << "3. Edit..." << std::endl;
        std::cout << "4. Exit" << std::endl;

        std::cin >> input;

        if (std::cin.fail()) {
            std::cin.clear(); // Изчистване на флага за грешка
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Изчистване на буфера
            std::cout << "Invalid input! Enter a number!" << std::endl;
            continue;
        }

        switch (input){
            case 1: 
                Menu::displayMenu();
                break;
            
            case 2:
                Menu::createMenu();
                break;

            case 3:
                Menu::editMenu();
                break;

            case 4:
                return;
            
            default:
                std::cout << "Invalid input! Enter a number between 1 and 4!" << std::endl;

        }
    }
}

void Menu::displayMenu(){
    Manager::displayAllPairs();
}

void Menu::createMenu(){

}

void Menu::editMenu(){

}