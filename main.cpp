#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <iterator>
#include <list>
#include <ctime>

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
void sort();

int availableReal = REAL_MEMORY_SIZE,
    availablePaging = PAGING_MEMORY_SIZE,
    swapoutcounter = 0;


//These are the page tables
Page realMemory[REAL_MEMORY_SIZE],
     pagingMemory[PAGING_MEMORY_SIZE];

//These are the process lists
list<Process>   activeProcesses,
                completedProcesses;
list<Page)      pages


int main(int argc, char* argv[]){
    string line;
    std::clock_t start;
    start = std::clock();
    

    }
    
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
                
                
                break;
            case 'E':
            case 'e':
                //No need to try/catch. No more input is processed.
                
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
    //While not all pages have been assigned.
    while(n){
        //Verify total memory availability
        if(availableReal){
            //TODO 
            process.assignPage(p);
            availableReal--;
        }
        else if(availablePaging){
            //TODO: sort(realMemory);
            //TODO: swap(realMemory with pageMemory);
            
            // This is wrong: list<Page>.sort();
        }
        else{
            //TODO Error: not enough memory.
            printf("No hay memoria suficiente! \n");
            break; //Don't bother trying to assign the rest of the pages, if any.
        }
        n--;
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

void sort(){

    
}

void reset(int start){
        if (start=>5000) //Define number of cycles for reset
            for (list<Page>::iterator it = pages.begin(); it != pages.end(); it++){
                *it.setbMod(false);
                *it.setbRef(false);
        }
        else 
        return 0;
}

