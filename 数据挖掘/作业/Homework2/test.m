data = load('dataForTraining.txt');

X = data(:,1:2);
y = data(:,3);
m = length(y);

[X,avg,sigma] = normalize(X);
X = [ones(m,1) , X];

theta = zeros(3,1);
alpha = 0.00015;
max_iter = 150000;

J_history = zeros(max_iter,1);
for iter = 1:max_iter
	theta = theta - alpha / m * X' * (X * theta - y); 
    J_history(iter) = sum((X * theta - y).^2) / (2*m);    
    %fprintf('iter:%d ------ Error:%f\n',iter,J_history(iter));
end

disp('Theta found by gradient descent:');
disp(theta);
