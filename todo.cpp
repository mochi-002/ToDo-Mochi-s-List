//
// Created by HP on 2025-03-22.
//
#include "todo.h"

// Global vector to store tasks
vector<Task> tasks;

// Start
void showMenu() {
    cout << "\n\033[1;36m=== To-Do List Menu ===\033[0m\n";
    cout << "\033[1;35m1. Add New Task\033[0m\n";
    cout << "\033[1;35m2. View All Tasks\033[0m\n";
    cout << "\033[1;35m3. Change Task Status\033[0m\n";
    cout << "\033[1;35m4. Delete Task\033[0m\n";
    cout << "\033[1;35m5. Search Tasks\033[0m\n";
    cout << "\033[1;35m6. Sort Tasks\033[0m\n";
    cout << "\033[1;35m7. Save Tasks\033[0m\n";
    cout << "\033[1;35m8. Load Tasks\033[0m\n";
    cout << "\033[1;35m9. Exit\033[0m\n";
    cout << "\033[1;35mEnter your choice:\033[0m ";
}

// Function to display a task
void displayTask(const Task& task, int index) {
    string status = task.isCompleted ? " Completed" : " Running";
    cout << "\033[1;34m" << index + 1 << ". " << task.description << "\033[0m\n";
    cout << "   \033[1;32mCategory:\033[0m " << task.category << "\n";
    cout << "   \033[1;32mPriority:\033[0m " << task.priority << "\n";
    cout << "   \033[1;32mDue Date:\033[0m " << task.dueDate << "\n";
    cout << "   \033[1;32mStatus:\033[0m " << status << "\n\n";
}

// Add a new task
void addTask() {
    Task newTask;
    cout << "\n\033[1;35mEnter Task Description:\033[0m ";
    cin.ignore();
    getline(cin, newTask.description);
    cout << "\033[1;35mEnter Task Category (e.g., Work, Personal, Study):\033[0m ";
    getline(cin, newTask.category);
    cout << "\033[1;35mEnter Priority (High, Medium, Low):\033[0m ";
    getline(cin, newTask.priority);
    cout << "\033[1;35mEnter Due Date (YYYY-MM-DD):\033[0m ";
    getline(cin, newTask.dueDate);
    newTask.isCompleted = false;
    tasks.push_back(newTask);
    cout << "\033[1;32mTask added successfully!\033[0m\n";
}

// View all tasks
void viewTasks() {
    if (tasks.empty()) {
        cout << "\033[1;31mNo tasks available.\033[0m\n";
        return;
    }
    cout << "\n\033[1;36m=== Your Tasks ===\033[0m\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        displayTask(tasks[i], i);
    }
}

// Mark a task as completed or not
void changeTaskStatus() {
    viewTasks();
    if (!tasks.empty()) {
        int taskNumber;
        cout << "\033[1;35mEnter the task number to change its status:\033[0m ";
        cin >> taskNumber;
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].isCompleted = !tasks[taskNumber - 1].isCompleted;
            cout << "\033[1;32mTask status changed successfully!\033[0m\n";
        } else {
            cout << "\033[1;31mInvalid task number.\033[0m\n";
        }
    }
}

// Delete a task
void deleteTask() {
    viewTasks();
    if (!tasks.empty()) {
        int taskNumber;
        cout << "\033[1;35mEnter the task number to delete:\033[0m ";
        cin >> taskNumber;
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "\033[1;32mTask deleted successfully!\033[0m\n";
        } else {
            cout << "\033[1;31mInvalid task number.\033[0m\n";
        }
    }
}

// Search for tasks
void searchTasks() {
    string query;
    cout << "\033[1;35mEnter a keyword to search for:\033[0m ";
    cin.ignore();
    getline(cin, query);
    bool found = false;
    for (size_t i = 0; i < tasks.size(); ++i) {
        if (tasks[i].description.find(query) != string::npos || tasks[i].category.find(query) != string::npos) {
            displayTask(tasks[i], i);
            found = true;
        }
    }
    if (!found) {
        cout << "\033[1;31mNo tasks found with that keyword.\033[0m\n";
    }
}

// Sort tasks by priority (High > Medium > Low)
void sortByPriority() {
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        if (a.priority == "High" && b.priority != "High") return true;
        if (a.priority == "Medium" && b.priority == "Low") return true;
        return false;
    });
    cout << "\033[1;32mTasks sorted by priority!\033[0m\n";
}

// Sort tasks by due date (earliest first)
void sortByDueDate() {
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.dueDate < b.dueDate;
    });
    cout << "\033[1;32mTasks sorted by due date!\033[0m\n";
}

// Sort tasks by category (alphabetical order)
void sortByCategory() {
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.category < b.category;
    });
    cout << "\033[1;32mTasks sorted by category!\033[0m\n";
}

// Save tasks to a file
void saveTasksToFile() {
    ofstream file("tasks.txt");
    for (const auto& task : tasks) {
        file << task.description << "\n" << task.category << "\n" << task.priority << "\n" << task.dueDate << "\n" << task.isCompleted << "\n";
    }
    file.close();
    cout << "\033[32mTasks saved to file!\033[0m\n";
}

// Load tasks from a file
void loadTasksFromFile() {
    ifstream file("tasks.txt");
    Task task;
    tasks.clear();
    while (getline(file, task.description)) {
        getline(file, task.category);
        getline(file, task.priority);
        getline(file, task.dueDate);
        file >> task.isCompleted;
        file.ignore();
        tasks.push_back(task);
    }
    file.close();
    cout << "\033[32mTasks loaded from file!\033[0m\n";
}