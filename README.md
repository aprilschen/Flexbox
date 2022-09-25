# Flexbox
# Copyright Aprilschen 2022!
C++ Program that provides instant, comprehensive, feedback on proposed cityscapes.
testCases.txt contains sample test cases which I used to debug the main program.
flexbox.cpp contains the actual program itself. I debugged and compiled it in gcc 7.5.0, along with the bits.stdc header.

## Inspiration
This project was actually inspired by some USACO problems which I had recently practicing! I decided to create a project about graphs, and connectivity because I thought that it would be an interesting project which would highlight my technical strengths as a competitive programmer.

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
I learned two things from this first hackathon experience:
1) I should diversity my technical skillset. My knowledge of web development, and especially full-stack work is weak compared to the top competitors at this Hackathon. In particular, I will need to learn how to connect Front-end UI and UX to back-end systems. In the future, I plan on learning React, and Node js / Express to diversity my skillset. I also plan on learning a couple useful API's to add more available tools which I can work with.

2) Next time I enter a hackathon, I will definitely plan on bringing friends and team partners! Team matching can be a pain, especially if most other already have a team and set plan. Hacking solo also limits the amount of work that I can get done, as I only have so much focus and time. If I had another two or three partners, I would definitely be able to push out a much more fleshed out, polished product.

## What's next for Flexbox: Rapid Prototyping Application for Urban Planning
I plan on developing a website, and front-end for this program, using node js to plug in my c++ file to the site. This will probably occur within the next week or so, depending on available free time, motivation, etc.
Thanks for reading!
