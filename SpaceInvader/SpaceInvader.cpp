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

int s[10];
int t[3];
static int score = 0;
static int life;
bool gameStarted;
int bulletImage[7][1] = {
	{1},
	{1},
	{1},
	{1},
	{1},
	{1},
	{1}
};

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


void updateScore(int x) {
	for (int i = 104; i < 150;i++) {
		for (int j = 7; j < 15;j++) {
			SetPixel(i, j, BLACK);
		}
	}
	int index = 0;
	if (x == 0) {
		s[index] = 0;
		for (int m = 0;m < 8;m++) {
			for (int n = 0;n < 8;n++) {
				if (font[48][m][n] == 1) {
					SetPixel(104 + n, 7 + m, GREEN);
				}
			}
		}
		return;
	}
	while (x > 0) {
		s[index] = x % 10;
		x = x / 10;
		index++;
	}
	for (int i = index - 1;i >= 0;i--) {
		for (int m = 0;m < 8;m++) {
			for (int n = 0;n < 8;n++) {
				int idx = 48 + s[i];
				if (font[idx][m][n] == 1) {
					SetPixel(104 + n + (index - i - 1) * 9, 7 + m, GREEN);
				}
			}
		}
	}
}


void draw_back_ground() {
	for (int j = 0;j < 200;j++) {
		for (int i = 0;i < 40;i++) {
			SetPixel(i, j, GREY);
			SetPixel(280 + i, j, GREY);
		}
	}

	for (int i = 40;i < 280;i++) {
		SetPixel(i, 190, GREEN);
	}
}


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

	void drawShape(int id) {
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
		case 18:
			for (int i = 0;i < width;i++) {
				for (int j = 0;j < height;j++) {
					if (bulletImage[j][i] == 1) {
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
		x = ((x - step) > 40) ? (x - step) : 40;
		drawShape(id);
	}

	void moveRight(int step) {
		deleteShape();
		x = ((x + step) < (280 - width)) ? (x + step) : (280 - width);
		drawShape(id);
	}

	void moveDown(int step) {
		deleteShape();
		y = ((y + step));
		drawShape(id);
	}

	void moveUp(int step) {
		deleteShape();
		y = (y - step);
		drawShape(id);
	}
};

struct Invader : Shape {
	int state;
} invader[5][11];

int commonState;
int startX;
int startY;
bool r;
bool d;

void drawAllInvaders(int startX, int startY, int state) {
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 11;j++) {
			invader[i][j].width = 12;
			invader[i][j].height = 8;
			invader[i][j].x = startX + j * invader[i][j].width + j * 2;
			invader[i][j].y = startY + i * invader[i][j].height + i * 5;
			invader[i][j].color = WHITE;
			if (invader[i][j].state == 4) {
				continue;
			}
			else {
				invader[i][j].state = state;
				if (state == 0) {
					if (i == 0) invader[i][j].id = 8;
					else if (i == 1 || i == 2) invader[i][j].id = 6;
					else invader[i][j].id = 4;
				}
				if (state == 1) {
					if (i == 0) invader[i][j].id = 9;
					else if (i == 1 || i == 2) invader[i][j].id = 7;
					else invader[i][j].id = 5;
				}
				invader[i][j].drawShape(invader[i][j].id);
			}
		}
	}
}
void clearAllInvader() {
	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 11;j++) {
			invader[i][j].deleteShape();
		}
	}
}
void moveAllInvader() {
	commonState = (commonState + 1) % 2;
	clearAllInvader();

	if (d) {
		drawAllInvaders(startX, startY, commonState);
		d = false;
		return;
	}

	if (r) {
		startX = (startX + 4 < 126) ? (startX + 4) : 126;
		drawAllInvaders(startX, startY, commonState);
		if (startX == 126) {
			r = false;
			startY = startY + 4;
			d = true;
		}
	}
	else {
		startX = (startX - 4 > 40) ? (startX - 4) : 40;
		drawAllInvaders(startX, startY, commonState);
		if (startX == 40) {
			r = true;
			startY = startY + 4;
			d = true;
		}
	}
}

