//
// Created by HP on 2025-03-22.
//
#include "todo.h"

// Global vector to store tasks
vector<Task> tasks;

// Start
void showMenu() {
    cout << MOCHI_PINK << "\n============ To-Do List Menu ============\n" << MOCHI_RESET;

    cout << MOCHI_YELLOW << " 1. " << MOCHI_WHITE << "Add New Task\n";
    cout << MOCHI_YELLOW << " 2. " << MOCHI_WHITE << "View All Tasks\n";
    cout << MOCHI_YELLOW << " 3. " << MOCHI_WHITE << "Change Task Status\n";
    cout << MOCHI_YELLOW << " 4. " << MOCHI_WHITE << "Delete Task\n";
    cout << MOCHI_YELLOW << " 5. " << MOCHI_WHITE << "Search Tasks\n";
    cout << MOCHI_YELLOW << " 6. " << MOCHI_WHITE << "Sort Tasks\n";
    cout << MOCHI_YELLOW << " 7. " << MOCHI_WHITE << "Edit Tasks\n";
    cout << MOCHI_YELLOW << " 8. " << MOCHI_WHITE << "Save Tasks\n";
    cout << MOCHI_YELLOW << " 9. " << MOCHI_WHITE << "Load Tasks\n";
    cout << MOCHI_CORAL << "10. " << MOCHI_WHITE << "Exit\n";

    cout << MOCHI_PINK << "============\n" << MOCHI_RESET;
}

// Function to display a task
void displayTask(const Task& task, int index) {
    string priorityColor = MOCHI_RED;
    if (task.priority == "medium" || task.priority == "med"
        || task.priority == "m" || task.priority == "MEDIUM"
        || task.priority == "MED" || task.priority == "M"
        || task.priority == "Medium")  priorityColor = MOCHI_YELLOW;
    else if (task.priority == "Low" || task.priority == "low"
        || task.priority == "l" || task.priority == "LOW"
        || task.priority == "L" ) priorityColor = MOCHI_GREEN;

    string status = task.isCompleted ?
                   MOCHI_GREEN "Completed" :
                   MOCHI_CORAL "Pending";

    cout << MOCHI_YELLOW << " " << index + 1 << ". "
         << MOCHI_WHITE << task.description << "\n";

    cout << MOCHI_GREEN << "   = Category: " << MOCHI_WHITE << task.category << "\n";
    cout << MOCHI_GREEN << "   = Priority: " << priorityColor << task.priority << "\n";
    cout << MOCHI_GREEN << "   = Due Date: " << MOCHI_WHITE << task.dueDate << "\n";
    cout << MOCHI_GREEN << "   = Status: " << status << MOCHI_RESET << "\n\n";
}

// Add a new task
void addTask() {
    Task newTask;

    cout << MOCHI_PINK << "\n============ Add New Task ============\n" << MOCHI_RESET;

    cout << MOCHI_YELLOW << "Description: " << MOCHI_RESET;
    getline(cin, newTask.description);

    cout << MOCHI_YELLOW << "Category: " << MOCHI_RESET;
    getline(cin, newTask.category);

    cout << MOCHI_YELLOW << "Priority (High/Medium/Low): " << MOCHI_RESET;
    getline(cin, newTask.priority);

    cout << MOCHI_YELLOW << "Due Date (YYYY-MM-DD): " << MOCHI_RESET;
    getline(cin, newTask.dueDate);

    newTask.isCompleted = false;
    tasks.push_back(newTask);

    cout << MOCHI_GREEN << "Task added successfully!\n" << MOCHI_RESET;
}

