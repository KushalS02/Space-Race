#include <osbind.h>
#include "raster.h"

int main()
{
	void *base = Physbase();

	plotHorizontalLine(base, 10, 10, 50);
	plotRectangle(base, 35, 50, 10, 20);
	plotPixel(base, 300, 300);



	return 0;
}
