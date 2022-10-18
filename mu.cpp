int meniuU4()
{
	system("cls");
	    cout<<"\n\n\n\n\tUSER MENIU / Raport"<<endl;
		cout<<"\tChoose a filter:"<<endl;
		cout<<"\t1.List of students by age"<<endl;
		cout<<"\t2.List of students by groups"<<endl;
		cout<<"\t3.List of all students"<<endl;
		cout<<"\tESC <-Go back"<<endl;
		switch(_getch())
	    {
		    case 49 : y=1; return 11; break;
		    case 50 : y=2; return 11; break;
		    case 51 : y=3; return 11; break;
		
		    case 27 : level=1; break;
	    }
	return 0;
}

int meniuU3()
{
	system("cls");
	cout<<"\n\n\n\n\tMENIU USER / Edit student"<<endl;
	cout<<"\tEdit:"<<endl;
	cout<<"\t1.First Name"<<endl;
	cout<<"\t2.Last Name"<<endl;
	cout<<"\t3.Age"<<endl;
	cout<<"\t4.IDNP"<<endl;
	cout<<"\t5.Group"<<endl;
	cout<<"\t6.Status"<<endl;
	cout<<"\tESC <-Go back"<<endl;
	
	switch(_getch())
	{
		case 49 : y=1; return 9; break;
		case 50 : y=2; return 9; break;
		case 51 : y=3; return 9; break;
		case 52 : y=4; return 9; break;
		case 53 : y=5; return 9; break;
		case 54 : y=6; return 9; break;
		
		case 27 : level=1; break;
	}
	return 0;
}

int meniuU2()
{
	system("cls");
	cout<<"\n\n\n\n\tMENIU USER / Find student"<<endl;
	cout<<"\tSearch by:"<<endl;
	cout<<"\t1.First Name"<<endl;
	cout<<"\t2.Last Name"<<endl;
	cout<<"\t3.IDNP"<<endl;
	cout<<"\t4.Group"<<endl;
	cout<<"\tESC <-Go back"<<endl;
	
	switch(_getch())
	{
		case 49 : y=1; return 8; break;
		case 50 : y=2; return 8; break;
		case 51 : y=3; return 8; break;
		case 52 : y=4; return 8; break;
		
		case 27 : level=1; break;
	}
	return 0;
}

int meniuU1()
{
	system("cls");
	
	cout<<"\n\n\n\n\tMENIU USER"<<endl;
	cout<<"\t1.Show students"<<endl;
	cout<<"\t2.Find student"<<endl;
	cout<<"\t3.Edit student"<<endl;
	cout<<"\t4.Raport"<<endl;
	cout<<"\tESC"<<endl;
	
	switch(_getch())
	{
		case 49 : y=2;      return 7; break;
		case 50 : x=0;      level =2; break;
		case 51 : x=0;      level =3; break;
		case 52 : x=0; q=1; level =4; break;
		
		case 27 : return 27;
	}
}

int USERmanagement()
{
	system("cls");
    
    switch(level)
    {
    	case 1 : return meniuU1(); break;
    	case 2 : return meniuU2(); break;
    	case 3 : return meniuU3(); break;
    	case 4 : return meniuU4(); break;
	}

return 0;
}




















