//
//  main.cpp
//  cpp
//
//  Created by Wu Penghui on 2020/9/3.
//  Copyright © 2020 Wu Penghui. All rights reserved.
//

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
struct exc
{
    double put,out;
    double op;
}e[1010];
bool cmp(const exc &a,const exc &b)
{
    if(a.op>b.op)return true;
    else return false;
}
int main()
{
    int n;
    double m;
    while(cin>>m)
    {
        if(m==-1)break;
        double now=m,sum=0.0;
        cin>>n;
        for(int i=0;i<n;++i)
        {
            cin>>e[i].out>>e[i].put;
            e[i].op=(e[i].out*1.0)/(e[i].put*1.0);
        }
        sort(e,e+n,cmp);
        for(int i=0;i<n;++i)
        {
            if(now>=e[i].put)
            {
                now-=e[i].put;
                sum+=e[i].out;
            }
            else
            {
                sum+=e[i].out*now/e[i].put;
                now=0;
            }
            if(!now)break;
        }
        cout<<setprecision(3)<<fixed<<sum<<endl;
    }
    return 0;
}
