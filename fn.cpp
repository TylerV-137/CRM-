/*

FILE *fp;
    
    if((fp = fopen(FILEuser,"w+b"))==NULL){system("cls"); cout<<"Error creating DB 1 r+"<<endl; system("pause"); exit(0);}
    
    strcpy(USERS[0].username,"admin");
    strcpy(USERS[0].password,"admin");
    USERS[0].status=1;
    
    strcpy(USERS[1].username,"user");
    strcpy(USERS[1].password,"user");
    USERS[1].status=0;
    
    fwrite(USERS,sizeof(users),2,fp);
    
    fclose(fp);
    

    
    if((fp = fopen(FILEstud,"w+b"))==NULL){system("cls"); cout<<"Error creating DB 2 r+"<<endl; system("pause"); exit(0);}
    
    strcpy(STUD[0].Fname,"AAAA");
    strcpy(STUD[0].Lname,"aaaa");
    STUD[0].status=1;
    
    strcpy(STUD[1].Fname,"BBBB");
    strcpy(STUD[1].Lname,"bbbb");
    STUD[1].status=0;
    
    fwrite(STUD,sizeof(students),2,fp);
    
    fclose(fp);

    if((fp = fopen(FILEstat,"w+b"))==NULL){system("cls"); cout<<"Error creating DB 3 r+"<<endl; system("pause"); exit(0);}
    
    fwrite(USERS,sizeof(users),0,fp);
    
    fclose(fp);






for(int i=0; i<Nstud; i++)
	{
		cout<<i<<setw(4)<<" ["<<STUD[i].ID<<"] F-Name:"<<STUD[i].Fname<<setw(10)<<" L-Name:"<<STUD[i].Lname<<setw(6)<<" Age:"<<STUD[i].age;
		cout<<setw(6)<<" Group:"<<STUD[i].group<<setw(10)<<" Status:"<<STUD[i].status;
		cout<<setw(15)<<" Inserted by:"<<STUD[i].inserted_by<<setw(15)<<" IDNP:";
		for(int j=0; j<13; j++)
		{
			cout<<STUD[i].IDNP[j]; 
		} 
		cout<<endl;
	}
	system("pause");

*/

