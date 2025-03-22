//
// Created by HP on 2025-03-22.
//
#include "todo.h"

int main() {
    int choice;
    loadTasksFromFile();

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
            break;
            case 2:
                viewTasks();
            break;
            case 3:
                changeTaskStatus();
            break;
            case 4:
                deleteTask();
            break;
            case 5:
                searchTasks();
            break;
            case 6: {
                int sortChoice;
                cout << "\n\033[1;36m=== Sort Tasks By ===\033[0m\n";
                cout << "\033[1;35m1. Priority\033[0m\n";
                cout << "\033[1;35m2. Due Date\033[0m\n";
                cout << "\033[1;35m3. Category\033[0m\n";
                cout << "\033[1;35mEnter your choice:\033[0m ";
                cin >> sortChoice;
                switch (sortChoice) {
                    case 1:
                        sortByPriority();
                    break;
                    case 2:
                        sortByDueDate();
                    break;
                    case 3:
                        sortByCategory();
                    break;
                    default:
                        cout << "\033[1;31m Invalid choice.\033[0m\n";
                }
                break;
            }
            case 7:
                saveTasksToFile();
            break;
            case 8:
                loadTasksFromFile();
            break;
            case 9:
                cout << "\033[1;36m Exiting...\033[0m\n";
            break;
            default:
                cout << "\033[1;31m Invalid choice. Please try again.\033[0m\n";
        }
    } while (choice != 9);

    return 0;
}