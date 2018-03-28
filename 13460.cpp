#include<iostream>

using namespace std;

char a[15][15];
int n, m, b[15][15], nowR[2], nowB[2], minx = 0x7fffffff;
bool levelflag = false;

int lean_left(int& Trx, int& Try, int& Tbx, int& Tby, int rx, int ry, int bx, int by);
int lean_right(int& Trx, int& Try, int& Tbx, int& Tby, int rx, int ry, int bx, int by);
int lean_up(int& Trx, int& Try, int& Tbx, int& Tby, int rx, int ry, int bx, int by);
int lean_down(int& Trx, int& Try, int& Tbx, int& Tby, int rx, int ry, int bx, int by);

void back(int level, int rx, int ry, int bx, int by)
{
	int Trx, Try, Tbx, Tby;
	if (level >= 10)
	{
		levelflag = true;
		return;
	}
	Trx = rx, Try = ry, Tbx = bx, Tby = by;
	int LL = lean_left(Trx, Try, Tbx, Tby, rx, ry, bx, by);
	Trx = rx, Try = ry, Tbx = bx, Tby = by;
	int LR = lean_right(Trx, Try, Tbx, Tby, rx, ry, bx, by);
	Trx = rx, Try = ry, Tbx = bx, Tby = by;
	int LU = lean_up(Trx, Try, Tbx, Tby, rx, ry, bx, by);
	Trx = rx, Try = ry, Tbx = bx, Tby = by;
	int LD = lean_down(Trx, Try, Tbx, Tby, rx, ry, bx, by);
	if (LL == 0 || LR == 0 || LU == 0 || LD == 0)
	{
		if (minx > level + 1)
			minx = level + 1;
	}
	if (LL == 1 && level < 10)
	{
		back(level + 1, Trx, Try, Tbx, Tby);
	}
	if (LR == 1 && level < 10)
	{
		back(level + 1, Trx, Try, Tbx, Tby);
	}
	if (LU == 1 && level < 10)
	{
		back(level + 1, Trx, Try, Tbx, Tby);
	}
	if (LD == 1 && level < 10)
	{
		back(level + 1, Trx, Try, Tbx, Tby);
	}
}

int lean_left(int& Trx, int& Try, int& Tbx, int& Tby, int rx, int ry, int bx, int by)
{
	bool flagR = false, flagB = false;
	while (1)
	{
		if (b[Trx][Try - 1] == 3)
			flagR = true;
		if (b[Tbx][Tby - 1] == 3)
			flagB = true;
		if (b[Trx][Try - 1] != -1)
			Try--;
		if (b[Tbx][Tby - 1] != -1)
			Tby--;
		if (b[Trx][Try - 1] == -1 && b[Tbx][Tby - 1] == -1)
		{
			if (flagR == true && flagB == false)
				return 0;
			if ((flagR == false && flagB == true) || (flagR == true && flagB == true))
				return -2;
			if (Try != ry || Tby != by)
				return 1;
			return -1;
		}
	}
}

int lean_right(int& Trx, int& Try, int& Tbx, int& Tby, int rx, int ry, int bx, int by)
{
	bool flagR = false, flagB = false;
	while (1)
	{
		if (b[Trx][Try + 1] == 3)
			flagR = true;
		if (b[Tbx][Tby + 1] == 3)
			flagB = true;
		if (b[Trx][Try + 1] != -1)
			Try++;
		if (b[Tbx][Tby + 1] != -1)
			Tby++;
		if (b[Trx][Try + 1] == -1 && b[Tbx][Tby + 1] == -1)
		{
			if (flagR == true && flagB == false)
				return 0;
			if ((flagR == false && flagB == true) || (flagR == true && flagB == true))
				return -2;
			if (Try != ry || Tby != by)
				return 1;
			return -1;
		}
	}
}

int lean_up(int& Trx, int& Try, int& Tbx, int& Tby, int rx, int ry, int bx, int by)
{
	bool flagR = false, flagB = false;
	while (1)
	{
		if (b[Trx - 1][Try] == 3)
			flagR = true;
		if (b[Tbx - 1][Tby] == 3)
			flagB = true;
		if (b[Trx - 1][Try] != -1)
			Trx--;
		if (b[Tbx - 1][Tby] != -1)
			Tbx--;
		if (b[Trx - 1][Try] == -1 && b[Tbx - 1][Tby] == -1)
		{
			if (flagR == true && flagB == false)
				return 0;
			if ((flagR == false && flagB == true) || (flagR == true && flagB == true))
				return -2;
			if (Try != ry || Tby != by)
				return 1;
			return -1;
		}
	}
}

int lean_down(int& Trx, int& Try, int& Tbx, int& Tby, int rx, int ry, int bx, int by)
{
	bool flagR = false, flagB = false;
	while (1)
	{
		if (b[Trx + 1][Try] == 3)
			flagR = true;
		if (b[Tbx + 1][Tby] == 3)
			flagB = true;
		if (b[Trx + 1][Try] != -1)
			Trx++;
		if (b[Tbx + 1][Tby] != -1)
			Tbx++;
		if (b[Trx + 1][Try] == -1 && b[Tbx + 1][Tby] == -1)
		{
			if (flagR == true && flagB == false)
				return 0;
			if ((flagR == false && flagB == true) || (flagR == true && flagB == true))
				return -2;
			if (Try != ry || Tby != by)
				return 1;
			return -1;
		}
	}
}


int main()
{
	int i, j;
	cin >> n >> m;
	for (i = 0; i < n; i++)
		cin >> a[i];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (a[i][j] == '#')
				b[i][j] = -1;
			else if (a[i][j] == 'R')
			{
				b[i][j] = 1;
				nowR[0] = i, nowR[1] = j;
			}
			else if (a[i][j] == 'B')
			{
				b[i][j] = 2;
				nowB[0] = i, nowB[1] = j;
			}
			else if (a[i][j] == 'O')
				b[i][j] = 3;
		}
	}
	back(0, nowR[0], nowR[1], nowB[0], nowB[1]);
	if (levelflag == true)
		cout << -1;
	if(levelflag == false)
		cout << minx;
	return 0;
}