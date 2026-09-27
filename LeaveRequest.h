/*
 * CSE 3206 | Lab 3 | Group 6 | Pattern: Chain of Responsibility
 * File   : LeaveRequest.h
 * Author : Roll 136
 * Role   : Request object - the data that travels along the chain
 */
#ifndef LEAVE_REQUEST_H
#define LEAVE_REQUEST_H

#include <stdexcept>
#include <string>

class LeaveRequest {
private:
    std::string studentName;
    std::string roll;
    int days;
    std::string reason;

public:
    LeaveRequest(const std::string& studentName, const std::string& roll, int days,
                 const std::string& reason)
        : studentName(studentName), roll(roll), days(days), reason(reason) {
        if (days <= 0) {
            throw std::invalid_argument("Leave duration must be at least 1 day.");
        }
    }

    const std::string& getStudentName() const { return studentName; }
    const std::string& getRoll() const { return roll; }
    int getDays() const { return days; }
    const std::string& getReason() const { return reason; }
};

#endif
