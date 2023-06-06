%% plot_histogram.m
function plot_histogram(data)
% plot_histogram Plots the normalized histogram
%
% Syntax:
%   plot_histogram(data);
%
% Input:
%   data = normalized histogram
%
% Output:
%   plots the histogram
%
% History:
%   Jose Luciano - Created plot_histogram function 4/09/2022
figure;
bar(data);

%change axis, xlabel = intensity value and ylabel = PMF
xlabel('intensity value');
xlim([1 255]);
ylabel('PMF');
y = max(data(:,1));
ylim([0 y]);

end