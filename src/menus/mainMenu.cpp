#include "mainMenu.h"
#include "manager.h"
#include "createMenu.h"
#include "displayMenu.h"
#include "assignMenu.h"
#include <iostream>
#include <limits>
#include <conio.h> 

void Menu::mainMenu(){
    int mainMenuInput;

    while(true){

        std::cout << "\nChoose one of the following (1/2/3/4/5):\n1. View information\n2. Create new...\n3. Make new pair\n4. Edit...\n5. Exit" << std::endl;

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
                Menu::assignMenu();
                break;
            case 4:
                Menu::editMenu();
                break;
            case 5:
                return;
            default:
                std::cout << "Invalid input! Enter a number between 1 and 4!" << std::endl;

        }
    }
}

void Menu::displayMenu(){
    int displayMenuInput;

    while(true){

        std::cout << "\nChoose one of the following (1/2/3/4):\n1. Display free cars\n2. Display all routes\n3. Display all pairs\n4. Return to main  menu" << std::endl;

        std::cin >> displayMenuInput;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Enter a number between 1 and 4!" << std::endl;
            continue;
        }

        switch (displayMenuInput){
            case 1: 
                displayMenu::displayFreeCars();
                break;
            case 2:
                displayMenu::displayAllRoutes();
                break;
            case 3:
                displayMenu::displayAllPairs();
                break;
            case 4:
                return;
            default:
                std::cout << "Invalid input! Enter a number between 1 and 4!" << std::endl;

        }
    }

    std::cout << "\nPress any key to get back to main menu.\n\n";
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
    assignMenu::assign();
}

void Menu::editMenu(){

}

void Menu::deleteMenu(){

}