// View all tasks
void viewTasks() {
    if (tasks.empty()) {
        cout << MOCHI_PEACH << "No tasks available.\n" << MOCHI_RESET;
        return;
    }

    cout << MOCHI_PINK << "\n=== Your Tasks ("
         << MOCHI_YELLOW << tasks.size()
         << MOCHI_PINK << (tasks.size() == 1 ? " task" : " tasks")
         << ") ===\n" << MOCHI_RESET;

    for (size_t i = 0; i < tasks.size(); ++i) {
        displayTask(tasks[i], i);
    }

    int completedCount = count_if(tasks.begin(), tasks.end(),
                                [](const Task& t) { return t.isCompleted; });

    cout << MOCHI_GREEN << "Completed: "
         << MOCHI_WHITE << completedCount << "/" << tasks.size()
         << MOCHI_GREEN << " ("
         << MOCHI_WHITE << (tasks.empty() ? 0 : (100 * completedCount / tasks.size()))
         << MOCHI_GREEN << "%)\n" << MOCHI_RESET;
}

// Mark a task as completed or not
void changeTaskStatus() {
    viewTasks();
    if (!tasks.empty()) {
        cout << MOCHI_PURPLE << "Enter task number to change status: " << MOCHI_RESET;
        int taskNumber;
        cin >> taskNumber;

        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].isCompleted = !tasks[taskNumber - 1].isCompleted;
            string status = tasks[taskNumber - 1].isCompleted ? "COMPLETED" : "PENDING";
            string color = tasks[taskNumber - 1].isCompleted ? MOCHI_GREEN : MOCHI_CORAL;

            cout << color << "Task status changed to: " << status << "\n" << MOCHI_RESET;
        } else {
            cout << MOCHI_RED << "Invalid task number!\n" << MOCHI_RESET;
        }
    }
}
// Delete a task
void deleteTask() {
    viewTasks();
    if (!tasks.empty()) {
        cout << MOCHI_CORAL << "Enter task number to delete: " << MOCHI_RESET;
        int taskNumber;
        cin >> taskNumber;

        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            string deletedTask = tasks[taskNumber - 1].description;
            tasks.erase(tasks.begin() + taskNumber - 1);

            cout << MOCHI_GREEN << "Task deleted successfully: \""
                 << MOCHI_WHITE << deletedTask
                 << MOCHI_GREEN << "\"\n" << MOCHI_RESET;
        } else {
            cout << MOCHI_RED << "Invalid task number!\n" << MOCHI_RESET;
        }
    }
}

// Search for tasks
void searchTasks() {
    cout << MOCHI_PINK << "Search for tasks (enter keyword): " << MOCHI_RESET;

    string query;
    //cin.ignore();
    getline(cin, query);

    bool found = false;
    cout << MOCHI_PURPLE << "\n=== Search Results ===\n" << MOCHI_RESET;

    for (size_t i = 0; i < tasks.size(); ++i) {
        if (tasks[i].description.find(query) != string::npos ||
            tasks[i].category.find(query) != string::npos) {
            displayTask(tasks[i], i);
            found = true;
            }
    }

    if (!found) {
        cout << MOCHI_PEACH << "No tasks found for: \""
             << MOCHI_WHITE << query
             << MOCHI_PEACH << "\"\n" << MOCHI_RESET;
    } else {
        cout << MOCHI_GREEN << "Search completed successfully\n" << MOCHI_RESET;
    }
}

// Sort tasks by priority (High > Medium > Low)
void sortByPriority() {
    static const unordered_map<string, int> priorityWeights = {
        {"high", 3}, {"h", 3}, {"HIGH", 3}, {"H", 3}, {"High", 3},
        {"medium", 2}, {"med", 2}, {"m", 2}, {"MEDIUM", 2}, {"MED", 2}, {"M", 2}, {"Medium", 2},
        {"low", 1}, {"l", 1}, {"LOW", 1}, {"L", 1}, {"Low", 1}
    };

    auto getWeight = [](const string& priority) {
        if (priority.empty()) return 0;
        string lowerPriority = priority;
        transform(lowerPriority.begin(), lowerPriority.end(), lowerPriority.begin(), ::tolower);
        for (const auto& [key, value] : priorityWeights) {
            if (lowerPriority.find(key) == 0) return value;
        }
        return 0;
    };

    sort(tasks.begin(), tasks.end(), [&](const Task& a, const Task& b) {
        int weightA = getWeight(a.priority);
        int weightB = getWeight(b.priority);
        return weightA > weightB || (weightA == weightB && a.description < b.description);
    });

    cout << MOCHI_PINK << "Tasks sorted by priority (High > Medium > Low)\n" << MOCHI_RESET;
}

