// Copyright [2022] <Aprilschen>
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using pi = pair<int, int>;
#define pb push_back
#define f first
#define s second
#define endl '\n';

struct DSU {  // Disjoint sets union data structure w/ path compression
  int components; vi e;
  DSU(int n) {
    components = n;
    e = vi(n, -1);
  }

  int find(int x) {
    return e[x] < 0 ? x : e[x] = find(e[x]);
  }

  bool connected(int a, int b) {
    return find(a) == find(b);
  }

  bool connect(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) {
      return false;
    }

    if (e[x] > e[y]) {
      swap(x, y);
    }

    e[x] += e[y];
    e[y] = x;
    components -= 1;
    return true;
  }
};

struct Edge {  // Struct made for Edge List
  int a, b, w;

  Edge(int from, int to, int weight) {
    a = from; b = to; w = weight;
  }

  bool operator<(const Edge& other) const {
    return w < other.w;
  }
};

int nodes, edges;
const int INF = 1e9;  // One billion
const long long MXNODES = 1000;
vector<vector<Edge>> graph(MXNODES);
vector<vi> dist;
DSU dsu(MXNODES);

void printReport(bool reachable, vi atRiskNodes, vector<pi> atRiskEdges, long long minRepCost, vector<vi> MST) {  // prints the result of calculations
  cout << endl;
  cout << "Your results are ready: You may view them below:" << endl;
  cout << endl;
  cout << "<=====================================================>" << endl;
  cout << endl;
  cout << "ROAD CONNECTIVITY CHECK: " << endl;
  if (!reachable) {
    cout << "Your city is not fully connected via roads!" << endl;
    cout << "There might be one (or multiple) intersections which are not connected at all by a road." << endl;
    cout << "Perhaps you can find a way to fix it!" << endl;
    cout << endl;
  } else {
    cout << "Success! Proceeding to check 2" << endl;
    cout << endl;
  }

  if (reachable) {
    cout << "<=====================================================>" << endl;
    cout << endl;
    cout << "ROAD CONNECTIVITY CHECK--Pt 2:" << endl;

    bool allConnected = true;
    for (int i = 0; i < nodes; i++) {
      for (int j = 0; j < nodes; j++) {
        if (dist[i][j] == INF) {
          cout << "WARNING: INTERSECTION " << i << " CANNOT ACCESS INTERSECTION " << j << "!" << endl;
          allConnected = false;
        }
      }
    }

    if (allConnected) {
      cout << "Success! All roads can transitively access all other roads." << endl;
      cout << "Would you like to access the distance matrix? (type y/n)" << endl;
      cout << endl;
      char s; cin >> s;
      cout << endl;
      if (s == 'y') {
        cout << "the ith row and the jth column denote the minimum distance between intersections i and j!" << endl;
        for (int i = 0; i < dist.size(); i++) {
          for (int j = 0; j < dist[0].size(); j++) {
            cout << dist[i][j] << " ";
          }
          cout << endl;
        }
      }
    }

    // prints at-risk intersection and roads
    if (atRiskNodes.size() > 0) {
      cout << "WARNING: Some intersections, if disabled or rendered temporarily unusable, would split the city in half." << endl;
      cout << "A list of at-risk intersections are presented below:" << endl;
      cout << endl;
      for (int i = 0; i < atRiskNodes.size() - 1; i++) {
        cout << atRiskNodes[i] << ", ";
      }
      cout << atRiskNodes[atRiskNodes.size() - 1];
      cout << endl; cout << endl;
      cout << "Please consider adding precautions guarding against this potentially catastrophic event." << endl;
      cout << endl;
    }

    if (atRiskEdges.size() > 0) {
      cout << "WARNING: Some roads, if disabled or rendered temporarily unusable, would split the city in half." << endl;
      cout << "A list of at-risk roads are presented below:" << endl;
      cout << endl;
      for (int i = 0; i < atRiskEdges.size() - 1; i++) {
        cout << atRiskEdges[i].f << ", " << atRiskEdges[i].s << "; ";
      }
      cout << atRiskEdges[atRiskEdges.size() - 1].f << ", " << atRiskEdges[atRiskEdges.size() - 1].s;
      cout << endl; cout << endl;
      cout << "Please consider adding precautions guarding against this potentially catastrophic event." << endl;
      cout << endl;
    }

    cout << endl;
    cout << "The minimum distance of roads needed to connect all known intersections is " << minRepCost << endl;
    cout << "Here is one combination of connections which would give the minimum distance: " << endl;

    for (int i = 0; i < MST.size(); i++) {
      for (int j = 0; j < MST[i].size(); j++) {
        cout << i << ", " << MST[i][j] << "; ";
      }
    }
  }
  cout << endl; cout << endl;
  cout << "thank you for using April's City Planning Prototype!" << endl;
  cout << endl;
  cout << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cout << "Welcome to the April's city planning prototype!\nPlease input, as an integer, the total numbers of intersections and roads within your city: "<< endl;
  cin >> nodes >> edges;
  graph.resize(nodes);
  dsu.e.resize(nodes); dsu.components = dsu.e.size();
  dist.resize(nodes);
  for (int i = 0; i < dist.size(); i++) {
    dist[i].resize(nodes);
  }

  cout << "For every street, submit the following information:"<< endl;
  cout << "First, input whether your road is a one-way road: type in 0 for one way, and 1 for two way" << endl;
  cout << "Then, input the intersection this road travels to, and from, as well as the distance distance residing between those two intersection points." << endl;
  cout << "Please represent your intersections as a number between 0 to N-1 inclusive. The program will not work otherwise!" << endl;
  for (int i = 0; i < edges; i++) {  // Taking in user input of the edges
    int a, b, w, d;
    cin >> d;
    cin >> a >> b >> w;
    if (d == 1) {  // 0 for one way, 1 for two way
      graph[a].push_back(Edge(a, b, w));
      graph[b].push_back(Edge(b, a, w));
    } else {
      graph[a].push_back(Edge(a, b, w));
    }
    dsu.connect(a, b);
  }

  bool reachable = (dsu.components == 1);

  if (reachable) {  // O(N^2logN)
    // Determine whether one node is reachable via all other nodes
    for (int src = 0; src < nodes; src++) {  // run dijkstras for every node--store inputs into 2d vector dist
      for (int i = 0; i < nodes; i++) {
        dist[src][i] = INF;
      }
      priority_queue<Edge> pq;
      dist[src][src] = 0;
      pq.push({-1, src, 0});

      while (!pq.empty()) {
        Edge next = pq.top(); pq.pop();
        long cdist = next.w;  // NOLINT
        int node = next.b;

        if (cdist != dist[src][node]) continue;

        for (Edge i : graph[node]) {
          if (cdist + i.w < dist[src][i.b]) {
            dist[src][i.b] = cdist + i.w;
            pq.push({i.a, i.b, (int) (cdist + i.w)});
          }
        }
      }
    }
  }

  // test for at-risk roads and intersections
  vi atRiskNodes;
  for (int node = 0; node < nodes; node++) {
    DSU eDSU(nodes);
    for (int i = 0; i < graph.size(); i++) {
      for (int j = 0; j < graph[i].size(); j++) {
        Edge e = graph[i][j];
        if (graph[i][j].a != node && graph[i][j].b != node) {
          eDSU.connect(e.a, e.b);
        }
      }
    }
    if (eDSU.components > 2) {  // > 2 because one node is removed
      atRiskNodes.push_back(node);
    }
  }

  vector<pi> atRiskEdges;
  for (int a = 0; a < graph.size(); a++) {
    for (int b = 0; b < graph[a].size(); b++) {
      DSU eDSU(nodes);
      for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
          Edge e = graph[i][j];
          if (!(e.a == graph[a][b].a && e.b == graph[a][b].b) && !(e.b == graph[a][b].a && e.a == graph[a][b].b)) {
            eDSU.connect(e.a, e.b);
          }
        }
      }
      if (eDSU.components > 1) {
        atRiskEdges.push_back({graph[a][b].a, graph[a][b].b});
      }
    }
  }

  // kruskals algorithm, determines minimum-spanning tree
  long long minRepCost = 0;
  vector<vi> MST(nodes);

  if (reachable) {  // Kruskals algorithm
    priority_queue<Edge> pq;
    DSU kruskal(nodes);

    for (int i = 0; i < graph.size(); i++) {
      for (int j = 0; j < graph[i].size(); j++) {
        pq.push({graph[i][j].a, graph[i][j].b, graph[i][j].w});
      }
    }

    while (!pq.empty()) {
      if (kruskal.components == 1) {
          break;
      }
      Edge e = pq.top(); pq.pop();
      if (kruskal.find(e.a) != kruskal.find(e.b)) {
        MST[e.a].push_back(e.b);
        kruskal.connect(e.a, e.b);
        minRepCost += e.w;
      }
    }
  }
  printReport(reachable, atRiskNodes, atRiskEdges, minRepCost, MST);
}
