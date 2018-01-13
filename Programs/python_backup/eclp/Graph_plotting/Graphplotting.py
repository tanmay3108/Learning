#import matplotlib.pyplot as plt
#plt.plot([1,2,3,4])
#plt.ylabel('some numbers')
#plt.show()
import pygame
pygame.font.init();
font=pygame.font.SysFont('Verdana',16,1);

white=(255,255,255)#non mutable tuples
black=(0,0,0)#tuples
green=(0,250,0);
blue=(100,240,255);
width=600;
extraw=400;
height=600;




screen=pygame.display.set_mode((width+extraw, height))#this creates the window of written dimensions and it must be global
pygame.display.set_caption("Graph Plotting")
print pygame.display.get_caption
screen.fill(white)
def graph(k):
    screen.set_clip(0,0,width,height);
    #for creation of graph paper
    for i in range(width/k):
        x=i*k;
        y=i*k;
        pygame.draw.line(screen,black,(x,0),(x,height),1);
        pygame.draw.line(screen,black,(0,x),(width,x),1);
    #for creation of last vertical line
    pygame.draw.line(screen,blue,(width,0),(width,height),8);
    #x and y axis
    midx=(width/(2*k));#this will result in decimals and latter again we have multiplied so that axes coincides with axes 
    midy=(height/(2*k));
    pygame.draw.line(screen,black,(midx*k,0),(midx*k,height),3);
    pygame.draw.line(screen,black,(0,midy*k),(width,midy*k),3);
    screen.set_clip(None);#Again having full screen for display
    

def mymain():
    running=1;
    k=25;#number of pixels per grid
    graph(k);
    #instructions and interaction 
    heading=font.render("Graph Utility Tool",1,(black));
    screen.blit(heading,(width+10,10));
    
    #bottom
    heading=font.render("Graph Utility Tool",1,(black));
    screen.set_clip(width,height-50,width+extraw,height);
    screen.fill(blue);
    screen.blit(heading,(width+10,height-50));
    screen.set_clip(None);
    
    while running:
        pygame.display.update();   
        event = pygame.event.poll()
        if event.type == pygame.QUIT:
            running=0
        
        
    
     
    
    
    
mymain();    
#pass