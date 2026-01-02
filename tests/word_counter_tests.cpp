#include "word_counter.h"

#include <cassert>
#include <vector>
#include <string>
#include <iostream>

using namespace word_count;

void test_empty_input()
{
    std::vector<Word> words;

    auto ordered   = count_ordered(words);
    auto unordered = count_unordered(words);

    assert(ordered.empty());
    assert(unordered.empty());
}

void test_single_word()
{
    std::vector<Word> words = { "hello" };

    auto ordered   = count_ordered(words);
    auto unordered = count_unordered(words);

    assert(ordered.size() == 1);
    assert(unordered.size() == 1);

    assert(ordered.at("hello") == 1);
    assert(unordered.at("hello") == 1);
}

void test_multiple_words()
{
    std::vector<Word> words =
    {
        "apple", "banana", "apple", "orange", "banana", "apple"
    };

    auto ordered   = count_ordered(words);
    auto unordered = count_unordered(words);

    assert(ordered.at("apple")  == 3);
    assert(ordered.at("banana") == 2);
    assert(ordered.at("orange") == 1);

    assert(unordered.at("apple")  == 3);
    assert(unordered.at("banana") == 2);
    assert(unordered.at("orange") == 1);
}

void test_case_sensitivity_assumption()
{
    // word_counter assumes normalized input
    std::vector<Word> words =
    {
        "Apple", "apple", "APPLE"
    };

    auto result = count_unordered(words);

    // This documents the expectation rather than enforcing normalization
    assert(result.at("Apple")  == 1);
    assert(result.at("apple")  == 1);
    assert(result.at("APPLE")  == 1);
}

int main()
{
    test_empty_input();
    test_single_word();
    test_multiple_words();
    test_case_sensitivity_assumption();

    std::cout << "All word_counter tests passed.\n";
    return 0;
}
