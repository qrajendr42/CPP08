#include "Span.hpp"

Span::Span(unsigned int n) : _maxSize(n), _data() {}

Span::Span(const Span &copy) : _maxSize(copy._maxSize), _data(copy._data) {}

Span &Span::operator=(const Span &src)
{
    if (this != &src)
    {
        _maxSize = src._maxSize;
        _data = src._data;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int nbr)
{
    if(_data.size() >= _maxSize)
        throw std::out_of_range("Span is full");
    _data.push_back(nbr);
}

int Span::shortestSpan(void) const
{
    if (_data.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");
    std::vector<int> tmp(_data);
    std::sort(tmp.begin(), tmp.end());

    int minSpan = tmp[1] - tmp[0];
    size_t i = 2;
    while (i < tmp.size())
    {
        int diff = tmp[i] - tmp[i - 1];
        if (diff < minSpan)
            minSpan = diff;
        ++i;
    }
    return minSpan;
}

int Span::longestSpan(void) const
{
    if (_data.size() < 2)
        throw std::logic_error("Not enough numbers to find a span");
    int minVal = *std::min_element(_data.begin(), _data.end());
    int maxVal = *std::max_element(_data.begin(), _data.end());
    return maxVal - minVal;
}