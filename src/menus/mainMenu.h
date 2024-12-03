#pragma once
#include <limits>
#include <conio.h> 
#include <string>
#include "createMenu.h"
#include "displayMenu.h"
#include "assignMenu.h"
#include "unassignMenu.h"
#include "editMenu.h"
#include "deleteMenu.h"
#include "../manager.h"

class MainMenu{
    public:
        static void mainMenu();
        static void displayMenu();
        static void createMenu();
        static void assignMenu();
        static void unAssignMenu();
        static void editMenu();
        static void deleteMenu();
};