struct UFO : Shape {
	int UFOscore;
	int right;
	bool isShooted;
	bool isDeleted;

	void init() {
		isDeleted = false;
		id = 2;
		x = 41;
		y = 25;
		width = 16;
		height = 8;
		color = RED;
		drawShape(id);
		UFOscore = (RandNum() % 6 + 1) * 50;
		right = RandNum() % 2;
		isDeleted = false;
	}

	void move() {
		if (right == 1) {
			moveRight(3);
			if (x == 264) {
				isDeleted = true;
				deleteShape();
				return;
			}
		}
		if (right == 0) {
			moveLeft(3);
			if (x == 40) {
				isDeleted = true;
				deleteShape();
				return;
			}
		}
	}

	void toScore() {
		int index = 0;
		while (UFOscore > 0) {
			t[index] = UFOscore % 10;
			UFOscore = UFOscore / 10;
			index++;
		}
		t[index] = '/0';
		for (int i = index - 1;i >= 0;i--) {
			for (int m = 0;m < 5;m++) {
				for (int n = 0;n < 3;n++) {
					if (smallNumber[t[i]][m][n] == 1) {
						SetPixel(x + n + (index - i - 1) * 4, y + m, RED);
					}
				}
			}
		}
	}
} ufo;


struct SpaceShip : Shape {
	int state;

	void init() {
		id = 1;
		x = 67;
		y = 171;
		width = 17;
		height = 8;
		color = GREEN;
		state = 0;
		drawShape(id);
	}
} spaceship;

void updateLife(int life) {
	for (int l = 0;l < 3;l++) {
		SpaceShip s;
		s.x = 200 + l * 17 + l * 3;
		s.y = 6;
		s.width = 17;
		s.height = 8;
		s.id = 1;
		s.color = BLACK;
		s.drawShape(s.id);
	}
	for (int l = 0;l < life;l++) {
		SpaceShip s;
		s.x = 200 + l * 17 + l * 3;
		s.y = 6;
		s.width = 17;
		s.height = 8;
		s.id = 1;
		s.color = GREEN;
		s.drawShape(s.id);
	}
}
struct Missile : Shape {
	bool isShooted;
	bool isDeleted;
	int type;
	int step;

	void init(Invader invader) {
		if (isShooted && isDeleted) {
			isShooted = false;
			isDeleted = false;
		}

		if (!isShooted && !isDeleted) {
			type = RandNum() % 2;
			id = (type % 2 == 0) ? 10 : 12;
			x = invader.x + 5;
			y = invader.y + 8;
			width = 3;
			height = 5;
			color = WHITE;
			step = 0;
		}
	}

	void move() {
		isShooted = true;
		step++;
		if (step == 5) {
			step = 0;
			if (type == 0) {
				id++;
				if (id > 11) id = 10;
			}
			else {
				id++;
				if (id > 13) id = 12;
			}
		}
		moveDown(1);
		if (GetPixel(x, y + 5) != BLACK || y + 5 >= 190) {
			if ((GetPixel(x, y + 5) == GREEN || GetPixel(x + 2, y + 5) == GREEN) && (y + 5) < 190) {
				spaceship.state = 1;
				life--;
				updateLife(life);
			}
			isDeleted = true;
			deleteShape();
		}
	}
} missile;

struct Bullet : Shape {
	bool isShooted;
	bool isDeleted;

	void init(SpaceShip spaceship) {
		if (isShooted && isDeleted) {
			isShooted = false;
			isDeleted = false;
		}

		if (!isShooted && !isDeleted) {
			id = 18;
			x = spaceship.x + 8;
			y = spaceship.y - 8;
			width = 1;
			height = 7;
			color = WHITE;
			drawShape(id);
			isShooted = true;
		}
	}

