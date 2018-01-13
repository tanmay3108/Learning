'''
Created on 15-Mar-2014
@author: Tanmay Sinha
'''
import pygame
from math import *
pygame.font.init();
font=pygame.font.SysFont('Verdana',16,1);
font1=pygame.font.SysFont('Verdana',10,1);
white=(255,255,255)#non mutable tuples
black=(0,0,0)#tuples
green=(0,250,0);
blue=(100,240,255);
graphcolor=(100,100,255)
header=(223,23,229);
red=(255,0,0);
width=600;
extraw=400;
height=600;

domain=[]
string=""

screen=pygame.display.set_mode((width+extraw, height))#this creates the window of written dimensions and it must be global
pygame.display.set_caption("Graph Plotting")
print pygame.display.get_caption
screen.fill(white)
def grapher(k):
    
    screen.set_clip(0,0,width,height);
    screen.fill(white)
    max=int((width/k)/2)
    txt=-max;
    #for creation of graph paper
    for i in range(width/k):
        x=i*k;
        y=i*k;
        pygame.draw.line(screen,black,(x,0),(x,height),1);
        numbers=font1.render(""+str(txt),1,black)
        
        txt=txt+1;
        pygame.draw.line(screen,black,(0,x),(width,x),1);
        if txt%2!=1:
            continue
        screen.blit(numbers,(x,302));
    #for creation of last vertical line
    pygame.draw.line(screen,blue,(width,0),(width,height),8);
    #x and y axis
    midx=(width/(2*k));#this will result in decimals and latter again we have multiplied so that axes coincides with axes 
    midy=(height/(2*k));
    pygame.draw.line(screen,black,(midx*k,0),(midx*k,height),3);
    pygame.draw.line(screen,black,(0,midy*k),(width,midy*k),3);
    screen.set_clip(None);#Again having full screen for display
    

def mymain(n,eq):
    
    k=25;#number of pixels per grid
    if n == 1:
        #clear screen
        screen.fill(white)
        grapher(k)
        equation=[]
        eq2= ' '        
    else:
        screen.set_clip(width, 0, width+extraw, height)
        screen.fill(white)
        screen.set_clip(None)
        eq2 = eq
        equation=[]
    
    #instructions and interaction 
    heading=font.render("Graph Utility Tool",1,(black));
    screen.blit(heading,(width+100,10));
    heading=font.render("Enter your equation Ex:-3*x^2-2*x+1",1,(black));
    screen.blit(heading,(width+10,40));
    screen.set_clip(None);
    equation=[]
    done=0;
    running=1;
    while running:
        screen.set_clip(width+10,height-40,width,height)
        #bottom
        eq=string.join(equation)
        #eq=string.replace(eq," ","")
        heading=font.render("Function Y ="+eq,1,(black));
        screen.set_clip(width,height-50,width+extraw,height);
        screen.fill(blue);
        screen.blit(heading,(width+10,height-50));
        
        #update
        pygame.display.update();
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running=0
                done=1
            elif event.type == pygame.KEYDOWN:
                if event.unicode == u'*':
                    equation.append("*")
                elif event.unicode == u'+':
                    equation.append("+")
                elif event.unicode == u'/':
                    equation.append("/")
                elif event.unicode == u'-':
                    equation.append("-")
                elif event.unicode == u'.':
                    equation.append(".")
                elif event.unicode == u'(':
                    equation.append("(")
                elif event.unicode == u')':
                    equation.append(")")
                elif event.unicode == u'^':
                    equation.append("**")      
                elif event.key ==pygame.K_1:
                    equation.append("1")
                elif event.key ==pygame.K_2:
                    equation.append("2")                    
                elif event.key ==pygame.K_3:
                    equation.append("3")
                elif event.key ==pygame.K_4:
                    equation.append("4")
                elif event.key ==pygame.K_5:
                    equation.append("5")
                elif event.key ==pygame.K_6:
                    equation.append("6")
                elif event.key ==pygame.K_7:
                    equation.append("7")
                elif event.key ==pygame.K_8:
                    equation.append("8")
                elif event.key ==pygame.K_9:
                    equation.append("9")
                elif event.key ==pygame.K_0:
                    equation.append("0")
                elif event.key==pygame.K_x:
                    equation.append("x")
                    
                elif event.key == pygame.K_s:
                    equation.append("sin(")
                elif event.key == pygame.K_c:
                    equation.append("cos(")                
                elif event.key == pygame.K_t:
                    equation.append("tan(")                
                elif event.key == pygame.K_r:
                    equation.append("sqrt(")
                elif event.key == pygame.K_a:
                    equation.append("abs(")                
                elif event.key == pygame.K_l:
                    equation.append("log10(")                
                elif event.key == pygame.K_n:
                    equation.append("log(")                
                elif event.key == pygame.K_e:
                    equation.append("e")
                elif event.key == pygame.K_j:
                    equation.append("floor(")                     
                elif event.key == pygame.K_p:
                    equation.append("pi")    
                elif event.key==pygame.K_q:
                    mymain(1,'')
                elif event.key == pygame.K_BACKSPACE:
                    equation = []
                elif event.key == pygame.K_RETURN:
                    running=0
                    #GraphPlot(k,equation)
                    #screen.set_clip(None)
    if done:
        pygame.quit()
    else:
        screen.set_clip(width,0,width+extraw,height-100)
        screen.fill(white)
        screen.set_clip(None)
        Graph(k,eq,eq2)    
        
            
            
                            
                                                                                                             
