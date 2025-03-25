//
// Created by HP on 2025-03-22.
//
#ifndef TODO_H
#define TODO_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <iomanip>

using namespace std;

// Mochi Color Palette
#define MOCHI_PINK "\033[38;5;225m"
#define MOCHI_PURPLE "\033[38;5;177m"
#define MOCHI_YELLOW "\033[38;5;228m"
#define MOCHI_GREEN "\033[38;5;157m"
#define MOCHI_PEACH "\033[38;5;223m"
#define MOCHI_CORAL "\033[38;5;210m"
#define MOCHI_RED "\033[38;5;203m"
#define MOCHI_WHITE "\033[38;5;230m"
#define MOCHI_BOLD "\033[1m"
#define MOCHI_RESET "\033[0m"

// Task structure
struct Task {
    string description;
    string category;
    string priority;
    string dueDate;
    bool isCompleted;
};

// Global vector to store tasks
extern vector<Task> tasks;

// Terminal Functions
void clearScreen();
void pauseAndClear();
int getValidatedInput(int min, int max);
string trimString(const string& str);
bool confirmAction(const string& message);

// Function declarations
void showMenu();
void displayTask(const Task& task, int index);
void addTask();
void viewTasks();
void changeTaskStatus();
void deleteTask();
void searchTasks();
void sortByPriority();
void sortByDueDate();
void sortByCategory();
void saveTasksToFile();
void loadTasksFromFile();
void editTask();
void exitProgram();

#endif