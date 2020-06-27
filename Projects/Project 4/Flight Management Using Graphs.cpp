#include <bits/stdc++.h>
using namespace std;
#define INF 999999
set <int> st;

//This function is used to add the airport (vertex) to the existing graph.
void Add_single_airport(vector <vector <int> >& cost, vector <vector <int> >& min_cost,vector<vector<int >>& time,vector<vector<int>> &min_time){
    int v = cost.size();
    vector <int> vec(v, INF);
    cost.push_back(vec);
    time.push_back(vec);
    min_cost.push_back(vec);
    min_time.push_back(vec);
    for(int i = 0 ; i<v+1 ; i++){
        cost[i].push_back(INF);
        time[i].push_back(INF);
        min_cost[i].push_back(INF);
        min_time[i].push_back(INF);
    }
    cost[v][v] = 0;
    min_cost[v][v] = 0;
    time[v][v] = 0;
    min_time[v][v] = 0;

}

//This function add the route(Edges)to the existing airports (vertex)in the graph.
void Add_edge(int i, int j, int val,int val2, vector <vector <int> >& cost,vector <vector <int> >& min_cost,vector<vector<int >>&time,vector<vector<int>>&min_time)
{
    // print_Mat(cost);
    int s=cost.size();
    if((i>s)||(j>s))
        cout<<"No such airport exist";

    if(i==j)
        cout<<"This is the same airport";
 else{
    cost[i-1][j-1] = val;
    time[i-1][j-1]=val2;
    min_cost = cost;
    min_time = time;
    }
}

//This perform the deletion function whenever, we are required to delete the Airport.
void Delete_node(vector <vector <int> >& cost, vector <vector <int> >& min_cost, vector <vector <int> >& time, vector <vector <int> >& min_time,int k){
    // cost.erase(cost.begin() + k-1);
    st.insert(k);
    for(int i = 0 ; i < cost.size() ; i++){
        cost[i][k-1] = INF;
        cost[k-1][i] = INF;
        time[i][k-1]=INF;
        time[k-1][i]=INF;
        // cost[i].erase(cost[i].begin() + k-1);
    }
    // print_Mat(cost);
    // print_Mat(time);
    min_cost = cost;
    min_time = time;
}


//This performs the deletion funtion of deleting the route between the two airport given ,Source and destination respectively.
void Delete_edge(int i, int j, vector <vector <int> >& cost, vector <vector <int> >& min_cost,vector<vector<int>> &time,vector<vector<int>>&min_time)
{
    if((cost[i-1][j-1] == INF) && (time[i-1][j-1]==INF))
        {cout<<"Edge not present"<<endl; return;}

    cost[i-1][j-1] = INF;
    time[i-1][j-1]=INF;
    min_cost = cost;
    min_time=time;
}

//This outputs the shortest or minimum cost and time of the given two airports ,source and destination respectively .
void shortest_distance_bw_two_Nodes(int x,int y,vector<vector<int>>&min_cost,vector<vector<int>>&min_time)
{   cout<<endl;
    cout<<"Rs:"<<min_cost[x-1][y-1]<<endl;
    cout<<min_time[x-1][y-1]<<"Hrs"<<endl;
}

//This function is used to give the shortest cost and time from the one node to all existing nodes.
void shortest_distance_bw_one_to_allNodes(int x,int a, int b, int c,vector<vector<int>>&min_cost,vector<vector<int>>&min_time)
{

    int n = min_cost.size();
    if(a==1){
        for(int i=0;i<n;i++){
      if(st.find(i+1) != st.end()) continue;
            if(x-1!=i && min_cost[x-1][i]!=999999){
            cout<<x<<"-->"<<i+1<<": "<<min_cost[x-1][i]<<"Rupees"<<endl;
            }
            else if(min_cost[x-1][i]==999999){
                cout<<x<<"-->"<<i+1<<": No route"<<endl;
            }
        }
    }
    if(b==1){
        for(int i=0;i<n;i++){
      if(st.find(i+1) != st.end()) continue;
            if(x-1!=i && min_time[x-1][i]!=999999){
            cout<<x<<"-->"<<i+1<<": "<<min_time[x-1][i]<<"Hour"<<endl;
            }
            else if(min_time[x-1][i]==999999){
                cout<<x<<"-->"<<i+1<<": No route"<<endl;
            }
        }
    }
    if(c==1){
        cout<<"Shortest distance based on Cost"<<endl;
        for(int i=0;i<n;i++){
      if(st.find(i+1) != st.end()) continue;
            if(x-1!=i && min_cost[x-1][i]!=999999){
            cout<<x<<"-->"<<i+1<<": "<<min_cost[x-1][i]<<" Rupees"<<endl;
            }
            else if(min_cost[x-1][i]==999999){
                cout<<x<<"-->"<<i+1<<": No route"<<endl;
            }
        }
        cout<<"Shortest distance based on Time"<<endl;
        for(int i=0;i<n;i++){
      if(st.find(i+1) != st.end()) continue;
            if(x-1!=i && min_time[x-1][i]!=999999){
            cout<<x<<"-->"<<i+1<<": "<<min_time[x-1][i]<<" Hour"<<endl;
            }
            else if(min_time[x-1][i]==999999){
                cout<<x<<"-->"<<i+1<<": No route"<<endl;
            }
        }
    }

}

