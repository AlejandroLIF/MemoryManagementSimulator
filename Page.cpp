#include "Page.h"

Page::Page(){
    Page(-1);
}

Page::Page(int iPageNum){
    this->bMod=false;
    this->bOcup=false;
    this->bRes=false;
    this->bRef=false;
}

int Page::getPageNum(){
    return iPagNum;
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

void Page::free(){
    Page(-1);
}
