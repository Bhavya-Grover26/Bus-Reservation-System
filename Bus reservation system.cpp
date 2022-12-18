//Bus booking system by E003 Aditi Ahuja, E011 Divinia Dsouza, E019 Rajrishi Gautum, E023 Bhavya Grover


#include <iostream>
#include <string.h>
using namespace std;

string nm[100],p[100];  //p is the seat character entered
string dest;
int date;
char arr[100][100];   //array used for dijkstra
int counts=30,final_price;
#define inf 9999
int dist[100],parent[100];
int src;
bool visited[100]={false};  //all vertex visited initialised at false


void timetable()
{
    cout<<"FROM      |"<<"TO            |"<<"DISTANCE   |"<<endl;
    cout<<"MUMBAI    |"<<"GOA           |"<<"614 KM     |"<<endl;
    cout<<"MUMBAI    |"<<"PUNE          |"<<"171 KM     |"<<endl;
    cout<<"MUMBAI    |"<<"SURAT         |"<<"285 KM     |"<<endl;
    cout<<"MUMBAI    |"<<"BANGALORE     |"<<"984 KM     |"<<endl;
    cout<<"MUMBAI    |"<<"UDAIPUR       |"<<"755 KM     |"<<endl;
}


void distance()
{
    for(int i=0;i<6;i++)
    {
        dist[i]=inf; // all distance initialised at infinity
    }
    dist[src]=0;
}
int minimum_dist()
{
    int minimum_value=inf;
    int minimun_node=0;
    for(int i=0;i<5;i++)
    {
        if(!visited[i]&&dist[i]<minimum_value) //node not visited and distance is less than minimum
        {
            minimum_value=dist[i];
            minimun_node=i;
        }

   }
   return minimun_node;
}
void Dijkstra(int graph[6][6])
{
    for(int i=0;i<6;i++)
    {
        int nearest=minimum_dist();
        visited[nearest]=true;
        for(int adj=0;adj<6;adj++)     //to check if there are any adjacent nodes
        {
            if(graph[nearest][adj]!=inf&&dist[adj]>dist[nearest]+graph[nearest][adj])
            {
                dist[adj]=dist[nearest]+graph[nearest][adj];                 //shortest distance changed
            }

        }
    }

}
void display()
{
    string display[6]={"Mumbai","Pune","Goa","Banglore","Surat","Udaipur"};
    cout<<"Destination\tDistance(km)"<<endl;
     for(int i=0;i<5;i++)
     {
         cout<<display[i+1]<<"\t\t\t"<<dist[i+1]<<"\t\t\t"<<"    "<<endl;
     }

}

int allOccupied(char arr[9][5])
{
    int count=0;
    for(int i=0;i<8;i++)
        {
            for(int j=1;j<5;j++)
            if(arr[i][j]=='X')
            count++;
        }
        if(count==36)
            return 1;
        return 0;
}

