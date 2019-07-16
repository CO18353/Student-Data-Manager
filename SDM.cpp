#include<fstream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include<iostream>
#include<string>
using namespace std;
string p="admin";
int check(int);
void save_id();
//void show_all_ids();
void display_id(int);
void edit_id();
void delete_id();
void arrange_ids();

class stu_data
{
    char name[20],add[30],email[20];
	int roll_number;
	long ph;
	public:
 
	long getPhone()
	{
		return ph;
	}
	int getRoll()
	{
		return roll_number;
	}	
	char* getName()
	{
		return name;
	}
	char* getAddress()
	{
		return add;
	}
	char* getEmail()
	{
		return email;
	}
	void show_id();
	void create_id();
	void edited_id();
	void operator=(stu_data&);
}; 
	void stu_data::operator=(stu_data &stu) // Overloading = OPERATOR FOR EASY SWAPPING
	{
		strcpy(name,stu.name);
		strcpy(add,stu.add);
		strcpy(email,stu.email);
		roll_number=stu.roll_number;
		ph=stu.ph;
	}

	void stu_data:: edited_id()		// FOR EDITING PARTICULAR FIELDS
	{
			cout<<"Name: ";
			cin.ignore();
            cin.getline(name,20);

			cout<<"Phone Number: ";
			cin>>ph;
				
			cout<<"Address: ";
			cin.ignore();
            cin.getline(add,30);

            cout<<"Email address: ";
            cin>>email;
            cout<<"\n";
	}
	
	void stu_data:: create_id()		// FOR CREATING NEW RECORD
	{
            cout<<"Roll Number: ";
            cin>>roll_number;

    		if(check(roll_number))		//CHECKS FOR UNIQUE ROLL NUMMBER
			{
				cout<<"Roll Number "<<roll_number<<" already exists";
				exit(0);
			}
			cout<<"Name: ";
			cin.ignore();
            cin.getline(name,20);

			cout<<"Phone Number: ";
			cin>>ph;
				
			cout<<"Address: ";
			cin.ignore();
            cin.getline(add,30);

            cout<<"Email address: ";
            cin>>email;
            cout<<"\n";
	}
	
	void stu_data:: show_id()	//FOR DISPLAYING THE RECORD
	{
		cout<<endl<<"Roll Number: "<<roll_number;
		cout<<endl<<"Name: "<<name;
		cout<<endl<<"Phone #: "<<ph;
		cout<<endl<<"Address: "<<add;
		cout<<endl<<"Email Address : "<<email;
	}

fstream fp;
stu_data stu1;

/*int pass()
{
	char c[20]={0},t;
	cout<<"Enter password"<<endl;
	int i=0;
	while(1)
	{
		t=getch();
		if((t>='a'&&t<='z')||(t>='A'&&t<='Z')||(t>='0'&&t<='9')||t==36||t==64||t==32)
		{
			c[i]=t;
			putch('*');
			i++;
		}
		else if(t=='\b'&&i>0)
		{
			cout<<"\b \b";
			i--;
			continue;
		}
		else if(t=='\r')
		{
			c[i]='\0';
			break;
		}
	}
	cout<<"\t\t\t\t"<<endl;
	char *p="admin";
	if(strcmp(p,c)==0)
	return 1;
	else
	return 0;
}*/
int pass()
{
	string pass ="";
	char ch;
	cout<<"Enter password"<<endl;
	int i=0;
	while(1)
	{
		ch=getch();
		if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')||ch==36||ch==64||ch==32)
		{
			pass.push_back(ch);
			putch('*');
			i++;
		}
		else if(ch=='\b'&&i>0)
		{
			cout<<"\b \b";
			i--;
			pass.pop_back(); 
			continue;
		}
		else if(ch=='\r')
		{
			break;
		}
	}
	if(p.compare(pass)==0)
	return 1;
	else
	return 0;
}
void change_pass()
{	
	string pass="";
	char ch;
	cout<<"Enter the current password: ";
	int i=0;
	while(1)
	{
		ch=getch();
		if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')||ch==36||ch==64||ch==32)
		{
			pass.push_back(ch);
			putch('*');
			i++;
		}
		else if(ch=='\b'&&i>0)
		{
			cout<<"\b \b";
			i--;
			pass.pop_back(); 
			continue;
		}
		else if(ch=='\r')
		{
			break;
		}
	}
	if(p.compare(pass)==0)
	{
		cout<<endl<<"Enter the new password: ";
 		string pass="";
		int i=0;
		while(1)
		{
			ch=getch();
			if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')||ch==36||ch==64||ch==32)
			{
				pass.push_back(ch);
				putch('*');
				i++;
			}
			else if(ch=='\b'&&i>0)
			{
				cout<<"\b \b";
				i--;
				pass.pop_back(); 
				continue;
			}
			else if(ch=='\r')
			{
				break;
			}
		}		
		p=pass;
	}
	else
	cout<<"Ki karda peyan ? ";
}

int check(int rollnumb)		//CHECKS FOR THE UNIQUE ROLL NUMBER
{
	stu_data stu2;
	int c=0;
	ifstream fp("DataBook.dat",ios::in);
	while(fp.read((char*)&stu2,sizeof(stu_data)))
	{
		if(rollnumb==stu2.getRoll())
		c++;
	}
	fp.close();
	return c;
}
 
void save_id()		//FOR WRITNING A NEW RECORD TO THE DATABOOK
{
	system("cls");
	cout<<"-->New ID\n===============================\n\n\t-->Enter the details of the student:";
	fp.open("DataBook.dat",ios::out|ios::app);
	stu1.create_id();
	fp.write((char*)&stu1,sizeof(stu_data));
	fp.close();
	cout<<endl<<endl<<"Id Closed";
	getchar();
}
 
