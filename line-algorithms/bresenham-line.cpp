// g++ -o b_line bresenham-line.cpp -lglut -lGL -lGLU

//This code can only print a line with a slope between 0 and 1
#include <GL/glut.h> 
#include<math.h>
#include <iostream>

void myinit() {
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glMatrixMode(GL_PROJECTION);

    glColor3f(1.0f, 1.0f, 1.0f);

    glPointSize(10.0f);

    gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
}
void display() {

    glClear(GL_COLOR_BUFFER_BIT);
    int x1 = 0, x2 = 100, y1 = 0, y2 = 50;
    int dx = x2 - x1;
    int dy = y2 - y1;
    int p = 2 * (dy - dx);
    
    glBegin(GL_POINTS);

    glVertex2i(x1, y1);

    for (int i = 0; i <= 4 * dx - 1; i++) {

        if (p >= 0) {
            p += 2 * (dy - dx);
            x1++;
            y1++;
        }
        else {
            p += 2 * dy;
            x1++;
        }

        glVertex2i(x1, y1);
    }
    glEnd(); 

    glFlush();  // Render now

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1500, 10000);  
    glutInitWindowPosition(200, 200); 
    glutCreateWindow("Line created using Bresenham's algorithm"); 
    glutDisplayFunc(display); 
    myinit();
    glutMainLoop();           
    return 0;
}