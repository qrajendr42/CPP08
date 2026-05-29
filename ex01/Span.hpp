#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <iostream>

class Span
{
    private:
        unsigned int    _maxSize;
        std::vector<int> _data;

    public:
        Span(unsigned int n);
        Span(const Span &copy);
        Span&operator=(const Span &src);
        ~Span();

        void    addNumber(int nbr);
        int     shortestSpan(void) const;
        int     longestSpan(void) const;

        template <typename InputIterator>
        void    addRange(InputIterator begin, InputIterator end)
        {
            typedef typename std::iterator_traits<InputIterator>::difference_type diff_t;

            diff_t d = std::distance(begin, end);
            if (d < 0)
                throw std::out_of_range("addRange: Invalid iterator range");

            if (_data.size() + static_cast<size_t>(d) > _maxSize)
                throw std::out_of_range("addRange: Span will exceed max capacity");

            _data.insert(_data.end(), begin, end);
        }
};

#endif