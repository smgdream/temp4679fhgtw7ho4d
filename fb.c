#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>

#define FB_DEV "/dev/fb0"

typedef struct px_argb_tag {
	int a, r, g, b;
} Px_argb;

int main()
{
	FILE *fb =  NULL;
	Px_argb *buf = NULL;

	if ((fb = fopen(FB_DEV, "wb")) == NULL) {
		fprintf(stderr, "open error: %s\n", FB_DEV);
		return 1;
	}

	buf = (Px_argb *) calloc(1, 1920 * 1080 * sizeof(Px_argb));
	for (int cnt = 1920 * 1080; cnt > 0; --cnt) {
		buf->a = 255;
		buf->r = 255;
		buf->g = 255;
		buf->b = 255;
		++buf;
	}
	while (1)
	fwrite(buf, 1920 * 1080 * sizeof(Px_argb), 1, fb);
	fclose(fb);

	return 0;
	
}
