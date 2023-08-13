#include<stdio.h>
#include<stdlib.h>

struct Node {
	char* word;
	struct Node* next;
};

struct Node* head = NULL;
struct Node* current = NULL;


struct Node* createNode(char* word) {
	struct Node* newNode = NULL;
	newNode = malloc(sizeof(struct Node));
	if (newNode != NULL) {
		newNode->next = NULL;
		newNode->word = word;
	}
	else {
		fprintf(stderr, "malloc faild!\n");
	}
	return newNode;
}


struct Node* getLastNode(struct Node* list)
{
	struct Node* current;
	current = list;
	if (current == NULL)
	{
		//TODO: --V-- in append, add as head.
		return current;
	}
	else
	{
		while (current)
		{
			current = current->next;
		}
		return current;
	}
}
void printPerson(const struct Node* node)
{
	if (node == NULL)
	{
		printf("is NULL\n");
	}
	else
	{
		printf("Word:%s address:%p nextInLine:%p\n",
			node->word,
			node,
			node->next);
	}
}

void PrintList(const struct Node* list)
{
	printf("Printing List:\n");
	const struct Node* t;
	t = list;
	if (t == NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		while (t)
		{
			printPerson(t);
			t = t->next;
		}
	}
}

void append(char* val) {

	struct Node* current = head;
	struct Node* newNode = createNode(val);;
	if (current == NULL) {
		current = createNode(val);
		head = newNode;
	}
	else {
		while (current->next != NULL) {
			current = current->next;

		}
		current->next = newNode;
	}
}

int main(int argc, char* argv[]) {


	if (argc == 1) {
		printf("%p", head);
		printf("1st arg set\n");
		append("12");
		printf("%p", head);
		append("42");
		append("mike");
		append("went");
		append("to");
		append("the");
		append("store");

		PrintList(head);
	}
	else if (argc == 2) {
		printf("2nd arg set\n");
	}
	else if (argc == 3) {


	}
	else {

	}
	return 0;
}
