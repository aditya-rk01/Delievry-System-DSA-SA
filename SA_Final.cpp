#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

#define V 16

int graph[V][V] = {{ 0,	0,	0,	0,	0,	0,	0,	0,	0,	20,	0,	9,	0,	0,	16,	0},
                        {0,	0,	0,	0,	0,	2,	7,	0,	0,	10,	0,	0,	0,	0,	0,	20},
                        {0,	0,	0,	0,	0,	0,	7,	0,	0,	0,	0,	0,	0,	0,	0,	0},
                        {0,	0,	0,	0,	0,	0,	2,	0,	0,	0,	0,	0,	0,	0,	0,	0},
                        {0,	0,	0,	0,	0,	15,	0,	0,	0,	0,	7,	0,	0,	0,	0,	0},
                        {0,	2,	0,	0,	15,	0,	0,	0,	0,	8,	0,	0,	0,	3,	0,	0},
                        {0,	7,	0,	2,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
                        {0,	0,	7,	0,	0,	0,	0,	0,	3,	0,	0,	0,	0,	0,	0,	0},
                        {0,	0,	0,	0,	0,	0,	0,	3,	0,	0,	0,	0,	0,	0,	0,	5},
                        {20,12,	0,	0,	0,	8,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
                        {0,	0,	0,	0,	7,	0,	0,	0,	0,	0,	0,	0,	12,	0,	0,	0},
                        {9,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
                        {0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	12,	0,	0,	0,	0,	0},
                        {0,	0,	0,	0,	0,	3,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
                        {16,0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
                        {0,	20,	0,	0,	0,	0,	0,	0,	5,	0,	0,	0,	0,	0,	0,	0},};

//maps delivery boy with his/her location
map<string, string> delivery_loc;


//defined to use on delivery boy
struct person{
    string name;
    string location;
    vector<string> food_item;
    int node_no;
    int distance;
    long long int mob_no;
};


void SetColor(int ForgC)
{
     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

void fontcolor()
{
    int x;
    x=rand()%256;
    SetColor(x);
}

//function will return a vector having shortest distance of source node to all other node
vector<int> djikstra(int graph[V][V],int src)
{
	vector<int> dist(V,INT_MAX);
	dist[src]=0;
	vector<bool> fin(V,false);

	for (int count = 0; count < V-1 ; count++)
	{
		int u = -1;

		for(int i=0;i<V;i++)
		    if(!fin[i]&&(u==-1||dist[i]<dist[u]))
		        u=i;
		fin[u] = true;

		for (int v = 0; v < V; v++)
			if (graph[u][v]!=0 && fin[v] == false)
				dist[v] = min(dist[v],dist[u]+graph[u][v]);
	}
    return dist;
}

int menu(string item){
    //initialize the menu
    map<string, int> menu_map;
    menu_map.insert (pair<string, int>("Pizza", 120));
    menu_map.insert (pair<string, int>("Burger", 100));
    menu_map.insert (pair<string, int>("Pasta", 150));
    menu_map.insert (pair<string, int>("Sandwich", 110));
    menu_map.insert (pair<string, int>("MisalPav", 130));
    menu_map.insert (pair<string, int>("Manchurian", 200));
    menu_map.insert (pair<string, int>("Noodles", 250));
    menu_map.insert (pair<string, int>("AlooParatha", 80));
    menu_map.insert (pair<string, int>("Sizzler", 450));
    menu_map.insert (pair<string, int>("Barbeque", 300));

    // iterator
    map<string, int>::iterator itr;

    for (itr = menu_map.begin(); itr != menu_map.end(); ++itr)
    {
        if(itr->first==item)
        {
            return itr->second;
        }
    }
    cout<<"No such item exists\n";
    return -1;

}

void map_print()
{
    int colwidth = 15;
    cout<<setw(colwidth)<<"Item";
    cout<<setw(colwidth)<<"Price";
    cout<<endl;
    cout<<"====================="<<endl;
    cout<<setw(colwidth)<<"Pizza";
    cout<<setw(colwidth)<<"120";
    cout<<endl;
    cout<<setw(colwidth)<<"Burger";
    cout<<setw(colwidth)<<"100";
    cout<<endl;
    cout<<setw(colwidth)<<"Pasta";
    cout<<setw(colwidth)<<"150";
    cout<<endl;
    cout<<setw(colwidth)<<"Sandwich";
    cout<<setw(colwidth)<<"110";
    cout<<endl;
    cout<<setw(colwidth)<<"MisalPav";
    cout<<setw(colwidth)<<"130";
    cout<<endl;
    cout<<setw(colwidth)<<"Manchurian";
    cout<<setw(colwidth)<<"200";
    cout<<endl;
    cout<<setw(colwidth)<<"Noodles";
    cout<<setw(colwidth)<<"250";
    cout<<endl;
    cout<<setw(colwidth)<<"AlooParatha";
    cout<<setw(colwidth)<<"80";
    cout<<endl;
    cout<<setw(colwidth)<<"Sizzler";
    cout<<setw(colwidth)<<"450";
    cout<<endl;
    cout<<setw(colwidth)<<"Barbeque";
    cout<<setw(colwidth)<<"300";
    cout<<endl;
}

//mapping of area name to node number
int mapping(string input)
{
    map<string, int> city_loc;
    city_loc.insert(pair<string, int>("SG Highway", 1));
    city_loc.insert(pair<string, int>("Chandkheda", 2));
    city_loc.insert(pair<string, int>("Ring Road", 3));
    city_loc.insert(pair<string, int>("Kalupur", 4));
    city_loc.insert(pair<string, int>("Adajan", 5));
    city_loc.insert(pair<string, int>("Old Wadaj",6));
    city_loc.insert(pair<string, int>("New Wadaj", 7));
    city_loc.insert(pair<string, int>("Paldi", 8));
    city_loc.insert(pair<string, int>("Vesu", 9));
    city_loc.insert(pair<string, int>("Vastrapur", 10));
    city_loc.insert(pair<string, int>("Chandini Chowk", 11));
    city_loc.insert(pair<string, int>("Connought Place", 12));
    city_loc.insert(pair<string, int>("Katargam", 13));
    city_loc.insert(pair<string, int>("Bhatar", 14));
    city_loc.insert(pair<string, int>("Godrej", 15));
    city_loc.insert(pair<string, int>("Manek Chowk", 16));

    // printing map city_loc
    map<string, int>::iterator itr;

    for (itr = city_loc.begin(); itr != city_loc.end(); ++itr)
    {
        if(itr->first==input)
        {
            return itr->second-1;
        }
    }
    return -1;
}

//initial distances of delivery boy from restaurant
void delivery_map_initialization()
{
    delivery_loc.insert(pair<string, string>("Aditya", "Adajan"));
    delivery_loc.insert(pair<string, string>("Chaitanya", "Paldi"));
    delivery_loc.insert(pair<string, string>("Aakarshak", "Sachin"));
    delivery_loc.insert(pair<string, string>("Vraj", "Katargam"));
}

//function to select the delivery boy based on shortest distance from restaurant
person delivery_person_selection(vector<int> distances)
{
    string name;
    person del_boy;
    del_boy.distance=INT_MAX;

    map<string, string>::iterator itr;

    for (itr = delivery_loc.begin(); itr != delivery_loc.end(); ++itr) {
        if(distances[mapping(itr->second)]<del_boy.distance){
            del_boy.distance=distances[mapping(itr->second)];
            del_boy.name=itr->first;
            del_boy.location=itr->second;
        }
    }
    return del_boy;
}

//function to update the location of the delivery boy
void delivery_boy_map_update(string dboyname, string dboyloc)
{
    delivery_loc.erase(dboyname);
    delivery_loc.insert(pair<string, string>(dboyname, dboyloc));
}

//input customer details
person input_details()
{
    person customer;

    cout<<"Enter your name: "<<endl;
    cin>>customer.name;
    cout<<"Enter your mobile no.: "<<endl;
    cin>>customer.mob_no;
    cout<<"Enter your location: "<<endl;
    cin>>customer.location;
    cout<<"Number of items you want to order ?: "<<endl;

    int item_no;
    string food_items;

    cin>>item_no;
    for(int i=0;i<item_no;++i)
    {
        cout<<"Item "<<i+1<<endl;
        cin>>food_items;
        customer.food_item.push_back(food_items);
    }

    char confirm;
    cout<<"Confirm order ?(Press y for yes and n for no)"<<endl;
    cin>>confirm;
    if(confirm!='y')
    {
        system("cls");
        input_details();
    }

    customer.node_no=mapping(customer.location);

    if(customer.node_no==-1)
    {
        cout<<"Enter a valid location"<<endl;
        exit(0);
    }
    return customer;
}

void bill(person cust, person del)
{
    int colwidth = 40;
    int colwidth0 = 30;
    ofstream fout;
    fout.open(cust.name+".txt");
    fout<<"-------------------"<<endl;
    fout<<"Customer Details"<<endl;
    fout<<"-------------------"<<endl;
    fout<<setw(colwidth0)<<"Name: "<<setw(colwidth)<<cust.name<<"\n";
    fout<<setw(colwidth0)<<"Location: "<<setw(colwidth)<<cust.location<<"\n";
    fout<<setw(colwidth0)<<"Mobile no.: "<<setw(colwidth)<<cust.mob_no<<"\n";
    fout<<setw(colwidth0)<<"Distance: "<<setw(colwidth)<<cust.distance<<"\n";
    fout<<"\n";

    fout<<"********************"<<endl;
    fout<<"Delivery Boy Details"<<endl;
    fout<<"********************"<<endl;
    fout<<setw(colwidth0)<<"Name: "<<setw(colwidth)<<del.name<<"\n";
    fout<<setw(colwidth0)<<"Location: "<<setw(colwidth)<<del.location<<"\n";
    fout<<setw(colwidth0)<<"Distance: "<<setw(colwidth)<<del.distance<<"\n";
    fout<<"\n";

    int food_cost=0;
    fout<<"###################"<<endl;
    fout<<"Order Details"<<endl;
    fout<<"###################"<<endl;
    for(int i=0;i<cust.food_item.size();++i)
    {
        fout<<setw(colwidth0)<<"Item: "<<setw(colwidth)<<cust.food_item[i]<<endl;
        fout<<setw(colwidth0)<<"Price: "<<setw(colwidth)<<menu(cust.food_item[i])<<"\n";
        food_cost+=menu(cust.food_item[i]);
        cout<<endl;
    }
    fout<<"\n";

    fout<<setw(colwidth0)<<"Delivery_cost: "<<setw(colwidth)<<cust.distance+del.distance<<"\n";
    fout<<setw(colwidth0)<<"Food_cost: "<<setw(colwidth)<<food_cost<<"\n";
    fout<<setw(colwidth0)<<"Total_cost: "<<setw(colwidth)<<cust.distance+del.distance+food_cost;

    fout.close();
}

void order_placing()
{
    person customer=input_details();
    vector<int> distances_from_restaurant;
    distances_from_restaurant=djikstra(graph,15);

    customer.distance=distances_from_restaurant[customer.node_no];

    person main_del_boy=delivery_person_selection(distances_from_restaurant);

    bill(customer, main_del_boy);

    delivery_boy_map_update(main_del_boy.name, customer.location);

    cout<<"Estimated Time: "<<(main_del_boy.distance+customer.distance)*2<<" mins"<<endl;
}

void show_map(){
    initwindow(600, 500, "Map");
    readimagefile("map.jpeg", 0, 0, 600, 300);
    delay(5000);
}

void show_deliveryboy_locations()
{
    map<string, string>::iterator itr;
    for (itr = delivery_loc.begin(); itr != delivery_loc.end(); ++itr)
    {
        cout<<"Name: "<<itr->first<<"   "<<"Location :"<<itr->second<<endl;
    }
}

int main()
{
    char cur_exe='y';

    delivery_map_initialization();
    fontcolor();

    while(cur_exe=='y')
    {
        cout<<"Welcome to AAC Restaurant"<<endl<<endl;
        cout<<"Options: "<<endl;
        cout<<"1: Place Order"<<endl;
        cout<<"2: Maps"<<endl;
        cout<<"3: Current delivery boy locations"<<endl;
        int option;
        cin>>option;
        system("cls");

        switch(option)
        {
            case 1: order_placing();
                    break;
            case 2: show_map();
                    break;
            case 3: show_deliveryboy_locations();
                    break;
        }

        cout<<"Do you want to continue? (Press y for yes and n for no)"<<endl;
        cin>>cur_exe;
        fontcolor();
        system("cls");
    }
	return 0;
}
