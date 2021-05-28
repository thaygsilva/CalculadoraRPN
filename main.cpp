// Thayna Gomes da Silva TIA:32092229
// Claudionor Domingues da Silva TIA:32086784

//Referências: Livro Introdução a Estrutura de Dados com técnicas de programaçao em C - Waldemar Celes/Renato Cerqueira/José Rangel 2nd cap 15.1.4
#include <string>
#include <iostream>
#include <sstream>
#include "calc.h"


int main()
{
	
	setlocale(LC_CTYPE, "pt_BR"); // não deixar LC_ALL, pois usa vírgula e não ponto, LC_CTYPE utiliza apenas letras pt.

	std::string input;
	while (input != "0") {
		Calc* calc = Create();
		bool error = false;

		std::getline(std::cin, input); // Lê uma string inserida pelo usuário.
		std::istringstream iss(input); // Passa o input para um istringstream.
		std::string str;
		// Cada string separada por um espaço em branco é copiada na string str.


		while (iss >> str)
		{
			//std::cout << str;
			// Tenta converter uma string para um float com std::stof().
			// Caso não seja possível realizar a conversão, o código dentro de catch
			// é executado.
			try
			{
				float value = std::stof(str);
				//std::cout << " (float: " << value << ")\n";
				Push(calc, value);
			}
			catch (std::invalid_argument e)
			{

				if (str == "+" || str == "-" || str == "*" || str == "/") {
					//std::cout << str << std::endl;
					if (calc->count == 1) {
						std::cout << "\nErro na expressão" << std::endl;
						error = true;
						break;
					}
					else calc_operador(calc, str, error);

				}
				else {
					std::cout << "\nErro na expressão" << std::endl;
					error = true;
					//	std::cout << " (" << e.what() << ")\n";
					break;
				}

			}

		}


		Node* n = new Node;
		n = Pop(calc);
		if (error == false)
		{
			if (IsEmpty(calc))
			{
				std::cout << "Resultado: " << n->value << std::endl;
			}
			else
			{
				std::cout << "Erro na expressão." << std::endl;
			}
		}


		DestroyNode(n);
		calc_libera(calc);
	}
	std::cout << "Fim" << std::endl;
}
