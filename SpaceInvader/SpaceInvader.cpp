#include "stc.h"
#include "font.h"
#include "bitmap.h"
#include <iostream>
using namespace std;

#define RED 0xff0000
#define BLUE 0x0000ff
#define GREEN 0x00ff00
#define BLACK 0x000000
#define WHITE 0xffffff
#define YELLOW 0xfff000
#define PINK 0x800080
#define MINT 0x429E9D
#define GREY 0x5a5a5a
#define ORANGE 0x654321

char s[100];
int score;
int life;

struct Shape {
	int id;
	int x;
	int y;
	int width;
	int height;
	unsigned int color;

	void deleteShape() {
		for (int i = x;i < x + width;i++) {
			for (int j = y;j < y + height;j++) {
				SetPixel(i, j, BLACK);
			}
		}
	}

	void drawShape() {
		switch (id)
		{
		case 1:
			for (int i = 0;i < width;i++) {
				for (int j = 0;j < height;j++) {
					if (spaceShip[j][i] == 1) {
						SetPixel(x + i, y + j, color);
					}
				}
			}
			break;
		case 2:
			for (int i = 0;i < width;i++) {
				for (int j = 0;j < height;j++) {
					if (UFOImage[j][i] == 1) {
						SetPixel(x + i, y + j, color);
					}
				}
			}
			break;
		case 3:
			for (int i = 0;i < width;i++) {
				for (int j = 0;j < height;j++) {
					if (shieldImage[j][i] == 1) {
						SetPixel(x + i, y + j, color);
					}
				}
			}
			break;

		case 4:
			for (int i = 0;i < width;i++) {
				for (int j = 0;j < height;j++) {
					if (invaderFirstImage1[j][i] == 1) {
						SetPixel(x + i, y + j, color);
					}
				}
			}
			break;

		case 5:
			for (int i = 0;i < width;i++) {
				for (int j = 0;j < height;j++) {
					if (invaderFirstImage2[j][i] == 1) {
						SetPixel(x + i, y + j, color);
					}
				}
			}
			break;

		case 6:
			for (int i = 0;i < width;i++) {
				for (int j = 0;j < height;j++) {
					if (invaderSecondImage1[j][i] == 1) {
						SetPixel(x + i, y + j, color);
					}
				}
			}
			break;
		case 7:
			for (int i = 0;i < width;i++) {
				for (int j = 0;j < height;j++) {
					if (invaderSecondImage2[j][i] == 1) {
						SetPixel(x + i, y + j, color);
					}
				}
			}
			break;
		case 8:
			for (int i = 0;i < width;i++) {
				for (int j = 0;j < height;j++) {
					if (invaderThirdImage1[j][i] == 1) {
						SetPixel(x + i, y + j, color);
					}
				}
			}
			break;
		case 9:
			for (int i = 0;i < width;i++) {
				for (int j = 0;j < height;j++) {
					if (invaderThirdImage2[j][i] == 1) {
						SetPixel(x + i, y + j, color);
					}
				}
			}
			break;
		case 10:
			for (int i = 0;i < width;i++) {
				for (int j = 0;j < height;j++) {
					if (missileFirstImage1[j][i] == 1) {
						SetPixel(x + i, y + j, color);
					}
				}
			}
			break;
		case 11:
			for (int i = 0;i < width;i++) {
				for (int j = 0;j < height;j++) {
					if (missileFirstImage2[j][i] == 1) {
						SetPixel(x + i, y + j, color);
					}
				}
			}
			break;

		case 12:
			for (int i = 0;i < width;i++) {
				for (int j = 0;j < height;j++) {
					if (missileSecondImage1[j][i] == 1) {
						SetPixel(x + i, y + j, color);
					}
				}
			}
			break;

		case 13:
			for (int i = 0;i < width;i++) {
				for (int j = 0;j < height;j++) {
					if (missileSecondImage2[j][i] == 1) {
						SetPixel(x + i, y + j, color);
					}
				}
			}
			break;

		case 14:
			for (int i = 0;i < width;i++) {
				for (int j = 0;j < height;j++) {
					if (breakSpaceShip1[j][i] == 1) {
						SetPixel(x + i, y + j, color);
					}
				}
			}
			break;

		case 15:
			for (int i = 0;i < width;i++) {
				for (int j = 0;j < height;j++) {
					if (breakSpaceShip2[j][i] == 1) {
						SetPixel(x + i, y + j, color);
					}
				}
			}
			break;

		case 16:
			for (int i = 0;i < width;i++) {
				for (int j = 0;j < height;j++) {
					if (breakSpaceShip3[j][i] == 1) {
						SetPixel(x + i, y + j, color);
					}
				}
			}
			break;

		case 17:
			for (int i = 0;i < width;i++) {
				for (int j = 0;j < height;j++) {
					if (breakInvader[j][i] == 1) {
						SetPixel(x + i, y + j, color);
					}
				}
			}
			break;
		default:
			break;
		}
	}

