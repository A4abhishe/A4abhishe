#include<iostream>
using namespace std;
class bank
{
	private:
		int accid;
		string name;
		float balance;
		static long bankbalance;
		static int count;
		public:
			void openAccount()
			{
				cout<<"Enter Account number:";
				cin>>accid;
				cin.ignore();
				cout<<"Enter Holder name:";
				getline(cin, name);
				cout<<"Enter Account Balance:";
				cin>>balance;
				bankbalance+=balance;
				count+=1;
			}
			void showAccount()
			{
				cout<<"Account number:"<<accid<<endl;
				cout<<"Account holder name:"<<name<<endl;
				cout<<"Account balance:"<<balance<<endl;
			}
			void deposit()
			{
				int amt;
				cout<<"Enter Amount you want to deposit:";
				cin>>amt;
				balance=balance+amt;
			}
			void withdarawal()
			{
				int amt;
				cout<<"Enter Amount you want to withdarwal:";
				cin>>amt;
				if(balance>=amt)
				{
					balance=balance+amt;
				}
				else
				{
					cout<<"Insfficiant fund";
				}
			}
			static void showbankbalance()
			{
				cout<<"bank balance:="<<bankbalance<<endl;
				cout<<"total custumer:"<<count<<endl;
			}
			int search(int);
};
long bank::bankbalance;
int bank::count;
int bank::search(int id)
{
	if(accid==id)
	{
		return(1);
	}
	return(0);
}
int main()
{
	bank pnb[3];
	int i;
	for(i=0;i<=2;i++)
	{
		pnb[i].openAccount();
	}
	bank::showbankbalance();
	int found=0,id,ch;
	do
	{
		cout<<"Main menu"<<endl;
		cout<<"1]display All Account"<<endl;
		cout<<"2]search account by Id"<<endl;
		cout<<"3]diposit"<<endl;
		cout<<"4]withdarwal"<<endl;
		cout<<"5]exit"<<endl;
		cout<<"Enter Your Choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				for(i=0;i<=2;i++)
				{
					pnb[i].showAccount();
				}
				break;
				case 2:
					cout<<"Enter Account Number You Want To Search:";
					cin>>id;
					for(i=0;i<=2;i++)
					{
						found=pnb[i].search(id);
						if(found)
						{
							pnb[i].showAccount();
							break;
						}
					}
					if(!found)
					{
						cout<<"No Account Found";
					}
					break;
					case 3:
						cout<<"Enter Account Number you Want to deposit:";
						cin>>id;
						for(i=0;i<=2;i++)
						{
							found=pnb[i].search(id);
							if(found)
							{
								pnb[i].showAccount();
								pnb[i].deposit();
								pnb[i].showAccount();
								break;
							}
						}
						if(!found)
						{
							cout<<"No Account found";
						}
						break;
						case 4:
							cout<<"Enter Account Number You Want to Withdrawal:";
							cin>>id;
							for(i=0;i<=2;i++)
							{
								found=pnb[i].search(id);
								if(found)
								{
									pnb[i].showAccount();
									pnb[i].withdarawal();
									pnb[i].showAccount();
									break;
								}
							}
							if(!found)
							{
								cout<<"No Account found";
							}
							break;
							case 5:
								cout<<"good bye"<<endl;
								break;
								default:
									cout<<"Wrong option";
		}
	}while(ch!=5);
}
