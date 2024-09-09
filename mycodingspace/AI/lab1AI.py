import heapq

#Heuristic Function: Chebyshev distance (By implementing the Chebyshev distance as our heuristic function we can find the most efficient path,
#Chebyshev distance works really well with object that is not restricted to move diagonally in this case is our drone which can move freely since its in the air
#but chebyshev distance could have some limitation like the lack of smoothing path where chebyshev distance path could be jagged due to it grid based movement.
def chebyshevdistance(start, goal):
    return max(abs(start[0] - goal[0]), abs(start[1] - goal[1]))

#function to reconstruct the path from end back to start
def reconstructpath(closedlist, current):
    totalpath = [current]
    while current in closedlist:
        current = closedlist[current]
        totalpath.append(current)
    return totalpath[::-1]  # Return reversed path which is from start to end

#function to visualize map
def visualize(citymap, path):
    visualmap = [row[:] for row in citymap]  #copy of the city map
    for (x, y) in path:
        visualmap[x][y] = 'p'  # Mark the path with 'p'
    for row in visualmap:
        print(' '.join(str(cell) for cell in row)) #print each row of the visual map
    print()

def astar(citymap, start, goal):
    openlist = [] #priority queue to keep track of all the nodes to explore based on their cost
    closedlist = {} 
    heapq.heappush(openlist, (0, start)) #add the starting node with a cost of 0
    
    pathcosts = {start: 0} #Cost from start to each cell
    totalcosts = {start: chebyshevdistance(start, goal)} #Total estimated cost from start to goal 
    
    while openlist: #loop so that it will go through every single node
        currentcost, current = heapq.heappop(openlist) #get the node with the lowest cost from the open list
        if current == goal: #If reach the goal then reconstruct the path
            return reconstructpath(closedlist, current)
        
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (-1, 1), (1, -1), (1, 1)]: #Explore neighbour node (including diagonals)
            neighbournode = (current[0] + dx, current[1] + dy) #calculate the position of the neighbouring node
            
            if (0 <= neighbournode[0] < len(citymap) and 0 <= neighbournode[1] < len(citymap[0]) and citymap[neighbournode[0]][neighbournode[1]] == 0):  #Check if other node is within range and not an obstacle
                # Calculate the cost from start to neighbour node
                tmp_pathcost = pathcosts[current] + (1.414 if dx != 0 and dy != 0 else 1)  # Diagonal move cost more therefor it will be 1.414 (the square root of 2)
                # If path to neighbour node is better, record it
                if neighbournode not in pathcosts or tmp_pathcost < pathcosts[neighbournode]:
                    closedlist[neighbournode] = current # save the best path to this neighbour
                    pathcosts[neighbournode] = tmp_pathcost #update cost to move to this neighbour node
                    totalcosts[neighbournode] = tmp_pathcost + chebyshevdistance(neighbournode, goal) #calculate the total estimated cost from this node to end
                    # Add neighbour node to the open list if not already there
                    if neighbournode not in [i[1] for i in openlist]:
                        heapq.heappush(openlist, (totalcosts[neighbournode], neighbournode))
    
    return None  # No path found

#city map 1
citymap1 =  [[0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0],
             [0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0],
             [0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0],
             [1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0],
             [0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1],
             [0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0],
             [0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0],
             [0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1],
             [1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0],
             [0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0],
             [0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0],
             [1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0],
             [0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0],
             [0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0]]

#city map 2
citymap2 = [[0, 0, 1, 0, 0, 0],
            [1, 0, 1, 0, 1, 0],
            [0, 0, 0, 1, 0, 0],
            [0, 1, 1, 0, 0, 0],
            [0, 0, 0, 1, 1, 0],
            [0, 0, 0, 0, 0, 0]]

#city map 3
citymap3 = [[0, 0, 1, 0, 0, 0, 0, 0, 0, 0],
            [0, 1, 1, 1, 1, 1, 1, 1, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
            [0, 1, 1, 1, 1, 0, 0, 1, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 1, 1, 0],
            [0, 1, 1, 1, 1, 1, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 1, 1, 1, 1, 0],
            [0, 1, 1, 1, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 1, 1, 1, 1, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]

#start and goal positions
startnode = (0, 0)
endnode1 = (13, 12)
endnode2 = (5, 3)
endnode3 = (9, 8)

#implementing a* pathfinding algorithm on citymap1-3
path1 = astar(citymap1, startnode, endnode1)
path2 = astar(citymap2, startnode, endnode2)
path3 = astar(citymap3, startnode, endnode3)

#print out path for each map
print("city map 1 path:", path1)
print("city map 2 path:", path2)
print("city map 3 path:", path3)

#visualize path for every map
print("city map 1:")
visualize(citymap1, path1)
print("city map 2:")
visualize(citymap2, path2)
print("city map 3:")
visualize(citymap3, path3)