struct users
{
	char username[256];
	char password[256];
	bool status;
	bool type;
	
}USERS[100];
int Nusers=0;

struct students
{
	char Fname[256];
	char Lname[256];
	int age;
	int IDNP[20];
	char group[50];
	char inserted_by[256];
	bool status;
	int ID;
	
}STUD[100];
int Nstud=0;

struct statistics
{
	int Nr_login=0;
	int Nr_inserted_u=0;
	int Nr_inserted_s=0;
	int Nr_edited_s=0;
	int Nr_delete_s=0;
	
}STAT[100];

int level=1,LOGIN;

int sys,x,y,z,q;
char FILEuser[256],FILEstud[256],FILEstat[256];

























