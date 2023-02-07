#include <osbind.h>
#include "raster.h"

int main()
{
	void *base = Physbase();

	
	plotRectangle(base, 0, 0, 640, 400);
	



	return 0;
}
