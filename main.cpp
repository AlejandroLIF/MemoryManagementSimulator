#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <iterator>
#include <list>
#include <ctime>
#include <algorithm>

#include "Process.cpp"
#include "Page.cpp"

#define REAL_MEMORY_SIZE 256
#define PAGING_MEMORY_SIZE 512
#define PAGE_SIZE 8

using namespace std;

void loadProcess(int n, int p);
void accessProcess(int d, int p, bool m);
void freeProcess(int p);
bool freePage(int p);
void sizeCheck(int petSize, int freeMem);
bool compareProcess(Page pageOne, Page pageTwo);
void reset(int start);
void fin();

int pageIDgenerator = 0;

int availableReal = REAL_MEMORY_SIZE,
    availablePaging = PAGING_MEMORY_SIZE,
    swapoutcounter = 0;


//These are the page tables
Page realMemory[REAL_MEMORY_SIZE],
     pagingMemory[PAGING_MEMORY_SIZE];

//These are the process lists
list<Process>   activeProcesses,
                completedProcesses;

int main(int argc, char* argv[]){
    string line;
    std::clock_t start;
    start = std::clock();
        
    if(argc != 2){
        printf("Usage: %s, input.txt\n", argv[0]);
        return -1;
    }
    ifstream inputFile(argv[1]);
    if(!inputFile.is_open()){
        printf("Unable to open file \"%s\"!\n\
                Program will now exit.\n", argv[1]);
        return -1;
    }
    
    while(getline(inputFile, line)){
        istringstream iss(line);
        vector<string> tokens{  istream_iterator<string>{iss},
                                istream_iterator<string>{}};
        
        reset(start);                        
        char temp = tokens.at(0)[0]; //First char of the first token.
        switch(temp){
            case 'P':
            case 'p':
                try{
                    int n = atoi(tokens.at(1).c_str()),
                        p = atoi(tokens.at(2).c_str());
                    loadProcess(n, p);
                }
                catch(...){
                
                }
                break;
            case 'A':
            case 'a':
                try{
                    int     d = atoi(tokens.at(1).c_str()),
                            p = atoi(tokens.at(2).c_str());
                    bool    m = atoi(tokens.at(3).c_str());
                    
                    accessProcess(d, p, m);
                }
                catch(...){
                
                }
                break;
            case 'L':
            case 'l':
                try{
                    int p = atoi(tokens.at(1).c_str());
                    freeProcess(p);
                }
                catch(...){
                
                }
                break;
            case 'F':
            case 'f':
                //No need to try/catch. No more input is processed.
                fin();
                
                break;
            case 'E':
            case 'e':
                //No need to try/catch. No more input is processed.
                printf("Unknown command \"%c\".\n\tExiting...\n", temp);
                break;
            default:
                //Any type of input in the default case is an error.
                printf("Unknown command \"%c\".\n\tExiting...\n", temp);
                
                break;
        }
    }
    return 0;   
}

void loadProcess(int n, int p){
    //Translate bytes needed to pages needed.
    //See http://www.cs.nott.ac.uk/~rcb/G51MPC/slides/NumberLogic.pdf for CEIL function explanation.
    n = (n + PAGE_SIZE - 1)/PAGE_SIZE;
    Process process = Process(p, n);
    
    // Verifies if there are enough pages in memory for the process to be loaded.
    if(n <= REAL_MEMORY_SIZE && n < availableReal + availablePaging){
        //While not all pages have been assigned.
        while(n--){
            //Verify real memory availability
            if(!availableReal){
                sort(realMemory, realMemory + REAL_MEMORY_SIZE, compareProcess);
                
                //TODO: move realMemory[0] to virtualMemory;
                
                availablePaging--;
                availableReal++;
            }
            //At this point, there is always enough real memory.
            // Looks for an empty space in real memory
            int i=-1;
            do{
                ++i;
            }while(realMemory[i].getbOcup());
            realMemory[i] = Page(pageIDgenerator);
            realMemory[i].setbOcup(true);
            realMemory[i].setbRes(true);
            process.assignPage(pageIDgenerator++);
            availableReal--;
        }
        activeProcesses.push_back(process);
    }
    else{
        printf("No hay memoria suficiente para cargar el proceso! \n");
    }
}

