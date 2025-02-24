#include "convert_integer_to_words.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert_number_to_words(int number, char* output);
void append_string(char* destination, const char* source);

const char* ones[]  = {"", "one", "two", "three", "four",
                       "five", "six", "seven", "eight", "nine"};
const char* teens[] = {"ten", "eleven", "twelve", "thirteen",
                       "fourteen", "fifteen", "sixteen", "seventeen",
                       "eighteen", "nineteen"};
const char* tens[]  = {"", "", "twenty", "thirty", "forty",
                       "fifty", "sixty", "seventy", "eighty", "ninety"};

char* convert_integer_to_words(int monetary_amount) {
    static char words_buffer[256];
    words_buffer[0] = '\0';

    int dollars = monetary_amount / 100;
    int cents = monetary_amount % 100;

    if (dollars > 0) {
        convert_number_to_words(dollars, words_buffer);
        append_string(words_buffer, (dollars == 1) ? " dollar" : " dollars");
    }

    if (cents > 0) {
        if (dollars > 0)
            append_string(words_buffer, " and ");
        convert_number_to_words(cents, words_buffer);
        append_string(words_buffer, (cents == 1) ? " cent" : " cents");
    } else if (dollars == 0) {
        append_string(words_buffer, "zero dollars");
    }

    return words_buffer;
}

void convert_number_to_words(int number, char* output) {
    if (number >= 1000) {
        append_string(output, ones[number / 1000]);
        append_string(output, " thousand");
        number %= 1000;
        if (number > 0)
            append_string(output, " ");
    }

    if (number >= 100) {
        append_string(output, ones[number / 100]);
        append_string(output, " hundred");
        number %= 100;
        if (number > 0)
            append_string(output, " ");
    }

    if (number >= 20) {
        append_string(output, tens[number / 10]);
        number %= 10;
        if (number > 0)
            append_string(output, "-");
    } else if (number >= 10) {
        append_string(output, teens[number - 10]);
        return;
    }

    if (number > 0)
        append_string(output, ones[number]);
}

void append_string(char* destination, const char* source) {
    strcat(destination, source);
}
