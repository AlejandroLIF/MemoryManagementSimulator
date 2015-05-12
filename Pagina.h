#include <stdio.h>
#include <iostream>
#include <queue>

class Page{
    private:
        bool bMod, bOcup, bRes, bRef;
		int iPagNum
        
    public:
        Page(int iPagNum);
        ~Page();        
        
        int iPagNum();
        bool getbMod();
		bool getbOcup();
		bool getbRes();
		bool getbRef();
        
        
        void end();
};
