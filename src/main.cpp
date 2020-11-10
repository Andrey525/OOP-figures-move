#include "figures.h"

#define COL_POINTS 5
#define COL_TRIANGLES 3
#define COL_LINES 3
#define COL_SQUARES 3
#define COL_RHOMBUS 3
#define COL_TRAPEZES 3

tPoint* point = new tPoint[COL_POINTS];
tLine* line = new tLine[COL_LINES];
tTriangle* triangle = new tTriangle[COL_TRIANGLES];
tSquare* square = new tSquare[COL_SQUARES];
tRhombus* rhombus = new tRhombus[COL_RHOMBUS];
tTrapeze* trapezes = new tTrapeze[COL_TRAPEZES];

void renderScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPointSize(point[1].getSize());
    // glEnable(GL_POINT_SMOOTH);
    glBegin(GL_POINTS);
    for (int i = 0; i < COL_POINTS; i++) {
        glVertex2f(point[i].getX(), point[i].getY());
        glColor3f(point[i].getR(), point[i].getG(), point[i].getB());
    }
    glEnd();

    glBegin(GL_LINES);
    for (int i = 0; i < COL_LINES; i++) {
        glColor3f(line[i].getR(), line[i].getG(), line[i].getB());
        glVertex2f(line[i].getPointAKoordX(), line[i].getPointAKoordY());
        glVertex2f(line[i].getPointBKoordX(), line[i].getPointBKoordY());
    }

    glEnd();

    glBegin(GL_TRIANGLES);
    for (int i = 0; i < COL_TRIANGLES; i++) {
        glColor3f(triangle[i].getR(), triangle[i].getG(), triangle[i].getB());
        glVertex2f(triangle[i].getPointAKoordX(), triangle[i].getPointAKoordY());
        glVertex2f(triangle[i].getPointBKoordX(), triangle[i].getPointBKoordY());
        glVertex2f(triangle[i].getPointCKoordX(), triangle[i].getPointCKoordY());
    }
    glEnd();

    glBegin(GL_QUADS);
    for (int i = 0; i < COL_SQUARES; i++) {
        glColor3f(square[i].getR(), square[i].getG(), square[i].getB());
        glVertex2f(square[i].getPointAKoordX(), square[i].getPointAKoordY());
        glVertex2f(square[i].getPointBKoordX(), square[i].getPointBKoordY());
        glVertex2f(square[i].getPointCKoordX(), square[i].getPointCKoordY());
        glVertex2f(square[i].getPointDKoordX(), square[i].getPointDKoordY());
    }
    glEnd();

    glBegin(GL_QUADS);
    for (int i = 0; i < COL_RHOMBUS; i++) {
        glColor3f(rhombus[i].getR(), rhombus[i].getG(), rhombus[i].getB());
        glVertex2f(rhombus[i].getPointAKoordX(), rhombus[i].getPointAKoordY());
        glVertex2f(rhombus[i].getPointBKoordX(), rhombus[i].getPointBKoordY());
        glVertex2f(rhombus[i].getPointCKoordX(), rhombus[i].getPointCKoordY());
        glVertex2f(rhombus[i].getPointDKoordX(), rhombus[i].getPointDKoordY());
    }
    glEnd();

    glBegin(GL_QUADS);
    for (int i = 0; i < COL_TRAPEZES; i++) {
        glColor3f(trapezes[i].getR(), trapezes[i].getG(), trapezes[i].getB());
        glVertex2f(trapezes[i].getPointAKoordX(), trapezes[i].getPointAKoordY());
        glVertex2f(trapezes[i].getPointBKoordX(), trapezes[i].getPointBKoordY());
        glVertex2f(trapezes[i].getPointCKoordX(), trapezes[i].getPointCKoordY());
        glVertex2f(trapezes[i].getPointDKoordX(), trapezes[i].getPointDKoordY());
    }
    glEnd();

    glutSwapBuffers();
}

void move(int j = 0)
{
    renderScene();
    for (int i = 0; i < COL_POINTS; i++) {
        if ((i % 5 == 0) || (i % 6 != 0 && i % 3 == 0)) {
            point[i].set_chaos_vector();
        }
        point[i].move();
    }

    for (int i = 0; i < COL_TRIANGLES; i++) {
        // if (i % 2 == 0) {
        //     triangle[i].set_chaos_vector();
        // }
        triangle[i].rotate();
        triangle[i].move();
    }

    for (int i = 0; i < COL_LINES; i++) {
        // if (i % 2 == 0) {
        //     line[i].set_chaos_vector();
        // }
        line[i].rotate();
        line[i].move();
    }

    for (int i = 0; i < COL_SQUARES; i++) {
        // if (i % 2 == 0) {
        //     square[i].set_chaos_vector();
        // }
        square[i].rotate();
        square[i].move();
    }

    for (int i = 0; i < COL_RHOMBUS; i++) {
        // if (i % 2 == 0) {
        //     rhombus[i].set_chaos_vector();
        // }
        rhombus[i].rotate();
        rhombus[i].move();
    }

    for (int i = 0; i < COL_TRAPEZES; i++) {
        // if (i % 2 == 0) {
        //     trapezes[i].set_chaos_vector();
        // }
        trapezes[i].rotate();
        trapezes[i].move();
    }

    glutTimerFunc(5, move, 0);
}

int main(int argc, char** argv)
{
    // инициализация
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 500);
    glutCreateWindow("Lab-3");
    glClearColor(0, 0, 0, 0);

    // регистрация обратных вызовов
    glutDisplayFunc(renderScene);

    move();

    // Основной цикл GLUT
    glutMainLoop();

    return 1;
}
