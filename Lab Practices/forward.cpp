#include<iostream>
#include<vector>
#include<climits>
        using namespace std;
const int INF=INT_MAX;

        void Forwardgraph (vector<vector<int>>&c,int n,int k,vector<int>&path ,vector<int>cost){
           
            vector<int>pred(n,-1);
            cost[0]=0;


            for(int j=1;j<n;++j){
                for(int i=0;i<n;++i){
                    if(c[i][j]!=INF  && cost[i]!=INF && cost[j] > cost[i]+c[i][j]){
                        cost[j] =cost[i]+c[i][j];
                        pred[j]=i;
                    }
                }
            }
            path[k-1]=(n-1);
            for(int i=k-2;i>=0;--i){
                path=pred[path[i+1]];
            }

        }

        int main(){
            int n,k,e;
            cout<<"Enter the number of node and stage: ";
            cin>>n>>k;

            vector<vector<int>c(n,vector<int>(n,INF));
            cout<<"Enter the eadges : "<<endl;

            for(int i=0;i<e;++i){
                int u,v,w;
                cin>>u>>v>>w;
                c[u][v]=w;
            }


            vector<int>path(k),cost(n,INF);
            Forwardgraph(c,n,path,cost);

            cout<<"Minimum cost: "<<

        }