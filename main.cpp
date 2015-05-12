#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>

#include "Process.cpp"

using namespace std;

int main(int argc, char* argv[]){
    string line;
    if(argc != 2){
        printf("Usage: %s, input.txt", argv[0]);
        return -1;
    }
    ifstream inputFile(argv[1]);
    if(!inputFile.is_open()){
        printf("Unable to open file \"%s\"!", argv[1]);
        return -1;
    }
    
    while(getline(inputFile, line)){
        istringstream iss(line);
        vector<string> tokens{  istream_iterator<string>{iss},
                                istream_iterator<string>{}};
        char temp = tokens.at(0)[0]; //First char of the first token.
        switch(temp){
            case 'P':
            case 'p':
                break;
            case 'A':
            case 'a':
                break;
            case 'L':
            case 'l':
                break;
            case 'F':
            case 'f':
                break;
            case 'E':
            case 'e':
                break;
            default:
                //Should never happen
                printf("Unknown command \"%c\". Exiting.", temp);
                return -1;
                break;
        }
    }
    
}
