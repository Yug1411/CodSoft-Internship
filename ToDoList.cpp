#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Task structure to store task details
struct Task {
    string description;
    bool completed;
};

// Function to add a task to the list
void addTask(vector<Task>& taskList, const string& description) {
    Task task;
    task.description = description;
    task.completed = false;
    taskList.push_back(task);
}

// Function to view tasks
void viewTasks(const vector<Task>& taskList) {
    if (taskList.empty()) {
        cout << "Task list is empty." << endl;
    } else {
        cout << "Task List:" << endl;
        for (size_t i = 0; i < taskList.size(); i++) {
            cout << "[" << i + 1 << "] ";
            if (taskList[i].completed) {
                cout << "[Completed] ";
            }
            cout << taskList[i].description << endl;
        }
    }
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& taskList, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= taskList.size()) {
        taskList[taskIndex - 1].completed = true;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

// Function to remove a task from the list
void removeTask(vector<Task>& taskList, int taskIndex) {
    if (taskIndex >= 1 && taskIndex <= taskList.size()) {
        taskList.erase(taskList.begin() + taskIndex - 1);
        cout << "Task removed." << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

int main() {
    vector<Task> taskList;

    while (true) {
        cout << "To-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    cin.ignore(); // Ignore any previous newline character
                    string description;
                    cout << "Enter task description: ";
                    getline(cin, description);
                    addTask(taskList, description);
                }
                break;
            case 2:
                viewTasks(taskList);
                break;
            case 3:
                {
                    int taskIndex;
                    cout << "Enter the task number to mark as completed: ";
                    cin >> taskIndex;
                    markTaskCompleted(taskList, taskIndex);
                }
                break;
            case 4:
                {
                    int taskIndex;
                    cout << "Enter the task number to remove: ";
                    cin >> taskIndex;
                    removeTask(taskList, taskIndex);
                }
                break;
            case 5:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
