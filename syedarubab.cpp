#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// Structure to represent a process
struct Process {
    int id;
    std::string name;
    std::string status;
};

// Function to display all processes
void displayProcesses(const std::vector<Process>& processes) {
    std::cout << std::setw(10) << "Process ID" 
              << std::setw(20) << "Process Name" 
              << std::setw(15) << "Status" << "\n";
    std::cout << std::string(45, '-') << "\n";

    for (const auto& process : processes) {
        std::cout << std::setw(10) << process.id 
                  << std::setw(20) << process.name 
                  << std::setw(15) << process.status << "\n";
    }
}

// Function to terminate a process by ID
bool terminateProcess(std::vector<Process>& processes, int processId) {
    for (auto it = processes.begin(); it != processes.end(); ++it) {
        if (it->id == processId) {
            std::cout << "Terminating process: " << it->name << " (ID: " << it->id << ")\n";
            processes.erase(it);
            return true;
        }
    }
    std::cout << "Process with ID " << processId << " not found.\n";
    return false;
}

int main() {
    // Example list of processes
    std::vector<Process> processes = {
        {1, "System Idle", "Running"},
        {2, "Chrome", "Running"},
        {3, "Code Editor", "Sleeping"},
        {4, "Terminal", "Running"}
    };

    int choice = 0;

    while (choice != 3) {
        std::cout << "\nProcess Manager\n";
        std::cout << "1. Display all processes\n";
        std::cout << "2. Terminate a process\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                displayProcesses(processes);
                break;

            case 2: {
                int processId;
                std::cout << "Enter Process ID to terminate: ";
                std::cin >> processId;
                terminateProcess(processes, processId);
                break;
            }

            case 3:
                std::cout << "Exiting Process Manager.\n";
                break;

            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
