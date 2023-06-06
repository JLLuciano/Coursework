#
# heuristic.py
#
# This script defines a utility class that can be used as an implementation
# of a frontier state (location) evaluation function for use in route-finding
# heuristic search algorithms. When a HeuristicSearch object is created,
# initialization code can be executed to prepare for the use of the heuristic
# during search. In particular, a RouteProblem object is typically provided 
# when the HeuristicFunction is created, providing information potentially
# useful for initialization. The actual heuristic cost function, simply
# called "h_cost", takes a state (location) as an argument.
#
# YOUR COMMENTS INCLUDING CITATIONS
# I received help from my TA, Ghazal Zand, during our zoom meeting call. I was informed how the algorithms
# # # will utilize sort_by, h_cost, and path_cost.
# YOUR NAME - THE DATE
# Jose Luciano Tuesday October 19, 2021


import route


class HeuristicFunction:
    """A heuristic function object contains the information needed to
    evaluate a state (location) in terms of its proximity to an optimal
    goal state."""

    def __init__(self, problem=None):
        self.problem = problem
        # PLACE ANY INITIALIZATION CODE HERE
        self.cost = problem.map
        self.time = 0
        time = 0
        count = 0
        places = problem.map.locations()
        visit = []
        visit2 = []
        for unknown in places:
            road = problem.action_cost(unknown, end=None)
            visit.append(unknown)
            for segment in road:
                if unknown in visit or visit2:
                    count += 1
                time = time + problem.action_cost(unknown, segment)
                count += 1
                visit2.append(segment)
        self.time = time/count

    def h_cost(self, loc=None):
        """An admissible heuristic function, estimating the cost from
        the specified location to the goal state of the problem."""
        # a heuristic value of zero is admissible but not informative
        value = 0.0
        if loc is None:
            return value
        else:
            # PLACE YOUR CODE FOR CALCULATING value OF loc HERE
            # value = self.problem.map.euclidean_distance(loc, self.problem.goal)
            # value = self.cost.euclidean_distance(loc, self.problem.goal)/4.8
            value = self.cost.euclidean_distance(loc, self.problem.goal)/self.time
            return value

