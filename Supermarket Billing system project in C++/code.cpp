#include<iostream>
#include<fstream>
using namespace std;
class shopping
{
	private:
		int pcode;
		float price;
		float dis;
		string pname;
	public:
		void menu();
		void administrator();
		void buyer();
		void add();
		void rem();
		void edit();
		void list();
		void receipt();
	
};

void shopping :: menu()
{
	int choice;
	string email,password;
	m:
	
	cout<<"\t\t\t\t____________________________________\n";
	cout<<"\t\t\t\t                                    \n";
	cout<<"\t\t\t\t     Supermarket Main Menu          \n";
	cout<<"\t\t\t\t                                    \n";
	cout<<"\t\t\t\t____________________________________\n";
	cout<<"\t\t\t\t                                    \n";
	cout<<"\t\t\t\t|  1) Administrator      |\n";
	cout<<"\t\t\t\t|                        |\n";
	cout<<"\t\t\t\t|  2) Buyer              |\n";
	cout<<"\t\t\t\t|                        |\n";
	cout<<"\t\t\t\t|  3) Exit               |\n";
	cout<<"\t\t\t\t|                        |\n";
	cout<<"\t\t\t\t Please select:";
	cin>>choice;
	
	switch(choice)
	{
	    case 1:
	    {
	        cout<<"\t\t\t Please Login \n";
	        cout<<"\t\t\t Enter email   \n";
	        cin>>email;
	        cout<<"\t\t\t Password        \n";
	        cin>>password;
	        
	        if(email=="angalkunal1@gmail.com" && password=="kunal")
	        {
	            administrator();
	        }
	        else
	        {
	            cout<<"Invalid email/password";
	        }
	        break;
	    }
	    
	    case 2:
	    {
	        buyer();
	    }
	    
	    case 3:
	    {
	        exit(0);
	    }
	    
	    default:
	    {
	        cout<<"Please select form the given options";
	    }
	}
goto m;	
}

void shopping :: administrator()
{
    int choice;
    m:
    cout<<"\n\n\n\t\t\t Admininistrator menu";
    cout<<"\n\t\t\t|_____1) Add the product_________|";
    cout<<"\n\t\t\t|                                |";
    cout<<"\n\t\t\t|_____2) Modify the product______|";
    cout<<"\n\t\t\t|                                |";
    cout<<"\n\t\t\t|_____3) Delete the product______|";
    cout<<"\n\t\t\t|                                |";
    cout<<"\n\t\t\t|_____4) Back to main menu_______|";
    
    cout<<"\n\n\t please enter your choice ";
    cin>>choice;
    
    switch(choice)
    {
        case 1:
        add();
        break;
        
        case 2:
        edit();
        break;
        
        case 3:
        rem();
        break;
        
        case 4:
        menu();
        break;
        
        default:
        cout<<"Invalid choice:";
    }
    goto m;
}

void shopping :: buyer()
{
    int choice;
    m:
    cout<<"\t\t\t  Buyer  \n";
    cout<<"\t\t\t________________\n";
    cout<<"                      \n";
    cout<<"\t\t\t 1) Buy Product \n";
    cout<<"                      \n";
    cout<<"\t\t\t 2) Go back     \n";
    cout<<"\t\t\t Enter your choice : ";
    cin>>choice;
    
    switch(choice)
    {
        case 1: receipt();
        break;
        case 2: menu();
        break;
        default: cout<<"Invalid choice";
    }
    goto m;
}

void shopping :: add()
{
    fstream data;
    int c,token=0;
    float p,d;
    string n;
    cout<<"\n\n\t\t\t Add new product";
    cout<<"\n\n\t Product code of the product";
    cin>>pcode;
    cout<<"\n\n\t Name of the product";
    cin>>pname;
    cout<<"\n\n\t Price of the product";
    cin>>price;
    cout<<"\n\n\t Discount on the product";
    cin>>dis;
    
    data.open("database.txt",ios::in);        //**********************//
    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;
        
        while(!data.eof())
        {
            if(c == pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
        
        if(token == 1)
        {
        m:
        goto m;
    	}
        else
        {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
        }
    }
    cout<<"\n\n\t\t Record Inserted !";
}

void shopping :: edit()
{
    fstream data,data1;
    int pkey,token=0,c;
    float p,d;
    string n;
    
    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Product code: ";
    cin>>pkey;
    
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n File doesn't exist ! ";
    }
    else
    {
        data1.open("database.txt",ios::app |ios::out);
        
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey == pcode)
            {
                cout<<"\n\t\t Product new code: ";
                cin>>c;
                cout<<"\n\t\t Name of the product: ";
                cin>>n;
                cout<<"\n\t\t Price: ";
                cin>>p;
                cout<<"\n\t\t Discount: ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited ";
                token++;
            }
            else 
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        
        remove("database.txt");
        rename("database.txt","database.txt");
        
        if(token==0)
        {
            cout<<"\n\n Record not found sorry!";
        }
    }
}

void shopping :: rem()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t  Delete product";
    cout<<"\n\n\t  Product code :";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"File doesn't exist";
    }
    else
    {
        data1.open("database.txt",ios::app|ios::out);				//*********************//	
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\n\t Product deleted successfully";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database.txt","database.txt");
        
        if(token==0)
        {
            cout<<"\n\n Record not found";
        }
    }
}

void shopping :: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|________________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n|________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}

void shopping :: receipt()
{
    fstream data;
    int arrc[100];
    int arrq[100];
    string choice;
    int c=0;
    float amount=0,dis=0,total=0;
    cout<<"\n\n\t\t\t\t Receipt";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty database";
    }
    else
    {
    	
        data.close();
        list();
        cout<<"\n__________________________________\n";
        cout<<"\n|                                 \n";
        cout<<"\n       Please Place the order     \n";
        cout<<"\n|                                 \n";
        cout<<"\n__________________________________\n";
        do
        {
            cout<<"\n\n Enter Product code";
            cin>>arrc[c];
            cout<<"\n\n Enter the product quantity :";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
            	if(arrc[c]==arrc[i])
            	{
            	m:
                cout<<"\n\n Duplicate product code. Please try again!";
                goto m;
            	}
            }
        c++;
        cout<<"\n\n Do you want to buy another product? if yes then press y else no";
        cin>>choice;
    }
	while(choice == "y");
    cout<<"\n\n\t\t\t________________Receipt______________\n";
    cout<<"\nProduct No\t Product Name\t Product quantity\tprice\tAmount\tAmount with discount\n";
    for(int i=0;i<=c;i++)
    {
        data.open("database.txt",ios::in);									//***************************************//
        data>>pcode>>pname>>price>>dis;
        while(!data.eof());
        {
            if(pcode==arrc[i])
            {
                amount=price*arrq[i];
                dis=amount-(amount*dis/100);
                total=total+dis;
                cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
            }
            data>>pcode>>pname>>price>>dis;
        }
    }
        data.close();
    cout<<"\n\n________________________________";
    cout<<"\nTotal amount:"<<total;
}
}

int main()
{
    shopping s;
    s.menu();
}