void raport()
{
	if(q==1)
	{   
	    int *z = new int;
	    
	    system("cls");
	    if(x==1)
	    {
	    	cout<<"\n\n\n\n\t1.Active"<<endl;
			cout<<"\t2.Inactive"<<endl;
			cout<<"\t3.ALL"<<endl;
			cout<<"\tESC <-Go back"<<endl;
			switch(_getch())
	    	{
		    	case 49 : *z=1; break;
		    	case 50 : *z=2; break;
		    	case 51 : *z=3; break;
		
		    	case 27 : return;
	    	}
		}
		else if(x==0) *z=1;
		
		students *S = new students[Nstud];
		
	    for(int i=0; i<Nstud; i++)
	    {
	   	    S[i] = STUD[i];
	    }
	   
	    bool *k = new bool; *k=1;
	   
	    students temp;
	    while(*k)
	    {
	   	    *k=0;
	   	    for(int i=0; i<Nstud-1; i++)
	   	    {
	   	   	    if(S[i].age > S[i+1].age)
	   	   	    {
	   	   	        temp = S[i];
				    S[i] = S[i+1];
					S[i+1] = temp;
					*k=1;	
				}
		    }
	    }
	    
	    delete k;
	    
	    if(y==1)
	    {
	    	system("cls");
	        cout<<"\n\n\n\n\t-----------------------------------------------------------"<<endl;
	        cout<<setw(3)<<"\tID"<<setw(11)<<"First Name"<<setw(15)<<"Last Name"<<setw(4)<<"Age"<<setw(6)<<"Group"<<setw(9)<<"Status"<<endl;
	        cout<<"\t-----------------------------------------------------------"<<endl;
	        
	        if(*z==1) //////////////////////////////////////////////////////////*********************************** list of all active students by age
	        {
		        for(int i=0; i<Nstud; i++)
			    {
			        if(S[i].status==1) cout<<setw(9)<<S[i].ID<<setw(12)<<S[i].Fname<<setw(15)<<S[i].Lname<<setw(4)<<S[i].age<<setw(6)<<S[i].group<<setw(9)<<"Active"<<endl;
			    }
			    cout<<"\t-----------------------------------------------------------"<<endl;
		    }
		    
		    else if(*z==2 && x==1) /////////////////////////////////////////////////////////************************************* List of all inactive students by age
	        {
		        for(int i=0; i<Nstud; i++)
			    {
			        if(S[i].status==0) cout<<setw(9)<<S[i].ID<<setw(12)<<S[i].Fname<<setw(15)<<S[i].Lname<<setw(4)<<S[i].age<<setw(6)<<S[i].group<<setw(9)<<"Inactive"<<endl;
			    }
			    cout<<"\t-----------------------------------------------------------"<<endl;
		    }
		    
			else if(*z==3 && x==1) //////////////////////////////////////************************************** List of all students by age
		    {
		        for(int i=0; i<Nstud; i++)
			    {
			        if(S[i].status==1) cout<<setw(9)<<S[i].ID<<setw(12)<<S[i].Fname<<setw(15)<<S[i].Lname<<setw(4)<<S[i].age<<setw(6)<<S[i].group<<setw(9)<<"Active"<<endl;
			        else cout<<setw(9)<<S[i].ID<<setw(12)<<S[i].Fname<<setw(15)<<S[i].Lname<<setw(4)<<S[i].age<<setw(6)<<S[i].group<<setw(9)<<"Inactive"<<endl;
			    }
		        cout<<"\t-----------------------------------------------------------"<<endl;
		    }
		    system("pause");
	    }
		
		if(y==2)  ////////////////////////////////////////////////////*********************************** List of all active students by group
		{
			system("cls");
	        cout<<"\n\n\n\n\t-----------------------------------------------------------"<<endl;
	        cout<<setw(3)<<"\tID"<<setw(11)<<"First Name"<<setw(15)<<"Last Name"<<setw(6)<<"Group"<<setw(15)<<"IDNP"<<setw(9)<<"Status"<<endl;
	        cout<<"\t-----------------------------------------------------------"<<endl;
	        
			if(*z==1)
			{
				int *vectorID = new int [Nstud];
	    		for(int i=0; i<Nstud; i++)
				{
			    	for(int j=0; j<Nstud; j++)
			    	{
			    		if(STUD[j].status==1)
			    		{
			    			if(strcmp(STUD[i].group,STUD[j].group)==0 && vectorID[j]!=j)
						{
					    	cout<<setw(9)<<STUD[j].ID<<setw(12)<<STUD[j].Fname<<setw(15)<<STUD[j].Lname<<setw(6)<<STUD[j].group<<setw(3);
						
							int *t = new int; *t=0;
			            	while(*t<13)
			            	{
				           		cout<<STUD[j].IDNP[*t];
				           		*t+=1;
			            	}
			            	delete t;
							cout<<setw(9)<<"Active"<<endl;
						
							vectorID[j]=j;
						}
						}
			        	 
					}
				}
				delete []vectorID;
				cout<<"\t-----------------------------------------------------------"<<endl;
				system("pause");
			}	
		
		    else if(*z==2 && x==1) /////////////////////////////////////////***************************************** List of all inactive students by group
			{
				int *vectorID = new int [Nstud];
	    		for(int i=0; i<Nstud; i++)
				{
			    	for(int j=0; j<Nstud; j++)
			    	{
			        	if(strcmp(STUD[i].group,STUD[j].group)==0 && vectorID[j]!=j && STUD[j].status==0)
						{
							cout<<setw(9)<<STUD[j].ID<<setw(12)<<STUD[j].Fname<<setw(15)<<STUD[j].Lname<<setw(6)<<STUD[j].group<<setw(3);
						
							int *t = new int; *t=0;
			            	while(*t<13)
			            	{
				           		cout<<STUD[j].IDNP[*t];
				           		*t+=1;
			            	}
			            	delete t;
							cout<<setw(9)<<"Inactive"<<endl;
						
							vectorID[j]=j;
						} 
					}
				}
				delete []vectorID;
				cout<<"\t-----------------------------------------------------------"<<endl;
				system("pause");
			}
			
			else if(*z==3 && x==1) /////////////////////////////////////////***************************************** List of all students by group
			{
				int *vectorID = new int [Nstud];
	    		for(int i=0; i<Nstud; i++)
				{
			    	for(int j=0; j<Nstud; j++)
			    	{
			        	if(strcmp(STUD[i].group,STUD[j].group)==0 && vectorID[j]!=j)
						{
							cout<<setw(9)<<STUD[j].ID<<setw(12)<<STUD[j].Fname<<setw(15)<<STUD[j].Lname<<setw(6)<<STUD[j].group<<setw(3);
						
							int *t = new int; *t=0;
			            	while(*t<13)
			            	{
				           		cout<<STUD[j].IDNP[*t];
				           		*t+=1;
			            	}
			            	delete t;
							if(STUD[j].status==1) cout<<setw(9)<<"Active"<<endl;
							else cout<<setw(9)<<"Inactive"<<endl;
						
							vectorID[j]=j;
						} 
					}
				}
				delete []vectorID;
				cout<<"\t-----------------------------------------------------------"<<endl;
				system("pause");
			}
		}
		
		if(y==3) /////////////////////////////////////////***************************** List of all active students
		{
			system("cls");
	        cout<<"\n\n\n\n\t-----------------------------------------------------------"<<endl;
	        cout<<setw(3)<<"\tID"<<setw(11)<<"First Name"<<setw(15)<<"Last Name"<<setw(6)<<"Group"<<setw(15)<<"IDNP"<<setw(9)<<"Status"<<endl;
	        cout<<"\t-----------------------------------------------------------"<<endl;
	        
			if(*z==1)
	        {
	            for(int i=0; i<Nstud; i++)
			    {
			        if(STUD[i].status==1)
				    {
					    cout<<setw(9)<<STUD[i].ID<<setw(12)<<STUD[i].Fname<<setw(15)<<STUD[i].Lname<<setw(6)<<STUD[i].group<<setw(3);
				    
					    int *t = new int; *t=0;
			            while(*t<13)
			            {
			                cout<<STUD[i].IDNP[*t];
				            *t+=1;
			            }
			        delete t;
				    cout<<setw(9)<<"Active"<<endl;
				    }
			    }
	    	    cout<<"\t-----------------------------------------------------------"<<endl;
	    	    system("pause");
			}	
			
        else if(*z==2 && x==1) /////////////////////////////////////////***************************** List of all inactive students
        	{
        		for(int i=0; i<Nstud; i++)
				{
			    	if(STUD[i].status==0)
					{
						cout<<setw(9)<<STUD[i].ID<<setw(12)<<STUD[i].Fname<<setw(15)<<STUD[i].Lname<<setw(6)<<STUD[i].group<<setw(3);
				    
						int *t = new int; *t=0;
			        	while(*t<13)
			        	{
			            	cout<<STUD[i].IDNP[*t];
				        	*t+=1;
			        	}
			    		delete t;
						cout<<setw(9)<<"Inactive"<<endl;
					}
				}
	    		cout<<"\t-----------------------------------------------------------"<<endl;
	    		system("pause");
			}
			
		else if(*z==3 && x==1) /////////////////////////////////////////***************************** List of all  students
        	{
        		for(int i=0; i<Nstud; i++)
				{
			    	cout<<setw(9)<<STUD[i].ID<<setw(12)<<STUD[i].Fname<<setw(15)<<STUD[i].Lname<<setw(6)<<STUD[i].group<<setw(3);
					int *t = new int; *t=0;
			    	while(*t<13)
			    	{
			        	cout<<STUD[i].IDNP[*t];
				    	*t+=1;
			    	}
			    	delete t;
					if(STUD[i].status==1) cout<<setw(9)<<"Active"<<endl;
					else cout<<setw(9)<<"Inactive"<<endl;
				}
	    		cout<<"\t-----------------------------------------------------------"<<endl;
	    		system("pause");
			}
        
	    	delete []S;
	    	delete z;
	    }
	}
	
	if(q==2 && y==1)
	{
	FILE *fp;
	
	if((fp=fopen("raport.doc","w+"))==NULL){system("cls"); cout<<"Error open raport w+"<<endl; system("pause"); return;}
	
	    fprintf(fp,"-----------------------------------\n");
	    fprintf(fp,"|%4s %13s %13s |\n","ID","Username","Status");
	    fprintf(fp,"-----------------------------------\n");
	
	    for(int i=1; i<Nusers; i++)
	    {
		    fprintf(fp,"|%4d %13s ",i,USERS[i].username,USERS[i].status);
		    if(USERS[i].status==1)fprintf(fp,"%13s |\n","Admin");
		    else fprintf(fp,"%13s |\n","User");
		
		    fprintf(fp,"...................................\n");
		    fprintf(fp,"|     %s %6d |\n","Nr_autentifications:",STAT[i].Nr_login);
		    fprintf(fp,"|     %s %8d |\n","Nr_inserted_users:",STAT[i].Nr_inserted_u);
		    fprintf(fp,"|     %s %5d |\n","Nr_inserted_students:",STAT[i].Nr_inserted_s);
		    fprintf(fp,"|     %s %4d |\n","Nr_edites_on_students:",STAT[i].Nr_edited_s);
		    fprintf(fp,"|     %s %2d |\n","Nr_deactivated_students:",STAT[i].Nr_delete_s);
		    fprintf(fp,"-----------------------------------\n");
	    }
	
	fclose(fp);
	
	system("raport.doc");
	}
	
	else if(q==3 && y==2) ////// ISSUE A RAPORT
	{
		char *name = new char[100];
		int *w = new int;
		system("cls");
		
		cout<<"\n\n\n\n\n\tEnter the ID of the user in order to proceed with the issuing the raport:"; cin>>*w;
       
	    if(*w<=0 || *w>=Nusers) { system("cls"); cout<<"\n\n\n\n\tNo data!"<<endl; system("pause"); return;}
        
		system("cls");
		cout<<"\n\n\n\n\n\tIssue raport for: "<<USERS[*w].username<<"?  y/n:";
		
		switch(_getch())
		{
			case 'y' :  system("cls");
			            cout<<"\n\n\n\n\n\tEnter the name of the file: "; cin>>name;
		                strcat(name,".doc");
			
			            FILE *fp;
			
			            if((fp=fopen(name,"w+"))==NULL){system("cls"); cout<<"Error open raport w+"<<endl; system("pause"); return;}
			            
						fprintf(fp,"-----------------------------------\n");
	                    fprintf(fp,"|%4s %13s %13s |\n","ID","Username","Status");
	                    fprintf(fp,"-----------------------------------\n");
	                   
	                    fprintf(fp,"|%4d %13s ",*w,USERS[*w].username,USERS[*w].status);
		                if(USERS[*w].status==1)fprintf(fp,"%13s |\n","Admin");
		                else fprintf(fp,"%13s |\n","User");
		
		                fprintf(fp,"...................................\n");
		                fprintf(fp,"|     %s %6d |\n","Nr_autentifications:",STAT[*w].Nr_login);
		                fprintf(fp,"|     %s %8d |\n","Nr_inserted_users:",STAT[*w].Nr_inserted_u);
		                fprintf(fp,"|     %s %5d |\n","Nr_inserted_students:",STAT[*w].Nr_inserted_s);
		                fprintf(fp,"|     %s %4d |\n","Nr_edites_on_students:",STAT[*w].Nr_edited_s);
		                fprintf(fp,"|     %s %2d |\n","Nr_deactivated_students:",STAT[*w].Nr_delete_s);
		                fprintf(fp,"-----------------------------------\n");
		                fclose(fp);
		                
		                system("cls");
					    cout<<"\n\n\n\n\t";
    				    for(int i=0; i<10; i++) { Sleep(100); cout<<"*"; }
    				    system("cls"); cout<<"\n\n\n\n\tFile was created in the local directory!"<<endl; Sleep(2000); break;
		    
			case 'n' :  return;
		}
	    delete w; delete name;	
    }
}

