#ifndef _MYVIEW_H
#define _MYVIEW_H

#include "CGFobject.h"
#include "CGFappearance.h"
#define HALF_SIZE 0.5f

class MyView: public CGFobject {
private:
    CGFappearance * view;
public:
    MyView();
    void draw();
};

#endif
