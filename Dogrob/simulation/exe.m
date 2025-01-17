%% ROBOT's FEATURES

upLegLength = 8;
downLegLength = 6;

%% RUNNING CODE

% dogrob = arduinoCommunication;
% 
% if isempty(instrfindall) == 1
%     port = dogrob.connect();
% else    
%     if exist('port','var') == 1
%         dogrob.disconnect(port);
%         dogrob.cleanConnection();
%     else
%         dogrob.cleanConnection();
%     end
%     
%     port = dogrob.connect();
% end
% 
% disp('Connected');

%%
for j=1:5
    for i=8:0.5:12

        servoData = defHeigth(upLegLength,downLegLength,i);

        runSIM(servoData)

        drawnow
    end
end

%%
% %%
% fprintf(port,100); 
% dados = dogrob.getRollPitch(port);
% dados
% %%
% % fprintf(port,101); 
% 
% %%
% angles = [0 0 0 0 90 90 90 90 90 90 90 90];
% fprintf(port,101);
% 
% fwrite(port, angles, 'uint16');
% 
% % for i=1:length(angles)
% %     angles(i)
% %    fprintf(port,angles(i));
% % end


%% DEFINE ROBOT's HEIGTH
function servoData = defHeigth(A,B,H)

    theta = acosd((A^2+H^2-B^2)/(2*A*H))+90;
    phi = acosd((B^2+H^2-A^2)/(2*B*H))+90;
    alpha = theta+phi-90;8
    
    leg0=[90 theta alpha];
    leg1=[90 theta alpha];
    leg2=[90 theta alpha];
    leg3=[90 theta alpha];
    
    servoData = [leg0  leg1 leg2 leg3];
end

%% SET POSITION
function servoData = setPosition()
    leg0=[90 90 130];
    leg1=[90 90 130];
    leg2=[90 90 130];
    leg3=[90 90 130];
    servoData = [leg0  leg1 leg2 leg3];
end

%% UP POSITION
function servoData = upPosition()
    leg0=[90 90 90];
    leg1=[90 90 90];
    leg2=[90 90 90];
    leg3=[90 90 90];
    servoData = [leg0  leg1 leg2 leg3];
end

%% DOWN POSITION
function servoData = downPosition()
    leg0=[90 120 145];
    leg1=[90 120 145];
    leg2=[90 120 145];
    leg3=[90 120 145];
    servoData = [leg0  leg1 leg2 leg3];
end