/*void show_all_ids()
{
	system("cls");
	cout<<"\n\t\t================================\n\t\t\tID's\n\t\t================================\n";
	fp.open("DataBook.dat",ios::in);
	while(fp.read((char*)&stu1,sizeof(stu_data)))
	{
		stu1.show_id();
		cout<<endl<<"=================================================\n"<<endl;
	}
	fp.close();
}*/
 
void display_id(int num)		// FOR DISPLAYING A PARTICULAR ID
{
	bool found;
	int ch;
 
		 found=false;
	fp.open("DataBook.dat",ios::in);
	while(fp.read((char*)&stu1,sizeof(stu_data)))
	{
		if(stu1.getRoll()==num)
		{
			system("cls");
			stu1.show_id();
			found=true;
		}
	}
	
	fp.close();
	if(found == false){
	cout<<"\n\nNo record found...";}    
	getchar();
}
 
 
void edit_id()		// FOR EDITING EXISTING RECORD
{
	int num;
	bool found=false;
	system("cls");
	cout<<"-->Edit the ID\n===============================\n\n\t-->Enter the roll number of student to edit: \n"<<endl;
    cin>>num;
	
	fp.open("DataBook.dat",ios::in|ios::out);
	while(fp.read((char*)&stu1,sizeof(stu_data)) && found==false)
	{
		if(stu1.getRoll()==num)
		{
			stu1.show_id();
            cout<<endl<<"\nPlease Enter The New Details of Student: "<<endl;
			stu1.edited_id();
			int pos=-1*sizeof(stu1);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&stu1,sizeof(stu1));
			cout<<endl<<endl<<"\t ID Successfully Updated...";
			found=true;
		}
	}
	fp.close();
	if(found==false)
		cout<<endl<<endl<<"ID Not Found...";
}
 
void delete_id()	// FOR DELETING A PARTICULAR RECORD
{
	int num;
	system("cls");
	cout<<"-->Delete the ID\n===============================\n\n\t-->Enter the roll number of student whose ID is to be deleted:";
	cin>>num;
	fp.open("DataBook.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&stu1,sizeof(stu_data)))
	{
		if(stu1.getRoll()!=num)
		{
			fp2.write((char*)&stu1,sizeof(stu_data));
		}
	}
	fp2.close();
	fp.close();
	remove("DataBook.dat");
	rename("Temp.dat","DataBook.dat");
	cout<<endl<<endl<<"\tID Deleted...";
}
 
void arrange_ids()		// FOR ARRANGING RECORD ACCORDING TO ROLL NUMBER SEQUENCE and DISPLAYING ALL RECORDS
{
	ifstream fin;
	fin.open("DataBook.dat");
	fin.seekg(0,ios::end);
	const int n=fin.tellg()/sizeof(stu_data);
	fin.seekg(0,ios::beg);
	stu_data stu[n];
	for(int i=0;i<n;i++)
	{
		fin.read((char*)&stu[i],sizeof(stu_data));
	}
	fin.close();
	stu_data temp;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(stu[j].getRoll()<stu[i].getRoll())
			{
				temp=stu[i];
				stu[i]=stu[j];
				stu[j]=temp;
			}
		}
	}
	ofstream fout;
	fout.open("tempe.dat");
	for(int i=0;i<n;i++)
	{
		fout.write((char*)&stu[i],sizeof(stu_data));
	}
	fout.close();
	remove("DataBook.dat");
	rename("Tempe.dat","DataBook.dat");
	for(int i=0;i<n;i++)
	{
		stu[i].show_id();
		cout<<endl<<"=================================================\n"<<endl;
	}
}



int main(int argc, char *argv[])
{
	system("cls");
	system("color 30");
	
    for(;;)
    {
		int ch;
    	cout<<"\n\t **** Student Database Management System ****";
   		cout<<"\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new ID\n\t\t[2] List all ID's\n\t\t[3] Search for an ID\n\t\t[4] Edit an ID\n\t\t[5] Delete an Id\n\t\t[6] Change Password\n\t\t[0] Exit\n\t\t=================\n\t\t";
    	cout<<"Enter the choice:";
 
    	cin>>ch;
 
    	switch(ch)
    	{
    		case 0: cout<<"\n\n\t\tThe databse has been closed.";
    				exit(0);
    				break;
    		case 1: if(pass()==1)
					{
						cout<<"\t\t\t\tWelcome"<<endl;
						save_id();
						break;
					}
					else
					{
						cout<<"\t\t\t\tWrong Password";
						break;
					}
    		case 2: arrange_ids();
					break;
   			case 3:	int num;
            		system("cls");
            		cout<<"\n\n\tRoll Number: ";
            		cin>>num;
					display_id(num);
    				break;
    		case 4: if(pass()==1)
					{
						cout<<"\t\t\t\tWelcome"<<endl;
						edit_id();
						break;
					}
					else
					{
						cout<<"\t\t\t\tWrong Password";
						break;
					}
    		case 5: if(pass()==1)
					{
						cout<<"\t\t\t\tWelcome"<<endl;
						delete_id();
						break;
					}
					else
					{
						cout<<"\t\t\t\tWrong Password";
						break;
					}
			case 6:change_pass();
					break;
    		default:cout<<"Wrong button pressed!";
    	}
		
		int opt;
   		cout<<"\n\n\n-->Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n";
 		cin>>opt;
		switch (opt)
		{
 			case 1:
				system("cls");
        		continue;
 
    		case 0:
 	       		exit(0);
			default:
				cout<<"Wrong button pressed!";
		}
	}
	return 0;
}
