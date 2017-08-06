#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>


#define MOD 1000000007
#define ll long long
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define pll pair<long long,long long>
#define PI 3.14159

using namespace std;
ll solve(ll x,ll y,ll x1,ll y1){
    return sqrt(pow(abs(x-x1),2)+pow(abs(y-y1),2));
}
int main() {
	// your code goes here
    ll no_of_means,no_of_datapoints;
    cin>>no_of_datapoints;
    vector< pair<ll,ll> >data(no_of_datapoints);
    vector< pair<double,double> > meanvec;
    for(ll i=0;i<no_of_datapoints;i++){
        cin>>data[i].F>>data[i].S;
    }
    cin>>no_of_means;
    vector< pair<ll,ll> >cluster[no_of_means];
    set< pair<double,double> >means;
    for(ll i=0;i<no_of_means;i++){
        ll ind=rand()%no_of_datapoints;
		while(means.find(data[ind])!=means.end()) {
			ind=rand()%no_of_datapoints;
		}
		meanvec.pb(mp(data[ind].F,data[ind].S));
		means.insert(mp(data[ind].F,data[ind].S));
    }
    cout<<"Randomly calculated means are as follows:\n";
    for(ll i=0;i<meanvec.size();i++){
        cout<<meanvec[i].F<<","<<meanvec[i].S<<" ";
    }
    cout<<endl;
    while(1){
           
        bool check=false;
        for(ll i=0;i<no_of_means;i++){
            cluster[i].clear();
        }
        vector< pair<double,double> >new_means;
        for(ll i=0;i<no_of_datapoints;i++){
            ll mini=1e9;
            ll pos=-1;
            for(ll j=0;j<meanvec.size();j++){
                ll dist=solve(data[i].F,data[i].S,meanvec[j].F,meanvec[j].S);
                if(dist<mini){
                    mini=dist;
                    pos=j;
                }
            }
            cluster[pos].pb(mp(data[i].F,data[i].S));
        }
        for(ll i=0;i<no_of_means;i++){
             sort(cluster[i].begin(),cluster[i].end());
             double totmeanx=0.0,totmeany=0.0;
             ll totsumx=0,totsumy=0;
             for(ll j=0;j<cluster[i].size();j++){
                 totsumx+=cluster[i][j].F;
                 totsumy+=cluster[i][j].S;
             }
             totmeanx=totsumx*1.0/cluster[i].size();
             totmeany=totsumy*1.0/cluster[i].size();
             new_means.pb(mp(totmeanx,totmeany));
        }
        for(ll i=0;i<new_means.size();i++){
            if(new_means[i].F!=meanvec[i].F || new_means[i].S!=meanvec[i].S){
                check=true;
            }
            meanvec[i].F=new_means[i].F;
            meanvec[i].S=new_means[i].S;
        }
        if(!check){
            break;
        }
    }    
        cout<<"Clusters formed are as follows:\n";
        for(ll i=0;i<no_of_means;i++){
            cout<<"Cluster "<<i+1<<": ";
            for(ll j=0;j<cluster[i].size();j++){
                cout<<cluster[i][j].F<<","<<cluster[i][j].S<<" ";
            }
            cout<<"\n";
            cout<<"Mean: ";
            cout<<meanvec[i].F<<","<<meanvec[i].S<<endl;
        }   
    
    
    
    
	return 0;
}