template <typename T>
void SAVEstruct(char F[],T s[],int N)
{
	FILE *fp;
    
    if((fp = fopen(F,"w+b"))==NULL){system("cls"); cout<<"Error SAVE struct w+"<<endl; system("pause"); exit(0);}
    
    fwrite(s,sizeof(T),N,fp);    
	    
    fclose(fp);
}

template <typename T>
int LOADstruct(char F[],T s[])
{
	FILE *fp;
    
    if((fp = fopen(F,"r+b"))==NULL){system("cls"); cout<<"Error LOAD struct r+"<<endl; system("pause"); exit(0);}
    
    x=fread(s,sizeof(T),100,fp);    
    
    return x;
    
    fclose(fp);
}

void autentification()
{
	int *i = new int; *i=0;
	bool *k = new bool; *k=0;
	int *eror = new int; *eror=0;
	int *timer = new int; *timer=0;
	int *KEY = new int;
	
	char *usr = new char[100];
	char *pass = new char[100];
	
	cout<<"\n\n\n\n\tEnter username: "; cin>>usr;
	cout<<"\t[0]Enter password: ";
	while(1)
	{
		*KEY=_getch();
		pass[*i] = (char)*KEY;
		
		if(*KEY==13)
		{
			system("cls");
			pass[*i]=0;
			
			for(int j=0; j<Nusers; j++)
			{
				if((strcmp(usr,USERS[j].username)==0)&&(strcmp(pass,USERS[j].password)==0)){ *k=1; LOGIN=j; STAT[j].Nr_login++; }	
			}
			if(*k==0) 
			{
				*eror+=1;
				
				system("cls");
				system("color c");
				cout<<"\n\n\n\n\t["<<*eror<<"]Wrong password or username"<<endl;
				system("pause");
				*i=0;
				
				if(*eror%3==0)
				{
					*timer+=10;
					
					for(int t=*timer; t>0; t--)
					{   
					    system("cls");
					    system("color c");
						if(t<10)cout<<"\n\n\n\n\t["<<*eror<<"]You are on pending for 00:00:0"<<t;
						else cout<<"\n\n\n\n\t["<<*eror<<"]You are on pending for 00:00:"<<t;
						Sleep(100);
					}
				    
				}
				if(*eror>9){system("cls"); cout<<"\n\n\n\n\tYou are kicked out due too many errors!!!"<<endl; system("pause"); exit(0);}
				
					
				system("cls");
				system("color f");
				cout<<"\n\n\n\n\tEnter username: "; cin>>usr;
	            cout<<"\t["<<*eror<<"]Enter password: ";
	        }
			
		}
		else if(*KEY==8)
		{
			if(*i>0) { *i-=1; cout<<"\b \b"; } 
		}
		else if(*KEY==27) exit(0);
		else
		{
			if(*i<13)
			{
			    cout<<"*";
			    *i+=1;	
			}	
		}
		
		if(*k) break;
	}

    system("cls");
    if(USERS[LOGIN].status==0) { system("color c"); cout<<"\n\n\n\n\tYour account was deactivated!\n\tPlease contact your ADMIN :x:"<<endl; system("pause"); exit(0); } 
    else cout<<"\n\n\n\n\tWelcome "<<USERS[LOGIN].username<<" !"<<endl;
    system("pause");
    
    SAVEstruct(FILEstat,STAT,Nusers);
    delete i;
    delete k;
    delete pass;
    delete usr;
    delete eror;
    delete timer;
    delete KEY;
}

