#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void menu();

class ManageMenu
{
    protected:
        string userName;  // Hide Admin Menu

    public:
        ManageMenu()  // Constructor
        {
            cout<<"\n\t\tEnter your Name to Continue as an Admin : "<<endl;
            cout<<"\t\t";
            cin>>userName;
            menu();
        }
        ~ManageMenu(){}  // Destructur
};

class Customers
{
    public:
        string name, gender, address, mobileNo;
        int age;
        static int cusId;
        char all[999];

        void getDetails()
        {
            ofstream out("Travel-Customer.txt", ios::app);
            {
                cout<<"\nEnter Customer ID : ";
                cin>>cusId;
                cout<<"Enter Customer Name : ";
                cin>>name;
                cout<<"Enter Age : ";
                cin>>age;
                cout<<"Enter Moblie Number : ";
                cin>>mobileNo;
                cout<<"Enter Address : ";
                cin>>address;
                cout<<"Enter Gender : ";
                cin>>gender;
            }

            out<<"Customer ID : "<<cusId<<"\nName : "<<name<<"\nAge : "<<age<<"\nMobile Number : "<<mobileNo<<"\nAddress : "<<address<<"\nGender : "<<gender<<endl;
            out.close();
            cout<<"\nDetails Saved!\nNOTE: We save your details record for future purpose\n"<<endl;
        }

        void showDetails()
        {
            ifstream in("Travel-Customer.txt");
            {
                if (!in)
                {
                    cout<<"File Error!"<<endl;
                }
                while (!(in.eof()))
                {
                    in.getline(all, 999);
                    cout<<all<<endl;
                }
                in.close();
            }
        }
};

int Customers :: cusId;

class Cabs
{
    public:
        int cabChoice;
        int kilometers;
        float cabCost;
        static float lastcabCost;

