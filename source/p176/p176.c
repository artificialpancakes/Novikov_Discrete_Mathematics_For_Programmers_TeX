#include <stdio.h>

bool method_of_resolution(set C)
{
	set M = C;
	while(1)
	{
		elem c1, c2;
		Choose(M, c1, c2, p1, p2, o);
		if(empty(c1) && empty(c2))
			return false;
		elem c = R(c1, c2, p1, p2, o);
		add_elem(M, c);
		if(empty(c)) break;
	}
	return true;
}

int main()
{
	
}
