#ifndef MY_CYLINDER
#define MY_CYLINDER

#include "CGF/CGFobject.h"
#include <math.h>

class myCylinder : public CGFobject {
	private: 
        int slices; 
        int stacks; 
        bool smooth; 
  
	public:
		myCylinder(int slices, int stacks, bool smooth);
		void draw();

};



#endif