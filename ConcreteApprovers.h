/*
 * CSE 3206 | Lab 3 | Group 6 | Pattern: Chain of Responsibility
 * File   : ConcreteApprovers.h
 * Author : Roll 138
 * Role   : Concrete handlers - each one checks only its own rule
 *            Class Advisor      : up to 2 days
 *            Head of Department : up to 5 days
 *            Dean               : up to 10 days
 */
#ifndef CONCRETE_APPROVERS_H
#define CONCRETE_APPROVERS_H

#include "Approver.h"

class ClassAdvisor : public Approver {
public:
    ClassAdvisor() : Approver("Class Advisor") {}

    void handleRequest(const LeaveRequest& request) override {
        if (request.getDays() <= 2) {
            approve(request);
        } else {
            forward(request);
        }
    }
};

class HeadOfDepartment : public Approver {
public:
    HeadOfDepartment() : Approver("Head of Department") {}

    void handleRequest(const LeaveRequest& request) override {
        if (request.getDays() <= 5) {
            approve(request);
        } else {
            forward(request);
        }
    }
};

class Dean : public Approver {
public:
    Dean() : Approver("Dean") {}

    void handleRequest(const LeaveRequest& request) override {
        if (request.getDays() <= 10) {
            approve(request);
        } else {
            forward(request);
        }
    }
};

#endif
