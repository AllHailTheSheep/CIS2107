#ifndef LAB9
#define LAB9
char convert_case(char c);

int all_letters(char *s); // returns 1 if all characters are letters
int num_in_range(char *s, int b, int t); // returns the num of characters such that b<=c<=t
int diff(char *s1, char *s2); // returns the amount of moves (substitutions, insertions, deletions) that would make the string equal
void shorten(char *s, int new_len); // shortens the length of s to new_len. if new_len>sizeof(s), there is no change
int len_diff(char *s1, char *s2); // returns the length of s1 - s2
void rm_left_space(char *s); // removes whatespace from the begninning of the string
// TODO: after here
void rm_right_space(char *s); // removes whatespace from the end of the string
void rm_space(char *s); // removes whitespace from the begninning and end of the string
int find(char *h, char *n); // returns the index of the first occurence of n in h or -1
char * ptr_to(char *h, char *n); // returns a pointer to the first occurence of n in h or null
void is_empty(char *s); // returns 1 if s is null, only '\0' of only whitespace
char * str_zip(char *s1, char *s2); // returns a new string with s1 and s2 interleaved (i.e. Apple and Orange becomes AOprpalnege)
void capitalize(char *s); // modifies s so the first letter of each word is uppercase, all else are lowercase
int strcmp_ign_case(char *s1, char *s2); // compares to words ignoring case. returns positive if s1 appears after s2 in dict, negative if not, 0 if equal
void take_last(char *s, int n); // modifies s so that it only consists of the last n characters
char * dedup(char *s); // returns a new string based on s but containing no duplicate characters
char * pad(char *s, int d); // returns a new string based on s but padded by spaces at the end so that total length of new string is an even multiple of d. if it already is, returns a copy of the string. returns null on fail or if s is null
int ends_with_ignore_case(char *s, char *suff); // returns 1 if suff is suffix of s, ignoring case
char * repeat(char *s, int x, char sep); // returns a new string with s repeated x times, seperated by sep
char * replace(char *s, char *pat, char *rep); // returns a new string with every instance of pat replaced by rep
char * str_connect(char **strs, int n, char c); // returns a new string of the first n strings in strs seperated by c
void rm_empties(char **words); // removes all strings with size 0
char ** str_chop_all(char *s, char c); // returns array of strings where each element is from s split by delim c

#endif