        void cabDetails()
        {
            cout<<"\n--------------- UBER Cabs ---------------\n"<<endl;
            cout<<"We collaborated with fastest, safest, and smartest cab services around the country\n"<<endl;
            cout<<"1. Rent a Standard Cab - Rs.15 for 1 Km"<<endl;
            cout<<"2. Rent a Luxury Cab - Rs.25 for 1 Km"<<endl;


            cout<<"\nTo calculate the cost for your journey"<<endl;
            cout<<"Enter which kind of cab you need : ";
            cin>>cabChoice;
            cout<<"Enter kilometers you have to travel : ";
            cin>>kilometers;

            int hireCab;

            if (cabChoice==1)
            {
                cabCost=kilometers*15;
                cout<<"\nYour ride costs "<<cabCost<<" Rupees for a Standard Cab"<<endl;
                cout<<"\nPress 1 to Hire this Cab"<<endl;
                cout<<"Press 2 to Select another Cab\n"<<endl;
                cin>>hireCab;

                if (hireCab==1)
                {
                    lastcabCost=cabCost;
                    cout<<"\nYou have successfully hired a Standard Cab\nGoto Menu and take the receipt"<<endl;
                }
                else if (hireCab==2)
                {
                    cabDetails();
                }
                else
                {
                    cout<<"Invalid Input! Redirecting to Previous Menu"<<endl;
                    cabDetails();
                }
            }

            else if (cabChoice==2)
            {
                cabCost=kilometers*25;
                cout<<"\nYour ride costs "<<cabCost<<" Rupees for a Luxury Cab"<<endl;
                cout<<"\nPress 1 to Hire this Cab"<<endl;
                cout<<"Press 2 to Select another Cab\n"<<endl;
                cin>>hireCab;

                if (hireCab==1)
                {
                    lastcabCost=cabCost;
                    cout<<"\nYou have successfully hired a Luxury Cab\nGoto Menu and take the receipt"<<endl;
                }
                else if (hireCab==2)
                {
                    cabDetails();
                }
                else
                {
                    cout<<"Invalid Input! Redirecting to Previous Menu"<<endl;
                    cabDetails();
                }
            }

            else
            {
                cout<<"Invalid Input! Redirecting to Previous Menu"<<endl;
                cabDetails();
            }

            cout<<"\nPress 1 to Redirect to the Main Menu : ";
            cin>>hireCab;

            if (hireCab==1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
};

float Cabs :: lastcabCost;

class Booking
{
    public:
        int choiceHotel;
        int packageChoice;
        static float hotelCost;

        void hotels()
        {
            cout<<endl;
            string hotelNo[] = {"Avendra","Landmark","Piccaso"};
            for (int a = 0; a<3; a++)
            {
                cout<<(a+1)<<". Hotel "<<hotelNo[a]<<endl;
            }
            cout<<"\nCurrrently we collaborted with above Hotels!\n"<<endl;
            cout<<"Enter number of the Hotel you wish to book\nOR Press any key to back : ";
            cin>>choiceHotel;

            if (choiceHotel==1)
            {
                cout<<"\n---------- WELCOME TO HOTEL AVENDRA ----------\n"<<endl;
                cout<<"The Garden, Food and Beverage. Enjoy all !!"<<endl;
                cout<<"Packages offered by HOTEL AVENDRA : \n"<<endl;
                cout<<"1. Standard Pack : "<<endl;
                cout<<"-> All basic facilities you need for just : Rs. 5000"<<endl;
                cout<<"2. Premium Pack : "<<endl;
                cout<<"-> Premium Experiancefor just : Rs. 10000"<<endl;
                cout<<"3. Luxury Pack : "<<endl;
                cout<<"-> Live all Luxury facilities for just Rs. 20000"<<endl;

                cout<<"\nEnter package number you want to book\nOR Press any key to back : ";
                cin>>packageChoice;

                if (packageChoice==1)
                {
                    hotelCost=5000;
                    cout<<"\nYou have successfully booked Standard Pack at HOTEL AVENDRA"<<endl;
                }
                else if (packageChoice==2)
                {
                    hotelCost=10000;
                    cout<<"\nYou have successfully booked Premium Pack at HOTEL AVENDRA"<<endl;
                }
                else if (packageChoice==3)
                {
                    hotelCost=20000;
                    cout<<"\nYou have successfully booked Luxury Pack at HOTEL AVENDRA"<<endl;
                }
                else
                {
                    cout<<"\nInvalid Input! Redirecting to Previous Menu\nPlease Wait!"<<endl;
                    hotels();
                }

                int gotoMenu;
                cout<<"\nPress 1 to redirect to Main Menu : ";
                cin>>gotoMenu;

                if (gotoMenu==1)
                {
                    menu();
                }
                else
                {
                    menu();
                }
            }

            else if (choiceHotel==2)
            {
                cout<<"\n---------- WELCOME TO HOTEL LANDMARK ----------\n"<<endl;
                cout<<"The Bar, Food, Beverage and Swimming Pool. Enjoy all !!"<<endl;
                cout<<"Packages offered by HOTEL LANDMARK : \n"<<endl;
                cout<<"1. Standard Pack : "<<endl;
                cout<<"-> All basic facilities you need for just : Rs. 10000"<<endl;
                cout<<"2. Premium Pack : "<<endl;
                cout<<"-> Premium Experiancefor just : Rs. 16000"<<endl;
                cout<<"3. Luxury Pack : "<<endl;
                cout<<"-> Live all Luxury facilities for just Rs. 25000"<<endl;

                cout<<"\nPress any key to back OR\nEnter package number you want to book : ";
                cin>>packageChoice;

                if (packageChoice==1)
                {
                    hotelCost=10000;
                    cout<<"\nYou have successfully booked Standard Pack at HOTEL LANDMARK"<<endl;
                }
                else if (packageChoice==2)
                {
                    hotelCost=16000;
                    cout<<"\nYou have successfully booked Premium Pack at HOTEL LANDMARK"<<endl;
                }
                else if (packageChoice==3)
                {
                    hotelCost=25000;
                    cout<<"\nYou have successfully booked Luxury Pack at HOTEL AVENDRA"<<endl;
                }
                else
                {
                    cout<<"\nInvalid Input! Redirecting to Previous Menu\nPlease Wait!"<<endl;
                    hotels();
                }

                int gotoMenu;
                cout<<"\nPress 1 to redirect to Main Menu : ";
                cin>>gotoMenu;

                if (gotoMenu==1)
                {
                    menu();
                }
                else
                {
                    menu();
                }
            }

            if (choiceHotel==3)
            {
                cout<<"\n---------- WELCOME TO HOTEL PICCASO ----------\n"<<endl;
                cout<<"The Garden, Food, Beverage, Bar, Gym and Swimming Pool. Enjoy all !!"<<endl;
                cout<<"Packages offered by HOTEL PICCASO : \n"<<endl;
                cout<<"1. Standard Pack : "<<endl;
                cout<<"-> All basic facilities you need for just : Rs. 16000"<<endl;
                cout<<"2. Premium Pack : "<<endl;
                cout<<"-> Premium Experiancefor just : Rs. 21000"<<endl;
                cout<<"3. Luxury Pack : "<<endl;
                cout<<"-> Live all Luxury facilities for just Rs. 30000"<<endl;

                cout<<"\nPress any key to back OR\nEnter package number you want to book : ";
                cin>>packageChoice;

                if (packageChoice==1)
                {
                    hotelCost=16000;
                    cout<<"\nYou have successfully booked Standard Pack at HOTEL PICCASO"<<endl;
                }
                else if (packageChoice==2)
                {
                    hotelCost=21000;
                    cout<<"\nYou have successfully booked Premium Pack at HOTEL PICCASO"<<endl;
                }
                else if (packageChoice==3)
                {
                    hotelCost=30000;
                    cout<<"\nYou have successfully booked Luxury Pack at HOTEL PICCASO"<<endl;
                }
                else
                {
                    cout<<"\nInvalid Input! Redirecting to Previous Menu\nPlease Wait!"<<endl;
                    hotels();
                }

                int gotoMenu;
                cout<<"\nPress 1 to redirect to Main Menu : ";
                cin>>gotoMenu;

                if (gotoMenu==1)
                {
                    menu();
                }
                else
                {
                    menu();
                }
            }
        }
};

float Booking :: hotelCost;

class Charges : public Booking, Cabs, Customers
{
    public:
        void printBill()
        {
            ofstream outf("Travel-Receipt.txt");
            {
                outf<<"---------- Ubaid Travel Agencies ----------"<<endl;
                outf<<"---------------- Receipt ------------------"<<endl;
                outf<<"___________________________________________"<<endl;
                outf<<"Customer ID : "         <<fixed<<setprecision(2)<<Customers::cusId<<endl<<endl;
                outf<<"Hotel Cost :       \t\t"<<fixed<<setprecision(2)<<Booking::hotelCost<<endl;
                outf<<"Travel (Cab) Cost :\t\t"<<fixed<<setprecision(2)<<Cabs::lastcabCost<<endl;
                outf<<"___________________________________________"<<endl;
                outf<<"Total Charges :    \t\t"<<fixed<<setprecision(2)<<Booking::hotelCost+Cabs::lastcabCost<<endl;       
                outf<<"___________________________________________"<<endl;
                outf<<"--------------- Thank You -----------------"<<endl;
            }
            outf.close();
        }

        void showBill()
        {
            ifstream inf("Travel-Receipt.txt");
            {
                if (!inf)
                {
                    cout<<"File opening Error!"<<endl;
                }
                while (!(inf.eof()))
                {
                    inf.getline(all, 999);
                    cout<<all<<endl;
                }
            }
            inf.close();
        }
};

void menu()
{
    int mainChoice;
    int inChoice;
    int gotoMenu;

    cout<<endl;
    cout<<"---------------------- Ubaid Travel Agencies ------------------------"<<endl;
    cout<<"--------------------------- MAIN MENU -------------------------------"<<endl;
    cout<<"\t\t __________________________________"<<endl;
    cout<<"\t\t|                                  |\t"<<endl;
    cout<<"\t\t|     Customer Management -> 1     |"<<endl;
    cout<<"\t\t|     Cab Booking         -> 2     |"<<endl;
    cout<<"\t\t|     Hotel Booking       -> 3     |"<<endl;
    cout<<"\t\t|     Charges & Bills     -> 4     |"<<endl;
    cout<<"\t\t|__________________________________|"<<endl;    
    
    cout<<"\nEnter your Choice : ";
    cin>>mainChoice;

    Customers a1;
    Cabs a2;
    Booking a3;
    Charges a4;

    if (mainChoice==1)
    {
        cout<<"\n-------- Customers --------\n"<<endl;
        cout<<"1.  Enter New Customer"<<endl;
        cout<<"2.  See Old Customer"<<endl;
        cout<<"\nEnter Choice : ";
        cin>>inChoice;

        if (inChoice==1)
        {
            a1.getDetails();
        }
        else if (inChoice==2)
        {
            a1.showDetails();
        }
        else
        {
            cout<<"Invalid Input! Redirecting to Previous Menu"<<endl;
            menu();
        }
        
        cout<<"Press 1 to Redirect to the Main Menu : ";
        cin>>gotoMenu;
        
        if (gotoMenu==1)
        {
            menu();
        }
        else
        {
            menu();
        }
    }

    else if (mainChoice==2)
    {
        a2.cabDetails();
    }

    else if (mainChoice==3)
    {
        a3.hotels();
    }

    else if (mainChoice==4)
    {
        a4.printBill();
    
        cout<<"\nYour Receipt is already printed you can\nget it from file path @Travel-Receipt.txt"<<endl;
        cout<<"\nTo display your Receipt in the Screen, Enter 1\nOr Enter any key to go back to the Main Menu : ";
        cin>>gotoMenu;

        if (gotoMenu==1)
        {
            cout<<endl<<endl<<endl;
            a4.showBill();
            cout<<"\n\nPress 1 to Redirect to the Main Menu : ";
            cin>>gotoMenu;

            if (gotoMenu==1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else
        {
            menu();
        }
    }

    else
    {
        cout<<"\nInvalid Input!"<<endl;
        menu();
    }
}

int main()
{
    ManageMenu startObj;

    return 0;
}
