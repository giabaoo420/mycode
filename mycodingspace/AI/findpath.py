
#Heuristic Function: manhattan distance
def manhatdis(start, goal): 
   return abs(start[0] - goal[0]) + abs(start[1] - goal[1]) #manhattan distance is the sum of the absolute differences of the cartesian coordinate of 2 point
import heapq

def astar(citymap, start, goal):
    # Priority queue to store (cost, position)
    open_list = []
    closed_list = {}
    heapq.heappush(open_list, (0, start))
    
    # Cost from start to each cell
    g_costs = {start: 0}
    
    # Total cost from start to goal through each cell
    f_costs = {start: manhatdis(start, goal)}
    
    
    while len(open_list) > 0:
        # Get the cell with the lowest f_cost
        current_cost, current = heapq.heappop(open_list)
        
        # If we reached the goal, reconstruct the path
        if current == goal:
            return reconstruct_path(closed_list, current)
        
        # Explore neighbors
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:  # Up, Down, Left, Right
            othernode = (current[0] + dx, current[1] + dy)
            
            # Check if neighbor is within bounds and not an obstacle
            if (0 <= othernode[0] < len(citymap) and
                0 <= othernode[1] < len(citymap[0]) and
                citymap[othernode[0]][othernode[1]] == 0):
                
                # Calculate the cost from start to neighbor
                tentative_g_cost = g_costs[current] + 1
                
                # If this path to neighbor is better, record it
                if othernode not in g_costs or tentative_g_cost < g_costs[othernode]:
                    closed_list[othernode] = current
                    g_costs[othernode] = tentative_g_cost
                    f_costs[othernode] = tentative_g_cost + manhatdis(othernode, goal)
                    
                    # Add neighbor to the open set if not already there
                    if othernode not in [i[1] for i in open_list]:
                        heapq.heappush(open_list, (f_costs[othernode], othernode))
    
    return None  # No path found

def reconstruct_path(closed_list, current):
    total_path = [current]
    while current in closed_list:
        current = closed_list[current]
        total_path.append(current)
    return total_path[::-1]  # Return reversed path
# Example city map 1
citymap1 = [[0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 1, 0, 0, 0, 0],
            [0, 1, 0, 0, 0, 1, 1, 1, 1, 0],
            [0, 1, 0, 0, 0, 1, 0, 0, 0, 0],
            [0, 1, 1, 1, 1, 1, 0, 0, 0, 0],
            [0, 0, 0, 1, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 1, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 1, 0, 0, 1, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 1, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 1, 0, 0, 0]]

# Example city map 2
citymap2 = [[0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]
# Define start and goal locations
start_node = (0, 0)
goal_end1 = (8, 9)
goal_end2 = (7, 6)

# Test on city_map1
path_1 = astar(citymap1, start_node, goal_end1)
print("Path for city map 1:", path_1)

# Test on citymap2
path_2 = astar(citymap2, start_node, goal_end2)
print("Path for city map 2:", path_2)
