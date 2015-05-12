#include "Page.h"

Page::Page(int iPagNum){
    this->bMod=false;
    this->bOcup=false;
    this->bRes=false;
    this->bRef=false;

}

Page::~Page(){

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


}


