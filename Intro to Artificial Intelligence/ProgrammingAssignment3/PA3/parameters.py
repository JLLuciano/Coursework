#
# parameters.py
#
# This Python script file gathers together parameters for the minimax
# solution to the Guardian Game.
#
# This content is protected and may not be shared, uploaded, or distributed.
#
# David Noelle - Mon Nov  1 11:11:01 PDT 2021
#


from enum import Enum


# player identity, West player or East player ...
Player = Enum('Player', 'west east')

# The number of steps each player starts from the Guardian ...
board_size = 13

# The minimum and maximum action selection steps ...
min_steps = 1
max_steps = 4

# The maximum payoff value, symmetric around zero ...
max_payoff = 100.0

# maximum number of ply to search before applying heuristic ...
max_ply = 3
