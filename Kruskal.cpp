#include <bits/stdc++.h>

using namespace std;

int main(){
    clock_t start = clock();

    int m = 100, n = 3500, W = 100000;

    vector<pair<int, pair<int,int> > > g;

    vector<vector<int> > graph(n, vector<int> (n, 0));

    //Generate a random graph as a list of edges
    for(int i = 0; i<n; i++)
        for(int j = i+1; j<n; j++)
                g.push_back({rand() % W, {i, j}});

    //Kraskal Algorithm
    int cost = 0;
    vector < pair<int,int> > res;

    sort (g.begin(), g.end());
    vector<int> tree_id(n);
    for (int i=0; i<n; ++i)
    	tree_id[i] = i;
    for (int i=0; i<g.size(); ++i)
    {
    	int a = g[i].second.first,  b = g[i].second.second,  l = g[i].first;
    	if (tree_id[a] != tree_id[b])
    	{
    		cost += l;
    		res.push_back (make_pair (a, b));
    		int old_id = tree_id[b],  new_id = tree_id[a];
    		for (int j=0; j<n; ++j)
    			if (tree_id[j] == old_id)
    				tree_id[j] = new_id;
    	}
    }

    //Display the number of ribs in the minimum skeleton
    cout << res.size() << "\n\n";

    //Вывод всех ребер
    /*
    for (int i = 0; i<res.size(); i++)
        cout << i << ' ' << res[i].first << ' ' << res[i].second << '\n';
    */

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    cout << seconds << '\n';

    cin >> n;
}
