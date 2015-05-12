#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <iterator>

#include "Process.cpp"
//Methods
void sizeCheck(int petSize, int freeMem){
    if (petSize>freeMem)
        swap(ID, ID2);
    else if (petSize>6144)
        printf("El Tamaño de la peticiones mayor que el tamaño de la memoria \n");
    else
        loadProcess(ID);
}

int realToVirtual(posReal){
    
    
}

int realToVirtual(int page, int shift){
    int rem=page%8;
    int pos=8*Page.getPageNum;
    
    


}

void sort(){
    
}
using namespace std;

int main(int argc, char* argv[]){
    string line;
    if(argc != 2){
        printf("Usage: %s, input.txt\n", argv[0]);
        return -1;
    }
    ifstream inputFile(argv[1]);
    if(!inputFile.is_open()){
        printf("Unable to open file \"%s\"!\n", argv[1]);
        return -1;
    }
    
    while(getline(inputFile, line)){
        istringstream iss(line);
        vector<string> tokens{  istream_iterator<string>{iss},
                                istream_iterator<string>{}};
        try{
        char temp = tokens.at(0)[0]; //First char of the first token.
        switch(temp){
            case 'P':
            case 'p':
                printf("P\t%i\t%i\n", atoi(tokens.at(1).c_str()), atoi(tokens.at(2).c_str()));
                break;
            case 'A':
            case 'a':
                printf("A\t%i\t%i\t%i\n", atoi(tokens.at(1).c_str()), atoi(tokens.at(2).c_str()), atoi(tokens.at(3).c_str()));
                break;
            case 'L':
            case 'l':
                printf("L\t%i\n", atoi(tokens.at(1).c_str()));
                break;
            case 'F':
            case 'f':
                printf("F\n");
                break;
            case 'E':
            case 'e':
                printf("E\n");
                break;
            default:
                //Should never happen
                printf("Unknown command \"%c\".\n\tExiting...\n", temp);
                return -1;
                break;
        }
        }
        catch (char e){
            printf("Error\n");
        }
    }
    return 0;   
}
