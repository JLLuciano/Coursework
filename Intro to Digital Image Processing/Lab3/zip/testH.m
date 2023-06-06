in_img = imread('Lab_03_image_original.tif');
out_img = compute_histogram(in_img);
plot_histogram(out_img);

figure;
in_img2 = imread('Lab_03_image2_light.tif');
out_img2 = compute_histogram(in_img2);
plot_histogram(out_img2);

figure;
in_img3 = imread('Lab_03_image1_dark.tif');
out_img3 = compute_histogram(in_img3);
plot_histogram(out_img3);

