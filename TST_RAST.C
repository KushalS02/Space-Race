#include <osbind.h>
#include "raster.h"

int main()
{
	void *base = Physbase();

	plotScreen(base, 1000);
	plotPixel(base, 300, 300);



	return 0;
}
