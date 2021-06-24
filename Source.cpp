#include "stc.h"
#include "font816.h"
#include "PhoneBook.h"
#include <iostream>
using namespace std;

#define RED 0xff0000
#define BLACK 0x000000
#define WHITE 0xffffff
#define YELLOW 0xfff000

char defaulText[7][40] = {
	{"Add"},
	{"Delete by name"},
	{"Delete by id"},
	{"Search by name"},
	{"Search by id"},
	{"List by name"},
	{"List by id"}
};

int length(char* s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return i;
}

bool compareStr(char* s1, char* s2)
{
	for (int i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return false;
	}
	return true;
}

void copyArr(char* s1, const char* s2)
{
	for (int i = 0; s2[i] != '\0'; i++)
	{
		s1[i] = s2[i];
		s1[i + 1] = '\0';
	}
}


void clear()
{
	for (int i = 0; i < 320; i++)
	{
		for (int j = 0; j < 200; j++)
		{
			SetPixel(i, j, BLACK);
		}
	}
}

void drawText(const char* s, int x, int line, unsigned int color) {
	for (int i = 0; s[i] != '\0'; i++)
	{
		for (int m = 0; m < 16; m++)
		{
			for (int n = 0; n < 8; n++)
			{
				if (font816[s[i] - 32][m][n] == 1)
				{
					SetPixel(x + n + i * 8, line * 16 + m, color);
				}
			}
		}
	}
}

void drawKey(int key, int x, int line) {
	for (int m = 0;m < 16;m++) {
		for (int n = 0;n < 8;n++) {
			if (font816[key - 32][m][n] == 1) {
				SetPixel(x + n, line * 16 + m, WHITE);
			}
		}
	}
}

void drawScreen(const char* s, bool isMain) {
	drawText(s, 0, 0, RED);
	for (int i = 0; i < 320; i++)
	{
		SetPixel(i, 15, RED);
	}
	if (!isMain) {
		drawText("ESC", 296, 0, YELLOW);
	}
}

void drawMenu(char textLine[][40], int size) {
	for (int i = 0; i < 7;i++) {
		drawText(textLine[i], 0, i + 1, WHITE);
	}
}

void drawLine(int& line, int index, char textLine[][40], int length) {
	for (int i = 0;i < length;i++) {
		for (int j = line * 16; j < line * 16 + 16;j++) {
			SetPixel(i, j, WHITE);
		}
	}
	drawText(textLine[index], 0, line, BLACK);
}

void deleteLine(int& line, int index, char textLine[][40], int length) {
	for (int i = 0;i < length;i++) {
		for (int j = line * 16; j < line * 16 + 16;j++) {
			SetPixel(i, j, BLACK);
		}
	}
	drawText(textLine[index], 0, line, WHITE);
}

void moveDown(int& line, int index, char textLine[][40], int length) {
	if (line <= 10 && textLine[line + 2][0] != '\0') {
		deleteLine(line, index, textLine, length);
		line++;
		drawLine(line, index + 1, textLine, length);
	}
}

void moveUp(int& line, int index, char textLine[][40], int length) {
	if (line > 1) {
		deleteLine(line, index, textLine, length);
		line--;
		drawLine(line, index - 1, textLine, length);
	}
}



struct User {
	int id;
	char name[15];
	char phone[15];
	char text[40];
	bool isDeleted;

	char* toString() {
		for (int i = 0;i < 40;i++) {
			text[i] = ' ';
		}
		for (int i = 0;i < length(name);i++) {
			text[i] = name[i];
		}

		char idArr[5];
		int temp = id;
		int index = 3;
		while (temp > 0) {
			idArr[index] = temp % 10 + 48;
			temp = temp / 10;
			index--;
		}
		idArr[4] = '\0';

		for (int i = 15;i < 15 + length(idArr);i++) {
			text[i] = idArr[i - 15];
		}

		for (int i = 25;i < 25 + length(phone);i++) {
			text[i] = phone[i - 25];
		}
		return text;
	}
};

void initData(User user[], int& size) {
	size = 100;
	for (int i = 0;i < 100;i++) {
		user[i].id = preloadId[i];
		copyArr(user[i].name, preloadName[i]);
		copyArr(user[i].phone, preloadPhone[i]);
		user[i].isDeleted = false;
	}
}

int searchById(int id, User user[]) {
	for (int i = 0;i < 1000;i++) {
		if (user[i].id == id && !user[i].isDeleted) return i;
	}
	return -1;
}

void add(int id, char* name, char* phone, User user[], int& size) {
	if (searchById(id, user) == -1) {
		user[size].id = id;
		copyArr(user[size].name, name);
		copyArr(user[size].phone, phone);
		user[size].isDeleted = false;
		size++;
		drawText("OK", 0, 4, WHITE);
	}
	else {
		drawText("USER IS EXISTED", 0, 4, WHITE);
	}
}

