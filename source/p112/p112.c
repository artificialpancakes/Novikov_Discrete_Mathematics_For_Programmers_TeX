#include <stdio.h>
#include <string.h>

typedef struct res
{
	int val;
	bool fail;
} res;

res Eval(int n, char *F_, set_func F, char *t[n], int x[n])
{
	res r;
	r.fail = false;
	for(int i = 0; i < n; ++i)
	{
		if(strcmp(F_, x_i) == 0)
		{
			r.val = x[i];
			return r;
		}
	}
	if(strcmp(F_, f(t)) == 0)
	{
		if(!func_include(f, F))
		{
			r.fail = true;
			return r;
		}
		res y[n];
		for(int j = 0; j < n; ++j)
		{
			y[j] = Eval(n, t[j], F, t, x);
			if(y[j].fail == true)
			{
				r.fail = true;
				return r;
			}
		}
		r.val = f(y);
		return r;
	}
	r.fail = true;
	return r;
}

int main()
{
	
}