void config()
{
	FILE *fp;
	
	if((fp = fopen("config.ini","r+"))==NULL){system("cls"); cout<<"Error config.ini r+"<<endl; system("pause"); exit(0);}
    
	fscanf(fp,"%s%s%s",FILEuser,FILEstud,FILEstat);
	
	fclose(fp);
}

void insert_u()
{
	do
	{
		system("cls");
	
	    cout<<"\n\n\n\n\tInsert username: "; cin>>USERS[Nusers].username;
	    cout<<"\tInsert password: "; cin>>USERS[Nusers].password;
	    cout<<"\tInsert status 1-active / 0-inactive: "; cin>>USERS[Nusers].status;
	    cout<<"\tInsert type 1-ADMIN / 0-USER: "; cin>>USERS[Nusers].type;
	    Nusers++;
	    STAT[LOGIN].Nr_inserted_u++;
	    
	    system("cls"); 
		cout<<"\n\n\n\n\tPress any key to continue / ESC to exit::";
		
		SAVEstruct(FILEstat,STAT,Nusers);
		SAVEstruct(FILEuser,USERS,Nusers);
		
	}while(_getch()!=27);
}

void insert_s()
{
    do
	{   
	    system("cls");
    	cout<<"\n\n\n\n\tInsert First name: "; cin>>STUD[Nstud].Fname;
		cout<<"\tInsert Last name: "; cin>>STUD[Nstud].Lname;
		cout<<"\tInsert age: "; cin>>STUD[Nstud].age;
	    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
		
		char *integer = new char[100];
	    cout<<"\tEnter IDNP: "; 
	    
		  int *i = new int;  *i=0;
		int *KEY = new int;
	     bool *k = new bool; *k=0;
	     
		while(1)
		{
		   *KEY = _getch();
		   integer[*i] = (char)*KEY;
		   
		   if(*KEY==13) 
		   {
		   	    integer[*i]=0;
		   	    if(*i==13) *k=1;
		   	    else
				{
				    cout<<"\t-->IDNP should be exactly 13 digits!"<<endl;
					
					cout<<"\tEnter IDNP: "; *KEY =_getch();
					*i=0;
				}
				
		   }
		   if(*KEY==8)  { if(*i>0) { *i-=1; cout<<"\b \b"; } }
		   else         { if(*i<13) { cout<<(char)*KEY; *i+=1; } }
		   if(*k) break;	
	    }
	    
	    *i=0;
	    while(*i<13)
	    {
		    STUD[Nstud].IDNP[*i] = integer[*i] - 48;
		    *i+=1;
	    }
	    
	    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
		cout<<"\n\tInsert group: "; cin>>STUD[Nstud].group;
		strcpy(STUD[Nstud].inserted_by,USERS[LOGIN].username);
		cout<<"\tInsert status 0-inactive / 1-active: "; cin>>STUD[Nstud].status;
		
		////////////
		
		E:
		*KEY=rand()%100;
		*k=0;
		for(int i=0; i<Nstud; i++)
		{
			if(*KEY==STUD[i].ID) {*k=0; goto E;}
			else *k=1;
		}
		if(*k) STUD[Nstud].ID = *KEY; 
		
		///////////
		
		Nstud++;
		STAT[LOGIN].Nr_inserted_s++;
		delete i; delete k; delete KEY; delete integer; 
		system("cls"); 
		cout<<"\n\n\n\n\tPress any key to continue / ESC to exit::";
		
		SAVEstruct(FILEstat,STAT,Nusers);
		SAVEstruct(FILEstud,STUD,Nstud);
	}while(_getch()!=27); 
}

void show_u()
{
	system("cls");
    if(Nusers==NULL){cout<<"\n\n\n\n\tNo data!"<<endl; system("pause"); return;}
    
	cout<<"\n\n\n\n";
	
	    for(int i=1; i<Nusers; i++)
	    {
		    if(USERS[i].type==1) cout<<"\t["<<i<<"] Username: *"<<USERS[i].username<<"\n\t    Status: ";
		    else cout<<"\t["<<i<<"] Username: "<<USERS[i].username<<"\n\t    Status: ";
			if(USERS[i].status==1)cout<<"   Active\n"<<endl;
			else cout<<"   Inactive\n"<<endl;
	    }
	 system("pause");	
}

