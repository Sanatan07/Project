#include <iostream>
using namespace std;

int main()
{
    int quantity;
    int choice;
//Quantity
    int Qrooms = 0 , Qpasta=0, Qburger=0, Qnoodles=0, Qshake=0, Qchicken=0;
//Sold Items 
    int Srooms=0, Spasta=0, Sburger=0, Snoodles=0, Sshake=0, Schicken=0;
//Total Price of items
    int Total_rooms=0, Total_pasta=0, Total_burger=0, Total_noodles=0, Total_shake=0, Total_chicken=0;

    cout<<"Quantity of items we offer."<<endl;
    cout<<"Rooms Available : ";
    cin>>Qrooms;
    cout<<"Quantity of pasta : ";
    cin>>Qpasta;
    cout<<"Quantity of Noodles : ";
    cin>>Qnoodles;
    cout<<"Quantity of Burger : ";
    cin>>Qburger;
    cout<<"Quantity of Shake : ";
    cin>>Qshake;
    cout<<"Quantity of Chicken-roll : ";
    cin>>Qchicken;

    menu:
    cout<<"PLease select form the menu option "<<endl<<endl;
    cout<<"1) Rooms"<<endl;
    cout<<"2) Pasta"<<endl;
    cout<<"3) Noodles"<<endl;
    cout<<"4) Burger"<<endl;
    cout<<"5) Shake"<<endl;
    cout<<"6) Chicken-Roll"<<endl;
    cout<<"7) Information regarding sales and collection"<<endl;
    cout<<"8) Exit"<<endl;

    cout<<"Enter your choice : ";
    cin>>choice;

    switch (choice)
    {
    case 1:
        cout<<"\n Enter the number of rooms you want." ;
        cin>>quantity;
        if(Qrooms-Srooms>=quantity)
        {
            Srooms=Srooms+quantity;
            Total_rooms = Total_rooms+quantity*1200;
            cout<<"\n\t\t"<<quantity<<"These number of rooms are alloted to you."<<endl;
        }
        else
        
            cout<<"Only "<<Qrooms-Srooms<<"rooms are available in the hotel";
            break;

            case 2:
        cout<<"\n Enter Pasta Quantity :" ;

        cin>>quantity;
        if(Qpasta-Spasta >=quantity)
        {
            Spasta=Spasta+quantity;
            Total_pasta = Total_pasta+quantity*180;
            cout<<"\n\t\t"<<quantity<<" Pasta is ordered."<<endl;
        }
        else
        
            cout<<"Only "<<Qpasta-Spasta<<" Pasta available in the hotel.";
            break;
        
        case 3:
        cout<<"\n Enter Burger Quantity :" ;

        cin>>quantity;
        if(Qburger - Sburger >= quantity)
        {
            Sburger = Sburger + quantity;
            Total_burger = Total_burger + quantity * 125;
            cout<<"\n\t\t"<<quantity<<" Burger is ordered."<<endl;
        }
        else
        
            cout<<"Only "<<Qburger-Sburger<<" Burger available in the hotel.";
            break;

        case 4:
        cout<<"\n Enter Noodles Quantity :" ;

        cin>>quantity;
        if(Qnoodles - Snoodles >= quantity)
        {
            Snoodles = Snoodles + quantity;
            Total_noodles = Total_noodles + quantity * 140;
            cout<<"\n\t\t"<<quantity<<" Nooldes is ordered."<<endl;
        }
        else
        
            cout<<"Only "<<Qnoodles - Snoodles<<" Noodles available in the hotel.";
            break;

        case 5:
        cout<<"\n Enter Shakes Quantity :" ;

        cin>>quantity;
        if(Qshake - Sshake >= quantity)
        {
            Sshake = Sshake + quantity;
            Total_shake = Total_shake + quantity * 100;
            cout<<"\n\t\t"<<quantity<<" Shake are ordered."<<endl;
        }
        else
        
            cout<<"Only "<<Qshake - Sshake<<" Shakes are available in the hotel.";
            break;

        case 6:
        cout<<"\n Enter Chicken-rolls Quantity :" ;

        cin>>quantity;
        if(Qchicken - Schicken >= quantity)
        {
            Schicken = Schicken + quantity;
            Total_chicken = Total_chicken + quantity * 90;
            cout<<"\n\t\t"<<quantity<<" Chicken Rolls are ordered."<<endl;
        }
        else
        
            cout<<"Only "<< Qchicken - Schicken <<" Chicken rolls are available in the hotel.";
            break;
            cout<<endl;


        case 7:

        cout<<"Details of sales and collection "<<endl;
        cout<<"Number of rooms we have "<<Qrooms<<endl;
        cout<<"Number of rooms we gave for rent"<<Srooms<<endl;
        cout<<"Remaining number of rooms"<<Qrooms-Srooms<<endl;
        cout<<"Total rooms collection for the day"<<Total_rooms<<endl;

        cout<<"Number of pasta we have "<<Qpasta<<endl;
        cout<<"Number of Pasta we gave for rent"<<Spasta<<endl;
        cout<<"Remaining number of pasta"<<Qpasta-Spasta<<endl;
        cout<<"Total pasta collection for the day"<<Total_pasta<<endl;

        cout<<"Number of burger we have "<<Qburger<<endl;
        cout<<"Number of burgers we gave for rent"<<Sburger<<endl;
        cout<<"Remaining number of burgers"<<Qburger-Sburger<<endl;
        cout<<"Total burgers collection for the day"<<Total_burger<<endl;

        cout<<"Number of noodles we have "<<Qnoodles<<endl;
        cout<<"Number of noodles we gave for rent"<<Snoodles<<endl;
        cout<<"Remaining number of noodles"<<Qnoodles-Snoodles<<endl;
        cout<<"Total noodles collection for the day"<<Total_noodles<<endl;

        cout<<"Number of shakes we have "<<Qshake<<endl;
        cout<<"Number of shakes we gave for rent"<<Sshake<<endl;
        cout<<"Remaining number of shakes"<<Qshake-Sshake<<endl;
        cout<<"Total shakes collection for the day"<<Total_shake<<endl;

        cout<<"Number of chicken-roll we have "<<Qchicken<<endl;
        cout<<"Number of chicken-roll we gave for rent"<<Schicken<<endl;
        cout<<"Remaining number of chicken-roll"<<Qchicken-Schicken<<endl;
        cout<<"Total chicken-roll collection for the day"<<Total_chicken<<endl;

        cout<<"\n\n\n Total collection for the day: " <<Total_burger + Total_chicken + Total_noodles + Total_pasta + Total_rooms + Total_shake;
        break;

        case 8:
            exit(0);
            default:
                cout<<endl;
                cout<<"Please select the numbers from above"<<endl;
    }
    goto menu;
}