	void move() {
		moveUp(1);
		if (GetPixel(x, y - 1) != BLACK || y - 1 < 20) {
			if (GetPixel(x, y - 1) == WHITE) {
				for (int i = 0;i < 5;i++) {
					for (int j = 0;j < 11;j++) {
						if (x >= invader[i][j].x && x <= (invader[i][j].x + 12) && y >= invader[i][j].y && y <= (invader[i][j].y + 8)) {
							invader[i][j].state = 3;
							invader[i][j].id = 17;
							invader[i][j].deleteShape();
							invader[i][j].drawShape(invader[i][j].id);
							invader[i][j].state = 4;
							score = score + 10;
							updateScore(score);
							break;
						}
					}
				}
			}

			if (GetPixel(x, y - 1) == RED) {
				ufo.isDeleted = true;
				cout << ufo.UFOscore << "\n";
				cout << score << "\n";
				score = score + ufo.UFOscore;
				updateScore(score);

				ufo.deleteShape();
				ufo.toScore();
			}
			isDeleted = true;
			deleteShape();
			return;
		}
	}
} bullet;

void clearMap() {
	for (int i = 40;i < 280;i++) {
		for (int j = 20;j < 200;j++) {
			SetPixel(i, j, BLACK);
		}
	}
}
void newGame() {
	clearMap();

	life = 3;
	commonState = 0;
	startX = 78;
	startY = 36;
	r = true;
	d = false;

	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 11;j++) {
			invader[i][j].state = commonState;
		}
	}
	updateScore(score);
	updateLife(life);
	drawAllInvaders(78, 36, commonState);
	spaceship.init();

	missile.isShooted = false;
	missile.isDeleted = false;

	bullet.isShooted = false;
	bullet.isDeleted = false;

	ufo.isDeleted == true;

}

void initBackground() {
	draw_text();
	draw_back_ground();
}

int main() {
	initBackground();
	newGame();
	int currentTime1 = 0;
	int currentTime2 = 0;
	int currentTime3 = 0;
	int currentTime4 = 0;
	int currentTime5 = 0;
	int currentTime6 = 0;

	while (true) {

		int keyPressed = GetInput(false);


		if (keyPressed == 32 && spaceship.state == 0) {
			bullet.init(spaceship);
		}

		if (keyPressed == 144 && spaceship.state == 0) {
			spaceship.moveLeft(3);
		}

		if (keyPressed == 146 && spaceship.state == 0) {
			spaceship.moveRight(3);
		}

		if ((GetMilisec() > (currentTime1 + 500)) && spaceship.state == 0) {
			currentTime1 = GetMilisec();
			moveAllInvader();
		}

		if ((GetMilisec() > (currentTime2 + 30)) && spaceship.state == 0) {
			currentTime2 = GetMilisec();
			missile.init(invader[4][5]);
			missile.move();
		}

		if ((GetMilisec() > (currentTime3 + 5)) && spaceship.state == 0) {
			currentTime3 = GetMilisec();
			if (bullet.isShooted && !bullet.isDeleted) {
				bullet.move();
			}
		}

		if ((GetMilisec() > (currentTime4 + 500)) && spaceship.state != 0) {
			currentTime4 = GetMilisec();
			if (spaceship.state == 1) {
				spaceship.id = 14;
			}
			if (spaceship.state == 2) {
				spaceship.id = 15;
			}
			if (spaceship.state == 3) {
				spaceship.id = 16;
			}
			if (spaceship.state == 4) {
				spaceship.deleteShape();
				spaceship.init();
				bullet.isDeleted = true;
				bullet.deleteShape();
				if (life == 0) {
					newGame();
				}
				continue;
			}
			spaceship.deleteShape();
			spaceship.drawShape(spaceship.id);
			spaceship.state++;

		}
		if ((GetMilisec() > (currentTime5 + 200)) && spaceship.state == 0) {
			currentTime5 = GetMilisec();
			if (ufo.isDeleted == false) {
				ufo.move();
			}
		}

		if ((GetMilisec() > (currentTime6 + 500)) && spaceship.state == 0) {
			currentTime6 = GetMilisec();
			if (ufo.isDeleted == true) {
				ufo.deleteShape();
				ufo.init();
			}
		}
	}
	return 0;
}
