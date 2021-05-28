// Thayna Gomes da Silva TIA:32092229
// Claudionor Domingues da Silva TIA:32086784
#ifndef STACK_H__
#define STACK_H__
#include <string>
#include <iostream>

struct Node {
	float value;
	Node* previous;
	Node* next;
};

struct Calc {
	Node* head;
	int count;
};

Calc* Create();

Node* Push(Calc* stack, float elem);

Node* Pop(Calc* stack);

Node* Top(const Calc* stack);

int Count(const Calc* stack);

bool IsEmpty(const Calc* stack);

void DestroyNode(Node* node);

bool Clear(Calc* stack);

void calc_operador(Calc* calc, std::string op, bool error);

void calc_libera(Calc* calc);

#endif // STACK_QUEUE_H__


