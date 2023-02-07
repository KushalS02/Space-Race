#include <osbind.h>
#include "raster.h"

int main()
{
	void *base = Physbase();

	plotHorizontalLine(base, 10, 10, 400);
	plotRectangle(base, 35, 50, 60, 120);
	plotPixel(base, 300, 300);



	return 0;
}
