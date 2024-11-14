#include "mainMenu.h"
#include "manager.h"
#include "createMenu.h"
#include <iostream>
#include <limits>
#include <conio.h> 

void Menu::mainMenu(){
    int mainMenuInput;

    while(true){

        std::cout << "\nChoose one of the following (1/2/3/4):\n1. View all information\n2. Create new...\n3. Edit...\n4. Exit" << std::endl;

        std::cin >> mainMenuInput;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Enter a number between 1 and 4!" << std::endl;
            continue;
        }

        switch (mainMenuInput){
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
    std::cout << std::endl;
    Manager::displayAllPairs();
    std::cout << "\nPress a key to get back to main menu.\n\n";
    getch();
}

void Menu::createMenu(){
    int createMenuInput;
    

    while(true){
        std::cout << "\nChoose what you want to create (1/2):\n1. New Car\n2. New Route\n3. Return to main menu" << std::endl;
        std::cin >> createMenuInput;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Enter a number between 1 and 2!" << std::endl;
            continue;
        }

        switch (createMenuInput){
            case 1:
                createMenu::createCar();
                break;
            case 2:
                createMenu::createRoute();
                break;
            case 3:
                return;
            default:
                std::cout << "Invalid input! Enter a number between 1 and 2!" << std::endl;
        }
    }
}

void Menu::assignMenu(){
    
}

void Menu::editMenu(){

}