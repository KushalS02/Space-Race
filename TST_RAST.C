#include <osbind.h>
#include "raster.h"

int main()
{
	void *base = Physbase();

	
	plotRectangle(base, 0, 0, 400, 640);
	



	return 0;
}
