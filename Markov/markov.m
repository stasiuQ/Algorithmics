clear
clc
close all

%parameters:
size = 6;
alpha = 0.0;
steps = 10000;
threshold = 1e-16;

%matrix
P = [0 0 0 0.5 0.5 0; 0 0 0.5 0 0 0.5;
    0.2 0.2 0 0.2 0.2 0.2; 1 0 0 0 0 0;
    0 0.5 0 0.5 0 0; 1/6 1/6 1/6 1/6 1/6 1/6];

%Google matrix
MG = (1-alpha)*P + (alpha/size)*ones(size,size);

iterator = 1;
converged = false;

distribution = ones(1, size)/size;
while (iterator  < steps && converged == false)
    temp_vector = distribution * MG;
    if (sum(abs(temp_vector - distribution)) < threshold)
        converged = true;
        disp("Converged!  no. iterations:");
        disp(iterator);
    else
        iterator = iterator + 1;
    end
    distribution = temp_vector;
end

if (converged == false)
    disp("Not converged!");
end

disp(distribution);
disp(sum(distribution));

