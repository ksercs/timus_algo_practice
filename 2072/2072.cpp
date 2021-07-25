#include <iostream>
#include <algorithm>
#include <utility>
#include <set>
#include <map>

using namespace std;

int n, last_ind=1;
long long ans;

set <int> st;
set <int>:: iterator it;
map <int, set <int> > mp;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int ch;
        cin >> ch;
        st.insert(ch);
        mp[ch].insert(i);
    }
    for (it = st.begin(); it != st.end(); it++)
    {
        set <int>:: iterator frst;
        set <int>:: reverse_iterator lst;
        int zn = (*it);
        lst = mp[zn].rbegin(), frst = mp[zn].begin();
        if (abs(last_ind-(*frst)) > abs(last_ind-(*lst)))
        {
            set <int>:: reverse_iterator iter;
            for (iter = lst; iter != mp[zn].rend(); iter++)
            {
                //cout << *iter << "\n"; system("PAUSE");
                ans +=1 + abs(last_ind-(*iter));
                last_ind = (*iter);
            }
        }
        else
        {
            set <int>:: iterator iter;
            for (iter = frst; iter != mp[zn].end(); iter++)
            {
                ans +=1 + abs(last_ind-(*iter));
                last_ind = (*iter);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
