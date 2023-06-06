%% histogram_transform.m
function T = histogram_transform(A)
% histogram_transform Computes the transformation function for histogram
%                     equalization
% 
% Syntax:
%   T = histogram_transform(A);
%
% Input:
%   A = a normalized histogram
%
% Output:
%   T = a length 256 vector which represents the transformation function
%       for histogram equalization
%
% History:
%   Jose Luciano - Created histogram_tranform function 4/9/2022
T = uint8(zeros(256,1));
sum = 0;
for x = 1:256
    sum = sum + A(x,1);
    T(x,1) = 255*sum; %use the equation from textbook
end
end