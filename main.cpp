#include "src/manager.h"
#include "src/fileManager.h"
#include "src/menus/mainMenu.h"

int main(){

    if(!FileManager::initializeFiles()){
        return 0;
    }
    
    FileManager::loadData();

    MainMenu::mainMenu();

    FileManager::closeFiles();

}