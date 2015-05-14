#include "Page.h"

Page::Page(){
    Page(-1);
}

Page::Page(int iPageNum){
    this->iPageNum = iPageNum;
    this->bMod=false;
    this->bOcup=false;
    this->bRes=false;
    this->bRef=false;
    this->address = 0;
}

int Page::getPageNum(){
    return iPageNum;
}

int Page::getAddress(){
    return address;
}

bool Page::getbMod(){
    return bMod;
}

bool Page::getbOcup(){
    return bOcup;
}

bool Page::getbRes(){
    return bRes;;
}

bool Page::getbRef(){
    return bRef;
}

void Page::setPageNum(int iPageNum){
    this->iPageNum = iPageNum;
}

void Page::setAddress(int address){
    this->address = address;
}

void Page::setbMod(bool bMod){
    this->bMod = bMod;
}

void Page::setbOcup(bool bOcup){
    this->bOcup = bOcup;
}
void Page::setbRes(bool bRes){
    this->bRes = bRes;
}

void Page::setbRef(bool bRef){
    this->bRef = bRef;
}
