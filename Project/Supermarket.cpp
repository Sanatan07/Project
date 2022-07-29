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
        void edit(); 
        void rem();
        void list();
        void receipt();
};

void shopping :: menu()
{
    m:
    int choice;
    string email;
    string password;

    cout<<"\t Supermarket Main Menu \t"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<" 1) Administrator"<<endl;
    cout<<" 2) Buyer"<<endl;
    cout<<" 3) Exit"<<endl;
    cout<<"Select a option";
    cin>>choice;

    switch(choice)
    {
        case 1:
        cout<<"Please login"<<endl;
        cout<<"Enter Email  " ;
        cin>>email;
        cout<<"Enter Password  ";
        cin>>password;
        cout<<endl;
        cout<<endl;

        if(email == "robby@gmail.com" && password == "robby@123")
        {
            administrator();
        }
        else{
            cout<<"Invalid LoginId and Password";
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
            cout<<"Select from the given option";
        }
    } 
    goto m;  
}



void shopping::administrator()
{
    m:
    int choice;
    cout<<" Administrator menu "<<endl;
    cout<<" 1) Add the product "<<endl;
    cout<<" 2) Modify the product "<<endl;
    cout<<" 3) Delete the product "<<endl;
    cout<<" 4) Back to Main Menu "<<endl;
    cout<<" Enter your choice "<<endl;
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
        cout<<"Invalid choice!";
    }
    goto m;

}

void shopping :: buyer()
{
    m:
    int choice;
    cout<<" Buyer "<<endl;
    cout<<" 1) Buy product "<<endl;
    cout<<" 2) Go Back "<<endl;
    cout<<" Enter choice "<<endl;
    cin>>choice;

    switch(choice)
    {
        case 1:
        receipt();
        break;

        case 2:
        menu();

        default:
        cout<<"Invalid Choice";
    }   
    goto m;

}

void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout<<"Add new product "<<endl;
    cout<<"Product code of the product : ";
    cin>>pcode;
    cout<<"Name of the product "<<endl;
    cin>>pname; 
    cout<<"Price of the product : ";
    cin>>price;
    cout<<"Discount on product : ";
    cin>>dis;

    data.open("database.txt",ios::in);
    
    if(!data)
    {
        data.open("database.txt",ios::app |ios::out);
        data<<" "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<endl;
        data.close();

    }
    else
    {
        data>>c>>n>>p>>d;

        while(!data.eof())
        {
            if(c==pcode)
            {
                token++;
            }
            data<<c<<n<<p<<d;
        }
        data.close();
    }

    if (token==1)
    {
        goto m;
    }
    else
    {
        data.open("database.txt",ios::app | ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
        data.close();
    }
    cout<<"Record Inserted! "<<endl;
}

void shopping::edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;
    
    cout<<"Modify the record"<<endl;
    cout<<"Product code : ";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
       cout<<"File doesn't exist! ";
    }
    else
    {
       data1.open("database1.txt",ios::app | ios::out);
       data>>pcode>>pname>>price>>dis;
       while(!data.eof())
       {
           if (pkey==pcode)
           {
               cout<<"Product new code :   ";
               cin>>c;
               cout<<endl;
               cout<<"Name of the product : ";
               cin>>n;
               cout<<endl;
               cout<<"Price : ";
               cin>>p;
               cout<<endl;
               data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<endl;
               cout<<"Record Edited ";
               token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;

            }
            data>>pcode>>pname>>price>>dis;

        }
        data.close() ;
        data1.close();

        remove("database.txt");
        remove("database1.txt");

        if (token==0)
        {
            cout<<"Record not found "<<endl;

        }

    }
}
void shopping ::rem()
{
    fstream data, data1;
    int pkey;
    int token=0;
    cout<<"Delete Product"<<endl;
    cout<<"Product code"<<endl;
    cin>>pkey;
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"File doesn't exist ";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"Product deleted sucessfully ";
                token++;

            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<endl;
                
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        remove("database1.txt");

        if(token==0)
        {
            cout<<"Record not found"<<endl;
        }
    }

}

void shopping::list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"ProNo\tName\tPrice"<<endl;
    cout<<endl;
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<"\t"<<pname<<"\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;

    }
    data.close();
}

void shopping::receipt()
{   
    m:
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;
    
    cout<<"RECEIPT"<<endl;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"Empty Database"<<endl;
    }
    else
    {
        data.close();
        list();
        cout<<"Please place the order"<<endl;
        do
        {
            cout<<"Enter product code";
            cin>>arrc[c];
            cout<<"Enter the product quantity";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"Duplicate product code. Try again!"<<endl;
                    goto m;   
                }
            }
            c++;
            cout<<"Do you want to buy another product? If Yes press y or press n for No"<<endl;
            cin>>choice;
        } 
        while (choice =='y');
        {
            cout<<"_____RECEIPT_____"<<endl;
            cout<<"\nProduct No \t Product Name \t Product Quantity \t price \t Amount with discount "<<endl;
            for (int i=0;i<c;i++)
            {
                data.open("database.txt");
                data>>pcode>>pname>>price>>dis;
                while(!data.eof())
                {
                    if(pcode==arrc[i])
                    {
                        amount = price*arrq[i];
                        dis=amount-(amount*dis/100);
                        total=total+dis;
                        cout<<"\n"<<pcode<<"\t"<<pname<<"\t"<<arrq[i]<<"\t"<<price<<"\t"<<amount<<"\t"<<dis;
                    }
                    data>>pcode>>pname>>price>>dis; 

                }

            }
            data.close();



        }
        cout<<"Total Amount : "<<total<<endl;
        
    }

}

int main()
{
    shopping s;
    s.menu();
}

