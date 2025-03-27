Lecture Notes 3/27/2025

- Last class we talked about Dij Algorithm 

- The next mid-term is on _______, to prepare for the exam
- the deadline for the exam is next Sunday, he will send this to us to help with the exam

- Today we are talking about Spanning Tree 
- Definition: Given a connected graph G=(V,E), can we find a subset of edges such that the graph is still connceted?

- Can we do anything like this?
- If we ask for anykind of subset , 
- Minimum Spanning Tree - Given a connected graph G=(V,E), can we find a minimal subset of the edges such that the graph is still
connected?

- Is there anything that we can do about this, 
- lets say we have a graph that hass 10,000 nodes, can we use an algorithm that we have discussed before, 
- BFS, or DFS something starts from one node, and tries to traverse all nodes
- if you traverse, will you visit any node more than once, no


- when you are implementing a minimal spanning tree, the numer of edges will be the number of nodes - 1
 - BFS and DFS, is what we can use when the graph has no weights, the edges are not weighted

- but if we have a graph, where the edges have weights, in a weighted graph, can we find a minimal subset of the edges such that
the graph is still connected?
- They want us to find a way to connect all houses, in some small town, you have to build a network or roads, so you dont spend a
lot of money, but all houses are still connected to each other

- If a graph has V vertices, how mand edges will the min spanning tree have? = v-1 edges

- Prims Algorithm, 
- Select an arbitraty node
- Mark it as known
- Grow tree by adding an edge from "known" vertices to "unknwon" vertices
- pick edge wil smallest wight that connected known to unknown
- when all the nodes are connected, we have the MST

- in the example, if we start with S -- C, because the cost between them was the lowest
- From C--B, 

- in Djistkras algorithm, how is it different than Prims Algorithm

- in Prims we are only considering the lenght of the edge, but in priority queue 
- we are not considering the full length, in Prims we are only consideted with the minimal lenght of the available edges


-Prims Algorithm
For each node V:
V.cost = infinity
v.known = flase
choose any node v:
  Mark v as known
  For each edge (v, u) with weight w:
  u.cost = w
  u.conn = v
While there are unknown noes in the graph:
  Select unknown node v with lowest cost
....


- Kruskals Algorithm Idea
- Select the smalled "unused" edge 
- Check if hey are connecting two unconnected part of the graph
  if yes , use that edge
- repeat these steps until the graph is connected




