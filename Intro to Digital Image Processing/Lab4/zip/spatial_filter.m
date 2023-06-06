function out = spatial_filter(A,B)
% spatial_filter: Applies spatial filter to greyscale image
% 
% Syntax: 
%   out = spatial_filter(A,B)
%
% Input:
%   A = Greyscale image (matrix) with intensity values ranging from 0-255
%   B = Spatial filter (matrix)
%
% Output:
%   out = Outputs an image of type double with same dimensions as input
%   image
% History:
%   Jose Luciano - Created function spatial_filter April 22, 2022

% getting dimensions of image and filter
[r c] = size(A);
[r3 c3] = size(B);

% creating a matrix of type double
out = double(zeros(r,c));

% calculating the amount of rows and columns to add for zero-padding
z_pad = 2*floor(r3/2);
% adding the extra rows and columns of zeros for zero-padding
temp = double(zeros(r+z_pad,c+z_pad));
% getting dimensions of matrix with zero-padding
[r2 c2] = size(temp);
% inputting values from original matrix
temp((z_pad/2+1):r2-(z_pad/2),(z_pad/2+1):c2-(z_pad/2)) = A;

% traversing every pixel of greyscale image
for row = 1:r
    for col = 1:c
        % resetting sum after moving to a different pixel
        sum = 0;
        %resetting value to start from beginning of spatial filter
        x = 0;
        for r = row:row+(r3-1)
            %updating row and resetting y when going to next row in spatial
            %filter
            x = x+1;
            y = 0;
            for s = col:col+(c3-1)
                y = y+1;
                %formula from book, equation 3.4
                sum = sum+(temp(r,s)*B(x,y));
            end
        end
        % updating matrix with values calculated using equation 3.4
        out(row,col) = sum;
    end
end
end

