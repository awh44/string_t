#include <stdio.h>
#include "string_t.h"

void print_string(string_t *s)
{
	printf("%.*s\n", s->elements, s->array);
}

int main(int argc, char *argv[])
{
	string_t s;
	string_initialize(&s);
	
	string_assign_from_char_array(&s, "Hello, how are you today?");
	print_string(&s);
	printf("s.elements = %zu\n", s.elements);

	size_t num;
	string_t *split = string_split(&s, ' ', &num);
	printf("%zu\n", num);
	size_t i;
	for (i = 0; i < num; i++)
	{
		print_string(split + i);
	}

	string_concatenate(split, split + 1);
	print_string(split);
	printf("%zu\n", split[0].elements);

	char *cstr = string_c_str(&s);
	printf("%s\n", cstr);

	string_uninitialize(&s);	
	for (i = 0; i < num; i++)
	{
		string_uninitialize(split + i);
	}
	free(split);

	return 0;
}
