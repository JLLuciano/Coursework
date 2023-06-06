function edges = find_edges(A, t)
% find_edges : Detects edges of an image by applying a threshold to the
% magnitude of the gradient
%
% Syntax:
%   edges = find_edges(A,t)
% Input:
%   A = greyscale image (matrix)
%   t = threshold value (scalar)
%
% Output:
%   edges = Binary image (255 and 0)containing the location of where edges
%   were detected
% History:
%   Jose Luciano - Created function find_edges April 23,2022

%getting dimensions of image
[r c] = size(A);

% calculating magnitude of gradient
g = gradient_magnitude(A);

edges = uint8(zeros(r, c));

for i= 1:r
    for j = 1:c
        %if edge is greater than threshold set value to 255 else 0
        if (g(i,j)>t)
            
            edges(i,j)=255;
            
        else
            edges(i,j) = 0;
        end

    end 
end
end