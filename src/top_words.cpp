#include "top_words.h"

#include <algorithm>

namespace top_words
{
    std::vector<WordCountPair> top_words::extract_top_n(const std::vector<WordCountPair> &input, std::size_t n)
    {
        if (input.empty() || n == 0)
            return {};

        if (n > input.size())
        {
            n = input.size();
        }

        std::vector<WordCountPair> result = input;

        if (n >= input.size())
        {
            std::sort(result.begin(), result.end(),
                [](const auto& a, const auto& b)
                {
                    return a.second > b.second;
                });
        }
        else
        {
            std::partial_sort(result.begin(), result.begin() + n, result.end(),
                [](const auto& a, const auto& b)
                {
                    return a.second > b.second;
                });
        }
        
        result.resize(n);
        return result;
    }
}