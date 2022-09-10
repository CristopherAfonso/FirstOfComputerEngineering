#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include "functions2.h"

int main() {
    std::string text_number_of_words = " ";
    std::vector<std::string> all_words;
    int exact_words{0};

    introduction();
    std::cin >> text_number_of_words;

    exact_words = number_of_words(text_number_of_words);

    while (exact_words == 0){
        error_message();
        std::cin >> text_number_of_words;
        exact_words = number_of_words(text_number_of_words);
    }

    all_words.reserve(exact_words);

    std::string actual_word;

    for(int i = 1; i <= exact_words; ++i){
        std::cout << std::endl;
        std::cout << "Introduce la palabra " << i << ": ";
        std::cin >> actual_word;
        std::cout << std::endl << std::endl;

        all_words.emplace_back(actual_word);
    }    

    final_message1();

    for(std::string each_word: all_words){
        std::cout << each_word << "  ";
    }
    std::cout << std::endl << std::endl;

    final_message2();

    for(int e = 0; e < exact_words; ++e){
        if (IsPalindrome(all_words[e]) == true){
            int word_place{e + 1};
            std::cout << "Palabra " << (word_place) << ": " << all_words[e] << std::endl; 
        }
    }

    return 0;
}