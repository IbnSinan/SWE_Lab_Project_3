/*
 * CSE 3206 | Lab 3 | Group 6 | Pattern: Chain of Responsibility
 * File   : main.cpp
 * Author : Roll 137
 * Role   : Client - builds the chain and submits leave requests
 *
 * Scenario: University Leave Application Approval System
 *   Class Advisor -> Head of Department -> Dean -> (rejected)
 *
 * Build: g++ -std=c++17 -Wall -o leave_approval main.cpp
 */
#include <iostream>
#include <stdexcept>
#include <vector>
#include "ConcreteApprovers.h"

using namespace std;

void submit(Approver& firstApprover, const LeaveRequest& request) {
    cout << "\nApplication: " << request.getStudentName() << " (Roll " << request.getRoll()
         << ") | " << request.getDays() << " day(s) | Reason: " << request.getReason() << "\n";
    firstApprover.handleRequest(request);
}

int main() {
    // 1. Create the handlers
    ClassAdvisor advisor;
    HeadOfDepartment head;
    Dean dean;

    // 2. Build the chain: Advisor -> Head -> Dean
    advisor.setNext(&head)->setNext(&dean);

    cout << "===== University Leave Approval System (Chain of Responsibility) =====\n";

    // 3. Submit requests to the FIRST handler only; the chain does the rest
    vector<LeaveRequest> requests = {
        LeaveRequest("Rahim",  "2103001", 1,  "Fever"),
        LeaveRequest("Karim",  "2103002", 4,  "Family program"),
        LeaveRequest("Nusrat", "2103003", 8,  "Surgery recovery"),
        LeaveRequest("Tanvir", "2103004", 15, "Study tour abroad"),
    };

    for (const LeaveRequest& request : requests) {
        submit(advisor, request);
    }

    // 4. Invalid input is caught before it enters the chain
    try {
        LeaveRequest invalid("Sadia", "2103005", 0, "Typo in form");
        submit(advisor, invalid);
    } catch (const invalid_argument& e) {
        cout << "\nApplication: Sadia (Roll 2103005) | 0 day(s)\n   [ERROR] " << e.what() << "\n";
    }

    // 5. Interactive mode for the live demonstration
    cout << "\n----- Try your own request (enter 0 days to exit) -----\n";
    while (true) {
        int days;
        cout << "Number of leave days: ";
        if (!(cin >> days) || days == 0) {
            break;
        }
        try {
            submit(advisor, LeaveRequest("Demo Student", "2103999", days, "Live demo"));
        } catch (const invalid_argument& e) {
            cout << "   [ERROR] " << e.what() << "\n";
        }
    }

    cout << "\nGoodbye!\n";
    return 0;
}
