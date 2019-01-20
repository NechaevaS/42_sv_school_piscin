#include <unistd.h>
#define N (4)//change to 9

void fill(char board[N][N], char **argv);
void print_board(char board[N][N]);
int solve(char board[N][N]);

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
			if ((argv[i][j] < 49 || argv[i][j] > 57) && (argv[i][j] != '.'))
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
	char board[N][N];
	fill(board, argv);
	print_board(board);
	if (!solve(board))
	{
		write(1, "Error\n", 6);
	}
	print_board(board);
	return (0);
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

int check_row_col(char board[N][N], int rn, int cn)
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
	return (1);
}

int solve(char board[N][N])
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < N)
		{
			if (board[i][j] == '.')
			{
				k = 1;
				while(k <= N)
				{
					board[i][j] = k + 48;
					// check square
					if (check_row_col(board, i, j))
					{
						write (1, "\n", 1);
						print_board(board);
						// check complete and exit
						if (solve(board))
						{
							return (1);	
						}
					}
					k++;
				}
				board[i][j] = '.';
				return (0);
			}
			j++;
		}
		i++;

	}
	return (0);
}
