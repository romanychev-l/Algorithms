/*
#include <algorithm>
#include <cstddef>
#include <iterator>
#include <memory>
#include <time.h>
#include <vector>
#include <deque>
*/
#include <bits/stdc++.h>

using namespace std;


typedef pair<int,int> rib;
typedef vector<vector<rib> > graph;

const int inf = 1000*1000*1000;

int main()
{
    cout << 0;
	int n = 5000, v1 = 0, W = 100000;
	int m = n * 100;
	graph g(n);
    srand(time(0));

	for(int i = 0; i<n; i++){
	    int w = rand() % W;
        g[i].push_back({i+1, w});
    };

    for(int i = n; i<m; i++){
        g[rand() % n].push_back({rand() % n, rand() % W});
    }

	vector<int> d(n, inf);
	d[v1] = 0;
	vector<int> id(n);
	deque<int> q;
	q.push_back (v1);
	vector<int> p(n, -1);

    int ans = 0;
	while (!q.empty())
	{
	    if(q.size() > ans){
            ans = q.size();
	    }
		int v = q.front();
		q.pop_front();
		id[v] = 1;
		for (size_t i=0; i<g[v].size(); ++i)
		{
			int to = g[v][i].first, len = g[v][i].second;
			if (d[to] > d[v] + len)
			{
				d[to] = d[v] + len;
				if (id[to] == 0)
					q.push_back(to);
				else if (id[to] == 1)
					q.push_front(to);
				p[to] = v;
				id[to] = 1;
			}
		}
	}

    cout << "OK " << ans;
    return 0;
}