void show_s()
{
	system("cls");
	
	if(Nstud==NULL){cout<<"\n\n\n\n\tNo data!"<<endl; system("pause"); return;}
 
	    students *S = new students[Nstud];
	    int *NS = new int; *NS=0;
	    
	    if(y==1)
	    {
	    	cout<<"\n\n\n\n\n\t1.Active"<<endl;
            cout<<"\t2.Inactive"<<endl;
            cout<<"\t3.All"<<endl;
			y=_getch(); y-=48;
		}
	    else y=1;
        
	    switch(y)
	    {
	    	case 1 :  for(int i=0; i<Nstud; i++) { if(STUD[i].status==1){S[*NS] = STUD[i]; *NS+=1;} }break;
	    	case 2 :  for(int i=0; i<Nstud; i++) { if(STUD[i].status==0){S[*NS] = STUD[i]; *NS+=1;} }break;
	    	case 3 :  y=3; *NS=Nstud; break;
	    	default : return;
		}
    
    system("cls");
	cout<<"\n\n\n\n";
    
    int *pp = new int; *pp=4;
    int *in = new int; *in=0;
	int *sf = new int; *sf=*pp;
    int *page = new int; *page=1;
    
    while(1)
    {
    	if(*pp>=*NS) { *in=0; *sf=*NS; }
    	system("cls");
    	
    	for(int i=0; i<88; i++)
		{
			if(i==0)cout<<(char)201;
			else if(i==87) cout<<(char)187;
			else if(i==4 || i==8 || i==19 || i==35 || i==40 || i==55 || i==69 || i==77) cout<<(char)209;
			else cout<<(char)205;
			
		}
    	cout<<endl;
    	
	    cout<<(char)186<<setw(3)<<"   "<<(char)179<<setw(3)<<"ID"<<(char)179<<setw(10)<<"First_name"<<(char)179<<setw(15)<<"Last_Name"<<(char)179<<setw(4)<<"Age"<<(char)179<<setw(14)<<"IDNP"<<(char)179<<setw(13)<<"Inserted by"<<(char)179<<setw(7)<<"Group"<<(char)179<<setw(9)<<"Status"<<(char)186<<endl;
    	for(int i=0; i<88; i++)
		{
			if(i==0)cout<<(char)199;
			else if(i==87) cout<<(char)182;
			else if(i==4 || i==8 || i==19 || i==35 || i==40 || i==55 || i==69 || i==77) cout<<(char)197;
			else cout<<(char)196;
		}   
		cout<<endl;
		
			for(int i=*in; i<*sf; i++)
	        {
	        	/////////////////////////////////////////******************************* show all active students
	        	if(y==1)
	        	{
	        	    cout<<(char)186<<setw(3)<<i<<(char)179<<setw(3)<<S[i].ID<<(char)179<<setw(10)<<S[i].Fname<<(char)179<<setw(15)<<S[i].Lname<<(char)179<<setw(4)<<S[i].age;
			        cout<<(char)179<<" ";
			        int *j = new int; *j=0;
			        while(*j<13)
			        {
				        cout<<S[i].IDNP[*j];
				        *j+=1;
			        }
			        delete j;
			
			        cout<<(char)179<<setw(13)<<S[i].inserted_by<<(char)179<<setw(7)<<S[i].group<<(char)179<<setw(9)<<"Active"<<(char)186<<endl;
		        
		        
		            for(int i=0; i<88; i++)
		            {
			            if(i==0)cout<<(char)199;
			            else if(i==87) cout<<(char)182;
			            else if(i==4 || i==8 || i==19 || i==35 || i==40 || i==55 || i==69 || i==77) cout<<(char)197;
			            else cout<<(char)196;
		            }   
		            cout<<endl;	
				}
	        	
	    	    /////////////////////////////////////////******************************* show all inactive students
	    	    else if(y==2)
	    	    {
	    	        cout<<(char)186<<setw(3)<<i<<(char)179<<setw(3)<<S[i].ID<<(char)179<<setw(10)<<S[i].Fname<<(char)179<<setw(15)<<S[i].Lname<<(char)179<<setw(4)<<S[i].age;
			        cout<<(char)179<<" ";
			        int *j = new int; *j=0;
			        while(*j<13)
			        {
				        cout<<S[i].IDNP[*j];
				        *j+=1;
			        }
			        delete j;
			
			        cout<<(char)179<<setw(13)<<S[i].inserted_by<<(char)179<<setw(7)<<S[i].group<<(char)179<<setw(9)<<"Inactive"<<(char)186<<endl;
		        
		        
		            for(int i=0; i<88; i++)
		            {
			            if(i==0)cout<<(char)199;
			            else if(i==87) cout<<(char)182;
			            else if(i==4 || i==8 || i==19 || i==35 || i==40 || i==55 || i==69 || i==77) cout<<(char)197;
			            else cout<<(char)196;
		            }   
		            cout<<endl;
				}
		        
		        else if(y==3) /////////////////////////////////////////******************************* show all students
		        
		        {
		        	cout<<(char)186<<setw(3)<<i<<(char)179<<setw(3)<<STUD[i].ID<<(char)179<<setw(10)<<STUD[i].Fname<<(char)179<<setw(15)<<STUD[i].Lname<<(char)179<<setw(4)<<STUD[i].age;
			    cout<<(char)179<<" ";
			    int *j = new int; *j=0;
			    while(*j<13)
			    {
				    cout<<STUD[i].IDNP[*j];
				    *j+=1;
			    }
			    delete j;
			
			    cout<<(char)179<<setw(13)<<STUD[i].inserted_by<<(char)179<<setw(7)<<STUD[i].group;
                if(STUD[i].status==0) cout<<(char)179<<setw(9)<<"Inactive"<<(char)186<<endl;
		        else cout<<(char)179<<setw(9)<<"Active"<<(char)186<<endl;
		        
		        
		        for(int i=0; i<88; i++)
		        {
			        if(i==0)cout<<(char)199;
			        else if(i==87) cout<<(char)182;
			        else if(i==4 || i==8 || i==19 || i==35 || i==40 || i==55 || i==69 || i==77) cout<<(char)197;
			        else cout<<(char)196;
		        }   
		        cout<<endl;
				}
		        
	        }
	        
	        for(int i=0; i<88; i++)
	        {
			    if(i==0)cout<<(char)200;
			    else if(i==87) cout<<(char)188;
			    else if(i==4 || i==8 || i==19 || i==35 || i==40 || i==55 || i==69 || i==77) cout<<(char)207;
			    else cout<<(char)205;
		    }
    	    cout<<endl;
	        
	    cout<<"Page ["<<*page<<"] out of ["<<*NS/ *pp+1<<"]  Press + / - to navigate"<<endl;
	
	    switch(_getch())
	    {
	    	case 43 : /*+*/ if(*sf>=*NS)
			                { 
			                    if(*sf=*NS) { *in=*in; *sf=*NS; }
			                   	else { *in=*pp; *sf=*NS; }
			                }
			                else 
							{
							    *in+=*pp; *sf+=*pp; *page+=1;
								if(*sf>*NS) { *in=*in; *sf=*NS; }
							} break;
			                
	    	case 45 : /*-*/ if(*sf>=*NS)
			                     {
			                     	if(*pp>=*NS && *in==0){ *in=0; *sf=*NS; }
								    else { *in-=*pp; *sf=*in+*pp; *page-=1; }
								 }
			                else { 
							        if(*in!=0)*page-=1;
			                        if(*in==0){ *in=0; *sf=*pp;} 
							        else {*in-=*pp; *sf-=*pp;}
								 } break;
	    	
	    	case 27 :  return; break;
		}
	}
       delete in;
       delete sf;
       delete pp;
       delete page;
       delete []S;
       delete NS;
       
	 system("pause");
}

