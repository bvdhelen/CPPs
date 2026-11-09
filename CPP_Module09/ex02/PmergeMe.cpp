/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvdhelen <bvdhelen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 03:08:01 by bvdhelen          #+#    #+#             */
/*   Updated: 2026/11/09 15:07:21 by bvdhelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{ 
}

PmergeMe::PmergeMe(const PmergeMe &other)
    : _vector(other._vector), _deque(other._deque)
{
    
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque = other._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

int PmergeMe::parseNumber(const std::string &argument) const
{
    std::size_t i;
    char        *end;
    long        value;

    if (argument.empty())
        throw std::runtime_error("Error");
    
    i = 0;
    while (i < argument.length())
    {
        if (argument[i] < '0' || argument[i] > '9')
            throw std::runtime_error("Error");
        i++;
    }

    errno = 0;
    value = std::strtol(argument.c_str(), &end, 10);

    if (errno == ERANGE || *end != '\0'
        || value <= 0 || value > INT_MAX)
        throw std::runtime_error("Error");
    
    return static_cast<int>(value);
}

void PmergeMe::parseInput(int argc, char **argv)
{
    int i;
    int number;
    
    if (argc < 2)
        throw std::runtime_error("Error");
    
    _vector.clear();
    _deque.clear();
    
    i = 1;
    while (i < argc)
    {
        number = parseNumber(argv[i]);
        _vector.push_back(number);
        _deque.push_back(number);
        i++;
    }
}

void PmergeMe::printBefore() const
{
    std::vector<int>::const_iterator    it;
    
    std::cout << "Before: ";
    for (it = _vector.begin(); it != _vector.end(); ++it)
    {
        if (it != _vector.begin())
            std::cout << " ";
        std::cout << *it;
    }
    std::cout << std::endl;
}

void    PmergeMe::printAfter() const
{
    std::vector<int>::const_iterator    it;
    
    std::cout << "After: ";
    for (it = _vector.begin(); it != _vector.end(); ++it)
    {
        if (it != _vector.begin())
            std::cout << " ";
        std::cout << *it;
    }
    std::cout << std::endl;
}

void    PmergeMe::makeVectorPairs(const std::vector<int> &values,
            std::vector<Pair> &pairs, int &straggler, bool &hasStraggler) const
{
    std::size_t i;
    Pair        pair;

    pairs.clear();
    hasStraggler = false;
    i = 0;
    
    while (i + 1 < values.size())
    {
        if (values[i] < values[i + 1])
        {
            pair.small = values[i];
            pair.large = values[i + 1];
        }
        else
        {
            pair.small = values[i + 1];
            pair.large = values[i];
        }
        pairs.push_back(pair);
        i += 2;
    }
    if (i < values.size())
    {
        straggler = values[i];
        hasStraggler = true;
    }
}

std::size_t PmergeMe::findInsertPositionVector(const std::vector<int> &chain, int number, std::size_t limit) const
{
    std::size_t left;
    std::size_t right;
    std::size_t middle;

    left = 0;
    right = limit;
    while (left < right)
    {
        middle = left + (right - left) / 2;
        if (chain[middle] < number)
            left = middle + 1;
        else
            right = middle;
    }
    return left;
}

void PmergeMe::insertPendingVector(std::vector<int> &chain, const std::vector<Pair> &pairs) const
{
    std::size_t previous;
    std::size_t current;
    std::size_t next;
    std::size_t end;
    std::size_t index;
    std::size_t limit;
    std::size_t position;

    if (pairs.size() <= 1)
        return;

    previous = 1;
    current = 3;
    while (previous < pairs.size())
    {
        end = current;
        if (end > pairs.size())
            end = pairs.size();

        index = end;
        while (index > previous)
        {
            limit = 0;
            while (limit < chain.size()
                && chain[limit] != pairs[index - 1].large)
                limit++;

            position = findInsertPositionVector(chain,
                    pairs[index - 1].small, limit);
            chain.insert(chain.begin() + position,
                pairs[index - 1].small);
            index--;
        }

        next = current + (2 * previous);
        previous = current;
        current = next;
    }
}

void    PmergeMe::fordJohnsonVector(std::vector<int> &values)
{
    std::vector<Pair>   pairs;
    std::vector<int>    maxima;
    std::vector<Pair>   sortedPairs;
    std::vector<int>    used;
    std::vector<int>    mainChain;
    int                 straggler;
    bool                hasStraggler;
    std::size_t         i;
    std::size_t         j;
    
    if (values.size() <= 1)
        return ;
    
    makeVectorPairs(values, pairs, straggler, hasStraggler);

    i = 0;
    while (i < pairs.size())
    {
        maxima.push_back(pairs[i].large);
        i++;
    }
    
    fordJohnsonVector(maxima);
    
    used.assign(pairs.size(), 0);
    i = 0;
    while (i < maxima.size())
    {
        j = 0;
        while (j < pairs.size())
        {
            if (used[j] == 0 && pairs[j].large == maxima[i])
            {
                sortedPairs.push_back(pairs[j]);
                used[j] = 1;
                break ;
            }
            j++;
        }
        i++;
    }
    
    mainChain.push_back(sortedPairs[0].small);
    mainChain.push_back(sortedPairs[0].large);
    
    i = 1;
    while (i < sortedPairs.size())
    {
        mainChain.push_back(sortedPairs[i].large);
        i++;
    }
    
    insertPendingVector(mainChain, sortedPairs);
    
    if (hasStraggler)
    {
        std::size_t position;
        
        position = findInsertPositionVector(mainChain, straggler, mainChain.size());
        mainChain.insert(mainChain.begin() + position, straggler);
    }

    values = mainChain;
}

void    PmergeMe::sortVector()
{
    fordJohnsonVector(_vector);
}

void    PmergeMe::makeDequePairs(const std::deque<int> &values,
            std::deque<Pair> &pairs, int &straggler, bool &hasStraggler) const
{
    std::size_t i;
    Pair        pair;

    pairs.clear();
    hasStraggler = false;
    i = 0;
    
    while (i + 1 < values.size())
    {
        if (values[i] < values[i + 1])
        {
            pair.small = values[i];
            pair.large = values[i + 1];
        }
        else
        {
            pair.small = values[i + 1];
            pair.large = values[i];
        }
        pairs.push_back(pair);
        i += 2;
    }
    if (i < values.size())
    {
        straggler = values[i];
        hasStraggler = true;
    }
}

std::size_t PmergeMe::findInsertPositionDeque(const std::deque<int> &chain, int number, std::size_t limit) const
{
    std::size_t left;
    std::size_t right;
    std::size_t middle;

    left = 0;
    right = limit;
    while (left < right)
    {
        middle = left + (right - left) / 2;
        if (chain[middle] < number)
            left = middle + 1;
        else
            right = middle;
    }
    return left;
}

void PmergeMe::insertPendingDeque(std::deque<int> &chain, const std::deque<Pair> &pairs) const
{
    std::size_t previous;
    std::size_t current;
    std::size_t next;
    std::size_t end;
    std::size_t index;
    std::size_t limit;
    std::size_t position;

    if (pairs.size() <= 1)
        return;

    previous = 1;
    current = 3;
    while (previous < pairs.size())
    {
        end = current;
        if (end > pairs.size())
            end = pairs.size();

        index = end;
        while (index > previous)
        {
            limit = 0;
            while (limit < chain.size()
                && chain[limit] != pairs[index - 1].large)
                limit++;

            position = findInsertPositionDeque(chain,
                    pairs[index - 1].small, limit);
            chain.insert(chain.begin() + position,
                pairs[index - 1].small);
            index--;
        }

        next = current + (2 * previous);
        previous = current;
        current = next;
    }
}

void    PmergeMe::fordJohnsonDeque(std::deque<int> &values)
{
    std::deque<Pair>   pairs;
    std::deque<int>    maxima;
    std::deque<Pair>   sortedPairs;
    std::deque<int>    used;
    std::deque<int>    mainChain;
    int                 straggler;
    bool                hasStraggler;
    std::size_t         i;
    std::size_t         j;
    
    if (values.size() <= 1)
        return ;
    
    makeDequePairs(values, pairs, straggler, hasStraggler);

    i = 0;
    while (i < pairs.size())
    {
        maxima.push_back(pairs[i].large);
        i++;
    }
    
    fordJohnsonDeque(maxima);
    
    used.assign(pairs.size(), 0);
    i = 0;
    while (i < maxima.size())
    {
        j = 0;
        while (j < pairs.size())
        {
            if (used[j] == 0 && pairs[j].large == maxima[i])
            {
                sortedPairs.push_back(pairs[j]);
                used[j] = 1;
                break ;
            }
            j++;
        }
        i++;
    }
    
    mainChain.push_back(sortedPairs[0].small);
    mainChain.push_back(sortedPairs[0].large);
    
    i = 1;
    while (i < sortedPairs.size())
    {
        mainChain.push_back(sortedPairs[i].large);
        i++;
    }
    
    insertPendingDeque(mainChain, sortedPairs);
    
    if (hasStraggler)
    {
        std::size_t position;
        
        position = findInsertPositionDeque(mainChain, straggler, mainChain.size());
        mainChain.insert(mainChain.begin() + position, straggler);
    }

    values = mainChain;
}

void    PmergeMe::sortDeque()
{
    fordJohnsonDeque(_deque);
}

// Checker vector == deque
bool    PmergeMe::sameResults() const
{
    std::size_t i;

    if (_vector.size() != _deque.size())
        return false;
    
    i = 0;
    while (i < _vector.size())
    {
        if (_vector[i] != _deque[i])
            return false;
        i++;
    }
    return true;
}

// Time
void    PmergeMe::printTimes(double vectorTime, double dequeTime) const
{
    std::cout << std::fixed << std::setprecision(5);

    std::cout << "Time to process a range of " << _vector.size()
        << " elements with std::vector : "
        << vectorTime << " us" << std::endl;
    
    std::cout << "Time to process a range of " << _deque.size()
        << " elements with std::deque : "
        << dequeTime << " us" << std::endl;
}
