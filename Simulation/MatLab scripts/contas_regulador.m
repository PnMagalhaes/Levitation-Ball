%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%                          25 Mar�o de 2017
%                           Electr�nica IV
% 
%   -> Varia��o de corrente na bobine para gerar oscila�ao num gap vertical
%
%                   Am�lia Ramos | Pedro Magalh�es
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clc;
close all;
clear all;

% Bobine
N=900;
RBmedio=1.7e-2;
ABobine=pi*RBmedio^2;

Pespira=2*pi*RBmedio;   % perimetro da espira ao longo da bobine
lfio=Pespira*N;            % comprimento total de fio necessario
raio_fio=0.2e-3;
rho_cobre=1.72e-8;
miu_ferro=200000;   % permeabilidade relativa do CORE   
miu0=pi*4e-7;

Afio=pi*raio_fio^2;
resistencia=rho_cobre*lfio/Afio;

% Calculos levita��o
massaBola=20e-3;        % Considerando uma bola de 20g = 0.020 kg
g=9.8;
Fmagnetica=g*massaBola; % For�a necess�ria para levitar a bola (contraria ao peso)
gap_min=3e-2;   % considerando 3 cm como a menor distancia � bobina
gap_max=8e-2;   % consideranto 8 cm como o gap maior � bobina


I_min=sqrt(2*Fmagnetica*gap_min^2/(miu0*ABobine))/N;    % corrente necessaria
I_max=sqrt(2*Fmagnetica*gap_max^2/(miu0*ABobine))/N;    % corrente necessaria

V_min=resistencia/I_max;    % tens�o que o fio impoe
V_max=resistencia/I_min;    % tens�o que o fio impoe







