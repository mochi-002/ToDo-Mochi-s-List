//
// Created by Mochi Lover on 2023-06-15.
//
#include "todo.h"

// こんにちは! このコードは愛でできています ♡
// (Hello! This code is made by mochi)
// Mochi Colors inspired by Japanese sweets

int main() {
    // Ensure clean start
    clearScreen();

    // Welcome message
    cout << MOCHI_PINK << "\nMochi Todo List\n" << MOCHI_RESET;

    // Try to load existing tasks
    try {
        loadTasksFromFile();
    } catch (const exception& e) {
        cout << MOCHI_PEACH << "No existing tasks found or error loading tasks.\n" << MOCHI_RESET;
    }

    int choice;
    do {
        // Show menu and get validated input
        showMenu();
        choice = getValidatedInput(1, 10);

        // Clear input buffer to prevent issues
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Process user choice
        switch (choice) {
            case 1: {
                clearScreen();
                addTask();
                pauseAndClear();
                break;
            }
            case 2: {
                clearScreen();
                viewTasks();
                pauseAndClear();
                break;
            }
            case 3: {
                clearScreen();
                changeTaskStatus();
                pauseAndClear();
                break;
            }
            case 4: {
                clearScreen();
                deleteTask();
                pauseAndClear();
                break;
            }
            case 5: {
                clearScreen();
                searchTasks();
                pauseAndClear();
                break;
            }
            case 6: {
                clearScreen();
                // Sorting submenu
                cout << MOCHI_PURPLE << "\nSort by:\n" << MOCHI_RESET;
                cout << MOCHI_YELLOW << " 1. " << MOCHI_WHITE << "Priority (High > Medium > Low)\n";
                cout << MOCHI_YELLOW << " 2. " << MOCHI_WHITE << "Due Date (Earliest first)\n";
                cout << MOCHI_YELLOW << " 3. " << MOCHI_WHITE << "Category (Alphabetical)\n";
                cout << MOCHI_CORAL << " 4. " << MOCHI_WHITE << "Cancel\n";

                int sortChoice = getValidatedInput(1, 4);
                switch (sortChoice) {
                    case 1: sortByPriority(); break;
                    case 2: sortByDueDate(); break;
                    case 3: sortByCategory(); break;
                    case 4: cout << MOCHI_PEACH << "Sorting cancelled.\n" << MOCHI_RESET; break;
                }
                pauseAndClear();
                break;
            }
            case 7: {
                clearScreen();
                editTask();
                pauseAndClear();
                break;
            }
            case 8: {
                clearScreen();
                if (confirmAction("Do you want to save all tasks?")) {
                    saveTasksToFile();
                }
                pauseAndClear();
                break;
            }
            case 9: {
                clearScreen();
                if (confirmAction("Do you want to load tasks from file? This will replace current tasks.")) {
                    loadTasksFromFile();
                }
                pauseAndClear();
                break;
            }
            case 10: {
                clearScreen();
                if (confirmAction("Do you want to save tasks before exiting?")) {
                    saveTasksToFile();
                }
                exitProgram();
                break;
            }
        }
    } while (choice != 10);

    return 0;
}