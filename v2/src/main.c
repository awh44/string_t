#include <stdio.h>
#include "string_t.h"

void print_string(string_t *s)
{
	printf("%.*s\n", string_size(s), string_c_array(s));
}

int main(int argc, char *argv[])
{
	string_t *s = string_initialize();
	string_assign_from_char_array(s, "Hello, how are you today?");
	print_string(s);
	printf("s->elements = %zu\n", string_length(s));

	size_t num;
	string_t **split = string_split(s, ' ', &num);
	char **c_str_split = string_split_as_c_strs(s, ' ', &num);
	printf("%zu\n", num);
	size_t i;
	for (i = 0; i < num; i++)
	{
		print_string(split[i]);
		printf("%s\n", c_str_split[i]);
	}

	string_concatenate(split[0], split[1]);
	print_string(split[0]);
	printf("%zu\n", string_size(split[0]));

	char *cstr = string_c_str(s);
	printf("%s\n", cstr);

	string_getline(s, stdin);
	print_string(s);

	string_concatenate_char_array(s, " blahblah yes!");
	print_string(s);


	for (i = 0; i < num; i++)
	{
		string_uninitialize(split[i]);
	}
	free(split);

	printf("Done test.\n");

	string_uninitialize(s);
	return 0;
}