void deleteByName(char* name, User user[]) {
	int count = 0;
	for (int i = 0;i < 1000;i++) {
		if (compareStr(user[i].name, name) && !user[i].isDeleted) {
			user[i].isDeleted = true;
			count++;
		}
	}
	if (count == 0) {
		drawText("USER IS NOT EXISTED", 0, 2, WHITE);
	}
	else {
		drawText("OK", 0, 2, WHITE);
	}
}

void deleteById(int id, User user[]) {
	int index = searchById(id, user);
	if (index != -1) {
		user[index].isDeleted = true;
		drawText("OK", 0, 2, WHITE);
	}
	else {
		drawText("USER IS NOT EXISTED", 0, 2, WHITE);
	}
}

bool isSmaller(char* name1, char* name2) {
	int l1 = length(name1);
	int l2 = length(name2);
	int min = 0;
	if (l1 < l2) {
		min = l1;
	}
	else min = l2;

	for (int i = 0;i < min;i++) {
		int temp1 = (name1[i] >= 65 && name1[i] <= 90) ? (name1[i] + 32) : name1[i];
		int temp2 = (name2[i] >= 65 && name2[i] <= 90) ? (name2[i] + 32) : name2[i];
		if (temp1 == temp2) continue;
		return temp1 < temp2;
	}
	return l1 < l2;
}

void sortByName(User user[], User temp[], int& size, char textLine[][40]) {
	for (int i = 0;i < size;i++) {
		temp[i].id = user[i].id;
		copyArr(temp[i].name, user[i].name);
		copyArr(temp[i].phone, user[i].phone);
		temp[i].isDeleted = user[i].isDeleted;
	}

	for (int i = 0;i < size;i++) {
		for (int j = 0; j < size - i - 1;j++) {
			if (!isSmaller(temp[j].name, temp[j + 1].name)) {
				swap(temp[j], temp[j + 1]);
			}
		}
	}

}


void backToMainScreen(int& line) {
	clear();
	line = 1;
	drawScreen("PHONEBOOK", true);
	drawMenu(defaulText, 7);
	drawLine(line, 0, defaulText, 320);
}
void drawList(User user[], User temp[], int& size, int& start, char textLine[][40]) {
	for (int i = start;i < start + 11;i++) {
		if (i >= size) {
			break;
		}
		if (!temp[i].isDeleted) {
			copyArr(textLine[i - start], temp[i].toString());
			drawText(textLine[i - start], i - start + 1, WHITE);
		}
	}
}

void openListScreen(int& line, int& size, int& start, char textLine[][40]) {
	while (start < size) {
		int lkey = GetInput(true);
		if (lkey == 27) {
			backToMainScreen(line);
		}

		if (lkey == 147) {
			clear();
			drawScreen("PHONEBOOK LIST", false);
			drawList(start, textLine);
			moveDown(line, line + start - 1, textLine, 310);
			if (line == 11) {
				start = start + 1;
				drawLine(line, line + start - 1, textLine, 310);
				continue;
			}
		}

		if (lkey == 145) {
			//if (line == 1) {
			//	line = 11;
			//	clear();
			//	drawScreen("PHONEBOOK LIST", false);
			//	drawList(start, textLine);
			//	drawLine(line, line + start - 1, textLine, 310);
			//}
			moveUp(line, line + start - 1, textLine, 310);
			//if (line == 11) {
			//	line = 12;
			//	start = start + 1;
			//	continue;
			//}
		}
	}
}

void openAddScreen(int& line, User user[], int& size) {
	clear();
	drawScreen("PHONEBOOK ADD", false);
	int enterCount = 1;
	char id[5];
	char name[15];
	char phone[15];
	int idIdx = 0;
	int nameIdx = 0;
	int phoneIdx = 0;
	drawText("Id> ", 0, enterCount, WHITE);
	while (enterCount < 4) {
		int lkey = GetInput(true);
		if (lkey == 27) {
			backToMainScreen(line);
			break;
		}

		if (enterCount == 1) {
			if (lkey != 13) {
				if (lkey >= 48 && lkey <= 57) {
					id[idIdx] = lkey;
					drawKey(lkey, 60 + idIdx * 8, enterCount);
					idIdx++;
				}
			}
			else {
				id[idIdx] = '\0';
				enterCount++;
				drawText("Name > ", 0, enterCount, WHITE);
				continue;
			}
		}

		if (enterCount == 2) {
			if (lkey != 13) {
				if ((lkey >= 65 && lkey <= 90) || (lkey >= 97 && lkey <= 122)) {
					name[nameIdx] = lkey;
					drawKey(lkey, 60 + nameIdx * 8, enterCount);
					nameIdx++;
				}
			}
			else {
				name[nameIdx] = '\0';
				enterCount++;
				drawText("Number> ", 0, enterCount, WHITE);
				continue;
			}
		}

		if (enterCount == 3) {
			if (lkey != 13) {
				phone[phoneIdx] = lkey;
				drawKey(lkey, 60 + phoneIdx * 8, enterCount);
				phoneIdx++;
			}
			else {
				phone[phoneIdx] = '\0';
				enterCount++;
				int idNum = (id[0] - 48) * 1000 + (id[1] - 48) * 100 + (id[2] - 48) * 10 + (id[3] - 48);
				add(idNum, name, phone, user, size);
			}
		}
	}
}

