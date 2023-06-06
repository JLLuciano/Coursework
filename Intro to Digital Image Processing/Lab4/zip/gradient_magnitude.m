function g = gradient_magnitude(A)
% gradient_magnitude: Returns the magnitude of the gradient 
%
% Syntax: g = gradient_magnitude(A);
% 
% Input:
%   A = Greyscale image
% 
% Output:
%   g = Magnitude of the gradient (type double matrix)
% 
% History:
%   Jose Luciano - Created function gradient_magnitude April 23, 2022

%getting dimensions of image
[r c] = size(A);

%initializing gradient g
g = zeros(r,c);

%Using Sobel Filter from book (10.14)
Sx = [-1, -2, -1; 0, 0, 0; 1, 2, 1]; 
Sy = [-1, 0, 1; -2, 0, 2; -1, 0, 1];

%Getting gx and gy to calculate gradient magnitude
Gx = spatial_filter(A, Sx);
Gy = spatial_filter(A, Sy);

for i = 1:r 
    for j =1:c
        %G(x,y) = square_root(gx^2 +gy^2)
        g(i,j) = sqrt(Gx(i,j).^2 +Gy(i,j).^2 );        
    end
end
end