void display1(char arr[9][5])
{
    for(int i=0;i<9;i++)
       {
            for(int j=0;j<5;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
}

string seat_name()
{
    string p;
    cout<<"enter valid seat no to check(like 1B): ";
    cin>>p;
    return p;
}

void update(char arr[9][5],int row,int col)   //to update seat arrangement after seat allocation
{
    cout<<"congrats, your seat is reserved"<<endl;
    cout<<"updated seat status:"<<endl;
    for(int i=0;i<9;i++)
       {
            for(int j=0;j<5;j++)
            {
                arr[row][col]='X';
            }
        }
}

int check(char arr[9][5],string s)  //to check if the seat is already occupied
{

    if(s[0]>'9' || s[0]<'1' || s[1]>'D' || s[1]<'A')
    {
        cout<<"invalid seat no\n";
        return 0;
    }
    int row=-1,col=-1;
    for(int i=0;i<9;i++)
        {
            if(arr[i][0]==s[0])
            row=i;
        }
    for(int j=0;j<5;j++)
        {
            if(arr[row][j]==s[1])
            col=j;
        }
        if(col==-1)
            {
                cout<<"Seat is already occupied. Please enter another seat"<<endl;
                seat_name();
                update(arr,row,col);
            }
        else
            {
                update(arr,row,col);
            }
            return 1;

}

void bus(int n,char arr[9][5])
{
for (int i=1;i<=n;i++)
{
string s;
s=seat_name();

if(check(arr,s))
display1(arr);
if(allOccupied(arr))
{
cout<<"sorry, no more seats left!"<<endl;
break;
}
}
}


void booking(int n,int age[100],int clas,int slep,int ac)
{
int i,price=100,total=0;
float amt[100];
if (clas==1)
{
    cout<<"Price per member for first class is additional RS.20 "<<endl;
    price=price+20*n;
}
else if(clas==2)
{
    cout<<"Price per member for second class is additional Rs.10 "<<endl;
    price=price+10*n;
}
else
{
    price=price+0*n;
}
if (slep==1)
{
    cout<<"Price per member for sleeper coach is additional Rs.50"<<endl;
    price=(price+(50*n));
}
else
{
    price=price+(0*n);
}
if (ac==1)
{
    cout<<"Price per member for A.C is additional Rs.50 "<<endl;
    price=price+50*n;
}
for(i=1;i<=n;i++)
{
if(age[i]>=1 && age[i]<=15)
		{
			cout<<"1-15(age) wins 10% discount."<<endl;
			amt[i]=(price-(100*10/100));
			cout<<"Rates for "<<age[i]<<" years member is: Rs "<<amt[i]<<endl;
		}
		else
		{
			amt[i]=price;
			cout<<"Rates for "<<age[i]<<" years member is: Rs "<<amt[i]<<endl;
		}
total=total+amt[i];
}
final_price=total;
cout<<"the total price is:"<<final_price<<endl;
}

void bill(int age[100],int clas,int ac,int slep,int n,int date,string dest)
{
    cout<<"  _________________________________________________________________________________________________"<<endl;
    cout<<"                                    BRAD bus reservations                                         "<<endl;
    cout<<"                                         e-Ticket                                                 "<<endl;
    cout<<"                                       Wishwish Nagar,                                            "<<endl;
    cout<<"                                     Goregaon, Mumbai,                                            "<<endl;
    cout<<"                                     Maharashtra 400063                                           "<<endl;
    cout<<"                                                                                                  "<<endl;
    cout<<"  Destination: Mumbai->"<<dest<<"                                                                  "<<endl;
    cout<<"  Start Date:"<<date<<"                                                                             "<<endl;
    cout<<"                                                                                                  "<<endl;
    cout<<"  Ticket Number:6781                                                                              "<<endl;
    cout<<"  PNR no.:18267363                                                                                "<<endl;
    cout<<"                                                                                                  "<<endl;
    cout<<"  _______________________________________________________                                          "<<endl;
    cout<<"  Mercedes Benz              |     7:00am      |     7:30am      |        "<<n<<"                        "<<endl;
    cout<<"                               Reporting Time    Departure Time     No. of Passengers             "<<endl;
    cout<<"                                                                                                  "<<endl;
    cout<<"                                                                                                  "<<endl;
    cout<<"  Boarding Point details    |   Location:"<<dest<<"\t"<<"Address:Wishwish Nagar,Goregaon, Mumbai,             "<<endl;
    cout<<"                                                                                                  "<<endl;
    cout<<"                                                                                                  "<<endl;
    cout<<"  Destination Details       |         Date                                                        "<<endl;
    cout<<"                                   "<<date<<"                                                           "<<endl;
    cout<<" ___________________________________________________                                              "<<endl;
    cout<<"                                                                                                  "<<endl;
    cout<<"                                                                                                  "<<endl;
    cout<<" Name\tAge\tClass\tAc/Non Ac\tSleeper/Non Sleeper                                                 "<<endl;
    for(int i=1;i<=n;i++)
    {
    cout<<" "<<nm[i]<<"\t"<<age[i]<<"\t"<<clas<<"\t"<<ac<<"\t\t"<<slep<<"                                                               "<<endl;
    cout<<"                                                                                                  "<<endl;
    }
    cout<<"                                                                  Fare:          Rs."<<final_price<<"             "<<endl;
    cout<<"                                                                  cgst(5%):      Rs."<<final_price*5/100<<"     "<<endl;
    cout<<"                                                                  gst(5%):       Rs."<<final_price*5/100<<"   "<<endl;
    cout<<"                                                                  Internet fees: Rs.77              "<<endl;
    cout<<"                                                                                 _________                  "<<endl;
    cout<<"                                                                  Total Fare: Rs."<<final_price+2*(final_price*5/100)+77<<"        "<<endl;
    cout<<" ___________________________________________________                                             "<<endl;
    cout<<" Note:This operator accepts e-ticket,you need not carry a print                                  "<<endl;
    cout<<" ________________________________________________________________________________________________"<<endl;

}

int main()
{
int n,choice,age[100],clas,slep,ac;
char arr[9][5];
int graph[6][6]={
      {0, 171, 614, 984, 285,755},
      {171, 0,448,9999,413,886},
      {614, 448, 0, 549, 852,9999},
      {984, 9999, 549, 0, 9999,9999},
      {285, 415, 852, 9999, 0,9999},
      {755, 886, 9999, 9999, 0,9999},
      };

		src=0;
cout<<",-.  ,-.   ,.  ,-.  "<<endl;
cout<<"|  ) |  ) /  \\ |  \\ "<<endl;
cout<<"|-<  |-<  |--| |  | "<<endl;
cout<<"|  ) |  \\ |  | |  / "<<endl;
cout<<"`-'  '  ' '  ' `-'"<<endl;
cout<<"Last Minute Booking - In a hurry to book a bus at the last minute? "<<endl;
cout<<"Choose the bus passing from your nearest boarding point and book in a few easy steps."<<endl;
cout<<"Comprehensive Ticket Details- Everything that you need to make the travel hassle free."<<endl;
cout<<endl;
do{
cout<<"1.View route"<<endl;                //to view dijkstra
cout<<"2.Book ticket and seat "<<endl;
cout<<"3.Exit"<<endl;
cin>>choice;
switch (choice)
{
case 1:
    {
        cout<<"Bus timetable:"<<endl;
        timetable();
        cout<<endl;
        cout<<"The shortest route is:"<<endl;
        distance();
        Dijkstra(graph);  //use of dijkstra algorithm
        display();
        break;
    }
case 2:
    {
        cout<<"Enter destination:"<<endl;
        cin>>dest;
        cout<<"Enter the date of travel(DDMMYY):"<<endl;
        cin>>date;
        cout<<"Enter how many passengers"<<endl;
        cin>>n;
        counts=counts-n;         //seats left in bus
        cout<<"Enter the Coach to travel:"<<endl;
        cout<<"1.First class "<<endl;
        cout<<"2.Second class "<<endl;
        cout<<"3.General"<<endl;
        cin>>clas;
        cout<<"1. Sleeper"<<endl;
        cout<<"2.Non sleeper"<<endl;
        cin>>slep;
        cout<<"1. A.C "<<endl;
        cout<<" 2.Non A.C"<<endl;
        cin>>ac;
        cout<<"Fill in passenger details:"<<endl;
        for(int i=1;i<=n;i++)
            {
                cout<<"Enter the age:"<<endl;
                cin>>age[i];
                cout<<"Enter the name:"<<endl;
                cin>>nm[i];
            }
        booking(n,age,clas,slep,ac);
        for(int i=0;i<9;i++)
        {
        arr[i][0]=i+1+'0';
        for(int j=1;j<5;j++)
        {
       arr[i][j]='A'+j-1;
        }
        }
        cout<<"initial seat arrangements:"<<endl;
        display1(arr);
        bus(n,arr);
        cout<<"Seats left:"<<counts<<endl;
        bill(age,clas,ac,slep,n,date,dest);
        break;
    }

default: cout<<"Invalid entry";     //to exit the program
}


}while(choice<3);

return 0;
}

