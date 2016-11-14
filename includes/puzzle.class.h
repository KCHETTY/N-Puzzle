#pragma once

class map_puzzle
{
	private:
		int		**puzzle;
		char	move;
	
	public:

	void set_move(char n_move) { this->move = n_move; }
	char get_move(void) { return (this->move); }
	void set_puzzle(int x, int y, int data) {this->puzzle[y][x] = data;}
	int  get_puzzle(int x, int y) { return (this->puzzle[y][x]); }
	void malloc_puzzle(int dimensions) 
	{
		this->puzzle = (int **)malloc(sizeof(int *) * dimensions);
  	for (int i = 0; i < dimensions; i++)
    	this->puzzle[i] = (int *)malloc(sizeof(int) * dimensions);
	}
};
