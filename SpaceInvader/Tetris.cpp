//#include "stc.h"
//#include "font.h"
//#include <iostream>
//using namespace std;
//
//#define RED 0xff0000
//#define BLUE 0x0000ff
//#define GREEN 0x00ff00
//#define BLACK 0x000000
//#define WHITE 0xffffff
//#define YELLOW 0xfff000
//#define PINK 0x800080
//#define MINT 0x429E9D
//#define GREY 0x5a5a5a
//#define ORANGE 0x654321	
//
//char s[100];
//int grid[22][13];
//
//int score;
//int row;
//int col;
//bool stop;
//int id;
//int turn;
//
//void init_grid() {
//	for (int i = 0;i < 22;i++) {
//		grid[i][0] = -1;
//		grid[i][11] = -1;
//		grid[i][12] = -1;
//	}
//	for (int j = 0;j < 13;j++) {
//		grid[20][j] = -1;
//		grid[21][j] = -1;
//
//	}
//}
//
//void draw_char(char c, int x, int y, unsigned int color) {
//	int posY = 0;
//
//	while (posY < 8)
//	{
//		int posX = 0;
//
//		while (posX < 8)
//		{
//			if (font[c][posY][posX] == 1) SetPixel(posX + x, posY + y, color);
//			else SetPixel(posX + x, posY + y, BLACK);
//			posX++;
//		}
//		posY++;
//	}
//}
//
//void draw_text() {
//	draw_char('S', 0, 0, YELLOW);
//	draw_char('C', 8, 0, YELLOW);
//	draw_char('O', 16, 0, YELLOW);
//	draw_char('R', 24, 0, YELLOW);
//	draw_char('E', 32, 0, YELLOW);
//}
//
//void updateScore(int x) {
//	for (int i = 48; i < 72;i++) {
//		for (int j = 0; j < 8;j++) {
//			SetPixel(i, j, BLACK);
//		}
//	}
//	char t[4];
//	t[3] = '\0';
//	t[2] = (x % 10) + '0';
//	x = x / 10;
//	t[1] = (x % 10) + '0';
//	x = x / 10;
//	t[0] = (x % 10) + '0';
//
//	for (int i = 0;t[i] != '\0';i++) {
//		draw_char(t[i], 48 + i * 8, 0, YELLOW);
//	}
//}
//
//void draw_background() {
//	for (int y = 0;y < 200;y++) {
//		for (int x = 0; x <= 110;x++) {
//			if (x < 40 && y < 8) {
//				SetPixel(x, y, BLACK);
//			}
//			else if (x > 48 && x < 72 && y < 8) {
//				SetPixel(x, y, BLACK);
//			}
//			else {
//				SetPixel(x, y, GREY);
//			}
//		}
//
//		for (int x = 210; x < 320;x++) {
//			SetPixel(x, y, GREY);
//		}
//	}
//
//	for (int i = 120;i <= 200;i += 10) {
//		for (int j = 0;j < 200;j++) {
//			SetPixel(i, j, ORANGE);
//		}
//	}
//	for (int i = 110;i < 210;i++) {
//		for (int j = 10;j <= 190;j += 10) {
//			SetPixel(i, j, ORANGE);
//		}
//	}
//}
//
//void draw_half_background() {
//	for (int y = 0;y < 200;y++) {
//		for (int x = 210; x < 320;x++) {
//			SetPixel(x, y, GREY);
//		}
//	}
//}
//
//
//int s1[1][2][2] = {
//	{
//		{ 1, 1},
//		{ 1, 1}
//	}
//};
//
//
//int s2[4][3][3] = {
//	{
//		{ 0, 1, 1},
//		{ 0, 1, 0},
//		{ 0, 1, 0}
//	},
//	{
//		{ 0, 0, 0},
//		{ 1, 1, 1},
//		{ 0, 0, 1}
//	},
//	{
//		{ 0, 1, 0},
//		{ 0, 1, 0},
//		{ 1, 1, 0}
//	},
//	{
//		{ 1, 0, 0},
//		{ 1, 1, 1},
//		{ 0, 0, 0}
//	},
//};
//
//int s3[4][3][3] = {
//	{
//		{ 1, 1, 0},
//		{ 0, 1, 0},
//		{ 0, 1, 0}
//	},
//	{
//		{ 0, 0, 1},
//		{ 1, 1, 1},
//		{ 0, 0, 0}
//	},
//	{
//		{ 0, 1, 0},
//		{ 0, 1, 0},
//		{ 0, 1, 1}
//	},
//	{
//		{ 0, 0, 0},
//		{ 1, 1, 1},
//		{ 1, 0, 0}
//	},
//};
//
//int s4[2][4][4] = {
//	{
//		{ 0, 1, 0, 0},
//		{ 0, 1, 0, 0},
//		{ 0, 1, 0, 0},
//		{ 0, 1, 0, 0}
//	},
//	{
//		{ 0, 0, 0, 0},
//		{ 1, 1, 1, 1},
//		{ 0, 0, 0, 0},
//		{ 0, 0, 0, 0},
//
//	}
//};
//
//int s5[4][3][3] = {
//	{
//		{ 0, 1, 0},
//		{ 1, 1, 1},
//		{ 0, 0, 0}
//	},
//	{
//		{ 0, 1, 0},
//		{ 0, 1, 1},
//		{ 0, 1, 0}
//	},
//	{
//		{ 0, 0, 0},
//		{ 1, 1, 1},
//		{ 0, 1, 0}
//	},
//	{
//		{ 0, 1, 0},
//		{ 1, 1, 0},
//		{ 0, 1, 0}
//	},
//};
//
//int s6[2][3][3] = {
//	{
//		{ 0, 1, 0},
//		{ 1, 1, 0},
//		{ 1, 0, 0}
//	},
//	{
//		{ 1, 1, 0},
//		{ 0, 1, 1},
//		{ 0, 0, 0}
//	}
//};
//
//int s7[2][3][3] = {
//	{
//		{ 0, 1, 0},
//		{ 0, 1, 1},
//		{ 0, 0, 1}
//	},
//	{
//		{ 0, 1, 1},
//		{ 1, 1, 0},
//		{ 0, 0, 0}
//	}
//};
//
//
//bool check_square_2(int a[][2][2], int r, int c) {
//	for (int m = 0; m < 2; m++) {
//		for (int n = 0; n < 2; n++) {
//			if (a[0][m][n] == 1 && grid[r + m][c + n + 1] != 0) return false;
//		}
//	}
//	return true;
//}
//
//void tick_square_2(int a[][2][2], int r, int c) {
//	for (int m = 0; m < 2; m++) {
//		for (int n = 0; n < 2; n++) {
//			if (a[0][m][n] == 1) {
//				grid[r + m][c + n + 1] = 1;
//			}
//		}
//	}
//}
//
//void delete_square_2(int r, int c) {
//	for (int m = 0; m < 2; m++) {
//		for (int n = 0; n < 2; n++) {
//			int y = (r + m) * 10 + 1;
//			int x = (c + n) * 10 + 110 + 1;
//			if (x >= 110 && x < 210 && grid[r + m][c + n + 1] == 0) {
//				for (int i = x; i < x + 9;i++) {
//					for (int j = y;j < y + 9;j++) {
//						SetPixel(i, j, BLACK);
//					}
//				}
//			}
//		}
//	}
//}
//
//void draw_square_2(int a[][2][2], int r, int c, unsigned int color) {
//	for (int m = 0; m < 2; m++) {
//		for (int n = 0; n < 2; n++) {
//			if (a[0][m][n] == 1) {
//				int y = (r + m) * 10 + 1;
//				int x = (c + n) * 10 + 110 + 1;
//				for (int i = x; i < x + 9;i++) {
//					for (int j = y;j < y + 9;j++) {
//						SetPixel(i, j, color);
//					}
//				}
//			}
//		}
//	}
//}
//
//
//
//bool check_square_3(int a[][3][3], int r, int c, int turn) {
//	for (int m = 0; m < 3; m++) {
//		for (int n = 0; n < 3; n++) {
//			if (a[turn][m][n] == 1 && grid[r + m][c + n + 1] != 0) return false;
//		}
//	}
//	return true;
//}
//
//void tick_square_3(int a[][3][3], int r, int c, int turn) {
//	for (int m = 0; m < 3; m++) {
//		for (int n = 0; n < 3; n++) {
//			if (a[turn][m][n] == 1) {
//				grid[r + m][c + n + 1] = 1;
//			}
//		}
//	}
//}
//
//void delete_square_3(int r, int c) {
//	for (int m = 0; m < 3; m++) {
//		for (int n = 0; n < 3; n++) {
//			int y = (r + m) * 10 + 1;
//			int x = (c + n) * 10 + 110 + 1;
//			if (x >= 110 && x < 210 && grid[r + m][c + n + 1] == 0) {
//				for (int i = x; i < x + 9;i++) {
//					for (int j = y;j < y + 9;j++) {
//						SetPixel(i, j, BLACK);
//					}
//				}
//			}
//		}
//	}
//}
//
//void draw_square_3(int a[][3][3], int r, int c, unsigned int color, int turn) {
//	for (int m = 0; m < 3; m++) {
//		for (int n = 0; n < 3; n++) {
//			if (a[turn][m][n] == 1) {
//				int y = (r + m) * 10 + 1;
//				int x = (c + n) * 10 + 110 + 1;
//				for (int i = x; i < x + 9;i++) {
//					for (int j = y;j < y + 9;j++) {
//						SetPixel(i, j, color);
//					}
//				}
//			}
//		}
//	}
//}
//
//bool check_square_4(int a[][4][4], int r, int c, int turn) {
//	for (int m = 0; m < 4; m++) {
//		for (int n = 0; n < 4; n++) {
//			if (a[turn][m][n] == 1 && grid[r + m][c + n + 1] != 0) return false;
//		}
//	}
//	return true;
//}
//
//void tick_square_4(int a[][4][4], int r, int c, int turn) {
//	for (int m = 0; m < 4; m++) {
//		for (int n = 0; n < 4; n++) {
//			if (a[turn][m][n] == 1) {
//				grid[r + m][c + n + 1] = 1;
//			}
//		}
//	}
//}
//
//void delete_square_4(int r, int c) {
//	for (int m = 0; m < 4; m++) {
//		for (int n = 0; n < 4; n++) {
//			int y = (r + m) * 10 + 1;
//			int x = (c + n) * 10 + 110 + 1;
//			if (x >= 110 && x < 210 && grid[r + m][c + n + 1] == 0) {
//				for (int i = x; i < x + 9;i++) {
//					for (int j = y;j < y + 9;j++) {
//						SetPixel(i, j, BLACK);
//					}
//				}
//			}
//		}
//	}
//}
//
//void draw_square_4(int a[][4][4], int r, int c, unsigned int color, int turn) {
//	for (int m = 0; m < 4; m++) {
//		for (int n = 0; n < 4; n++) {
//			if (a[turn][m][n] == 1) {
//				int y = (r + m) * 10 + 1;
//				int x = (c + n) * 10 + 110 + 1;
//				for (int i = x; i < x + 9;i++) {
//					for (int j = y;j < y + 9;j++) {
//						SetPixel(i, j, color);
//					}
//				}
//			}
//		}
//	}
//}
//
//bool check_shape(int id, int r, int c, int turn) {
//	if (id == 1) return check_square_2(s1, r, c);
//	else if (id == 2) return check_square_3(s2, r, c, turn);
//	else if (id == 3) return check_square_3(s3, r, c, turn);
//	else if (id == 4) return check_square_4(s4, r, c, turn);
//	else if (id == 5) return check_square_3(s5, r, c, turn);
//	else if (id == 6) return check_square_3(s6, r, c, turn);
//	else return check_square_3(s7, r, c, turn);
//}
//
//void delete_shape(int id, int r, int c) {
//	if (id == 1) delete_square_2(r, c);
//	else if (id == 4) delete_square_4(r, c);
//	else delete_square_3(r, c);
//}
//
//void draw_shape(int id, int turn, int r, int c) {
//	if (id == 1) {
//		draw_square_2(s1, r, c, WHITE);
//	}
//	else if (id == 2) {
//		if (turn == 0) {
//			draw_square_3(s2, r, c, BLUE, 0);
//		}
//		else if (turn == 1) {
//			draw_square_3(s2, r, c, BLUE, 1);
//		}
//		else if (turn == 2) {
//			draw_square_3(s2, r, c, BLUE, 2);
//		}
//		else {
//			draw_square_3(s2, r, c, BLUE, 3);
//		}
//	}
//	else if (id == 3) {
//		if (turn == 0) {
//			draw_square_3(s3, r, c, MINT, 0);
//		}
//		else if (turn == 1) {
//			draw_square_3(s3, r, c, MINT, 1);
//		}
//		else if (turn == 2) {
//			draw_square_3(s3, r, c, MINT, 2);
//		}
//		else {
//			draw_square_3(s3, r, c, MINT, 3);
//		}
//	}
//	else if (id == 4) {
//		if (turn == 0) {
//			draw_square_4(s4, r, c, RED, 0);
//		}
//		else {
//			draw_square_4(s4, r, c, RED, 1);
//		}
//	}
//	else if (id == 5) {
//		if (turn == 0) {
//			draw_square_3(s5, r, c, GREEN, 0);
//		}
//		else if (turn == 1) {
//			draw_square_3(s5, r, c, GREEN, 1);
//		}
//		else if (turn == 2) {
//			draw_square_3(s5, r, c, GREEN, 2);
//		}
//		else {
//			draw_square_3(s5, r, c, GREEN, 3);
//		}
//	}
//	else if (id == 6) {
//		if (turn == 0) {
//			draw_square_3(s6, r, c, PINK, 0);
//		}
//		else if (turn == 1) {
//			draw_square_3(s6, r, c, PINK, 1);
//		}
//		else if (turn == 2) {
//			draw_square_3(s6, r, c, PINK, 2);
//		}
//		else {
//			draw_square_3(s6, r, c, PINK, 3);
//		}
//	}
//	else {
//		if (turn == 0) {
//			draw_square_3(s7, r, c, YELLOW, 0);
//		}
//		else if (turn == 1) {
//			draw_square_3(s7, r, c, YELLOW, 1);
//		}
//		else if (turn == 2) {
//			draw_square_3(s7, r, c, YELLOW, 2);
//		}
//		else {
//			draw_square_3(s7, r, c, YELLOW, 3);
//		}
//	}
//}
//
//void move_shape(int id, int turn, bool left) {
//	if (left) {
//		if (check_shape(id, row, col - 1, turn)) {
//			delete_shape(id, row, col);
//			draw_shape(id, turn, row, col - 1);
//			col = col - 1;
//		}
//	}
//	else {
//		if (check_shape(id, row, col + 1, turn)) {
//			delete_shape(id, row, col);
//			draw_shape(id, turn, row, col + 1);
//			col = col + 1;
//		}
//	}
//}
//
//void move_down(int id, int turn) {
//	if (check_shape(id, row + 1, col, turn)) {
//		delete_shape(id, row, col);
//		draw_shape(id, turn, row + 1, col);
//		row = row + 1;
//	}
//	else {
//		stop = true;
//		if (id == 1) {
//			tick_square_2(s1, row, col);
//		}
//		else if (id == 2) {
//			tick_square_3(s2, row, col, turn);
//		}
//		else if (id == 3) {
//			tick_square_3(s3, row, col, turn);
//		}
//		else if (id == 4) {
//			tick_square_4(s4, row, col, turn);
//		}
//		else if (id == 5) {
//			tick_square_3(s5, row, col, turn);
//		}
//		else if (id == 6) {
//			tick_square_3(s6, row, col, turn);
//		}
//		else {
//			tick_square_3(s7, row, col, turn);
//		}
//
//		cout << "\n";
//
//		for (int i = 0;i < 22;i++) {
//			for (int j = 0;j < 13;j++) {
//				cout << grid[i][j] << "\t";
//			}
//			cout << "\n";
//		}
//		int k = 19;
//		while (k >= 0) {
//			int sum = 0;
//			for (int j = 1; j <= 10;j++) {
//				sum += grid[k][j];
//			}
//			if (sum == 10) {
//				score++;
//				updateScore(score);
//				for (int i = k;i >= 1;i--) {
//					for (int j = 1; j <= 10;j++) {
//						grid[i][j] = grid[i - 1][j];
//					}
//				}
//
//				for (int i = k;i >= 1;i--) {
//					for (int j = 0;j < 10;j++) {
//						int y = i * 10 + 1;
//						int x = j * 10 + 110 + 1;
//						for (int m = x; m < x + 9;m++) {
//							for (int n = y; n < y + 9;n++) {
//								SetPixel(m, n, GetPixel(x, y - 10));
//							}
//						}
//					}
//				}
//			}
//			else {
//				k--;
//			}
//		}
//
//	}
//}
//
//void spin(int id) {
//	if (id == 1) {
//		if (!check_square_2(s1, row, col)) return;
//		turn = 0;
//	}
//	else if (id == 2) {
//		int temp = turn + 1;
//		if (temp > 3) temp = 0;
//		if (!check_square_3(s2, row, col, temp)) return;
//		turn = turn + 1;
//		if (turn > 3) turn = 0;
//	}
//	else if (id == 3) {
//		int temp = turn + 1;
//		if (temp > 3) temp = 0;
//		if (!check_square_3(s3, row, col, temp)) return;
//		turn = turn + 1;
//		if (turn > 3) turn = 0;
//	}
//	else if (id == 4) {
//		int temp = turn + 1;
//		if (temp > 1) temp = 0;
//		if (!check_square_4(s4, row, col, temp)) return;
//		turn = turn + 1;
//		if (turn > 1) turn = 0;
//	}
//	else if (id == 5) {
//		int temp = turn + 1;
//		if (temp > 3) temp = 0;
//		if (!check_square_3(s5, row, col, temp)) return;
//		turn = turn + 1;
//		if (turn > 3) turn = 0;
//	}
//	else if (id == 6) {
//		int temp = turn + 1;
//		if (temp > 1) temp = 0;
//		if (!check_square_3(s2, row, col, temp)) return;
//		turn = turn + 1;
//		if (turn > 1) turn = 0;
//	}
//	else {
//		int temp = turn + 1;
//		if (temp > 3) temp = 0;
//		if (!check_square_3(s7, row, col, temp)) return;
//		turn = turn + 1;
//		if (turn > 1) turn = 0;
//	}
//	delete_shape(id, row, col);
//	draw_shape(id, turn, row, col);
//
//}
//
//void gameOver() {
//	for (int i = 110;i < 210;i++) {
//		for (int j = 0;j < 200;j++) {
//			SetPixel(i, j, BLACK);
//		}
//	}
//	draw_char('G', 120, 100, YELLOW);
//	draw_char('A', 128, 100, YELLOW);
//	draw_char('M', 136, 100, YELLOW);
//	draw_char('E', 144, 100, YELLOW);
//	draw_char('O', 160, 100, YELLOW);
//	draw_char('V', 168, 100, YELLOW);
//	draw_char('E', 176, 100, YELLOW);
//	draw_char('R', 184, 100, YELLOW);
//}
//
//void init() {
//	score = 0;
//	draw_background();
//	draw_text();
//	updateScore(score);
//	row = 0;
//	col = 5;
//	turn = 0;
//	stop = true;
//	int nextId = RandNum() % 7;
//	int current = 0;
//	bool endGame = false;
//	while (!endGame) {
//		BeginUpdate();
//		if (stop == true) {
//			row = 0;
//			col = 4;
//			turn = 0;
//			id = nextId;
//			if (check_shape(id, row, col, turn)) {
//				draw_shape(id, turn, row, col);
//				stop = false;
//				nextId = RandNum() % 7;
//				draw_half_background();
//				draw_shape(nextId, 0, 8, 14);
//			}
//			else {
//				gameOver();
//				endGame = true;
//			}
//		}
//		int keyPressed = GetInput(false);
//		if (keyPressed == 145) {
//			spin(id);
//		}
//
//		if (keyPressed == 144) {
//			move_shape(id, turn, true);
//		}
//
//		if (keyPressed == 146) {
//			move_shape(id, turn, false);
//		}
//
//		if (keyPressed == 147) {
//			move_down(id, turn);
//		}
//		if (GetMilisec() > (current + 500)) {
//			current = GetMilisec();
//			move_down(id, turn);
//		}
//		EndUpdate();
//	}
//}
//int main() {
//	init_grid();
//	init();
//	return 0;
//}