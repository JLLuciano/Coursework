%% testpattern.m
test_img = imread('Fig0225(a)(face).tif');
imshow(test_img);
out = halftone(test_img);
figure;
imshow(out);
imwrite(out, 'face.tif')


figure;
test_img2 = imread('Fig0225(b)(cameraman).tif');
imshow(test_img2);
out2 = halftone(test_img2);
figure;
imshow(out2);
imwrite(out2, 'cameraman.tif')

figure;
test_img3 = imread('Fig0225(c)(crowd).tif');
imshow(test_img3);
out3 = halftone(test_img3);
figure;
imshow(out3);
imwrite(out3, 'crowd.tif')