//This function is used to find the shortest distance based in cost and time from all nodes to all other existing nodes.
void all_Nodes(vector <vector <int>> min_cost){
	int n = min_cost.size();


    cout<<"     ";
    for(int i = 0 ; i< n; i++){
      if(st.find(i+1) != st.end()) continue;
      cout<<i+1<<"   ";
    }
    cout<<endl;
    // cout<<endl<<"     ------------------------------------------------"<<endl;
    for(int i = 0 ; i < n; i++){
      if(st.find(i+1) != st.end()) continue;
      cout<<i+1<<":   ";
        for(int j = 0 ; j < n ; j++){
          if(st.find(j+1) != st.end()) continue;
          if(min_cost[i][j] == INF)
          cout<<"No Route   ";
          else
          cout<<min_cost[i][j]<<"   ";
        }
        cout<<endl;
      }

}

//This function prints the cost and time matrix.
void print_Mat(vector <vector <int> > cost){
		int n = cost.size();
    cout<<"     ";
    for(int i = 0 ; i< n; i++){
      cout<<i+1<<"   ";
    }
      cout<<endl;
        for(int i = 0 ; i < n; i++){
            cout<<i+1<<":   ";
            for(int j = 0 ; j < n ; j++){
                if(cost[i][j] == INF)
                cout<<"INF ";
                else
                cout<<cost[i][j]<<"  ";
            }
            cout<<endl;
        }
        cout<<"-----------"<<endl;
}

// Floyd Warshall Algorithm
void Cal_all_Nodes_Shortest_path(vector <vector <int>>& cost,vector<vector<int> >& time){
    int n = cost.size();
    for(int k = 0 ; k < n ; k++){
        for(int i = 0 ; i < n; i++){
            for(int j = 0 ; j < n ; j++){
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                time[i][j]=min(time[i][j] ,time[i][k]+time[k][j]);
            }
        }
    }
}