void edit_u()
{
	system("cls");
	int *y = new int;
	int *o = new int;
	char *pass = new char[256];
	int *timer = new int; *timer=0;
	int *eror = new int; *eror=0;
	
	cout<<"\n\n\n\n\tEnter user's ID: "; cin>>*y;
	
	system("cls");
	if(*y<=0 || *y>Nusers-1) { system("cls"); cout<<"\n\n\n\n\tNo data!"<<endl; system("pause"); return;}
	
		cout<<"\n\n\n\n\t["<<*y<<"]Username: "<<USERS[*y].username<<endl;
		cout<<"\tDo you want to edit this user? y/n"; *o=_getch();
		
		if(*o!=121) return;
		
		system("cls");
		cout<<"\n\n\n\n\t["<<*y<<"]Username: "<<USERS[*y].username<<endl;
		switch(x)
	    {
		    case 1 : cout<<"\tCurrent username: "<<USERS[*y].username<<"\n\tEnter new username: "; cin>>USERS[*y].username; break;
		    case 2 : cout<<"\tEnter password: "; cin>>pass;
					 while(1)
		             {	
		             	if(strcmp(pass,USERS[*y].password)==0) { system("cls");    cout<<"\n\n\n\n\tEnter new password: "; cin>>USERS[*y].password; break; } 
					  	else
					  	{
					 	    *eror+=1;
				
			  	         	system("cls"); system("color c");
				         	cout<<"\n\n\n\n\t["<<*eror<<"]Wrong password"<<endl;
				         	system("pause");
				
				         	if(*eror%3==0)
				         	{
					         	*timer+=10;
					
					         	for(int t=*timer; t>0; t--)
					         	{   
					             	system("cls"); system("color c");
						         	if(t<10)cout<<"\n\n\n\n\t["<<*eror<<"]You are on pending for 00:00:0"<<t;
						         	else cout<<"\n\n\n\n\t["<<*eror<<"]You are on pending for 00:00:"<<t;
						         	Sleep(100);
					         	}
				         	}
				         	if(*eror>9){system("cls"); USERS[*y].status=0; cout<<"\n\n\n\n\t"<<USERS[*y].username<<"'s account has been deactivated due too many errors\n\tPlease contact your ADMIN!!!"<<endl; system("pause"); system("color f"); SAVEstruct(FILEuser,USERS,Nusers); return;}
				         	
				         	system("cls"); system("color f");
				         	cout<<"\n\n\n\n\n\t["<<*eror<<"]Enter password:"; cin>>pass;
					  	}
					 } break;
					 
		    case 3 : cout<<"\tCurrent status: "<<USERS[*y].status<<"\n\tEnter new status 0-Inactiv / 1-Activ: "; cin>>USERS[*y].status; break;
		    case 4 : cout<<"\tCurrent type: "<<USERS[*y].type<<"\n\tEnter new type 0-USER / 1-ADMIN: "; cin>>USERS[*y].type; break;
	    }
    
    SAVEstruct(FILEuser,USERS,Nusers);
	delete y; delete o;
	delete eror; delete timer;
}

