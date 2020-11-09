#include <GL/glut.h>
#include <stdio.h>

int x00,y00,x01,y01;

void init()
{
  glClearColor(0,0,0,0);
  glClear(GL_COLOR_BUFFER_BIT);
  gluOrtho2D(-600,600,-600,600);
  glFlush();
}

void writepixel(int x,int y)
{
  glPointSize(2);
  glBegin(GL_POINTS);       //WRITE PIXEL
  glColor3f(1,0,0);
  glVertex2f(x,y);
  glEnd();
  glFlush();
}
void display()
{
 
  int i,j;

  float dx=x01-x00; 
  float dy = y01-y00; 

  float d = 2*dy-dx;

  float incrE = dy;
  float incrNE = dy - dx;
  
  int x=x00;
  int y=y00;
     
  writepixel(x,y);

   while(x<x01)
   {
      if(d<=0)
      {
 	  d=d+2*incrE;
          x=x+1;
      }
      else
      {
          d=d+2*incrNE;
          x=x+1;
          y=y+1;
      }
      writepixel(x,y);
   } 
}

int main(int argc,char *argv[])
{
  
  printf("Enter the values \n");
  printf("x0="); 
  scanf("%d",&x00);
  printf("y0="); 
  scanf("%d",&y00);
  printf("x1="); 
  scanf("%d",&x01);
  printf("y1="); 
  scanf("%d",&y01);
  
  glutInit(&argc,argv);
  glutCreateWindow("MIDPOINT LINE ALGORITHM");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}