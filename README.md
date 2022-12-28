# Flexbox
C++ Program that provides instant, comprehensive, feedback on proposed cityscapes.
testCases.txt contains sample test cases which I used to debug the main program.
flexbox.cpp contains the actual program itself. I debugged and compiled it in gcc 7.5.0, along with the bits.stdc header.

## Inspiration
This project was actually inspired by USACO problems which I had recently practicing. I decided to create a project about graphs, and connectivity since maps/graphs-related problems had always interested me.

## What it does
Flexbox receives basic topographic information about a given area and returns unique insights on its Urban Design. It uses the Union Find data structure, as well as Dijkstra's and Kruskal's algorithms to compute connectivity, shortest paths and the minimum spanning tree. The program contains 4 main functions:
1) Determine whether all intersections are connected to eachother via directed or undirected roads
2) Determine whether a given node can reach all other nodes through some transitive path
3) Determine intersections and roads which were "at risk" (that is, determine the intersections and roads which, when removed, would split the city into two disjoint components)
4) Determine the minimum spanning tree (that is, determine the minimum amount of road which would need to be laid so that all nodes can be accessed somehow)

## How we built it
I began by building and debugging the input system. Afterwards, I moved onto the DSU structure, Dijkstras, and finally the Kruskals algorithms. A lot of debugging, and testing went into this program-- Since I rarely use these algorithms, I received a lot of help from online resources and textbooks.

## Accomplishments that we're proud of
I'm proud of getting through my first hackathon, and making many friends and acquaintances along the way! I'm also proud of actually putting out my first project, which I managed to complete solo. Going into this Hackathon, I had thought that I needed a team to succeed and that I lacked the skills to put out a successful project by myself.

## What we learned
1) My knowledge of everything besides algorithms is weak. In particular, I will need to learn how to connect Front-end UI and UX to back-end systems. In the future, I plan on learning React, and Node js / Express to diversity my skillset. I also plan on learning a couple useful API's to add more available tools which I can work with.

2) Next time I enter a hackathon, I will definitely plan on bringing friends and team partners! Team matching can be a pain, especially if most other already have a team and set plan. Hacking solo also limits the amount of work that I can get done, as I only have so much focus and time. If I had another two or three partners, I would definitely be able to push out a much more fleshed out, polished product.
