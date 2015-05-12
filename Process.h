#include <stdio.h>
#include <iostream>
#include <queue>
#include <time.h>

class Process{
    private:
        int size; //In bytes
        int ID;
        int pageFaults;
        int swapOut;
        clock_t arrivalTime, exitTime;
        std::queue<int> assignedPages;
        
    public:
        Process(int ID);
        ~Process();        
        
        int getSize();
        clock_t getArrivalTime();
        clock_t getExitTime();
        double getReturnTime();
        std::queue<int> getAssignedPages();
        
        void setSize(int size);
        void assignPage(int page);
        void end();
};
