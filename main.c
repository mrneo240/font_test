
#include "tro.h"
#define PI 3.141592654

#define BUFFER_POS(X, Y) (Y * 640 + X)

//------------------------------------
// Main Stuff
//------------------------------------
extern void bfont_draw_large_str(uint16 *buffer, int width, char *str);
extern void draw_char24(int x, int y, int ch, int rgb);
extern void bfont_draw_mid_symbol(uint16 *buffer, int chr);
extern void bfont_draw_large_letter(uint16 *buffer, uint8 c);
int chrSelected = 0;
int flashing = 0;
char txtDisplay[19];

char *dispFlash(char *str)
{
	if (flashing)
	{
		txtDisplay[chrSelected] = ' ';
	}
	else
	{
		txtDisplay[chrSelected] = str[chrSelected];
	}
	return &txtDisplay;
}

int main()
{
	uint16 controls = 0;

	clrscr(0);
	init_video(check_cable(), 1);
	int running = 1;
	flashing = 0;
	chrSelected = 1;

	char *txt = "PRESS START BUTTON";

	memcpy(txtDisplay, txt, 19);

	do
	{

		bfont_draw_large_str(vram_s + BUFFER_POS(0, 0), 640, dispFlash(txt));
		bfont_draw_large_str(vram_s + BUFFER_POS(64, 440), 640, "PRESS");
		bfont_draw_mid_symbol(vram_s + BUFFER_POS(64 + (32 * 6), 440), 518400 + (11 * 72));
		bfont_draw_large_str(vram_s + BUFFER_POS(64 + (32 * 8), 440), 640, "TO PATCH");
		sleep_ms(500);
		clrscr(0);
		flashing = !flashing;

	} while (running);
}
