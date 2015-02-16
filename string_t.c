#include <string.h>
#include "string_t.h"

void string_initialize(string_t *s)
{
	char_vector_initialize(s);
}

void string_uninitialize(string_t *s)
{
	char_vector_uninitialize(s);
}

void string_assign_from_char_array(string_t *s, char *arr)
{
	string_assign_from_char_array_with_size(s, arr, strlen(arr));
}

void string_assign_from_char_array_with_size(string_t *s, char *arr, size_t length)
{
	char_vector_assign_from_array(s, arr, length);
}

void string_concatenate(string_t *a, string_t *b)
{
	char_vector_size_at_least(a, a->elements + b->elements);
	memcpy(a->array + a->elements, b->array, b->elements * sizeof *b->array);
	a->elements += b->elements;
}

string_t *string_split(string_t *s, char delim, size_t *num)
{
	string_t *ret_val = NULL;
	*num = 0;
	char *start_pos = s->array;
	size_t i;
	for (i = 0; i < s->elements; i++)
	{
		if (s->array[i] == delim)
		{
			(*num)++;
			ret_val = realloc(ret_val, *num * sizeof *ret_val);
			string_initialize(ret_val + *num - 1);

			s->array[i] = '\0';
			string_assign_from_char_array(ret_val + *num - 1, start_pos);
			
			s->array[i] = delim;
			start_pos  = s->array + i + 1;
		}
	}

	(*num)++;
	ret_val = realloc(ret_val, *num * sizeof *ret_val);
	string_initialize(ret_val + *num - 1);
	string_assign_from_char_array_with_size(ret_val + *num - 1, start_pos, s->array + i - start_pos);

	return ret_val;
}

char *string_c_str(string_t *s)
{
	char_vector_size_at_least(s, s->elements + 1);
	s->array[s->elements + 1] = '\0';
	return s->array;
}
