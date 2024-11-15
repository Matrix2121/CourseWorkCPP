#include "mainMenu.h"

void MainMenu::mainMenu(){
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
                MainMenu::displayMenu();
                break;
            case 2:
                MainMenu::createMenu();
                break;
            case 3:
                MainMenu::assignMenu();
                break;
            case 4:
                MainMenu::editMenu();
                break;
            case 5:
                return;
            case 6:
                
            case 7:
                return;
            default:
                std::cout << "Invalid input! Enter a number between 1 and 4!" << std::endl;

        }
    }
}

void MainMenu::displayMenu(){
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
                DisplayMenu::displayFreeCars();
                break;
            case 2:
                DisplayMenu::displayAllRoutes();
                break;
            case 3:
                DisplayMenu::displayAllPairs();
                break;
            case 4:
                return;
            default:
                std::cout << "Invalid input! Enter a number between 1 and 4!" << std::endl;

        }
    }

    std::cout << "\nPress any key to get back to main MainMenu.\n\n";
    getch();
}

void MainMenu::createMenu(){
    int createMainMenuInput;
    

    while(true){
        std::cout << "\nChoose what you want to create (1/2):\n1. New Car\n2. New Route\n3. Return to main MainMenu" << std::endl;
        std::cin >> createMainMenuInput;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Enter a number between 1 and 2!" << std::endl;
            continue;
        }

        switch (createMainMenuInput){
            case 1:
                CreateMenu::createCar();
                break;
            case 2:
                CreateMenu::createRoute();
                break;
            case 3:
                return;
            default:
                std::cout << "Invalid input! Enter a number between 1 and 2!" << std::endl;
        }
    }
}

void MainMenu::assignMenu(){
    AssignMenu::assign();
}

void MainMenu::editMenu(){

}

void MainMenu::deleteMenu(){

}