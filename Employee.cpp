#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
struct emp
{
	string name,id,address;
	int slaray,contact;
};
emp e[100];
int total=0;
void empdata()
{
	int choice;
	cout<<"How Many Data You Want To Store:";
	cin>>choice;
	for(int i=total;i<total+choice;i++)
	{
		cout<<"Enter Data Of Employee"<<i+1<<endl;
		cout<<"Enter Employee Name:";
		cin>>e[i].name;
		cout<<"Enter Id:";
		cin>>e[i].id;
		cout<<"Enter Address:";
		cin>>e[i].address;
		cout<<"Enter Contact Number:";
		cin>>e[i].contact;
		cout<<"Enter Salary:";
		cin>>e[i].slaray;
	}
	total=total+choice;
}
void showdata()
{
	int i;
	if(total!=0)
	{
	for(i=0;i<total;i++)
	{
	cout<<"Data Of Employee:-"<<i+1<<endl;
	cout<<"Emplyee Name:-"<<e[i].name<<endl;
	cout<<"Employee id:-"<<e[i].id<<endl;
	cout<<"Emplyee Address:-"<<e[i].address<<endl;
	cout<<"Employee Contact:-"<<e[i].contact<<endl;
	cout<<"Employee Salary:-"<<e[i].slaray<<endl;
    }
    }
    else
    {
    	cout<<"Recod Not found";
	}
}
void search()
{
	if(total!=0)
	{
	string id;
	cout<<"Enter Id You Want To search:";
	cin>>id;
		for(int i=0;i<total;i++)
		{
			if(id==e[i].id)
			{
				cout<<"Data Of Employee:-"<<i+1<<endl;
             	cout<<"Emplyee Name:-"<<e[i].name<<endl;
            	cout<<"Employee id:-"<<e[i].id<<endl;
	            cout<<"Emplyee Address:-"<<e[i].address<<endl;
            	cout<<"Employee Contact:-"<<e[i].contact<<endl;
             	cout<<"Employee Salary:-"<<e[i].slaray<<endl;
             	break;
			}
			if(i==total-1)
	     	{
			cout<<"No Recod Found";
	     	}
		}
	}
	else
	{
		cout<<"Recode is Empathy";
	}
}
void update()
{
	if(total!=0)
	{
		string id;
		cout<<"Enter Id You Want To update:";
		cin>>id;
		for(int i=0;i<total;i++)
		{
			if(id==e[i].id)
			{
				cout<<"Previous Data"<<endl;
				 cout<<"Data Of Employee:-"<<i+1<<endl;
             	cout<<"Emplyee Name:-"<<e[i].name<<endl;
            	cout<<"Employee id:-"<<e[i].id<<endl;
	            cout<<"Emplyee Address:-"<<e[i].address<<endl;
            	cout<<"Employee Contact:-"<<e[i].contact<<endl;
             	cout<<"Employee Salary:-"<<e[i].slaray<<endl;
             	cout<<"Enter New Data"<<endl;
             	cout<<"Enter Employee Name:";
		        cin>>e[i].name;
		        cout<<"Enter Id:";
		        cin>>e[i].id;
	        	cout<<"Enter Address:";
	        	cin>>e[i].address;
	        	cout<<"Enter Contact Number:";
	        	cin>>e[i].contact;
	           	cout<<"Enter Salary:";
	         	cin>>e[i].slaray;
	         	break;
			}
			if(i==total-1)
			{
			   cout<<"No Recod Found";
			}
		}
	}
	else
	{
		cout<<"Recod Is empty";
	}
}
void del()
{
	if(total!=0)
	{
		char user;
		cout<<"1]Delet Full data recode"<<endl;
		cout<<"2]Delet Specific Data Recod"<<endl;
		user=getch();
		if(user=='1')
		{
			total=0;
			cout<<"Delet All Recod";
		}
		else if(user=='2')
		{
			string id;
			cout<<"Enter Id You Want To Delet:-";
			cin>>id;
			for(int i=0;i<total;i++)
			{
				if(id==e[i].id)
				{
					for(int j=i;j<total;j++)
					{
						e[j].name=e[j+1].name;
						e[j].id=e[j+1].id;
						e[j].address=e[j+1].address;
						e[j].contact=e[j+1].contact;
						e[j].slaray=e[j+1].slaray;
						total--;
						cout<<"your Recuired data is delete";
						break;
					}
				}
					if(i==total-1)
					{
						cout<<"No Recod Found"<<endl;
					}
			}
			
		}
	}
	else
	{
		cout<<"Empty Recod";
	}
}
int main()
{
	string username,password;
	cout<<"\n\n\n\t\tEmployee Management System";
	cout<<"\n\t\t\tSing up\n";
	cout<<"\t\tEnter UserName: ";
	cin>>username;
	cout<<"\t\tEnter Password: ";
	cin>>password;
	cout<<"Please Wait Your Account Is Creating";
	for(int i=0;i<=2;i++)
	{
		cout<<".";
		Sleep(1000);
	}
	cout<<"\nYour Account Created Succesfully";
	cout<<"\n\n\n\t\tEmployee Management System";
	start:
	cout<<"\n\t\tLog In\n";
	string username1,password1;
	cout<<"\t\tUser Name: ";
	cin>>username1;
	cout<<"\t\tPassword: ";
	cin>>password1;
	if(username1==username && password1==password)
	{
		int ch;
		do
		{
			cout<<"press 1 To Enter Data"<<endl;
			cout<<"press 2 To show Data"<<endl;
			cout<<"press 3 To Search Data"<<endl;
			cout<<"Press 4 To Update Data"<<endl;
			cout<<"Press 5 To Delet Data"<<endl;
			cout<<"Press 6 To Log out"<<endl;
			cout<<"Press 7 To Exit"<<endl;
			cout<<"Enter Your Choice:-";
			cin>>ch;
			switch(ch)
			{
				case 1:
					empdata();
					break;
					case 2:
					showdata();
					break;
					case 3:
					search();
					break;
					case 4:
					update();	
					break;
					case 5:
					del();
					break;
					case 6:
						goto start;
						break;
						case 7:
							cout<<"Good Bye...."<<endl;
							break;
							default:
								cout<<"\aWrong Option";
					
			}
        }while(ch!=7);
        
	}
	else if(username1!=username)
	{
		cout<<"\n\tIncorrect username"<<endl;
		Sleep(3000);
		goto start;
	}
	else if(password1!=password)
	{
		cout<<"\n\tIncorrect Password"<<endl;
		Sleep(3000);
		goto start;
	}

}
