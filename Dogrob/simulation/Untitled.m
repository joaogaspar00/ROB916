%% OPEN COMMUNICATION
clear all; close all;
port = serial('COM3','BAUD', 9600);
fopen(port);
pause(3);
disp('Connected');

%% CLOSE COMMUNICATION
fclose(port);
%%
delete(instrfindall);disp('Disconnected');
clc; clear all; close all;