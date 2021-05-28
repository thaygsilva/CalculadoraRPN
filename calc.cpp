// Thayna Gomes da Silva TIA:32092229
// Claudionor Domingues da Silva TIA:32086784
#include "calc.h"
#include <string.h>
#include <iostream>
using namespace std;


Calc* Create()
{
	Calc* stack = new Calc;

	stack->count = 0;
	stack->head = nullptr;

	return stack;
}

Node* Push(Calc* stack, float elem)
{

	Node* n = new Node;

	n->value = elem;
	n->next = nullptr;

	if (IsEmpty(stack)) {
		stack->head = n;
		n->previous = nullptr;
	}
	else {
		stack->head->next = n;
		n->previous = stack->head;
		stack->head = n;

	}

	++stack->count;
	return n;
}

Node* Pop(Calc* stack)
{

	Node* toRemove = stack->head;
	
	if (IsEmpty(stack)) return toRemove;

	if (stack->count == 1) stack->head = nullptr;
	else {
		stack->head = stack->head->previous;
		stack->head->next = nullptr;
	}
	toRemove->next = nullptr;
	toRemove->previous = nullptr;
	--stack->count;

	return toRemove;
}

Node* Top(Calc* stack)
{

	return stack->head;
}

int Count(const Calc* stack)
{
	return stack->count;
}

bool IsEmpty(const Calc* stack)
{
	return stack->count == 0;
}

void DestroyNode(Node* node)
{
	delete node;
	node = nullptr;

}

bool Clear(Calc* stack)
{

	Node* toRemove = stack->head;
	Node* next = nullptr;

	if (IsEmpty(stack)) return true;

	while (stack->count != 0) {
		next = toRemove->next;
		DestroyNode(toRemove);
		toRemove = next;
		--stack->count;
	}
	stack->head = nullptr;

	return IsEmpty(stack);
}

void calc_operador(Calc* calc, string op, bool error) {


	Node* v1 = new Node;
	Node* v2 = new Node;

	v2 = Pop(calc);
	v1 = Pop(calc);

	if (v1 == nullptr || v2 == nullptr) {
		std::cout << "Erro na expressão." << std::endl;
		error = true;
		return;
	}


	float v = 0.0;
	if (op == "+") v = v1->value + v2->value;
	else if (op == "-") v = v1->value - v2->value;
	else if (op == "*") v = v1->value * v2->value;
	else if (op == "/") v = v1->value / v2->value;
	else
	{
		std::cout << "Erro na expressão." << std::endl;
		error = true;
		return ;
	}

	Push(calc, v);

}

void calc_libera(Calc* calc) {


	Clear(calc);
	delete(calc);
	calc = nullptr;
}



