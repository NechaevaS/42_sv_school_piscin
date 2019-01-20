#include <unistd.h>
#define N (4)//change to 9
#define BSIZE (2)//change to 3 

void fill(char board[N][N], char **argv);
void print_board(char board[N][N]);
int solve(char workboard[N][N], int* nsolutions, char result[N][N]);
int check(char board[N][N], int rn, int cn);

int main(int argc, char **argv)
{
	if (argc != (N + 1))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	
	int i;

	i = 1;
	while (i < argc)
	{
		int j;
		int l;
		
		l = 0;
		j = 0;
		while (argv[i][j] != '\0')
		{
			l = l + 1;
			if ((argv[i][j] < '1' || argv[i][j] > '9') && (argv[i][j] != '.'))
			{
				write(1, "Error\n", 6);
				return (1);
			}
			j++;
		}
		if (l != N)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		i++;
	}
	char workboard[N][N];
	char result[N][N];

	fill(workboard, argv);
	
	int nsolutions = 0;
	solve(workboard, &nsolutions, result);
	if (nsolutions == 1)
	{
		print_board(result);
		return (0);
	}

	write(1, "Error\n", 6);
	return (1);

}

void copy_board(char dst[N][N], char src[N][N]) 
{
	int i;
	int j;
	i = 0;
	while(i < N) {
		j = 0;
		while(j<N) {
			dst[i][j] = src[i][j];
			j++;
		}
		i++;
	}
}

void fill(char board[N][N], char **argv)
{
	int i;
	int j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			board[i][j] = argv[i + 1][j];
			j++;
		}
		i++;
	}
}

void print_board(char board[N][N])
{
	int i;
	int j;
	
	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			write(1, &(board[i][j]), 1);
			if (j != (N - 1))
			{
				write(1, " ", 1);
			}

			j++;
		}
		write(1, "\n", 1);
		i++;
	}	
}

int check(char board[N][N], int rn, int cn)
{
	int j;
	
	j = 0;
	while (j < N)
	{
		if (j != cn &&  board[rn][cn] == board[rn][j])
		{
			return (0);
		}
		if (j != rn && board[rn][cn] == board[j][cn])
		{
			return (0);
		}			
		j++;
	}
	
	int i;
	int rnbox;
	int cnbox;

	rnbox = rn / BSIZE;
	i = rnbox * BSIZE;
	while (i < (rnbox + 1) * BSIZE)
	{
		cnbox = cn / BSIZE;
		j = cnbox * BSIZE;
		while (j < (cnbox + 1) * BSIZE)
		{
			if ((rn != i || cn != j) && board[rn][cn] == board[i][j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int find_first_dot(char board[N][N], int *row, int *col)
{
	int i;
	int j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if (board[i][j] == '.')
			{
				*row = i;
				*col = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int solve(char workboard[N][N], int *nsolutions, char result[N][N])
{
	int i;
	int j;
	int k;
	
	if (!find_first_dot(workboard, &i, &j))
	{

		(*nsolutions)++;
		if (*nsolutions > 1)
			return (0);
	
		copy_board(result, workboard);
		return (1);
	}

	k = 1;
	while(k <= N && *nsolutions <= 1)
	{
		workboard[i][j] = k + '0';
		if (check(workboard, i, j))
		{
			solve(workboard, nsolutions, result);
		}
		k++;
	}
	workboard[i][j] = '.';
	return (0);
}
