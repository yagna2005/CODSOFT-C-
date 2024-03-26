#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

// Function prototypes
void addTask(vector<Task> &tasks, const string &description);
void viewTasks(const vector<Task> &tasks);
void markTaskAsCompleted(vector<Task> &tasks, int index);
void removeTask(vector<Task> &tasks, int index);

int main() {
    vector<Task> tasks;

    cout << "Welcome to the To-Do List Manager!" << endl;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Choose an option (1-5): ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                // Add Task
                string description;
                cout << "Enter the task description: ";
                cin.ignore(); // Clear input buffer
                getline(cin, description);
                addTask(tasks, description);
                break;
            }
            case 2:
                // View Tasks
                viewTasks(tasks);
                break;
            case 3: {
                // Mark Task as Completed
                int index;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> index;
                markTaskAsCompleted(tasks, index);
                break;
            }
            case 4: {
                // Remove Task
                int index;
                cout << "Enter the index of the task to remove: ";
                cin >> index;
                removeTask(tasks, index);
                break;
            }
            case 5:
                // Exit
                cout << "Exiting the To-Do List Manager. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please choose an option from 1 to 5." << endl;
        }
    }

    return 0;
}

void addTask(vector<Task> &tasks, const string &description) {
    Task newTask = {description, false};
    tasks.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

void viewTasks(const vector<Task> &tasks) {
    cout << "\nTask List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << (tasks[i].completed ? "[X] " : "[ ] ") << tasks[i].description << endl;
    }
}

void markTaskAsCompleted(vector<Task> &tasks, int index) {
    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid index. Please enter a valid index." << endl;
    }
}

void removeTask(vector<Task> &tasks, int index) {
    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid index. Please enter a valid index." << endl;
    }
}
