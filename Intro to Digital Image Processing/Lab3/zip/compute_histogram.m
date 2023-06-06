%% compute_histogram.m
function h = compute_histogram(A)
% compute_histogram Compute the normalized histogram of the image
%
% Syntax:
%   h = compute_histogram(A);
%
% Input:
%   A =  greyscale image with intensity values from 0-255 
%
% Output:
%   h = a vector of length 256 which is the normalized histogram of the
%       greyscale image
% History:
%   Jose Luciano - Created compute_histogram function 4/9/2022
[r c] = size(A);
%initialize histogram
h = double(zeros(256,1));
for x = 1:r
    for y = 1:c
        index = A(x,y);
        if index == 0
            index = 1;
        end
        %count how many times each value appears
        h(index,1) = h(index,1) + 1;
     
    end
end
%normalization
for x = 1:256
    h(x,1) = h(x,1)./(r*c);
end
end