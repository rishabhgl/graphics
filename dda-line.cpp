//g++ -o dda_line dda-line.cpp -lglut -lGL -lGLU
#include <GL/glut.h>
#include <iostream>
#include <math.h>

//Draw a line using the DDA line algorithm

void myinit() {
    //Set the clear color to black 
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // set pixel size 
    glPointSize(5.0); 

    // setting pen colour to red
    glColor3f(1.0, 0.0, 0.0);

    //Setting window coordiante system dimensions
    gluOrtho2D(-1000.0, 1000.0, -1000.0, 1000.0);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    float start[] = { -1000, -1000 };
    float end[] = { 1000, 1000 };
    float abs_dx = abs(end[0] - start[0]);
    float dx = end[0] - start[0];
    float abs_dy = abs(end[1] - start[1]);
    float dy = end[1] - start[1];
    float steps = (abs_dx >= abs_dy) ? abs_dx : abs_dy;
    float m = float(dy)/dx;
    float abs_m = float(abs_dy)/abs_dx;

    for (int i = 0; i <= steps; i++){
        glBegin(GL_POINTS);
        std::cout << start[0] << " " << start[1] << std::endl;
        glVertex2f(start[0], start[1]);
        if (abs_m <= 1){
            start[0] += 1 * (abs_dx/dx);
            start[1] += abs_m * (abs_dy/dy);
        } else {
            start[0] += 1/abs_m * (abs_dy/dy);
            start[1] += 1 * (abs_dy/dy);
        }
        glEnd();
    }

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1500, 1000);   // Set the window's initial width & height
    glutInitWindowPosition(200, 200); // Position the window's initial top-left corner
    glutCreateWindow("Line drawn using the DDA algorithm"); // Create a window with the given title
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    myinit();
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}
