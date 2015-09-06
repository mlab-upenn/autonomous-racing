% run this before the simulink file
v = 5;
k1 = 0.001;
k2 = 0.0034;
k3 = 0.00787;

%init conditions
x0 = 0;
y0 = 0;
xv0 = .1;
xm0 = 0.1;
theta0 = 0;

%lin st fb
L1 = -0.1;
L2 = -0.1;