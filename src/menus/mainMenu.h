#pragma once
#include <limits>
#include <conio.h> 
#include <string>
#include "createMenu.h"
#include "displayMenu.h"
#include "assignMenu.h"
#include "../manager.h"

class MainMenu{
    public:
        static void mainMenu();
        static void displayMenu();
        static void createMenu();
        static void assignMenu();
        static void editMenu(); //to-do
        static void deleteMenu(); //to-do
    
};