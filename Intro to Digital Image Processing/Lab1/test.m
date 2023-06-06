%% testwedge.m
test_img = uint8(zeros(256,256));

for c = 1:256
    %0 means black
    test_img(c, :) = c-1; % 0 to 255
end
imshow(test_img);

out = halftone(test_img);

figure;

imshow(out);

imwrite(out, 'test.tif')
imwrite(test_img, 'wedge.tif')