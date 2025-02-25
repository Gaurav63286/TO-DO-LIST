#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    string name;
    bool isCompleted;

    Task(string taskName) {
        name = taskName;
        isCompleted = false;
    }
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask() {
        string taskName;
        cout << "Enter the task you want to add: ";
        cin.ignore();
        getline(cin, taskName);
        tasks.push_back(Task(taskName));
        cout << "Task added successfully!" << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
            return;
        }

        cout << "Your tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            string status = tasks[i].isCompleted ? "Completed" : "Pending";
            cout << i + 1 << ". " << tasks[i].name << " [" << status << "]" << endl;
        }
    }

    void markTaskAsCompleted() {
        if (tasks.empty()) {
            cout << "No tasks to mark as completed." << endl;
            return;
        }

        int taskNumber;
        cout << "Enter the task number to mark as completed: ";
        cin >> taskNumber;

        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].isCompleted = true;
            cout << "Task marked as completed." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    void removeTask() {
        if (tasks.empty()) {
            cout << "No tasks to remove." << endl;
            return;
        }

        int taskNumber;
        cout << "Enter the task number to remove: ";
        cin >> taskNumber;

        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task removed successfully." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }
};

void displayMenu() {
    cout << "\nTo-Do List Manager" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
}

int main() {
    ToDoList todoList;
    int choice;

    while (true) {
        displayMenu();
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                todoList.addTask();
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                todoList.markTaskAsCompleted();
                break;
            case 4:
                todoList.removeTask();
                break;
            case 5:
                cout << "Exiting To-Do List Manager. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
