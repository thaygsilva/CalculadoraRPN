// Thayna Gomes da Silva TIA:32092229
// Claudionor Domingues da Silva TIA:32086784

//Refer�ncias: Livro Introdu��o a Estrutura de Dados com t�cnicas de programa�ao em C - Waldemar Celes/Renato Cerqueira/Jos� Rangel 2nd cap 15.1.4
#include <string>
#include <iostream>
#include <sstream>
#include "calc.h"


int main()
{
	
	setlocale(LC_CTYPE, "pt_BR"); // n�o deixar LC_ALL, pois usa v�rgula e n�o ponto, LC_CTYPE utiliza apenas letras pt.

	std::string input;
	while (input != "0") {
		Calc* calc = Create();
		bool error = false;

		std::getline(std::cin, input); // L� uma string inserida pelo usu�rio.
		std::istringstream iss(input); // Passa o input para um istringstream.
		std::string str;
		// Cada string separada por um espa�o em branco � copiada na string str.


		while (iss >> str)
		{
			//std::cout << str;
			// Tenta converter uma string para um float com std::stof().
			// Caso n�o seja poss�vel realizar a convers�o, o c�digo dentro de catch
			// � executado.
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
						std::cout << "\nErro na express�o" << std::endl;
						error = true;
						break;
					}
					else calc_operador(calc, str, error);

				}
				else {
					std::cout << "\nErro na express�o" << std::endl;
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
				std::cout << "Erro na express�o." << std::endl;
			}
		}


		DestroyNode(n);
		calc_libera(calc);
	}
	std::cout << "Fim" << std::endl;
}
