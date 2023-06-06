#
# heuristic.py
#
# This Python script file provides two functions in support of minimax search
# using the expected value of game states. First, the file provides the
# function "expected_value_over_delays". This function takes as an argument
# a state of game play in which the current player has just selected an
# action. The function calculates the expected value of the state over all
# possible random results determining the amount of time before the
# Guardian changes gaze direction. This function calculates this value
# regardless of whose turn it is. The value of game states that result from
# different random outcomes is determined by calling "value". Second, the
# file provides a heuristic evaluation function for non-terminal game states.
# The heuristic value returned is between "max_payoff" (best for the
# computer player) and negative one times that value (best for the opponent).
# The heuristic function may be applied to any state of play. It uses
# features of the game state to predict the game payoff without performing
# any look-ahead search.
#
# This content is protected and may not be shared, uploaded, or distributed.
#
# PLACE ANY COMMENTS, INCLUDING ACKNOWLEDGMENTS, HERE
#
# PLACE YOUR NAME AND THE DATE HERE
# Jose Luciano Fri November 19 2021


from parameters import *
from minimax import probability_of_time
from minimax import value


def expected_value_over_delays(state, ply):
    """Calculate the expected utility over all possible randomly selected
    Guardian delay times, ranging from 2 to 5 steps. Return this expected
    utility value."""
    val = 0.0

    # PLACE YOUR CODE HERE
    # Note that the value of "ply" must be passed along, without
    # modification, to any function calls that calculate the value 
    # of a state.

    delay = [2, 3, 4, 5]
    for chance in delay:
        state.time_remaining = chance
        val = val + (probability_of_time(chance) * value(state, ply))
        if state.time_remaining == 5:
            return val

    return val


def heuristic_value(state):
    """Return an estimate of the expected payoff for the given state of
    game play without performing any look-ahead search. This value must
    be between the maximum payoff value and the additive inverse of the
    maximum payoff."""
    val = 0.0

    # PLACE YOUR CODE HERE
    if state.e_loc > (-1 * state.w_loc):
        val = ((board_size - state.w_loc * -1)/board_size * 100)

    else:
        if state.e_loc < board_size / 2:
            val = -1 * ((board_size - state.e_loc)/board_size * 100)
        else:
            val = -1 * ((board_size - (-1 * state.w_loc - state.e_loc) / board_size) * 100)

    return val
