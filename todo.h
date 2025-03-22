//
// Created by HP on 2025-03-22.
//
#ifndef TODO_H
#define TODO_H

#include <bits/stdc++.h>
#include <algorithm>
#include <fstream>

using namespace std;

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

#endif