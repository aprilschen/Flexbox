# Flexbox
Flexbox is a C++ Program which implements common graph algorithms to determine critical failure points in a city. 
testCases.txt contains sample test cases which I used to debug the main program.
flexbox.cpp contains the program. I debugged and compiled it in gcc 7.5.0, using the bits.stdc header.

## What it does
Flexbox receives basic topographic information about a given area and returns unique insights on its Urban Design. It uses the Union Find data structure, as well as Dijkstra's and Kruskal's algorithms to compute connectivity, shortest paths and the minimum spanning tree. The program contains 4 main functions:
1) Determine whether all intersections are connected to eachother via directed or undirected roads
2) Determine whether a given node can reach all other nodes through some transitive path
3) Determine intersections and roads which were "at risk" (that is, determine the intersections and roads which, when removed, would split the city into two disjoint components)
4) Determine the minimum spanning tree (that is, determine the minimum amount of road which would need to be laid so that all nodes can be accessed somehow)
