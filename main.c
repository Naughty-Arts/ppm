#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <color.h>
#include <canvas.h>

#include "ppm.h"

int main()
{
	printf("------------------ PPM -------------------- \n");

	Canvas* canvas = canvas_make(32, 16);

	color_init();

	for (int i = 8; i < 24; ++i)
	{
		for (int j = 4; j < 6; ++j)
		{
			canvas_set(canvas, i, j, red);
		}
	}

	for (int i = 0; i < 32; ++i)
	{
		canvas_set(canvas, i, 0, blue);
		canvas_set(canvas, i, 15, blue);
	}

	for (int i = 0; i < 16; ++i)
	{
		canvas_set(canvas, 0, i, blue);
		canvas_set(canvas, 31, i, blue);
	}

	FILE* out = fopen("canvas.ppm", "w");
	ppm3_write(out, canvas);
	fclose(out);
}