#include "word_counter.h"

namespace word_count
{
    OrderedResult count_ordered(const std::vector<Word> &words)
    {
        OrderedResult result;

        for (const auto& word : words)
        {
            ++result[word];
        }

        return result;
    }

    UnorderedResult count_unordered(const std::vector<Word> &words)
    {
        UnorderedResult result;
        result.reserve(words.size());

        for (const auto& word : words)
        {
            ++result[word];
        }

        return result;
    }
}
