%% equalize.m
function out = equalize(input)
% equalize The function performs histogram equalization on a greyscale
%          image.
%
% Syntax:
%   out = equalize(input);
% 
% Input:
%   input = greyscale image with intensity values from 0-255 
% 
% Output:
%   out = returns a greyscale image which is the histogram equalized 
%         version of the original image
% 
% History:
%   Jose Luciano - Created equalize function 4/10/2022
[r c] = size(input);
out = uint8(zeros(r,c));

% perform the histogram equalization of input image [0,255]
graph = compute_histogram(input);

plot_histogram(graph);

%compute the transformation vector
T = histogram_transform(graph);

% loop all the values, perform equalization for each pixel
for x = 1:r %each row
    for y = 1:c %each column
         index = input(x,y);
         if index == 0
             index = 1;
         end
         out(x,y) = T(index,1);%from T
    end
end
graph_eq = compute_histogram(out);
plot_histogram(graph_eq);

% get average and standard deviation using built-in functions
% change images to type double to calculate mean and std
input = double(input);
std_original = std(input(:));
mean_original = mean(input(:));

out = double(out);
std_eq = std(out(:));
mean_eq = mean(out(:));

fprintf('Original Image: Standard Deviation = %f   ', std_original);
fprintf('Mean = %f\n', mean_original);

fprintf('Equalized Image: Standard Deviation = %f   ', std_eq);
fprintf('Mean = %f\n', mean_eq);

out = uint8(out);
end