// Sort tasks by due date (earliest first)
void sortByDueDate() {
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.dueDate < b.dueDate;
    });

    cout << MOCHI_PINK << "Tasks sorted by due date (Earliest first)\n" << MOCHI_RESET;
}

// Sort tasks by category (alphabetical order)
void sortByCategory() {
    static const unordered_map<string, int> categoryWeights = {
        {"work", 3}, {"w", 3}, {"WORK", 3}, {"W", 3},
        {"personal", 2}, {"p", 2}, {"PERSONAL", 2}, {"P", 2},
        {"study", 1}, {"s", 1}, {"STUDY", 1}, {"S", 1}
    };

    auto getCategoryWeight = [](const string& category) {
        if (category.empty()) return 0;

        string lowerCategory = category;
        transform(lowerCategory.begin(), lowerCategory.end(),
                 lowerCategory.begin(), ::tolower);

        for (const auto& [key, value] : categoryWeights) {
            if (lowerCategory == key) {
                return value;
            }
        }

        for (const auto& [key, value] : categoryWeights) {
            if (lowerCategory.find(key) == 0) {
                return value;
            }
        }

        return 0;
    };

    sort(tasks.begin(), tasks.end(), [&](const Task& a, const Task& b) {
        int weightA = getCategoryWeight(a.category);
        int weightB = getCategoryWeight(b.category);

        if (weightA == weightB) {
            return a.category < b.category ||
                  (a.category == b.category && a.description < b.description);
        }

        return weightA > weightB;
    });

    cout << MOCHI_PURPLE << "Tasks sorted by category (Work > Personal > Study)\n" << MOCHI_RESET;
}

// Save tasks to a file
void saveTasksToFile() {
    ofstream file("tasks.txt");
    for (const auto& task : tasks) {
        file << task.description << "\n"
             << task.category << "\n"
             << task.priority << "\n"
             << task.dueDate << "\n"
             << task.isCompleted << "\n";
    }
    file.close();
    cout << MOCHI_GREEN << "Tasks saved successfully to tasks.txt\n" << MOCHI_RESET;
}

// Load tasks from a file
void loadTasksFromFile() {
    ifstream file("tasks.txt");
    Task task;
    tasks.clear();

    cout << MOCHI_PURPLE << "Loading tasks from file..." << MOCHI_RESET << endl;

    while (getline(file, task.description)) {
        getline(file, task.category);
        getline(file, task.priority);
        getline(file, task.dueDate);
        file >> task.isCompleted;
        file.ignore();
        tasks.push_back(task);
    }
    file.close();

    cout << MOCHI_GREEN << "Successfully loaded " << MOCHI_YELLOW << tasks.size()
         << MOCHI_GREEN << (tasks.size() == 1 ? " task" : " tasks")
         << " from tasks.txt\n" << MOCHI_RESET;
}

