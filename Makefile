CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

leave_approval: main.cpp $(wildcard *.h)
	$(CXX) $(CXXFLAGS) -o $@ main.cpp

run: leave_approval
	./leave_approval

clean:
	rm -f leave_approval leave_approval.exe

.PHONY: run clean
