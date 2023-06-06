%test script
in_img = imread('Lab_03_image2_light.tif');
temp = equalize(in_img);
figure;
imshow(temp);
imwrite(temp, 'light_image.png');
imwrite(in_img,'Lab_03_image2_light(png).png');

in_img2 = imread('Lab_03_image1_dark.tif');
temp2 = equalize(in_img2);
figure;
imshow(temp2);
imwrite(temp2, 'dark_image.png');
imwrite(in_img2,'Lab_03_image1_dark(png).png');


