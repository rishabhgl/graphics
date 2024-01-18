//g++ -o lab1 assignment-1.cpp -lglut -lGL

#include <GL/glut.h>

//Write a program to:
// Create an empty window of different colours 
// Draw a point of width 10 pixels 
// Draw a green coloured line 
// Draw a triangle on black background

void myInit(){
    // setting background color
    // last argument relates to opacity(no observed effect)  
    glClearColor(0.0, 0.0, 0.0, 0.0); 
      
    // set pixel size 
    glPointSize(10.0); 

    // setting pen colour to red
    glColor3f(1.0, 0.0, 0.0); 

    //Below three customizations result in errors!
    // glMatrixMode(GL_PROJECTION);  
    // glLoadIdentity(); 
    // setting allowable pixel range values in X- and Y- direction 
    // gluOrtho2D(-780, 780, -420, 420); // Default values are -1, 1
}

void display(){

    //glClear and glFlush are mandatory!

    glClear(GL_COLOR_BUFFER_BIT);

    // setting pen colour to green, and line width(does not render widths greater than 10)
    glColor3f(0.0, 1.0, 0.0); 
    glLineWidth(10.0);
    //Drawing an oblique green line
    glBegin(GL_LINES);
    glVertex2f(-1.0, 0.2);
    glVertex2f(1.0, 0.2);
    glEnd();

    //Drawing triangle on black background
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0, 1.0);
    glVertex2f(-1.0, -1.0);
    glVertex2f(1.0, -1.0);
    glEnd();

    // setting pen colour to red
    glColor3f(1.0, 0.0, 0.0); 
    // Drawing a pixel at the center of the window
    glBegin(GL_POINTS);
    glVertex2f(0.0, 0.0);
    glEnd();

    //setting pen colour to blue
    glColor3f(0.0, 0.0, 1.0);
    // glBegin(GL_QUADS);
    // glVertex2f(-0.2, -0.2);
    // glVertex2f(0.2, -0.2);
    // glVertex2f(-0.2, -0.4);
    // glVertex2f(0.2, -0.4);
    // glEnd();
    glRectf(-0.2, -0.2, 0.2, -0.4);

    glFlush();

}

int main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //Uses a single buffer to store RGB values, GLUT_DOUBLE allows for more changes

    glutInitWindowPosition(300, 300);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Assignment-1 Solution");

    myInit();

    glutDisplayFunc(display);

    //glutMainLoop is mandatory!
    glutMainLoop();

    return 0;
}