void accessProcess(int d, int p, bool m){
    //Translate virtual address to real address.
    int page = d / PAGE_SIZE;
    //The displacement is ignored for the purposes of this exercise.
    
    list<int> assignedPages;
    for(list<Process>::iterator it = activeProcesses.begin(); it != activeProcesses.end(); it++){
        if((*it).getID() == p){
            assignedPages = it->getAssignedPages();
            
            //Checks if the page is in real memory or virtual memory
            if(assignedPages.getbRes()){
                assignedPages.setbRef(true);
                if(m)
                    assignedPages.setbMod(true);
            }
            else {

        }
    }
    
    if(assignedPages.empty()){
        //ERROR: Process not found.
    }
    
    //TODO
    
}

void freeProcess(int p){
    //Checks the pages process p has.
    list<int> assignedPages;
    list<Process>::iterator it;
    for(it = activeProcesses.begin(); it != activeProcesses.end(); it++){
        if(it->getID() == p){
            assignedPages = it->getAssignedPages();
            break;
        }
    }
    
    if(it == activeProcesses.end()){
        printf("Tried to free a process that wasn't loaded to memory.");
    }
    else{
        //Swap out should not be increased because pages aren't swapped. They are just marked as "free".
        //Set exit time.
        it->end();
        //Move process to the completed list.
        completedProcesses.push_back(*it);
        //Remove process from the active list.
        activeProcesses.erase(it);
        while(!assignedPages.empty()){
            int pageNumber = assignedPages.front();
            assignedPages.pop_front();
            freePage(pageNumber);
        }
    }
    //Process freed.
}

//#TODO: print freed pages along with process ID.
bool freePage(int p){
    for(int i=0; i<REAL_MEMORY_SIZE; i++){
        if(realMemory[i].getPageNum() == p){
            realMemory[i].free();
            return true;
        }
    }
    for(int i=0; i<PAGING_MEMORY_SIZE; i++){
        if(pagingMemory[i].getPageNum() == p){
            pagingMemory[i].free();
            return true;
        }
    }
    return false;
}


int realToVirtual(int posReal){
    
    
}

void reset(int start){
        if (start >= 5000) //Define number of cycles for reset
            for(int i=0; i<REAL_MEMORY_SIZE; i++){
                realMemory[i].setbMod(false);
                realMemory[i].setbRef(false);
            }
        
}

bool compareProcess(Page pageOne, Page pageTwo){
    // Returns true if pageOne has residence bit off and pageTwo on
    if(pageOne.getbRes() == false && pageTwo.getbRes() == true){
        return true;
    }
    // Enters else if, if both pages have the residence bit off
    else if(pageOne.getbRes() == false && pageTwo.getbRes() == false){
        // Returns true if pageOne has both residence and reference bits off and pageTwo having residence bit off and reference bit on.
        if(pageOne.getbRef() == false && pageTwo.getbRef() == true){
            return true;
        }
        //Enters else if, if both pages have both residence and reference bits off. 
        else if(pageOne.getbRef() == false && pageTwo.getbRef() == false){
            //Returns true if pageOne has residence, reference and modification bits off while pageTwo has both residence and reference bits off and modification bit on.
            if(pageOne.getbMod() == false && pageTwo.getbMod() == true){
                return true;
            }
        }
    }
    else{
        return false;
    }
}

void fin(){
    printf("Fin\n");
    list<int> assignedPages;
        for(list<Process>::iterator it = activeProcesses.begin(); it != activeProcesses.end(); it++){
            printf("Process ID:%i\n",it->getID());
            printf("\tReturn time: %f\n",it->getReturnTime());
            printf("\tPage faults: %i\n",it->getPageFaults());
            printf("\tSwap outs: %i\n",it->getSwapOut());
            printf("\tSize: %i\n",it->getSize());
            printf("\tAssigned pages: ");
            assignedPages = it->getAssignedPages();
            
            for(list<int>::iterator pit = assignedPages.begin(); pit != assignedPages.end(); pit++){
                printf("%i ", *pit);
            }
        }     
}