void openDeleteByNameScreen(int& line, User user[], int& size) {
	clear();
	drawScreen("PHONEBOOK DELETE", false);
	char name[15];
	int nameIdx = 0;
	drawText("Name> ", 0, 1, WHITE);
	while (nameIdx < 15) {
		int lkey = GetInput(true);
		if (lkey == 27) {
			backToMainScreen(line);
			break;
		}

		if (lkey != 13) {
			if ((lkey >= 65 && lkey <= 90) || (lkey >= 97 && lkey <= 122)) {
				name[nameIdx] = lkey;
				drawKey(lkey, 60 + nameIdx * 8, 1);
				nameIdx++;
			}
		}
		else {
			deleteByName(name, user);
			break;
		}
	}
}

void openDeleteByIdScreen(int& line, User user[], int& size) {
	clear();
	drawScreen("PHONEBOOK DELETE", false);
	char id[15];
	int idIdx = 0;
	drawText("Id> ", 0, 1, WHITE);
	while (idIdx < 5) {
		int lkey = GetInput(true);
		if (lkey == 27) {
			backToMainScreen(line);
			break;
		}

		if (lkey != 13) {
			if (lkey >= 48 && lkey <= 57) {
				id[idIdx] = lkey;
				drawKey(lkey, 60 + idIdx * 8, 1);
				idIdx++;
			}
		}
		else {
			int idNum = (id[0] - 48) * 1000 + (id[1] - 48) * 100 + (id[2] - 48) * 10 + (id[3] - 48);
			deleteById(idNum, user);
			break;
		}
	}
}

void openSearchByIdScreen(int& line, User user[], int& size) {
	clear();
	drawScreen("PHONEBOOK SEARCH", false);
	char id[15];
	int idIdx = 0;
	drawText("Id> ", 0, 1, WHITE);
	while (idIdx < 5) {
		int lkey = GetInput(true);
		if (lkey == 27) {
			backToMainScreen(line);
			break;
		}

		if (lkey != 13) {
			if (lkey >= 48 && lkey <= 57) {
				id[idIdx] = lkey;
				drawKey(lkey, 60 + idIdx * 8, 1);
				idIdx++;
			}
		}
		else {
			int idNum = (id[0] - 48) * 1000 + (id[1] - 48) * 100 + (id[2] - 48) * 10 + (id[3] - 48);
			int index = searchById(idNum, user);
			if (index != -1) {
				drawText(user[index].toString(), 0, 2, WHITE);
			}
			else {
				drawText("USER IS NOT EXISTED", 0, 2, WHITE);
			}
			break;
		}
	}
}
int main() {
	User user[1000];
	User temp[1000];
	char textLine[1000][40];
	int size = 0;
	int line = 1;
	int start = 0;

	drawScreen("PHONEBOOK", true);
	drawMenu(defaulText, 7);
	drawLine(line, start, defaulText, 320);
	initData(user, size);

	while (true) {
		int key = GetInput(true);
		if (key == 147) {
			moveDown(line, line - 1 + start, defaulText, 320);
		}

		if (key == 145) {
			moveUp(line, line - 1 + start, defaulText, 320);
		}
		if (key == 13) {
			if (line == 1) {
				openAddScreen(line, user, size);
			}
			if (line == 2) {
				openDeleteByNameScreen(line, user, size);
			}
			if (line == 3) {
				openDeleteByIdScreen(line, user, size);
			}
			if (line == 5) {
				openSearchByIdScreen(line, user, size);
			}
			if (line == 6) {
				clear();
				drawScreen("PHONEBOOK LIST", false);
				start = 0;
				line = 1;
				sortByName(user, temp, size, textLine);
				drawList(start, textLine);
				drawLine(line, start, textLine, 310);
				openListScreen(line, size, start, textLine);
			}
		}

	}
	return 0;
}