/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:53:42 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/12/27 16:53:42 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	1) Recibir 3 argumentos:
		./replace filename s1 s2
	2) Leer el archivo filename
	3) Reemplazar todas las apariciones de s1 por s2
	4) Guardar el resultado en un nuevo archivo:
		filename.replace
*/

	// std::ifstream -> input file stream -> abre el archivo
	// std::ofstream -> output file stream -> crea el archivo si no existe

#include <iostream>
#include <fstream>
#include <string>

// std::string::npos ("no position")
	//Constante estática de std::string -> Valor no encontrado
void	replaceString(std::string &content, const std::string &s1, const std::string &s2)
{
	size_t	pos = 0;

	while ((pos = content.find(s1, pos)) != std::string::npos)
	{
		content.erase(pos, s1.length());
		content.insert(pos, s2);
		pos += s2.length();
	}
}

std::string	readFile(std::ifstream &inputFile)
{
	std::string	content;
	std::string	line;

	while (std::getline(inputFile, line))
	{
		content += line;
		if (!inputFile.eof())
			content += "\n";
	}
	return (content);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "\033[0;31mError\033[0m" << std::endl;
		std::cout << "Usage: ./replace filename s1 s2" << std::endl;
		return (1);
	}
	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	if (s1.empty())
	{
		std::cout << "Error: s1 cannot be empty" << std::endl;
		return (1);
	}
	// Archivo de entrada
	std::ifstream	inputFile(filename.c_str());
	if (!inputFile)
	{
		std::cout << "Error: cannot open input file " << filename << std::endl;
		return (1);
	}
	// Archivo de salida
	std::ofstream	outputFile((filename + ".replace").c_str());
	if (!outputFile)
	{
		std::cout << "Error: cannot create output file " << filename << ".replace" << std::endl;
		return (1);
	}
	// Leer todo el archivo y guardarlo en un string
	std::string content = readFile(inputFile);
	// Reemplazar s1 por s2
	replaceString(content, s1, s2);
	// Escribir en output
	outputFile << content;
	// No es necesario cerrar los archivos ya que en C++ se cierran solos con el destructor
	inputFile.close();
	outputFile.close();
	return (0);
}
