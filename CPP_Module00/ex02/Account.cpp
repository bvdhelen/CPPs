/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:04:12 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/12/23 12:04:12 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream> //Para imprimir por consola (std::cout)
#include <iomanip> //Para utilizar setw, setfill
#include <ctime> //Para utilizar fecha y hora

/* RESUMEN DEL LOG
info global		->	displayAccountInfos
crear cuenta	->	constructor
mostrar cuenta	->	displayStatus
ingresar		->	makeDeposit
retirar OK		->	makeWithdrawal
retirar KO		->	makeWithdrawal
destruir		->	destructor
*/

// Para corregir el ejercicio:
// ./globalbanksters | diff - 19920104_091532.log

// FUNCIÓN PARA IMPRIMIR FECHA Y HORA ACTUAL
// Formato: [YYYYMMDD_HHMMSS]
	//lt->tm_year	años desde 1900
	//lt->tm_mon	mes (0–11)
	//lt->tm_mday	día (1–31)
	//lt->tm_hour	horas (0–23)
	//lt->tm_min	minutos (0–59)
	//lt->tm_sec	segundos (0–59)
// std::setw(2)		 -> siempre ocupa 2 carácteres
// std::setfill('0') -> rellena con 0 por la izquierda
void	Account::_displayTimestamp(void)
{
	// var1: tiempo actual en seg
	// var2: estructura que contiene la fecha
	std::time_t	now;
	std::tm		*lt;

	now = std::time(NULL);
	lt = std::localtime(&now);
	//std::cout << "[19920104_091532] ";
	std::cout	<< "["
				<< lt->tm_year + 1900
				<< std::setw(2) << std::setfill('0') << lt->tm_mon + 1
				<< std::setw(2) << std::setfill('0') << lt->tm_mday
				<< "_"
				<< std::setw(2) << std::setfill('0') << lt->tm_hour
				<< std::setw(2) << std::setfill('0') << lt->tm_min
				<< std::setw(2) << std::setfill('0') << lt->tm_sec
				<< "] ";
}

// Las variables static se declaran en el .hpp:
	//static int	_nbAccounts;
	//static int	_totalAmount;
	//static int	_totalNbDeposits;
	//static int	_totalNbWithdrawals;
// Y se definen en el .cpp:
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// Constructor
Account::Account(int initial_deposit)
{
	// Inicializar atributos privados de la clase 
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	// Actualizar variables globales
	_nbAccounts++;
	_totalAmount += initial_deposit;

	// Imprime crear cuenta (igual que el log)
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created"
				<< std::endl;
}

// Destructor
Account::~Account(void)
{
	// Imprime cerrar cuenta (igual que el log)
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed"
				<< std::endl;
}

// FUNCIONES PARA MOSTRAR
// global
void	Account::displayAccountsInfos(void)
{
	// Imprime estado del banco
	_displayTimestamp();
	std::cout	<< "accounts:" << _nbAccounts
				<< ";total:" << _totalAmount
				<< ";deposits:" << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals
				<< std::endl;
}

// por cuenta
void	Account::displayStatus(void) const
{
	// Imprime estado de la cuenta
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
				<< std::endl;
}

// FUNCIÓN PARA METER DINERO EN LA CUENTA
void	Account::makeDeposit(int deposit)
{
	// Imprime estado previo de la cuenta
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";deposit:" << deposit;
	// Modifica la cuenta
	_amount += deposit;
	_nbDeposits++;
	// Modifica los contadores globales
	_totalAmount += deposit;
	_totalNbDeposits++;
	// Imprime estado final de la cuenta  (después del depósito)
	std::cout	<< ";amount:" << _amount
				<< ";nb_deposits:" << _nbDeposits
				<< std::endl;
}

// FUNCIÓN PARA SACAR DINERO DE LA CUENTA
bool	Account::makeWithdrawal(int withdrawal)
{
	// Imprime estado previo de la cuenta
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount;
	
	// Comprobar si NO se puede sacar dinero
	if (withdrawal > _amount)
	{
		std::cout	<< ";withdrawal:"
					<< "refused"
					<< std::endl;
		return (false);
	}
	// Modifica la cuenta
	_amount -= withdrawal;
	_nbWithdrawals++;
	// Modifica los contadores globales
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	// Imprime estado final de la cuenta (después de la retirada)
	std::cout	<< ";withdrawal:" << withdrawal
				<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals
				<< std::endl;
	return (true);
}
