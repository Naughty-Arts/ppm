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

Canvas* ppm3_read(FILE* in)
{
	fseek(in, 0, SEEK_END);
	long length = ftell(in);
	char* buffer = malloc(sizeof(char) * length);
	fseek(in, 0, SEEK_SET);
	fread(buffer, 1, length, in);

	char* pointer = buffer;
	if (strncmp(pointer, "P3", 2) != 0)
	{
		fprintf(stderr, "File is not P3\n");
		exit(EXIT_FAILURE);
	}
	pointer += 3;

	// skip the comment
	if (*pointer == '#')
	{
		while (*pointer != '\n') ++pointer;
		++pointer;
	}

	int width = atoi(pointer);
	while (*pointer != ' ' && *pointer != '\n') ++pointer;
	++pointer;

	int height = atoi(pointer);
	while (*pointer != ' ' && *pointer != '\n') ++pointer;
	++pointer;

	Canvas* canvas = canvas_make(width, height);

	int ppm_number = atoi(pointer);
	if (ppm_number != 255)
	{
		fprintf(stderr, "Only 255 colors are supported for p3\n");
		exit(EXIT_FAILURE);
	}

	while (*pointer != ' ' && *pointer != '\n') ++pointer; ++pointer;

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			int red = atoi(pointer);
			while (*pointer != ' ' && *pointer != '\n') ++pointer; ++pointer;
			int green = atoi(pointer);
			while (*pointer != ' ' && *pointer != '\n') ++pointer; ++pointer;
			int blue = atoi(pointer);
			while (*pointer != ' ' && *pointer != '\n') ++pointer; ++pointer;
			Color color = { red / 255.0, green / 255.0, blue / 255.0, 1 };
			canvas_set(canvas, x, y, color);
		}
	}	

	return canvas;	
}

/*
char * buffer = 0;
long length;
FILE * f = fopen (filename, "rb");

if (f)
{
  fseek (f, 0, SEEK_END);
  length = ftell (f);
  fseek (f, 0, SEEK_SET);
  buffer = malloc (length);
  if (buffer)
  {
    fread (buffer, 1, length, f);
  }
  fclose (f);
}

if (buffer)
{
  // start to process your data / extract strings here...
}
*/
