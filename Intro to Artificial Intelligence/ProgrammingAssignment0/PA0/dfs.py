#
# dfs.py
#
# This file provides a function implementing depth-first search for a
# route-finding problem. Various search utilities from "route.py" are
# used in this function, including the classes RouteProblem, Node, and
# Frontier.
# 
# YOUR COMMENTS INCLUDING CITATIONS
# Received help from Ghazal Zand during scheduled appointment
# YOUR NAME - THE DATE
# Jose Luciano - September 28,2021


from route import Node
from route import Frontier


def DFS(problem, repeat_check=False):
    """Perform depth-first search to solve the given route finding
    problem, returning a solution node in the search tree, corresponding
    to the goal location, if a solution is found. Only perform repeated
    state checking if the provided boolean argument is true."""

    # PLACE YOUR CODE HERE
    root = Node(problem.start)

    if problem.is_goal(root.loc):
        return root

    fifo = Frontier(root, True)
    if repeat_check:
        reached = [root.loc]

    while not fifo.is_empty():
        node = fifo.pop()
        if problem.is_goal(node.loc):
            return node
        node_list = node.expand(problem)
        for child in node_list:
            if repeat_check:
                if child.loc not in reached:
                    fifo.add(child)
                    reached.append(child.loc)
            else:
                fifo.add(child)

    return None
