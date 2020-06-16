#include<bits/stdc++.h>
#define mp make_pair
#define lli long long int
#define ulli unsigned long long int
#define dout if(debug)cout<<" "
#define mod 1000000007
using namespace std;

int vrt(int n, vector<vector<int>>paths, vector<vector<int>>queries){
  vector<int> visited(n+1);
  vector<int> parent(n+1);
  fill(visited.begin(), visited.end(), 0);
  fill(parent.begin(), parent.end(), 0);
  vector<vector<int>>graph(n+1);
  for(int i = 0; i < paths.size(); i++){
    graph[paths[i][0]].push_back(paths[i][1]);
    graph[paths[i][1]].push_back(paths[i][0]);
  }

  int curr_par;
  queue<int>bfs;
  for(int i = 1; i < graph.size(); i++){
    if(visited[i] == 0){
      curr_par = i;
      bfs.push(i);
      while(!bfs.empty()){
        int node = bfs.front();
        visited[node] = 1;
        parent[node] =  curr_par;
        for(int i = 0; i < graph[node].size(); i++){
          if(!visited[graph[node][i]]){
            bfs.push(graph[node][i]);
            visited[graph[node][i]] = 1;
          }
        }
        bfs.pop();
      }
    }
  }

  int ans = 0;
  for(int i = 0; i < queries.size(); i++){
    if(parent[queries[i][0]] == parent[queries[i][1]]){
      ans++;
    }
  }

  return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	t=1;
	//cin >> t;
	while(t--){
    int n;
    cin >> n;
    
    int total_paths;
    cin >> total_paths;
    vector<vector<int>>paths(total_paths);
    for(int i = 0; i < total_paths; i++){
      vector<int> vertices(2);
      cin >> vertices[0] >> vertices[1];
      paths[i] = vertices;
    }

    int total_queries;
    cin >> total_queries;
    vector<vector<int>> queries(total_queries);
    for(int i = 0; i < total_queries; i++){
      vector<int>query(2);
      cin >> query[0] >> query[1];
      queries[i] = query;
    }

    int ans = vrt(n, paths, queries);
    cout << ans << endl;
	}
	return 0;
}
