#ifndef _MYVIEW_H
#define _MYVIEW_H

#include "CGFobject.h"
#include "CGFappearance.h"

class MyView: public CGFobject {
private:
    CGFappearance * view;
public:
    MyView();
    void draw();
};

#endif
