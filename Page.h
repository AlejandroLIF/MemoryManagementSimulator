#include <stdio.h>
#include <iostream>
#include <queue>

class Page{
    private:
        bool bMod, bOcup, bRes, bRef;
		int iPageNum;
        
    public:
        Page();
        Page(int iPageNum);

        int getPageNum();
        bool getbMod();
        bool getbOcup();
        bool getbRes();
        bool getbRef();
        void setbMod(bool bMod);
        void setbOcup(bool bOcup);
        void setbRes(bool bRes);
        void setbRef(bool bRef);
        void free();
        
        void end();
};