def Graph(k,eq,eq2):
    for i in range(width):
        try:
            
            x=(width/2-i)/float(k)              
            y=eval(eq);
            #domain=x
            #print domain                        
            pos1=((width/2+x*k,height/2-y*k))
            #print pos1
            nx = x = (width/2-(1+i))/float(k)
            ny=eval(eq)
            pos2=(width/2+nx*k,height/2-ny*k)
            pygame.draw.line(screen,graphcolor,pos1,pos2,3)
        except:
            pass
        try:
            x = (width/2-i)/float(k)
            y2 = eval(eq2)            
                                        
            pos21 = (width/2+x*k, height/2-y2*k)

            nx = x = (width/2-(i+1))/float(k)
            ny2 = eval(eq2)
            pos22 = (width/2+nx*k, height/2-ny2*k)

            pygame.draw.line(screen, graphcolor, pos21, pos22, 3)
        except:
            pass

    xValue=[];
    xVal='?';
    yVal='?';        
#Instructions and Results                  
    running=1;
    while running:
        screen.set_clip(width,0,width+400,height-300)
        screen.fill(white);
        heading=font.render("Graph Utility Tool",1,(header));
        screen.blit(heading,(width+10,10));
        heading=font.render("To Restart Press Q",1,(black));
        screen.blit(heading,(width+10,40));
        #Resize of Grid instructions
        heading=font.render("To Resize Grid Press S,M,L,O",1,(black));
        screen.blit(heading,(width+10,200));
        #Plotting x and y values        
        
        xdisplay=string.join(xValue)
        plotx=font.render("x = "+str(xdisplay),1,(black));
        screen.blit(plotx,(width+10,150));
        
        ploty=font.render("("+str(xVal)+","+str(yVal)+")",1,(black))                
        screen.blit(ploty,(width+220,150));
        screen.set_clip(None)
        pygame.display.update()
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running=0
            elif event.type ==pygame.KEYDOWN:
                if event.key == pygame.K_q:
                    mymain(1,'');
                elif event.key == pygame.K_y:
                    #Calculating Y intercept
                    x=0;
                    try:
                        yint=(eval(eq));
                        yplot= int(height/2-yint*k);
                        pygame.draw.circle(screen,red,(width/2,yplot),8,2)#highlighting the Y intercept
                        heading=font.render("Y-intercept is (0,"+str(yint)+")",1,(black));
                        screen.blit(heading,(width+100,400));
                    except:
                        yint='dne';
                        heading=font.render("Y-intercept is (0,"+str(yint)+")",1,(black));
                        screen.blit(heading,(width+100,400));
                elif event.key == pygame.K_x:
                    print 'ok'                    
                    domain=[]
                    for i in range(width-1):
                        try:
                            x=(width/2-i)/float(k);
                            y=eval(eq)
                            x1=(300-(i+1))/float(k);
                            x2=x
                            x=x1
                            #print y
                            y1=eval(eq)
                            x=x2                            
                            if (y*y1)<=0:                                
                                domain.append(x)
                                domain.append(x1)
                                                                                                                                  
                        except:
                            pass
                    try:                                                    
                        x1=x=domain[0]
                        y1=eval(eq);
                        x2=x=domain[1];
                        y2=eval(eq);
                        if y1>y2:                        
                            b=x1
                            a=x2
                        else:
                            a=x1
                            b=x2
                        x=a    
                        y=eval(eq)        
                        while int(y*1000)!=0:                        
                            x=(a+b)/2.0
                            y=eval(eq)
                            if(y>0):
                                b=x;
                            if(y<0):
                                a=x;    
                        print x
                        pygame.draw.circle(screen,red,(int(width/2+x*k),height/2),8,2)#highlighting the X intercept
                        heading=font.render("X-intercept is ("+str(x)+",0)",1,(black));
                        screen.blit(heading,(width+100,440));                          
                    except:
                        yint='dne';
                        heading=font.render("X-intercept is (DNE,0)",1,(black));
                        screen.blit(heading,(width+100,440));
                                                                                                                                                                                                        

                    
                                                                                                                          
                                                    
                                                            
                                
                                
                elif event.key == pygame.K_i:                    
                    for i in range(width):
                        try:                            
                            x=(width/2-i)/float(k)
                            #print eq                            
                            y1=eval(eq);
                            y2=eval(eq2);            
                            if y1==y2:
                                pos=(width/2+x*k,height/2-y1*k)
                                print 'intersection is'+str(pos);
                                pygame.draw.circle(screen,red,(int(width/2+x*k),int(height/2-y1*k)),8,2)#highlighting the Y intercept                                                                
                                
                            #print y
                            
                        except:
                            pass  
                elif event.key == pygame.K_s:
                    k=25
                    grapher(k)
                    Graph(k,eq,'')                               
                elif event.key == pygame.K_m:
                    k=20
                    grapher(k)
                    Graph(k,eq,'')                
                elif event.key == pygame.K_l:
                    k=10
                    grapher(k)
                    Graph(k,eq,'')
                elif event.key == pygame.K_o:
                    k=5
                    grapher(k)
                    Graph(k,eq,'')
                elif event.key == pygame.K_z:
                    k=2
                    grapher(k)
                    Graph(k,eq,'')         
                elif event.key ==pygame.K_1:
                    xValue.append("1")
                elif event.key ==pygame.K_2:
                    xValue.append("2")                    
                elif event.key ==pygame.K_3:
                    xValue.append("3")
                elif event.key ==pygame.K_4:
                    xValue.append("4")
                elif event.key ==pygame.K_5:
                    xValue.append("5")
                elif event.key ==pygame.K_6:
                    xValue.append("6")
                elif event.key ==pygame.K_7:
                    xValue.append("7")
                elif event.key ==pygame.K_8:
                    xValue.append("8")
                elif event.key ==pygame.K_9:
                    xValue.append("9")
                elif event.key ==pygame.K_0:
                    xValue.append("0")
                elif event.unicode == u'-':
                    xValue.append("-")
                elif event.unicode == u'.':
                    xValue.append(".")
                elif event.key == pygame.K_RETURN:
                    #calculating co-ordinates
                    x=xVal=float(xdisplay);
                    try:
                        yVal=eval(eq)                        
                        pygame.draw.circle(screen,red,(int(width/2+k*x),int(height/2-k*yVal)),8,2)
                        yVal= int(yVal*1000)
                        xValue=[]
                    except:
                        yVal='DNE'
                        xValue=[]    
                elif event.key == pygame.K_g:
                    mymain(2,eq)    
                                                                     
    pygame.quit()        
        
            
                                                                    
                              
           
              
                 
                    
    

mymain(1,'');    
#pass