	void moveLeft(int step) {
		deleteShape();
		x = (x - step > 40) ? (x - step) : 40;
		drawShape();
	}

	void moveRight(int step) {
		deleteShape();
		x = (x + step < (280 - width)) ? (x + step) : (280 - width);
		drawShape();
	}

	void moveDown(int step) {
		deleteShape();
		y = y + step;
		drawShape();
	}
};

struct Invader : Shape {
	int state;

};

Invader invader[3][6];

void drawInvader() {
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 6;j++) {
			invader[i][j].x = 40 + j * 15;
			invader[i][j].y = 20 + i * 11;
			invader[i][j].width = 12;
			invader[i][j].height = 8;
			invader[i][j].id = (i % 3)*2 + 4;
			invader[i][j].color = WHITE;
			invader[i][j].drawShape();

		}
	}
}

void draw_char(char c, int x, int y, unsigned int color) {
	int posY = 0;

	while (posY < 8)
	{
		int posX = 0;

		while (posX < 8)
		{
			if (font[c][posY][posX] == 1) SetPixel(posX + x, posY + y, color);
			else SetPixel(posX + x, posY + y, BLACK);
			posX++;
		}
		posY++;
	}
}

void draw_text() {
	draw_char('S', 56, 7, WHITE);
	draw_char('C', 64, 7, WHITE);
	draw_char('O', 72, 7, WHITE);
	draw_char('R', 80, 7, WHITE);
	draw_char('E', 88, 7, WHITE);

	draw_char('L', 152, 7, WHITE);
	draw_char('I', 160, 7, WHITE);
	draw_char('V', 168, 7, WHITE);
	draw_char('E', 176, 7, WHITE);
	draw_char('S', 184, 7, WHITE);
}

void swap(char& a, char& b) {
	char c = a;
	a = b;
	b = c;
}

char* toString(int x) {
	int size = 0;
	if (x == 0) {
		s[0] = '0';
		s[1] = '\0';
		return s;
	}
	while (x > 0) {
		s[size++] = x % 10 + '0';
		x /= 10;
	}
	s[size] = '\0';
	for (int i = 0; i < size / 2; i++) {
		swap(s[i], s[size - i - 1]);
	}
	return s;
}

void updateScore(int x) {
	for (int i = 104; i < 150;i++) {
		for (int j = 7; j < 15;j++) {
			SetPixel(i, j, BLACK);
		}
	}

	char* t = toString(x);
	for (int i = 0;t[i] != '\0';i++) {
		draw_char(t[i], 104 + i * 8, 7, GREEN);
	}
}

void draw_back_ground() {
	for (int j = 0;j < 200;j++) {
		for (int i = 0;i < 40;i++) {
			SetPixel(i, j, GREY);
			SetPixel(280 + i, j, GREY);
		}
	}
}


void init() {
	score = 0;
	draw_text();
	updateScore(score);
	draw_back_ground();
}

int main() {
	init();
	drawInvader();
	//while (true) {
	//	int keyPressed = GetInput(false);
	//	if (keyPressed == 144) {
	//		cout << keyPressed;

	//		ship.moveLeft(5);
	//	}
	//	if (keyPressed == 146) {
	//		cout << keyPressed;
	//		ship.moveRight(5);
	//	}
	//}
	return 0;
}