//driver function
int main(){

    int choice;

    cout<<"\nWelcome to Flight Management System\n";
    cout<<" \nbuild Airport\n";
    cout<<"\nEnter the number of airports: "<<endl;
    int n;
    cin>>n;
    vector< vector<int> > cost(n, vector<int>(n, INF));
    vector< vector<int> > time(n, vector<int>(n, INF));
    vector <vector <int> > min_cost(n, vector <int>(n));
    vector<vector <int> > min_time(n,vector<int>(n));
    for(int i = 0 ; i<n;i++){
      cost[i][i] = 0;
      time[i][i] = 0;
    }
    cout<<"Enter the number of Edges: "<<endl;
    int no_of_edges;
    cin>>no_of_edges;

    cout<<"Enter the "<<no_of_edges<<" edges and its Cost and Time "<<endl;
    for(int i = 0 ; i < no_of_edges; i++){
      int x, y, cost1, time1;
      cin>>x>>y>>cost1>>time1;
      cost[x-1][y-1] = cost1;
      time[x-1][y-1] = time1;
    }
    min_cost = cost;
    min_time = time;
    Cal_all_Nodes_Shortest_path(min_cost, min_time);
    cout<<"\n Airports build Successfully"<<endl;
    cout<<"Routes with Cost Details"<<endl;
    print_Mat(cost);
    // cout<<"Routes with Minimum Cost Details"<<endl;
    // print_Mat(min_cost);
    cout<<"Routes with Time Details"<<endl;
    print_Mat(time);
    // cout<<"Routes with Minimum Time Details"<<endl;
    // print_Mat(min_time);


    while(1){
        cout<<"\n1. Add Airport\n";
        cout<<"2. Add Route between 2 Airports\n";
        cout<<"3. Delete Airport\n";
        cout<<"4. Delete Route\n";
        cout<<"5. Update Route cost and Travel Timing\n";
        cout<<"6. Find Shortest distance between any two Airports\n";
        cout<<"7. Find Shortest distance from one Airport to all other Airports\n";
        cout<<"8. Find Shortest distance between all Airports to all airports\n";
        cout<<"9. Exit\n";
        cout<<"Please Enter your choice: \n"<<endl;
        cin>>choice;
        if(choice == 9){
            cout<<"Thank you..."<<endl;
            break;}
       switch(choice){
          case 1:
                  Add_single_airport(cost,min_cost,time,min_time);
                  cout<<"\nAirport "<< cost.size() << " is Created, please Add edges"<<endl;
                  break;

           case 2:
                    int x, y, costI, timeI;
                    cout<<"Number of edges"<<endl;
                    int number_of_edges;
                    cin>>number_of_edges;
                    cout<<"Enter the route you desire to generate and the cost and time required: ex Input: 1 2 200 2"<<endl;

                    for(int i = 0 ; i < number_of_edges ;i++){
                    cin>>x>>y>>costI>>timeI;
                    Add_edge(x,y,costI,timeI,cost,min_cost,time,min_time);
                  }
                    cout<<" edges added Successfully "<<endl;
                    Cal_all_Nodes_Shortest_path(min_cost, min_time);

                    break;
           case 3:

                  cout<<"Enter the Airport to be deleted: "<<endl;
                  cin>>x;
                  Delete_node(cost,min_cost,time,min_time,x);

                  Cal_all_Nodes_Shortest_path(min_cost,min_time);

                  cout<<"\nAirport is deleted Successfully "<<endl;

                  break;


           case 4:

                  cout<<"Enter the source and destination: "<<endl;
                  cin>>x>>y;
                  Delete_edge(x,y,cost,min_cost,time,min_time);
                  Cal_all_Nodes_Shortest_path(min_cost,min_time);
                  cout<<"Edge deleted Successfully"<<endl;

                  break;

           case 5:
                 int n;int k;int l;
                 int ch;
                 cout<<"Enter the number of edges to update"<<endl;
                 cin>>n;
                 for(int i=0;i<n;i++)
                 {
                 cout<<" 1-Update cost of the Route"<<endl;
                 cout<<" 2-Update time of the Route"<<endl;
                 cout<<" 3-Update Both"<<endl;
                 cin>>ch;
                 if(ch==1)
                 {
                     cout<<"Enter the source and destination of the Route and Cost "<<endl;
                     cin>>x>>y>>k;
                     Add_edge(x,y,k,time[x-1][y-1],cost,min_cost,time,min_time);
                 }
                 else if(ch==2)
                 {
                     cout<<"Enter the source ,destination and Time"<<endl;
                  cin>>x>>y>>l;
                  Add_edge(x,y,cost[x-1][y-1],l,cost,min_cost,time,min_time);
                 }
                 else if(ch==3)
                 {
                     cout<<"Enter the source ,destination ,Cost and Time"<<endl;
                  cin>>x>>y>>k>>l;
                 Add_edge(x,y,k,l,cost,min_cost,time,min_time);
                 }
                 else
                     cout<<"Enter correct choice"<<endl;
                 cout<<" Edge Successfully updated"<<endl;
                 }
                 Cal_all_Nodes_Shortest_path(min_cost,min_time);
                 break;

           case 6:
                    cout<<"Enter the source and destination"<<endl;
                    cin>>x>>y;
                    shortest_distance_bw_two_Nodes(x,y,min_cost,min_time);
                    break;

           case 7:
           int a,b,c,op;
                cout<<"Enter Airport\n";
                cin>>x;
                if(st.find(x) != st.end()) {
                  cout<<" Airport Dosent Exist! "<<endl;
                  break;
                }
                cout<<"1. To find shortest distance between one airport to al other airport Based on Cost\n";
                cout<<"2. To find shortest distance between one airport to al other airport Based on Time\n";
                cout<<"3. To find shortest distance between one airport to al other airport Based on Both Cost and Time\n";
                cin>>op;
                if(op==1){
                    shortest_distance_bw_one_to_allNodes(x,1,0,0,min_cost,min_time);
                }
                else if(op==2){
                    shortest_distance_bw_one_to_allNodes(x,0,1,0,min_cost,min_time);
                }
                else if(op==3){
                    shortest_distance_bw_one_to_allNodes(x,0,0,1,min_cost,min_time);
                }
                break;

           case 8:
                 cout<<"Minimum cost in Rupees"<<endl;
                 all_Nodes(min_cost);
                 cout<<endl;
                 cout<<"Minimum Time in Hours"<<endl;
                 all_Nodes(min_time);
                 cout<<endl;
                 break;


       }

    }


  return 0;
}

// 1 2 300 3
// 2 1 800 8
// 2 3 200 2
// 3 4 100 1
// 1 4 700 7
// 4 1 200 2
// 3 1 500 5
