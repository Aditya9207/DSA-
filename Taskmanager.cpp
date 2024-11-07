/*Group Members:
Sheryash Bhalekar-23508
Aditya Jamdade-23525
Atharva Joshi-23529
Vaibhavi Shete-23557*/

#include <iostream>
#include <string>
using namespace std;

class Task {
private:
    string description;
    bool isCompleted;
    string dueDate;  

public:
    Task() : description(""), isCompleted(false), dueDate("") {}

    void setDescription(const string& desc) {
        description = desc;
    }

    void setDueDate(const string& date) {
        dueDate = date;
    }

    void markCompleted() {
        isCompleted = true;
    }

    bool completed() const {
        return isCompleted;
    }

    string getDescription() const {
        return description;
    }

    string getDueDate() const {
        return dueDate;
    }

    void printTask(int index) const {
        if (!description.empty()) {
            cout << index + 1 << ". " << description
                      << " [ " << (isCompleted ? "Completed" : "Incomplete")
                      << " | Due: " << dueDate << " ]\n";
        }
    }
};


void displayMenu();
void addTask(Task tasks[], int& taskCount, int maxTasks);
void listTasks(const Task tasks[], int taskCount);
void completeTask(Task tasks[], int taskCount);



void displayMenu() {
    cout << "\n--- Task Manager Menu ---\n";
    cout << "1. Add a new task\n";
    cout << "2. List all tasks\n";
    cout << "3. Mark a task as completed\n";
    cout << "4. Exit the program\n";
}


void addTask(Task tasks[], int& taskCount, int maxTasks) {
    if (taskCount >= maxTasks) {
        cout << "Task list is full! You cannot add more than " << maxTasks << " tasks.\n";
        return;
    }
    cin.ignore();  
    string taskDescription;
    string dueDate;

    
    cout << "Enter the task description: ";
    getline(cin, taskDescription);
    
    
    cout << "Enter the due date (DD/MM/YYYY): ";
    getline(cin, dueDate);

    tasks[taskCount].setDescription(taskDescription);
    tasks[taskCount].setDueDate(dueDate);
    taskCount++;
    cout << "Task added successfully.\n";
}


void listTasks(const Task tasks[], int taskCount) {
    cout << "\n--- Task List ---\n";
    if (taskCount == 0) {
        cout << "No tasks available.\n";
        return;
    }

    for (int i = 0; i < taskCount; ++i) {
        tasks[i].printTask(i);
    }
}


void completeTask(Task tasks[], int taskCount) {
    if (taskCount == 0) {
        cout << "No tasks to complete.\n";
        return;
    }

    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= taskCount) {
        tasks[taskNumber - 1].markCompleted();
        cout << "Task marked as completed.\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    int maxTasks;
    cout << "Enter the number of tasks you want to schedule: ";
    cin >> maxTasks;

    
    Task* tasks = new Task[maxTasks];
    int taskCount = 0;  
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks, taskCount, maxTasks);
                break;
            case 2:
                listTasks(tasks, taskCount);
                break;
            case 3:
                completeTask(tasks, taskCount);
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    
    delete[] tasks;

    return 0;
}

