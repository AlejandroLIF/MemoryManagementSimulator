#include <stdio.h>
#include <iostream>
#include <queue>

class Page{
    private:
        bool bMod, bOcup, bRes, bRef;
		int iPagNum;
        
    public:
        Page();
        Page(int iPagNum);
        
    	int getPagNum();
    	bool getbMod();
		bool getbOcup();
		bool getbRes();
		bool getbRef();
        
        
        void end();
};
