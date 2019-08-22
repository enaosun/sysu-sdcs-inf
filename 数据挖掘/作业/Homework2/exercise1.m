%exercise 1

%读取文件数据
data = load('dataForTraining.txt');
data2 = load('dataForTesting.txt');

%读取自变量数据
x = data(:,1:2);
x2 = data2(:,1:2);
%读取因变量数据
y = data(:,3);
y2 = data2(:,3);
m = length(y);
m2 = length(y2);


%增添一列为1的数据，计算对应的b
x = [ones(m,1),x];
x2 = [ones(m2,1),x2];

theta = zeros(3,1);%系数；
alpha = 0.00015;   %自定义的学习率
max_iter = 150000;  %自定义的迭代次数
error = zeros(max_iter,1); %记录误差值
error2 = zeros(max_iter,1);
store = zeros(max_iter*3,1);


for i = 1:max_iter
    theta = theta - alpha/m * x' * ( x * theta - y) ;
    error(i) = sum((x * theta - y).^2) / (2*m);
    error2(i) = sum((x2*theta - y2).^2) /(2*m2);
    
end


for i = 1 : 15
    disp(i);
    disp(error(i*10000));
    disp(error2(i*10000)); 
end






    




