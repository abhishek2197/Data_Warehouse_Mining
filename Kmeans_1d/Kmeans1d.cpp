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

int main() {
	// your code goes here
    ll no_of_means,no_of_datapoints;
    cin>>no_of_datapoints;
    vector<ll>data(no_of_datapoints);
    vector<double>meanvec;
    for(ll i=0;i<no_of_datapoints;i++){
        cin>>data[i];
    }
    cin>>no_of_means;
    vector<ll>cluster[no_of_means];
    set<double>means;
    for(ll i=0;i<no_of_means;i++){
        ll ind=rand()%no_of_datapoints;
		while(means.find(data[ind])!=means.end()) {
			ind=rand()%no_of_datapoints;
		}
		meanvec.pb(data[ind]);

		means.insert(data[ind]);
    }
    cout<<"Randomly calculated means are as follows:\n";
    for(ll i=0;i<meanvec.size();i++){
        cout<<meanvec[i]<<" ";
    }
    cout<<endl;
    while(1){
           
        bool check=false;
        for(ll i=0;i<no_of_means;i++){
            cluster[i].clear();
        }
        vector<double>new_means;
        for(ll i=0;i<no_of_datapoints;i++){
            ll mini=1e9;
            ll pos=-1;
            for(ll j=0;j<meanvec.size();j++){
                if(abs(data[i]-meanvec[j])<mini){
                    mini=abs(data[i]-meanvec[i]);
                    pos=j;
                }
            }
            cluster[pos].pb(data[i]);
        }
        for(ll i=0;i<no_of_means;i++){
             sort(cluster[i].begin(),cluster[i].end());
             double totmean=0.0;
             ll totsum=0;
             for(ll j=0;j<cluster[i].size();j++){
                 totsum+=cluster[i][j];
             }
             totmean=totsum*1.0/cluster[i].size();
             new_means.pb(totmean);
        }
        for(ll i=0;i<new_means.size();i++){
            if(new_means[i]!=meanvec[i]){
                check=true;
            }
            meanvec[i]=new_means[i];
        }
        if(!check){
            break;
        }
    }    
        cout<<"Clusters formed are as follows:\n";
        for(ll i=0;i<no_of_means;i++){
            cout<<"Cluster "<<i+1<<": ";
            for(ll j=0;j<cluster[i].size();j++){
                cout<<cluster[i][j]<<" ";
            }
            cout<<"\n";
            cout<<"Mean: ";
            cout<<meanvec[i]<<endl;
        }   
    
    
    
    
	return 0;
}
