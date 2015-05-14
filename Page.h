#include <stdio.h>
#include <iostream>
#include <queue>

class Page{
    private:
        bool bMod, bOcup, bRes, bRef;
		int iPageNum;
		int address;
        
    public:
        Page();
        Page(int iPageNum);

        int getPageNum();
        int getAddress();
        bool getbMod();
        bool getbOcup();
        bool getbRes();
        bool getbRef();
        void setPageNum(int pageNum);
        void setAddress(int address);
        void setbMod(bool bMod);
        void setbOcup(bool bOcup);
        void setbRes(bool bRes);
        void setbRef(bool bRef);
        
        void end();
};