void edit_s()
{
	system("cls");
	int *w = new int;
	int *o = new int;
	
	cout<<"\n\n\n\n\tEnter user's ID: "; cin>>*w;
	
	system("cls");
	bool *k = new bool; *k=1;
	for(int i=0; i<Nstud; i++) { if(*w==STUD[i].ID){*k=0; *w=i;} }
	if(*k) { system("cls"); cout<<"\n\n\n\n\tNo data!"<<endl; system("pause"); delete k; return;}
	delete k;

	if(x==0 && STUD[*w].status==0)
	{ 
	    system("cls");
	    cout<<"\n\n\n\n\n\tNo data!"<<endl;
		system("pause"); return; 
	}

	system("cls");
	cout<<"\n\n\n\n\tFull name: "<<STUD[*w].Fname<<" "<<STUD[*w].Lname<<endl;
	cout<<"\tDo you want to edit this student? y/n"; *o=_getch();
	if(*o!=121) return;
	
	system("cls");
	     if(y==1) { cout<<"\n\n\n\n\tFull name: "<<STUD[*w].Fname<<" "<<STUD[*w].Lname<<endl; cout<<"\tEnter new First Name: "; cin>>STUD[*w].Fname; }
	else if(y==2) { cout<<"\n\n\n\n\tFull name: "<<STUD[*w].Fname<<" "<<STUD[*w].Lname<<endl; cout<<"\tEnter new Last Name:"; cin>>STUD[*w].Lname; }
	else if(y==3) { cout<<"\n\n\n\n\tFull name: "<<STUD[*w].Fname<<" "<<STUD[*w].Lname<<"\n\tCurrent age: "<<STUD[*w].age<<endl; cout<<"\tEnter new Age: "; cin>>STUD[*w].age; }
	else if(y==4)
    {
    	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		char *integer = new char[100];
	    cout<<"\n\n\n\n\tFull name: "<<STUD[*w].Fname<<" "<<STUD[*w].Lname<<"\n\tCurrent IDNP: "; for(int i=0; i<13; i++) cout<<STUD[*w].IDNP[i];
		cout<<"\n\tEnter new IDNP: ";  
	    
		  int *i = new int;  *i=0;
		int *KEY = new int;
	     bool *k = new bool; *k=0;
	     
		while(1)
		{
		   *KEY = _getch();
		   integer[*i] = (char)*KEY;
		   
		   if(*KEY==13) 
		   {
		   	    integer[*i]=0;
		   	    if(*i==13) *k=1;
		   	    else
				{
				    cout<<"\t-->IDNP should be exactly 13 digits!"<<endl;
					
					cout<<"\tEnter IDNP: "; *KEY =_getch();
					*i=0;
				}
				
		   }
		   if(*KEY==8)  { if(*i>0) { *i-=1; cout<<"\b \b"; } }
		   else         { if(*i<13) { cout<<(char)*KEY; *i+=1; } }
		   if(*k) break;	
	    }
	    
	    *i=0;
	    while(*i<13)
	    {
		    STUD[*w].IDNP[*i] = integer[*i] - 48;
		    *i+=1;
	    }
	    delete integer;
	    delete i;
	    delete KEY;
	    delete k;
	    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	}
	else if(y==5) { cout<<"\n\n\n\n\tFull name: "<<STUD[*w].Fname<<" "<<STUD[*w].Lname<<"\n\tCurrent Group: "<<STUD[*w].group<<endl; cout<<"\tEnter new Group: "; cin>>STUD[*w].group; }
	else if(y==6) 
	{ 
	    cout<<"\n\n\n\n\tFull name: "<<STUD[*w].Fname<<" "<<STUD[*w].Lname<<"\n\tCurrent Status: ";
	        if(STUD[*w].status==0) cout<<"Inactive"<<endl;
		    else cout<<"Active"<<endl;
		cout<<"\tEnter new Status 0-inactive / 1-active: "; cin>>STUD[*w].status; 
	}
	STAT[LOGIN].Nr_edited_s++;
	
	SAVEstruct(FILEstud,STUD,Nstud);
	SAVEstruct(FILEstat,STAT,Nusers);
	delete w;
	delete o;
}

void find_u()
{
	system("cls");
	int *y = new int;
	cout<<"\n\n\n\n\tEnter user's ID: "; cin>>*y;
	
	if(*y<=0 || *y>Nusers-1) { system("cls"); cout<<"\n\n\n\n\tNo data!"<<endl; system("pause"); return ; }
	else{system("cls"); cout<<"\n\n\n\n\t["<<*y<<"]Username: "<<USERS[*y].username<<endl; system("pause");}
	
	delete y;
}

