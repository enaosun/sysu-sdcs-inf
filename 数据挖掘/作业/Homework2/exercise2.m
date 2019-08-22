% user input data 
f = input('Frequency Of Sinusoid:');
n = input('Samplig Frequency:');
u = input('Amplitude: ');
% signal
t = 0:0.001:1;
g1 = u*cos(2*pi*f*t);
plot(t,g1,'-');
ylabel('x(t)');
hold on ;
ns = 0:1:n;
gs = u*cos(2*f*pi*ns/n);
plot(ns/n,gs,'o');hold off