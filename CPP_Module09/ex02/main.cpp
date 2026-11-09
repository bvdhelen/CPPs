/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 03:08:18 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/11/09 15:16:25 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    std::clock_t    start;
    std::clock_t    end;
    double          vectorTime;
    double          dequeTime;
    
    try
    {
        PmergeMe    pmerge;

        pmerge.parseInput(argc, argv);
        pmerge.printBefore();
        
        start = std::clock();
        pmerge.sortVector();
        end = std::clock();
        vectorTime = static_cast<double>(end - start)
            * 1000000.0 / CLOCKS_PER_SEC;

        start = std::clock();
        pmerge.sortDeque();
        end = std::clock();
        dequeTime = static_cast<double>(end - start)
            * 1000000.0 / CLOCKS_PER_SEC;
        
        if (!pmerge.sameResults())
            throw std::runtime_error("Error");
        
        pmerge.printAfter();
        pmerge.printTimes(vectorTime, dequeTime);
    }
    
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