// to make it easy to edit tasks
void editTask() {
    viewTasks();
    if (tasks.empty()) {
        cout << MOCHI_PEACH << "No tasks available to edit.\n" << MOCHI_RESET;
        return;
    }

    cout << MOCHI_PURPLE << "\n=== Edit Task ===\n" << MOCHI_RESET;
    cout << MOCHI_YELLOW << "Enter task number: " << MOCHI_RESET;

    int taskNumber;
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        Task& taskToEdit = tasks[taskNumber - 1];

        cout << MOCHI_PINK << "\nEditing Task #" << taskNumber << MOCHI_RESET << endl;
        cout << MOCHI_WHITE << "Current details:\n";
        displayTask(taskToEdit, taskNumber - 1);

        cout << MOCHI_PURPLE << "\nEdit Options:\n" << MOCHI_RESET;
        cout << MOCHI_YELLOW << "1. " << MOCHI_WHITE << "Edit Description\n";
        cout << MOCHI_YELLOW << "2. " << MOCHI_WHITE << "Edit Category\n";
        cout << MOCHI_YELLOW << "3. " << MOCHI_WHITE << "Edit Priority\n";
        cout << MOCHI_YELLOW << "4. " << MOCHI_WHITE << "Edit Due Date\n";
        cout << MOCHI_YELLOW << "5. " << MOCHI_WHITE << "Toggle Completion\n";
        cout << MOCHI_CORAL << "6. " << MOCHI_WHITE << "Cancel\n";
        cout << MOCHI_YELLOW << "Your choice: " << MOCHI_RESET;

        int editChoice;
        cin >> editChoice;
        cin.ignore();

        switch (editChoice) {
            case 1:
                cout << MOCHI_YELLOW << "New description: " << MOCHI_RESET;
                getline(cin, taskToEdit.description);
                break;
            case 2:
                cout << MOCHI_YELLOW << "New category: " << MOCHI_RESET;
                getline(cin, taskToEdit.category);
                break;
            case 3:
                cout << MOCHI_YELLOW << "New priority: " << MOCHI_RESET;
                getline(cin, taskToEdit.priority);
                break;
            case 4:
                cout << MOCHI_YELLOW << "New due date (YYYY-MM-DD): " << MOCHI_RESET;
                getline(cin, taskToEdit.dueDate);
                break;
            case 5:
                taskToEdit.isCompleted = !taskToEdit.isCompleted;
                cout << MOCHI_GREEN << "Status changed to: "
                     << (taskToEdit.isCompleted ? "COMPLETED" : "PENDING") << MOCHI_RESET << endl;
                break;
            case 6:
                cout << MOCHI_CORAL << "Edit cancelled.\n" << MOCHI_RESET;
                return;
            default:
                cout << MOCHI_RED << "Invalid choice!\n" << MOCHI_RESET;
                return;
        }

        cout << MOCHI_GREEN << "Task updated successfully!\n" << MOCHI_RESET;
    } else {
        cout << MOCHI_RED << "Invalid task number!\n" << MOCHI_RESET;
    }
}

// end
void exitProgram() {
    cout << MOCHI_PINK << "Thank you for using Mochi Todo List. Goodbye!\n" << MOCHI_RESET;
    exit(0);
}

// Terminal Functions
// Clear screen cross-platform
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Pause and clear screen
void pauseAndClear() {
    cout << "\n" << MOCHI_YELLOW << "Press Enter to continue..." << MOCHI_RESET;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    clearScreen();
}

// Get validated integer input within a range
int getValidatedInput(int min, int max) {
    int input;
    while (true) {
        cout << MOCHI_BOLD << MOCHI_YELLOW << "-> Enter your choice: " << MOCHI_RESET;

        // Check if input is valid
        if (cin >> input) {
            // Check if input is within range
            if (input >= min && input <= max) {
                return input;
            }
        }

        // Clear error flags and input buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Show error message
        cout << MOCHI_RED << "Invalid input! Please try again.\n" << MOCHI_RESET;
    }
}

// Trim whitespace from string
string trimString(const string& str) {
    auto start = str.begin();
    while (start != str.end() && isspace(*start)) {
        start++;
    }

    auto end = str.end();
    do {
        end--;
    } while (distance(start, end) > 0 && isspace(*end));

    return string(start, end + 1);
}

// Confirm action with user
bool confirmAction(const string& message) {
    while (true) {
        cout << MOCHI_YELLOW << message << " (y/n): " << MOCHI_RESET;
        string response;
        getline(cin, response);

        // Convert to lowercase and trim
        transform(response.begin(), response.end(), response.begin(), ::tolower);
        response = trimString(response);

        if (response == "y" || response == "yes" || response == "Y") return true;
        if (response == "n" || response == "no" || response == "N") return false;

        cout << MOCHI_RED << "Invalid input. Please enter 'y' or 'n'.\n" << MOCHI_RESET;
    }
}