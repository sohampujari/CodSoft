#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};
void addTask(std::vector<Task>& tasks) {
    std::string description;
    std::cout << "Enter task description: ";
    std::cin.ignore();
    std::getline(std::cin, description);
    tasks.emplace_back(description);
    std::cout << "Task added.\n";
}
void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks in the list.\n";
    } else {
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].description << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
        }
    }
}
void markTaskAsCompleted(std::vector<Task>& tasks) {
    size_t index;
    std::cout << "Enter task number to mark as completed: ";
    std::cin >> index;
    if (index > 0 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        std::cout << "Task marked as completed.\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}
void removeTask(std::vector<Task>& tasks) {
    size_t index;
    std::cout << "Enter task number to remove: ";
    std::cin >> index;
    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        std::cout << "Task removed.\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}
int main() {
    std::vector<Task> tasks;
    int choice;
    while (true) {
        std::cout << "\nTo-Do List Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskAsCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                std::cout << "Exiting the program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}

