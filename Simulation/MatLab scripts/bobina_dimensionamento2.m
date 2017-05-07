%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%                       21 Fevereiro de 2017
%                           Electrónica IV
% 
%                   DIMENSIONAMENTO DA BOBINA 2
%                 Amélia Ramos | Pedro Magalhães
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clc;
close all;
clear all;
%DADOS

massaBola=50e-3;        % Considerando uma bola de 50g = 0.050 kg
g=10;
Fmagnetica=g*massaBola; % Força necessária para levitar a bola
gap=5e-2;         %Considerando 5 cm de levitação
%Bobina
Rb = 1.7e-2;      %1.7cm - estimado
Ab = pi*Rb^2;     %Area Bobina
%fio 
RF=0.2e-3;        % Raio do fio no DETI em metros -> 0.4mm (raio de 0.2 mm)
AF=pi*(RF^2);     %UM FIO

miu0=pi*4e-7;   % permeabilidade do vazio 

const=(Fmagnetica*2*(gap^2))/miu0;    %const=(N1*I)^2*A1;
NI = sqrt(const/Ab);

% Arbitrando 500 espiras a colocar na bobine
N=900;
Idevido=NI/N;
Pespira=2*pi*Rb;   % perimetro da espira ao longo da bobine
l=Pespira*N;       % comprimento total de fio necessario

%%%%%%%%%%%%%%%%%%%%%% CALCULAR RESISTENCIA DO FIO %%%%%%%%%%%%%%%%%%%%%%
rho_cobre=1.72e-8;
%Afio=pi*raio_fio^2;
resistencia=rho_cobre*l/AF;

% Tensão na bobine
V = 20;
I = V/resistencia;
P=resistencia*I^2;

% Calculos para o enrolamento da bobine
AtB = N*AF*1.2; % Area transversal da bobine
X=0.01;     
L = AtB/X;

RaioFioEstimado = sqrt(AF/pi); %raio para calcular o AWG de ter 2 fios em paralelo

fprintf('------------------ Dimensionamento da Bobina -------------------\n');
fprintf('\n');
fprintf('Massa da bola (g): %d\n',massaBola*1000);
fprintf('Altura de levitação (cm): %d\n',gap*100);
fprintf('Fio usado:\n');
fprintf('   Raio (mm): %.2f\n',RF*1000);
fprintf('   Comprimento total do fio (m): %.1f\n',l);
fprintf('   Resistencia associada ao fio : %.1f\n',resistencia);
fprintf('\n');
fprintf('Numero de espiras: %d\n',N);
fprintf('Corrente na bobine (A): %.1f\n',I);
fprintf('Corrente necessaria na bobine (A): %.1f\n',Idevido);
fprintf('Tensão na bobine (V): %.1f\n',V);
fprintf('Potência dissipada na bobine (W): %.1f\n',P);

fprintf('----------------------------------------------------------------\n');