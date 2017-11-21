%NCD1INIT Sets up necessary data files for optimization of ncddemo1.

%   Author(s): A. Potvin, 12-1-92
%              M. Yeddanapudi, Sept., 25 '96
%   Copyright (c) 1990-1998 by The MathWorks, Inc. All Rights Reserved.
%   $Revision: 1.6 $
%   $Date: 1997/12/30 21:17:33 $

% Note: when using the NCD Blockset in practice there is no need
% for an initialization file. Use the NCD Blockset Save and Load 
% menu operations instead.

% Define Optimization parameters
%     - incremental step size  : ncdStruct.Tdelta
%     - tunable parameters     : ncdStruct.TvarStr
%     - optimization options   : ncdStruct.OptmOptns
%     - lower bound limits     : ncdStruct.TvlbStr
%     - upper bound limits     : ncdStruct.TvubStr

% declare globals
clear ncdStruct %apaga variavel global
ncdglob;

ncdStruct.Tdelta = 0.001;
ncdStruct.TvarStr = 'kp ki '; 
ncdStruct.OptmOptns = [0.001 0.001 0.001];
ncdStruct.TvlbStr = '0 0 0';
ncdStruct.TvubStr = '0 0 0';

% Generate constraint bound matrices
%ncdStruct.CnstrLB = [    1     1     1     1     1     1; ...
 %                        0    10    10    30    30   100; ...
  %                      -1    -1    90/3    90/3    99/3    99/3; ... 
   %                      1     0     1     0     1     0];
                  
%ncdStruct.CnstrUB = [    1     1     1     1; ...
 %                        0    30  30    100; ...
  %                     120/3   120/3   101/3   101/3; ...
   %                      1     0     1     0];

% Other NCD default data

ncdStruct.RngLmts = [];
ncdStruct.RefSgnl = '';
ncdStruct.UvarStr = '';
ncdStruct.UvlbStr = '';
ncdStruct.UvubStr = '';
ncdStruct.NumMC = 0;
ncdStruct.PlntON = [1 0 0 0];
ncdStruct.GradFlag = 0;

% Define Tunable Variable initial values
%kp = 0.1367; ki = 4.8710; kd = 0.0026;
% Ziegler-Nichols Tuning
% Ku = ?; Pu = ? sec

kp = 10; ki = 0; kd = 0;

%kp =1500;
%ki =405.3912;
%kd = 69.6825;

% Define Uncertain Variable initial values

disp('Inicialização: Ajuste do PID.')

