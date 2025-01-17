A=8;B=6;

x=[];
y=[];
for H=0:0.1:15

theta = acosd((A^2+H^2-B^2)/(2*A*H))+90;
phi = acosd((B^2+H^2-A^2)/(2*B*H))+90;
alpha = theta+phi-90;

x=[x theta];
y=[y alpha];

end

figure(101)
plot3(x,y,0:0.1:15);
grid on;