/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 03:08:08 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/11/09 15:03:25 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>      // std::vector
#include <deque>       // std::deque
#include <string>      // std::string
#include <stdexcept>   // std::runtime_error
#include <iostream>    // std::cout, std::cerr
#include <cstdlib>     // std::strtol
#include <climits>     // INT_MAX
#include <ctime>       // std::clock, CLOCKS_PER_SEC
#include <cerrno>      // errno, ERANGE
#include <iomanip>     // std::fixed, std::setprecision

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;

        struct Pair
        {
            int small;
            int large;
        };

        void        makeVectorPairs(const std::vector<int> &values, std::vector<Pair> &pairs, int &straggler, bool &hasStraggler) const;
        void        fordJohnsonVector(std::vector<int> &values);
        std::size_t findInsertPositionVector(const std::vector<int> &chain, int number, std::size_t limit) const;
        void        insertPendingVector(std::vector<int> &chain, const std::vector<Pair> &pairs) const;
        
        void        makeDequePairs(const std::deque<int> &values, std::deque<Pair> &pairs, int &straggler, bool &hasStraggler) const;
        void        fordJohnsonDeque(std::deque<int> &values);
        std::size_t findInsertPositionDeque(const std::deque<int> &chain, int number, std::size_t limit) const;
        void        insertPendingDeque(std::deque<int> &chain, const std::deque<Pair> &pairs) const;
        
        int parseNumber(const std::string &argument) const;

    public:
        //OCF
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        void    parseInput(int argc, char **argv);
        void    printBefore() const;
        void    printAfter() const;
        bool    sameResults() const;
        
        void    sortVector();
        void    sortDeque();

        void    printTimes(double vectorTime, double dequeTime) const;
};

#endif
