#ifndef _STRING_T_H_
#define _STRING_T_H_
#include "vector_t.h"
MAKE_VECTOR_TYPE(char)
typedef char_vector_t string_t;

void string_initialize(string_t *s);
void string_uninitialize(string_t *s);
size_t string_length(string_t *s);
void string_assign_from_char_array(string_t *s, char *arr);
void string_assign_from_char_array_with_size(string_t *s, char *arr, size_t length);
void string_concatenate(string_t *a, string_t *b);
void string_concatenate_char_array(string_t *s, char *arr);
void string_concatenate_char_array_with_size(string_t *s, char *arr, size_t n);
string_t *string_split(string_t *s, char delim, size_t *num);
string_t *string_split_skip_consecutive(string_t *s, char delim, size_t *num, uint8_t skip);
char **string_split_as_c_strs(string_t *s, char delim, size_t *num);
char *string_c_str(string_t *s);
void string_getline(string_t *s, FILE *stream);
int string_compare_char_array(string_t *s1, char *s2);
void string_trim(string_t *s);
void string_replace(string_t *s, char oldc, char newc);
#endif
