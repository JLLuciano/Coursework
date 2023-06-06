%testing find_edges
clear all;
image = imread('watertower.tif');
imshow(image)
edges = find_edges(image,100);

figure;
imshow(edges)

imwrite(edges, 'watertower_edge(100).png');
imwrite(image, 'watertower.png');

canny_edges = edge(image, 'Canny');
figure;
imshow(canny_edges);