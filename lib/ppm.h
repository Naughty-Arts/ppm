#ifndef _PPM_H_
#define _PPM_H_

#define ppm3_write(out, _canvas) fprintf(out, "P3\n");\
			fprintf(out, "%d %d\n", _canvas->w, _canvas->h);\
			fprintf(out, "255\n");\
			for (int y = 0; y < _canvas->h; ++y)\
			{\
				int offset = _canvas->w * y;\
				for (int x = 0; x < _canvas->w; ++x)\
				{\
					c color = _canvas->d[offset + x];\
					int r = color.r * 255;\
					int g = color.g * 255;\
					int b = color.b * 255;\
					fprintf(out, "%d %d %d\n", r, g, b);\
				}\
			}

#endif
