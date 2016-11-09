#pragma once

class map_puzzle
{
	private:
		int		**puzzle;
		char	move;
	
	public:

	void set_move(char n_move) { this->move = n_move; }
	char get_move(void) { return (this->move); }
	int  **get_puzzle(void) { return (this->puzzle); }
		
};