void find_s()
{
	system("cls");
	
	char *name = new char[100];
	bool *k    = new bool; *k=1;
	
	if(y==1)
	{
	    cout<<"\n\n\n\n\tEnter First name: "; cin>>name;
		system("cls");
		cout<<"\n\n\n\n\t";
		
		if(x==0) // user access
		{
			for(int j=0; j<Nstud; j++)
			{
				if(STUD[j].status==1)
				{
					if(strcmp(name,STUD[j].Fname)==0)
		            {
		                cout<<"\n\t["<<STUD[j].ID<<"] First name: "<<STUD[j].Fname;
		                *k=0;
			        }
				}
			}
		}
		else // ADMIN access
	    {
	    	for(int j=0; j<Nstud; j++)
	    	{
	    		if(strcmp(name,STUD[j].Fname)==0)
		        {
		           cout<<"\n\t["<<STUD[j].ID<<"] First name: "<<STUD[j].Fname;
		           *k=0;
			    }
			}
		}
		
	    if(*k)cout<<"\n\n\n\n\tNo data!"<<endl; 
	    else cout<<endl;
		system("pause"); 	
	}
	
	else if(y==2) /// USER access
	{   
	    cout<<"\n\n\n\n\tEnter Last name: "; cin>>name;
		system("cls");
		cout<<"\n\n\n\n\t";
		
		if(x==0)
		{
			for(int j=0; j<Nstud; j++)
			{
				if(STUD[j].status==1)
				{
					if(strcmp(name,STUD[j].Lname)==0)
		            {
		                cout<<"\n\t["<<STUD[j].ID<<"] Last name: "<<STUD[j].Lname;
		                *k=0;
			        }
				}
			}
		}
		else /// ADMIN access
		{
		    for(int j=0; j<Nstud; j++)
			{
				if(strcmp(name,STUD[j].Lname)==0)
		        {
		            cout<<"\n\t["<<STUD[j].ID<<"] Last name: "<<STUD[j].Lname;
		            *k=0;
			    }
			}	
		}

		if(*k)cout<<"\n\n\n\n\tNo data!"<<endl; 
		else cout<<endl;
		system("pause");		
	}

	else if(y==3) 
	{
	    int  *KEY  = new int;
	    int  *v    = new int[100];
	    int  *q    = new int;	
		int  *i    = new int;  *i=0;	
		cout<<"\n\n\n\n\tEnter IDNP: ";
	    *k=0;
		         
	    while(1)
		{
		    *KEY = _getch();
		    name[*i] = (char)*KEY;
		   
		    if(*KEY==13) 
		    {
		   	    name[*i]=0;
		   	    if(*i==13) *k=1;
		   	    else
				{
				    cout<<"\t-->IDNP should be exactly 13 digits!"<<endl;
					cout<<"\tEnter IDNP: "; *KEY =_getch();
				    *i=0;
				}
		    }
		    if(*KEY==8)  { if(*i>0) { *i-=1; cout<<"\b \b"; } }
		    else         { if(*i<13) { cout<<(char)*KEY; *i+=1; } }
		    if(*k) break;	
	    }
	    delete KEY;
	             
	    *i=0;
	    while(*i<13)
	    {
		    v[*i] = name[*i] - 48;
		    *i+=1;
	    }
	    
	    *k=0; 
	             
	    for(int j=0; j<Nstud; j++)
	    {	      
	        for(int o=0; o<13; o++)
	        {
				if(v[o]!=STUD[j].IDNP[o]){break;} 
	            else { if(o==12){*k=1; *q=j;}}
			}
		} 
		
		if(x==0) /// USER access
		{
			if(*k && STUD[*q].status==1) { system("cls"); cout<<"\n\n\n\n\t["<<STUD[*q].ID<<"]Full name: "<<STUD[*q].Fname<<" "<<STUD[*q].Lname<<endl; system("pause"); }
			else { system("cls"); cout<<"\n\n\n\n\tNo data!"<<endl; system("pause"); }
		}
		else /// ADMIN access
		{
			if(*k) { system("cls"); cout<<"\n\n\n\n\t["<<STUD[*q].ID<<"]Full name: "<<STUD[*q].Fname<<" "<<STUD[*q].Lname<<endl; system("pause"); }
			else { system("cls"); cout<<"\n\n\n\n\tNo data!"<<endl; system("pause"); }
		}
		
		delete k;
	    delete i;
	    delete v;
	    delete q;
	}
		
	else if(y==4)
	{
		cout<<"\n\n\n\n\tEnter Group: "; cin>>name;
		system("cls");
		
		cout<<"\n\n\n\n\tStudent[s] from group: "<<name<<endl;
		
		if(x==0) /// USER access
		{
			for(int i=0; i<Nstud; i++)
		    {
		    	if(strcmp(name,STUD[i].group)==0 && STUD[i].status==1) 
			    {
			        cout<<"\t["<<STUD[i].ID<<"]First name: "<<STUD[i].Fname<<" "<<STUD[i].Lname<<endl;
		        }
			}
		}
		else  /// ADMIN access
		{
			for(int i=0; i<Nstud; i++)
		    {
		    	if(strcmp(name,STUD[i].group)==0) 
			    {
			        cout<<"\t["<<STUD[i].ID<<"]First name: "<<STUD[i].Fname<<" "<<STUD[i].Lname<<endl;
		        }
			}
		}
		
	    system("pause");
	}
	delete name;
}

void DEL_u()
{
	system("cls");
	int *y = new int;
	cout<<"\n\n\n\n\tEnter user's ID: "; cin>>*y;
	
	if(*y<=0 || *y>Nusers-1) { system("cls"); cout<<"\n\n\n\n\tNo data!"<<endl; system("pause"); return ; }
	else
	{
	    system("cls"); 
		cout<<"\n\n\n\n\t["<<*y<<"]Username: "<<USERS[*y].username<<endl; 
		cout<<"\tAre you sure you want to delete this user? y/n";
		switch(_getch())
		{
			case 'y' : for(int i=*y; i<=Nusers; i++)
			           {
			           	  USERS[i] = USERS[i+1];
					   }
					   Nusers--;
					   system("cls");
					   cout<<"\n\n\n\n\t";
    				   for(int i=0; i<10; i++) { Sleep(100); cout<<"*"; }
    				   system("cls"); cout<<"\n\n\n\n\tUser deleted!"<<endl; Sleep(1000); break;
			case 'n' : return;
		}
	}
	SAVEstruct(FILEuser,USERS,Nusers);
	delete y;
}

void DEL_s()
{
	system("cls");
	int *y = new int;
	cout<<"\n\n\n\n\tEnter student's' ID: "; cin>>*y;
	
	system("cls");
	bool *k = new bool; *k=1;
	for(int i=0; i<Nstud; i++) { if(*y==STUD[i].ID){*k=0; *y=i;} }
	if(*k) { system("cls"); cout<<"\n\n\n\n\tNo data!"<<endl; system("pause"); delete k; return;}
	delete k;
	
	    system("cls"); 
		cout<<"\n\n\n\n\t["<<STUD[*y].ID<<"]Full Name: "<<STUD[*y].Fname<<" "<<STUD[*y].Lname<<endl; 
		cout<<"\tAre you sure you want to delete this student? y/n";
		switch(_getch())
		{
			case 'y' : STAT[LOGIN].Nr_delete_s++; 
			        
			           for(int i=*y; i<=Nstud; i++)
			           {
			           	  STUD[i] = STUD[i+1];
					   }
					   Nstud--;
	
					   system("cls");
					   cout<<"\n\n\n\n\t";
    				   for(int i=0; i<10; i++) { Sleep(100); cout<<"*"; }
    				   system("cls"); cout<<"\n\n\n\n\tStudent deleted!"<<endl; Sleep(1000); break;
			case 'n' : return;
		}
	SAVEstruct(FILEstud,STUD,Nstud);
	SAVEstruct(FILEstat,STAT,Nusers);
	delete y;
}



















