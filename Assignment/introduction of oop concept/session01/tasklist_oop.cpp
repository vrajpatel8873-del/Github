#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Task {
private:
    string title;
    bool isDone;

public:
    Task(const string& taskTitle) : title(taskTitle), isDone(false) {}

    void markDone() { isDone = true; }

    void display() const {
        cout << title << " [" << (isDone ? "DONE" : "PENDING") << "]\n";
    }
};

class TaskList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& title) { tasks.emplace_back(title); }

    bool markTaskDone(size_t index) {
        if (index >= tasks.size()) return false;
        tasks[index].markDone();
        return true;
    }

    void showTasks() const {
        if (tasks.empty()) {
            cout << "No tasks yet.\n";
            return;
        }
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            tasks[i].display();
        }
    }
};

int main() {
    TaskList list;
    list.addTask("Study C++");
    list.addTask("Practice loops");
    list.addTask("Submit assignment");
    cout << "Initial list:\n";
    list.showTasks();
    list.markTaskDone(1);
    cout << "\nAfter marking task 2 as done:\n";
    list.showTasks();

    cout << "\nThree improvements over the procedural version:\n"
         << "1. Task data and behaviour are grouped in a class.\n"
         << "2. Private fields prevent direct, uncontrolled changes.\n"
         << "3. TaskList owns list operations, making the code easier to extend.\n";
}
