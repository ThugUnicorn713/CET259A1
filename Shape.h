#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include "SaveManager.h"

using namespace std;

class Shape
{
protected:

	SaveManager* sm;

public:
	Shape(SaveManager* manager);


};

#endif


