
int meniuA7()
{
	system("cls");
	    cout<<"\n\n\n\n\tADMIN MENIU / Raport / Student raport"<<endl;
		cout<<"\tChoose a filter:"<<endl;
		cout<<"\t1.List of students by age"<<endl;
		cout<<"\t2.List of students by groups"<<endl;
		cout<<"\t3.List of all students"<<endl;
		cout<<"\tESC <-Go back"<<endl;
		switch(_getch())
	    {
		    case 49 : y=1; x=1; return 11; break;
		    case 50 : y=2; x=1; return 11; break;
		    case 51 : y=3; x=1; return 11; break;
		
		    case 27 : level=6; break;
	    }
	return 0;
}

int meniuA6()
{
	system("cls");
	cout<<"\n\n\n\n\tADMIN MENIU / Raport"<<endl;
	cout<<"\t1.Students raport"<<endl;
	cout<<"\t2.Statistics raport"<<endl;
	cout<<"\tESC <-Go back"<<endl;
	
	switch(_getch())
	{
		case 49 : q=1; level=7; break;
		case 50 : q=2; y=1; return 11; break;
		
		case 27 : level=1; break;
	}
	return 0;
}

int meniuA5()
{
	system("cls");
	cout<<"\n\n\n\n\tADMIN MENIU / Edit student"<<endl;
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

int meniuA4()
{
	system("cls");
	cout<<"\n\n\n\n\tADMIN MENIU / Find student"<<endl;
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

int meniuA3()
{
	system("cls");
	cout<<"\n\n\n\n\tADMIN MENIU / Management user / Edit user"<<endl;
	cout<<"\tEdit:"<<endl;
	cout<<"\t1.Name"<<endl;
	cout<<"\t2.Password"<<endl;
	cout<<"\t3.Status"<<endl;
	cout<<"\t4.Type"<<endl;
	cout<<"\tESC <-Go back"<<endl;
	
	switch(_getch())
	{
		case 49 : x=1; return 3; break;
		case 50 : x=2; return 3; break;
		case 51 : x=3; return 3; break;
		case 52 : x=4; return 3; break;
		
		case 27 : level=2; break;
	}
	return 0;
}

int meniuA2()
{
	system("cls");
	cout<<"\n\n\n\n\tADMIN MENIU / Management user"<<endl;
	cout<<"\t1.Insert user"<<endl;
	cout<<"\t2.Show user"<<endl;
	cout<<"\t3.Edit user"<<endl;
	cout<<"\t4.Find user"<<endl;
	cout<<"\t5.Delete user"<<endl;
	cout<<"\t6.Issue raport"<<endl;
	cout<<"\tESC <-Go back"<<endl;
	
	switch(_getch())
	{
		case 49 : return 1; break;
		case 50 : return 2; break;
		case 51 : level =3; break;
		case 52 : return 4; break;
		case 53 : return 5; break;
		case 54 : q=3; y=2; return 11; break;
		
		case 27 : level=1;  break;
	}
	return 0;
}

int meniuA1()
{
	system("cls");
	cout<<"\n\n\n\n\tADMIN MENIU"<<endl;
	cout<<"\t1.Management users"<<endl;
	cout<<"\t2.Insert student"<<endl;
	cout<<"\t3.Show students"<<endl;
	cout<<"\t4.Find student"<<endl;
	cout<<"\t5.Edit student"<<endl;
	cout<<"\t6.Delete student"<<endl;
	cout<<"\t7.Raport"<<endl;
	cout<<"\tESC."<<endl;
	
	switch(_getch())
	{
		case 49 : level=2;  break;
		case 50 : return 6; break;
		case 51 : y=1; return 7; break;
		case 52 : x=1; level=4;  break;
		case 53 : x=1; level=5;  break;
		case 54 : return 10; break;
		case 55 : level=6; break;
		
		case 27 : return 27;
	}
	
}

int ADMINmanagement()
{
	switch(level)
	{
		case 1 : return meniuA1(); break;
		case 2 : return meniuA2(); break; 
		case 3 : return meniuA3(); break;
		case 4 : return meniuA4(); break;
		case 5 : return meniuA5(); break;
		case 6 : return meniuA6(); break;
		case 7 : return meniuA7(); break;
	}
}


















