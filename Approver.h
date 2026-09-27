/*
 * CSE 3206 | Lab 3 | Group 6 | Pattern: Chain of Responsibility
 * File   : Approver.h
 * Author : Roll 136
 * Role   : Handler (abstract) - keeps the link to the next handler
 */
#ifndef APPROVER_H
#define APPROVER_H

#include <iostream>
#include <string>
#include "LeaveRequest.h"

class Approver {
protected:
    Approver* next = nullptr;   // next handler (not owned)
    std::string title;

    // Pass the request on, or reject it at the end of the chain
    void forward(const LeaveRequest& request) {
        if (next != nullptr) {
            std::cout << "   " << title << " -> forwarding to " << next->getTitle() << "\n";
            next->handleRequest(request);
        } else {
            std::cout << "   [REJECTED] No authority can approve " << request.getDays()
                      << " days of leave.\n";
        }
    }

    void approve(const LeaveRequest& request) const {
        std::cout << "   [APPROVED] by " << title << " (" << request.getDays() << " day(s))\n";
    }

public:
    explicit Approver(const std::string& title) : title(title) {}
    virtual ~Approver() = default;

    // Returns the next handler so calls can be chained: a.setNext(&b)->setNext(&c)
    Approver* setNext(Approver* nextApprover) {
        next = nextApprover;
        return nextApprover;
    }

    const std::string& getTitle() const { return title; }

    virtual void handleRequest(const LeaveRequest& request) = 0;
};

#endif
