#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum token_type;
char** symbols;
struct token_struct;

enum node_type;
struct node_struct;

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

	size_t strlen_argv_1 = strlen(argv[1]);
	token code_lex[strlen_argv_1]; // "argv[1]" because I don't want to have to deal with file management until I need to
	for (int i = 0; i < strlen_argv_1; i++){
		
	}
	
	node code_tree;
	code_tree.type = PROGRAM;
	code_tree.back = NULL;
	code_tree.left = malloc(sizeof(node));
	code_tree.right = malloc(sizeof(node));
}
