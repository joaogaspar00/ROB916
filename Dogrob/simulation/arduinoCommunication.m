classdef arduinoCommunication
    methods
        
    end
    methods(Static)
        function disconnect(port)
            fclose(port);  
        end
        function port = connect()
            disp('Connecting to the device');
            port = serial('COM9','BAUD', 115200);
            fopen(port);
            pause(2);
        end
        function cleanConnection()
            delete(instrfindall);
            clc; clear; close all;
        end
        function data = getRollPitch(port)
            i=1;
            dados = zeros(6,3);
            while(i<=6)   
                for k=1:3
                   read = str2double(fscanf(port));
                   dados(i,k)=read;
                end
               i=i+1;
            end
            dados(1,:) = [];
            accelerometerDados = mean(dados);
            
            roll = atan(accelerometerDados(2) / sqrt(accelerometerDados(1)^2 + accelerometerDados(3)^2)) * 180 / pi;
            pitch = atan(-1 * accelerometerDados(1) / sqrt(accelerometerDados(2)^2 + accelerometerDados(3)^2)) * 180 / pi;
            
            data = [roll pitch];
            pause(0.1);
        end
        function sendServoAngles(port, angles)
            for i=1:length(angles)
                angles(i)
               fprintf(port,angles(i));
            end
        end
        % OFFSET
        function offset = setOffset()
            leg0=[0 10 0];
            leg1=[0 0 0];
            leg2=[-5 10 0];
            leg3=[0 0 0];
            offset = [leg0  leg1 leg2 leg3];
        end
    end
end

