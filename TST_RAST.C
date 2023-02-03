#include <osbind.h>
#include "raster.h"

int main()
{
	void *base = Physbase();

	plotPixel(base, 300, 300);

	return 0;
}
