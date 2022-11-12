#include "ppm.h"

void ppm3_write(FILE* out, Canvas *canvas)
{
	fprintf(out, "%d %d\n", canvas->w, canvas->h);
	fprintf(out, "255\n");
	for (int y = 0; y < canvas->h; ++y)
	{
		int offset = canvas->w * y;
		for (int x = 0; x < canvas->w; ++x)
		{
			Color color = canvas->data[offset + x];
			int r = color.r * 255;
			int g = color.g * 255;
			int b = color.b * 255;
			fprintf(out, "%d %d %d\n", r, g, b);
		}
	}
}
