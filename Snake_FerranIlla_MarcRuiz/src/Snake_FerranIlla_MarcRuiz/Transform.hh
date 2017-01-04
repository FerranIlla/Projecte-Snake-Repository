#pragma once
#include <SDL\SDL.h>

// Transform structure to store Game Objects (and UI Objects) position
struct Transform {
	union {//A union is a special class type that can hold only one of its non-static data members at a time.
		   //explained at the end of the hh
		SDL_Rect rect;//sdl rect es per crear un rectangle (funcio de llibreria sdl)
		struct { Sint32 x, y, w, h; };//coul int x,.. also should works. Jordi use Sint32 for something related with memory (i suppose)
	};
	Transform(int x_, int y_) : x(x_), y(y_), w(0), h(0) {};
	Transform(int x_, int y_, int w_, int h_) : x(x_), y(y_), w(w_), h(h_) {};
	Transform() { x = y = w = h = 0; };//if dont recives nothing equale all to 0
	inline const SDL_Rect &operator()(void) const { return rect; };//no acabo dentendre aquesta linea pero crec qe esta relacionada amb que et retorni el rectangle en si
	friend bool operator == (Transform &lhs, Transform &rhs) {//linea relacionada amb la overload, perqe no doni eerrors les seguentslinees d'abaix
		return (lhs.x == rhs.x &&//iguala coordenades de dreta esquerra
			lhs.y == rhs.x &&//ENTENC QUE LHS =LEFT HIGH SQUARE o algo aixi
			lhs.w == rhs.w &&
			lhs.h == rhs.h);
	}
};

/*Explanation
The union is only as big as necessary to hold its largest data member.
The other data members are allocated in the same bytes as part of that largest member.
The details of that allocation are implementation - defined, and it's undefined behavior
to read from the member of the union that wasn't most recently written.Many compilers implement,
as a non - standard language extension, the ability to read inactive members of a union.

a)A union can have member functions (including constructors and destructors), but not virtual functions.

b)A union cannot have base classes and cannot be used as a base class.

c)A union cannot have data members of reference types.*/