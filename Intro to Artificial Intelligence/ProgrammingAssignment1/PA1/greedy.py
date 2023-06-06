#
# greedy.py
#
# This file provides a function implementing greedy best-first search for
# a route finding problem. Various search utilities from "route.py" are
# used in this function, including the classes RouteProblem, Node, and
# Frontier. Also, this function uses heuristic function objects defined
# in the "heuristic.py" file.
#
# YOUR COMMENTS INCLUDING CITATIONS
# I received help from my TA, Ghazal Zand, during our zoom meeting call. I was informed how the algorithms
# # will utilize sort_by, h_cost, and path_cost. Furthermore, I copy and pasted my BFS.py from ProgrammingAssignment0
# and modified it for each algorithm.
# YOUR NAME - THE DATE
# Jose Luciano Tuesday October 19, 2021


from route import Node
from route import Frontier


def greedy_search(problem, h, repeat_check=False):
    """Perform greedy best-first search to solve the given route finding
    problem, returning a solution node in the search tree, corresponding
    to the goal location, if a solution is found. Only perform repeated
    state checking if the provided boolean argument is true."""

    # PLACE YOUR CODE HERE
    root = Node(problem.start)
    fifo = Frontier(root, sort_by='h')
    reached = [root.loc]

    if problem.is_goal(root.loc):
        return root

    while not fifo.is_empty():
        node = fifo.pop()
        if problem.is_goal(node.loc):
            return node
        node_list = node.expand(problem, h_fun=h)
        for child in node_list:
            if repeat_check:
                if child.loc not in reached:
                    reached.append(child.loc)
                    fifo.add(child)
            else:
                fifo.add(child)

    return None
