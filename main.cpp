#include <iostream>
#include <conio.h>
#include <cstring>
#include <windows.h>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
 
using namespace std;

#include "struct.cpp"
#include "fn.cpp"
#include "ma.cpp"
#include "mu.cpp"

int main()
{   
    srand(time(0));
    
    config();
     
    Nusers = LOADstruct(FILEuser,USERS); 
    Nstud  = LOADstruct(FILEstud,STUD); 
             LOADstruct(FILEstat,STAT);
    
    autentification();
    
	while(1)
    {
    	
    	
    	switch(USERS[LOGIN].type)
    	{
    		case 0 : sys = USERmanagement(); break;
    		case 1 : sys = ADMINmanagement();
		}
		
		switch(sys)
		{
			case 1 : insert_u(); break;
			case 2 : show_u(); break;
			case 3 : edit_u(); break;
			case 4 : find_u(); break;
			case 5 : DEL_u(); break;
			
			case 6 : insert_s(); break;
			case 7 : show_s(); break;
			case 8 : find_s(); break;
			case 9 : edit_s(); break;
			case 10 : DEL_s(); break;
			 
			case 11 : raport(); break;
			
			case 27 : SAVEstruct(FILEuser,USERS,Nusers);
			          SAVEstruct(FILEstud,STUD,Nstud);
			          SAVEstruct(FILEstat,STAT,Nusers);
			          exit(0);
		}
	}
	
	return 0;
} 


















