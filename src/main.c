#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum token_type;
char** symbols;
struct token_struct;

enum node_type;
struct node_struct;

int check_different_sized_strings(char* original_string_literal, char* check_string_literal){
	size_t strlen_check_string = strlen(check_string_literal);
    size_t strlen_original_string = strlen(original_string_literal);

    char original_string[strlen_original_string];
    strcpy(original_string, original_string_literal);

    char check_string[strlen_check_string];
    strcpy(check_string, check_string_literal);

    if (strlen_original_string > strlen_check_string){
        char replaced_char = original_string[strlen_check_string];
        original_string[strlen_check_string] = '\0';

        int return_value = strcmp(original_string, check_string);
        original_string[strlen_check_string] = replaced_char;

        return return_value;
    } else if (strlen_check_string > strlen_original_string){
        char replaced_char = check_string[strlen_original_string];
        check_string[strlen_original_string] = '\0';

        int return_value = strcmp(original_string, check_string);
        check_string[strlen_original_string] = replaced_char;

        return return_value;
    } else {
        return strcmp(original_string, check_string);
    }
}

int main(int argc, char** argv){
	char* symbols[] = {"+=", "-="};

	enum token_type {
		WORD = 128 + sizeof(symbols)/sizeof(symbols[0]), // 128 because that's where ASCII ends
		INT,
		FLOAT
	};

	enum node_type {
		PROGRAM = 128 + sizeof(symbols)/sizeof(symbols[0]),
	};

	typedef struct token_struct {
		enum token_type type;
		char* string_argument;
		struct token_struct* token_argument;
	} token;

	typedef struct node_struct {
		enum node_type type;
		token* token_argument;
		struct node_struct* back;
		struct node_struct* left;
		struct node_struct* right;
	} node;

	size_t strlen_argv_1 = strlen(argv[1]); // "argv[1]" because I don't want to have to deal with file management until I need to
	char* raw_code = argv[1];

	token code_lex[strlen_argv_1];

	int quote_mode = 0;
	size_t quote_buf_start;
	char* quote_arg = malloc(1);

	for (int i = 0; i < strlen_argv_1; i++){
		if (quote_mode){
			if (raw_code[i] == '"' && raw_code[i - 1] != '\\'){
				quote_mode--;
				int buf_size = i - quote_buf_start;
				quote_arg = realloc(quote_arg, 1 + buf_size);
				strncpy(quote_arg, &raw_code[quote_buf_start], buf_size);
				quote_arg[buf_size] = '\0'; // check if it works without this
				
				printf("%s\n", quote_arg);
				continue;
			}
			continue;
		}

		if (raw_code[i] == '"'){
			quote_mode++;
			quote_buf_start = i + 1;
			continue;
		}
	}
	
	node code_tree;
	code_tree.type = PROGRAM;
	code_tree.back = NULL;
	code_tree.left = malloc(sizeof(node));
	code_tree.right = malloc(sizeof(node));

}
