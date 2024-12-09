#include "mainMenu.h"

void MainMenu::mainMenu(){

    if(!FileManager::initializeFiles()){
        std::cout << "File initialization error!" << std::endl;
        return;
    }
    
    FileManager::loadData();

    int mainMenuInput;

    while(true){

        std::cout << "\nChoose one of the following (1/2/3/4/5/6/7):\n1. Display information\n2. Create new...\n3. Assign new pair\n4. Unassign a pair\n5. Edit...\n6. Delete...\n7. Exit" << std::endl;

        std::cin >> mainMenuInput;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Enter a number between 1 and 6!" << std::endl;
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
                MainMenu::unAssignMenu();
                break;
            case 5:
                MainMenu::editMenu();
                break;
            case 6:
                MainMenu::deleteMenu();
                break;
            case 7:
                FileManager::closeFiles();
                return;
            default:
                std::cout << "Invalid input! Enter a number between 1 and 6!" << std::endl;

        }
    }
}

void MainMenu::displayMenu(){
    int displayMenuInput;

    while(true){

        std::cout << "\nChoose one of the following (1/2/3/4):\n1. Display all vehicles\n2. Display all routes\n3. Display all pairs\n4. Return to main menu" << std::endl;

        std::cin >> displayMenuInput;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Enter a number between 1 and 4!" << std::endl;
            continue;
        }

        switch (displayMenuInput){
            case 1: 
                DisplayMenu::displayAllVehicles();
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
    int createMenuInput;
    
    while(true){
        std::cout << "\nChoose what you want to create (1/2/3):\n1. New Vehicle\n2. New Route\n3. Return to main menu" << std::endl;
        std::cin >> createMenuInput;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Enter a number between 1 and 2!" << std::endl;
            continue;
        }

        switch (createMenuInput){
            case 1:
                CreateMenu::createVehicle();
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

void MainMenu::unAssignMenu(){
    UnassignMenu::unassign();
}

void MainMenu::editMenu(){
    int editMenuInput;
    
    while(true){
        std::cout << "\nChoose what you want to create (1/2/3):\n1. Edit Vehicle\n2. Edit Route\n3. Return to main menu" << std::endl;
        std::cin >> editMenuInput;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Enter a number between 1 and 3!" << std::endl;
            continue;
        }

        switch (editMenuInput){
            case 1:
                EditMenu::editVehicle();
                break;
            case 2:
                EditMenu::editRoute();
                break;
            case 3:
                return;
            default:
                std::cout << "Invalid input! Enter a number between 1 and 3!" << std::endl;
        }
    }
}

void MainMenu::deleteMenu(){
    int deleteMenuInput;
    
    while(true){
        std::cout << "\nChoose what you want to create (1/2/3):\n1. Delete Vehicle\n2. Delete Route\n3. Return to main main menu" << std::endl;
        std::cin >> deleteMenuInput;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Enter a number between 1 and 3!" << std::endl;
            continue;
        }

        switch (deleteMenuInput){
            case 1:
                DeleteMenu::deleteVehicle();
                break;
            case 2:
                DeleteMenu::deleteRoute();
                break;
            case 3:
                return;
            default:
                std::cout << "Invalid input! Enter a number between 1 and 3!" << std::endl;
        }
    }
}