#include <osbind.h>
#include "raster.h"

int main()
{
	void *base = Physbase();

	plotHorizontalLine(base, 10, 10, 50);
	plotPixel(base, 300, 300);



	return 0;
}
