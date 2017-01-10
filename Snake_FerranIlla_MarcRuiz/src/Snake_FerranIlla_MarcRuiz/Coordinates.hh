#pragma once

#define GRID_WIDTH 64
#define GRID_HEIGHT 48

struct COOR {
	int column;
	int row;

	bool operator <(COOR rhs) {
		return (row<rhs.row || (row == rhs.row && column < rhs.column));
	}

	bool operator ==(COOR rhs) {
		return(column == rhs.column && row == rhs.row);
	}
};