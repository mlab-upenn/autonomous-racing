function [y] = mfun(u)
load('Data.mat');

y = 20*M(1,1)*u;
