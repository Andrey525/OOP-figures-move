#ifndef POINT_H
#define POINT_H

#include <GL/freeglut.h>
#include <GL/glut.h>
#include <cmath>
#include <cstdlib>
#include <ctime>

class tPoint {
protected:
    /* Координаты */
    float x;
    float y;

    /* Размер */
    float size;

    /* Цвет */
    float r;
    float g;
    float b;

    /* Направление движения */
    float vector_x;
    float vector_y;

    /* Коэффициент скорости*/
    float koef;

public:
    tPoint();

    void setX(float rx);
    void setY(float ry);
    void setSize(float rsize);
    void setR(float mr);
    void setG(float mg);
    void setB(float mb);
    void setVX(float v_x);
    void setVY(float v_y);
    void setKoef(float koef);

    float getX();
    float getY();
    float getSize();
    float getR();
    float getG();
    float getB();
    float getVX();
    float getVY();
    float getKoef();

    /* Движение */
    virtual void move();
    virtual void rotate();
    void set_chaos_vector();
};

class tLine : public tPoint {
protected:
    tPoint A, B;
    float alpha;

public:
    tLine();
    void setPointA(float rx, float ry);
    void setPointB(float rx, float ry);
    void setAlpha(float a);

    float getAlpha();
    float getPointAKoordX();
    float getPointAKoordY();
    float getPointBKoordX();
    float getPointBKoordY();

    void move();
    void rotate();
};

class tTriangle : public tLine {
protected:
    tPoint C;

public:
    tTriangle();

    void setPointC(float rx, float ry);

    float getPointCKoordX();
    float getPointCKoordY();

    void move();
    void rotate();
};

class tSquare : public tTriangle {
protected:
    tPoint D;

public:
    tSquare();

    void setPointD(float rx, float ry);

    float getPointDKoordX();
    float getPointDKoordY();

    void move();
    void rotate();
};

class tRhombus : public tSquare {
public:
    tRhombus();
};

class tTrapeze : public tSquare {
public:
    tTrapeze();
};

#endif

