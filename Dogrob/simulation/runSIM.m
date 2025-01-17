%% SIM DRAW
function runSIM(servoData)
    
%     disp('Begin simulation');

    upLegLength = 8;
    downLegLength = 6;
    
    for i=0:3
        gama = servoData(3*i+1);
        phi = servoData(3*i+2);
        alpha = servoData(3*i+3);

        beta = 180-phi;
        theta = alpha-phi+90;
        figure(100);
        subplot(2,2,i+1); 
        draw(downLegLength, upLegLength, beta, theta);
        xlim([-10 10]); ylim([-2 15]);
        title(i);
    end
    
%     disp('End simulation');
end 


function draw(a, b, beta, theta)
    
%     disp('Begin drawing');
    
    downLeg = [a*cosd(theta) a*sind(theta)];
    upLeg = [downLeg(1)+b*cosd(beta) downLeg(2)+b*sind(beta)];
     
    leg([0 0], downLeg, 2.5, 'black');
    leg(downLeg, upLeg, 2.5, 'red');
    
    joint(0,0,0.2,'black');
    joint(downLeg(1),downLeg(2),0.15,'blue');
    joint(upLeg(1),upLeg(2),0.15,'blue');
    
    grid on;
    hold off;

end

function joint(x,y,r,c)
    th = 0:pi/50:2*pi;
    x_circle = r * cos(th) + x;
    y_circle = r * sin(th) + y;
    plot(x_circle, y_circle);
    fill(x_circle, y_circle, c)
    hold on;
    axis equal
end

function leg(initpos, finalpos, w, c)
    x = linspace(initpos(1),finalpos(1), 10);
    y = linspace(initpos(2),finalpos(2), 10);
    plot(x, y, c, 'LineWidth',w);  
    hold on;
end