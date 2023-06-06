#
# arch.py
#
# This script implements three Python classes for three different artificial
# neural network architectures: no hidden layer, one hidden layer, and two
# hidden layers. Note that this script requires the installation of the
# PyTorch (torch) Python package.
#
# This content is protected and may not be shared, uploaded, or distributed.
#
# PLACE ANY COMMENTS, INCLUDING ACKNOWLEDGMENTS, HERE.
# ALSO, PROVIDE ANSWERS TO THE FOLLOWING TWO QUESTIONS.
# I received help from my TA, Ghazal, in understanding how to setup each type of network.
# architecture.

# Which network architecture achieves the lowest training set error?
# The artificial neural network with two hidden layers has the lowest training set error.
# Which network architecture tends to exhibit the best testing set accuracy?
# The artificial neural network with one hidden layer tends to exhibit the best testing set accuracy.
#
# PLACE YOUR NAME AND THE DATE HERE
# Jose Luciano 10 December 2021 5:27 PST

# PyTorch - Deep Learning Models
import torch.nn as nn
import torch.nn.functional as F


# Number of input features ...
input_size = 4
# Number of output classes ...
output_size = 3


class AnnLinear(nn.Module):
    """Class describing a linear artificial neural network, with no hidden
    layers, with inputs directly projecting to outputs."""

    def __init__(self):
        super().__init__()
        # PLACE NETWORK ARCHITECTURE CODE HERE
        self.my_layer = nn.Linear(in_features=4, out_features=3)

    def forward(self, x):
        # PLACE YOUR FORWARD PASS CODE HERE
        y_hat = F.relu(self.my_layer(x))
        return y_hat


class AnnOneHid(nn.Module):
    """Class describing an artificial neural network with one hidden layer,
    using the rectified linear (ReLU) activation function."""

    def __init__(self):
        super().__init__()
        # PLACE NETWORK ARCHITECTURE CODE HERE
        self.layer = nn.Linear(in_features=4, out_features=20)
        self.hidden_layer = nn.Linear(in_features=20, out_features=3)

    def forward(self, x):
        # PLACE YOUR FORWARD PASS CODE HERE
        layer_act = F.relu(self.layer(x))
        y_hat = self.hidden_layer(layer_act)
        return y_hat


class AnnTwoHid(nn.Module):
    """Class describing an artificial neural network with two hidden layers,
    using the rectified linear (ReLU) activation function."""

    def __init__(self):
        super().__init__()
        # PLACE NETWORK ARCHITECTURE CODE HERE
        self.layer = nn.Linear(in_features=4, out_features=16)
        self.hidden_layer = nn.Linear(in_features=16, out_features=12)
        self.hidden_layer2 = nn.Linear(in_features=12, out_features=3)

    def forward(self, x):
        # PLACE YOUR FORWARD PASS CODE HERE
        layer_act = F.relu(self.layer(x))
        hidden_layer_act = self.hidden_layer(layer_act)
        hidden_layer2_act = F.relu(hidden_layer_act)
        y_hat = self.hidden_layer2(hidden_layer2_act)

        return y_hat
