#include<bits/stdc++.h>
using namespace std;
int main()
{

    int no_of_trans, friends;
    cin>>no_of_trans>>friends;
    int x,y,amount;
    //Make oneD array to store the net amount that each person will have to take at the end
    int net[100000] = {0};
    while(no_of_trans--)
    {
        cin>>x>>y>>amount;
        net[x]-=amount;
        net[y]+=amount;
    }
    multiset<int> m;
    //Initialize a list and sort it => multiset
    for(int i =0 ;i<friends; i++)
    {
        if(net[i]!= 0)
        {
            m.insert(net[i]);
        }
    }
    //pop out two persons and try to settle them
    int cnt = 0;
    while(!m.empty())
    {
        auto low = m.begin();
        auto high = prev(m.end());
        int debit = *low;
        int credit = *high;
        
        //erase
        m.erase(low);
        m.erase(high);
        
        //settlement
        int settlement_amount = min(-debit,credit);
        cnt++;
        
        //settlement from donor to acceptor
        debit += settlement_amount;
        credit -=settlement_amount;
        
        
        if(debit!=0)
        {
            m.insert(debit);    
        }
        
        if(credit!=0)
        {
            m.insert(credit);    
        }
        
        
    }
    cout<<cnt<<endl;

return 0;
}