//Grocery Store and E-Billing
//***************************************************************
// HEADER FILE USED IN PROJECT
//****************************************************************
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<fstream>
#include<iomanip>
#include<iostream>
using namespace std;
class grocery_store
{
	int ino;
	char iname[50];
	float price,qty,tax,dis;
	public:
	int create_item()
	{
		cin.ignore();
		cout<<"\nPlease Enter the Item Code :";
		cin>>ino;
		cout<<"\nPlease Enter the Name of the Item :";
		cin>>iname;
		cout<<"\nPlease Enter the Price of the Item :";
		cin>>price;
		cout<<"\nPlease Enter the Discount (%) :";
		cin>>dis;
		return 0;
	}

	int display_item()
	{
		cout<<"\nThe Item Code : "<<ino;
		cout<<"\nThe Name of The Item : "<<iname;
		cout<<"\nThe Price of The Item : "<<price;
		cout<<"\nDiscount (%) : "<<dis;
		return 0;
	}
		int retino()
		{
			return ino;
		}
		float retprice()
		{
			return price;
		}
		char* retiname()
		{
			return  iname;
		}
		int retdis()
		{
			return dis;
		}
}i;
//******************************************************************************
//GLOBAL DECLARATION OF STREAM OBJECT, CLASS OBJECT
//******************************************************************************
fstream fio;
ifstream fin;
ofstream fout;
int constant()
{
	cout<<"\n===============================================================================";
	cout<<"\n==========================GROCERY STORE AND E-BILLING==========================";
	cout<<"\n===============================================================================";
	return 0;
}
//******************************************************************************
// FUNCTION TO WRITE IN THE FILE
//******************************************************************************
int write_item()
{
	fio.open("store",ios::in|ios::out|ios::app);
	i.create_item();
	fio.write((char*)&i,sizeof(grocery_store));
	fio.close();
	cin.ignore();
	cout<<"\n\nThe Item Has Been Created ";
	return 0;
}
//******************************************************************************
// FUNCTION TO DISPLAY ALL ITEM RECORD IN THE FILE 
//******************************************************************************
int display_all()
{
	system("cls");
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	fio.open("store",ios::in|ios::out);
	while(fio.read((char*)&i,sizeof(grocery_store)))
	{
		i.display_item();
		cout<<"\n\n====================================\n";
		cin.ignore();
	}
	fio.close();
	return 0;
}
//******************************************************************************
// FUNCTION TO DISPLAY SPECIFIC RECORD IN THE FILE
//******************************************************************************
int display_sp(int n)
{
	int flag=0;
	system("cls");
	cout<<"\n\n====================================\n";
	cin.ignore();
	fio.open("store",ios::in|ios::out);
	while(fio.read((char*)&i,sizeof(grocery_store)))
	{
		if(i.retino()==n)
		{
			i.display_item();
			flag=1;
		}
	}
	fio.close();
	if(flag==0)
	cout<<"\n\n Record not exist";
	return 0;
}
//**********************************************************************************
// FUNCTION TO MODIFY RECORD SPECIFIED BY ADMINISTRATOR
//**********************************************************************************
int modify_item()
{
	int no,found=0;
	system("cls");
	cout<<"\n\n\tTo Modify ";
	cout<<"\n\n\tPlease Enter The Item Code to be Modified :";
	cin>>no;
	fio.open("store",ios::in|ios::out);
	while(fio.read((char*)&i,sizeof(grocery_store)))
	{
		if(i.retino()==no)
		{
			i.display_item();
			cout<<"\nPlease Enter The New Details of Item"<<endl;
			i.create_item();
			int pos=-1*sizeof(i);
			fio.seekp(pos,ios::cur);
			fio.write((char*)&i,sizeof(grocery_store));
			cin.ignore();
			cout<<"\n\n\t Record Updated";
			cin.ignore();
			found=1;
		}
	}
	fio.close();
	if(found==0)
	cout<<"\n\n Record Not Found ";
	return 0;
}
//**********************************************************************************
// FUNCTION TO DELETE RECORD SPECIFIED BY ADMINISTRATOR
//**********************************************************************************
int delete_item()
{
	system("cls");
	int no;
	cout<<"\n\n\tItem Deletion";
	cout<<"\n\nEnter Item code of Item to be Deleted :";
	cin>>no;
	display_sp(no);
	cout<<"\n\nThe above Item will be Deleted";
	fio.open("store",ios::in|ios::out);
	fstream fio2;
	fio2.open("temp",ios::binary|ios::out);
	fio.seekg(0,ios::beg);
	while(fio.read((char*)&i,sizeof(i)))
	{
		if(i.retino()!=no)
		{
			fio2.write((char*)&i,sizeof(i));
		}
	}
	fio2.close();
	fio.close();
	remove("store");
	rename("temp","store");
	cin.ignore();
	cout<<"\n\nItem Is deleted!!!";
	cin.ignore();
	return 0;
}
//******************************************************************************
// FUNCTION TO DISPLAY ITEM MENU FOR THE CUSTOMER
//******************************************************************************
int menu()
{
	system("cls");
	fio.open("store",ios::in|ios::out|ios::app);
	if(!fio)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Admin Menu to create Menu";
		cout<<"\n\n\n Program is closing ....";
		exit(0);
	}
	cout<<"\n\t\tITEM MENU\n";
	cout<<"===============================================\n";
	cout<<"INO.\t\tNAME\t\tPRICE\n";
	cout<<"===============================================\n";
	while(fio.read((char*)&i,sizeof(grocery_store)))
	{
		cout<<i.retino()<<"\t\t"<<i.retiname()<<"\t\t"<<i.retprice()<<endl;
	}
	fio.close();
	return 0;
}
//******************************************************************************
// FUNCTION FOR PLACING ORDER BY THE CUSTOMER
//******************************************************************************
int place_order()
{   
	system("cls");
	int order_arr[50],quan[50],c=0,rtotal=0;
	float amt,damt,total=0,tax=0,gtotal=0;
	char ch='Y';
	placeorder:
	menu();
	cout<<"===============================================\n";
	cout<<" PLACE YOUR ORDER";
	cout<<"\n===============================================\n";
	cout<<"\nEnter The Item Code of The Item : ";
	cin>>order_arr[c];
	cout<<"Quantity in Number : ";
	cin>>quan[c];
	c++;
	cout<<"\nDo You Want To Order Another Item ?(Y/N) :";
	cin>>ch;
	if(ch=='Y'||ch=='y')
	{
		system("cls");
		goto placeorder;
	}
	else
	cout<<"\n**Thank You For Placing The Order**";
	system("cls");
	cout<<"\n\t\t\t\tINVOICE\n";
	cout<<"============================================================================";
	cout<<"\n Ino \tItem \tQuantity \tPrice \tAmount \tAmount After Discount\n";
	cout<<"============================================================================";
	for(int x=0;x<=c;x++)
	{
		fio.open("store",ios::in|ios::out);
		fio.read((char*)&i,sizeof(grocery_store));
		while(!fio.eof())
		{
			if(i.retino()==order_arr[x])
			{
				amt=i.retprice()*quan[x];
				damt=amt-(amt*i.retdis()/100);
				cout<<"\n "<<order_arr[x]<<"\t"<<i.retiname()<<"\t"<<quan[x]<<"\t\t"<<i.retprice()<<"\t"<<amt<<"\t\t"<<damt;
				total+=damt;
			}
			fio.read((char*)&i,sizeof(grocery_store));
		}
		fio.close();
	}
	cout<<"\n============================================================================";
	cin.ignore();
	tax=0.09*total;
	gtotal=(2*tax)+total;
	rtotal=gtotal;
	float round=gtotal-rtotal;
	cout<<"\n\n\t\t\tTake out Total       =\t\t"<<total;
	cout<<"\n\t\t\tSGST @9.00%          =\t\t "<<tax;
	cout<<"\n\t\t\tCGST @9.00%          =\t\t "<<tax;
	cout<<"\n\t\t\tTotal (incl.taxes)   =\t\t"<<gtotal;
	cout<<"\n\t\t\tRounding Off         =\t\t  "<<setprecision(2)<<round;
	cout<<"\n\n\t\t\tTotal Due            = \t\t"<<rtotal;
	cout<<"\n\n\n\t\t\t**THANK YOU FOR VISITING US**";
	cout<<"\n\n\t\t\t**PLEASE COME AGAIN**";
	cin.ignore();
	return 0;
}
//******************************************************************************
// FUNCTION TO DISPLAY ADMIN MENU FOR ADMINISTRATOR 
//******************************************************************************
int admin_menu()
{
	system("cls");
	char ch2;
	constant();
	cout<<"\n\n\n\tADMIN MENU";
	cout<<"\n\n\t1.CREATE ITEM";
	cout<<"\n\n\t2.DISPLAY ALL PRODUCTS";
	cout<<"\n\n\t3.QUERY(SEARCH BY ITEM CODE) ";
	cout<<"\n\n\t4.MODIFY ITEM";
	cout<<"\n\n\t5.DELETE ITEM";
	cout<<"\n\n\t6.VIEW ITEM MENU";
	cout<<"\n\n\t7.LOGOUT AND BACK TO MAIN MENU";
	cout<<"\n\n\t8.LOGOUT AND EXIT";
	cout<<"\n\n\tPlease Enter Your Choice (1-7) :";
	cin>>ch2;

	switch(ch2)
	{
		case '1':
			 system("cls");
			 write_item();
			 admin_menu();
			 break;
		case '2':
			 display_all();
			 cin.ignore();
			 admin_menu();
			 break;
		case '3':
			 int num;
			 system("cls");
			 cout<<"\n\n\tPlease Enter The Item Code :";
			 cin>>num;
			 display_sp(num);
			 cout<<"\n\n====================================";
			 cin.ignore();
			 admin_menu();
			 break;
		case '4':
			 modify_item();
			 admin_menu();
			 break;
		case '5':
			 delete_item();
			 admin_menu();
			 break;
		case '6':
			 menu();
			 cout<<"\n\nBack To Admin Menu?(Y/N) :";
			 cin>>ch2;
			 if(ch2=='y'||ch2=='Y')
			 {
				admin_menu();
			 }
			 break;
		case '7':
			 break;
		case '8':
			 cout<<"\n\n\t\tYOU HAVE BEEN SUCCESSFULLY LOGGED OUT AND SESSION HAS BEEN TERMINATED\n\n";
			 cout<<"\a";
			 exit(0);
			 break;
		default :
			 cout<<"\a";
			 admin_menu();
	}
	return 0;
}
//******************************************************************************
// MAIN FUNCTION OF THE PROGRAM
//******************************************************************************
int main()
{
	char ch;
	do
	{
		string user,pswrd; int check=1;
		again: 
		system("cls");
		constant();
		cout<<"\n\n\n\t\tMAIN MENU";
		cout<<"\n\n\t\t 01. CUSTOMER";
		cout<<"\n\n\t\t 02. ADMINISTRATOR";
		cout<<"\n\n\t\t 03. EXIT";
		cout<<"\n\n\t\tPlease Select Your Option (1-3) :";
		cin>>ch;
		switch(ch)
		{
			case '1':
				 system("cls");
				 place_order();
				 break;
			case '2':
				 cout<<"\n\n\t\tEnter Admin Username: ";
				 cin>>user;
				 if(user=="admin"||user=="User"||user=="USER"||user=="Admin"||user=="adnan"||user=="adnan@123")
				 {
			 		cout<<"\n\t\tEnter Password: ";
		 			cin>>pswrd;
	 				if(pswrd=="adnan123"||pswrd=="admin"||pswrd=="Admin"||pswrd=="ADMIN")
 					{ 
						check=0;
						cin.ignore();
						cout<<"\n\t\tLogging in...";
						cin.ignore();
					}
				 }
				 if(check==1)
    			 {
					cin.ignore();
				 	cout<<"\n\t\t============INVALID USERNAME OR PASSWORD============"<<endl;
				 	cout<<"\n\t\tSESSION HAS BEEN TERMINATED!!!PLEASE RETRY!!!\n"<<endl;
				 	cout<<"\a";
					cin.ignore();
					goto again;
				 }	
				 admin_menu();
				 break;
			case '3':
				 exit(0);
			default :cout<<"\a";
		}
	}while(ch!='3');
	return 0;
}
