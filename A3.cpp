/*
 * Problem Statement :- Write a program to solve a 0-1 Knapsack problem using dynamic
 * 						programming or branch and bound strategy.
 *
 * Time complexity  : O(n*c)      (n=>number of elements  c=>capacity of knapsack)
 * Space Complexity : O(n*c)
 */

#include<bits/stdc++.h>
using namespace std;

int rec(vector<int>& wt, vector<int>&val,int i, int w, vector<vector<int>>& dp)
{
    if(i==wt.size()) return 0;
    if(w==0) return 0;
    if(dp[i][w]!=-1)
        return dp[i][w];
    if(w<wt[i])
        return rec(wt,val,i+1,w,dp);
    int l,r;
    l=val[i]+rec(wt,val,i+1,w-wt[i],dp);
    r=rec(wt,val,i+1,w,dp);
    return dp[i][w]=max(l,r);
}
int main()
{
	int n, c;

	cout<<"\n\t Enter number of elements : ";
	cin>>n;
    cout<<"\n\t Enter the capacity of knapsack : ";
    cin>>c;

    vector<int> wt(n, 0), val(n, 0);

    cout<<"\n\t Enter the value/cost of all elements : ";
    for(int i=0; i<n; i++) cin>>val[i];

    cout<<"\n\t Enter the weight of all elements : ";
    for(int i=0; i<n; i++) cin>>wt[i];
    vector<vector<int>>dp(n+1,vector<int>(c+1,-1));

    int max_val=rec(wt,val,0,c,dp);
    cout<<"\n\t Maximum total value in the knapsack : "<<max_val<<endl;
}