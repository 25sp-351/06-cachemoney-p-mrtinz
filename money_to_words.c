#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "convert_integer_to_words.h"
#include "cache_manager.h"

// Function to retrieve or compute money-to-words conversion
char* convert_money_to_words(int monetary_amount) {

    char* cached_result = get_cached_value(monetary_amount);
    if (cached_result != NULL) {
        return cached_result;
    }

    // Convert monetary amount to words
    char* word_representation = convert_integer_to_words(monetary_amount);

    store_cached_value(monetary_amount, word_representation);

    return word_representation;
}

int main() {
    int monetary_amount;

    printf("Enter an amount in cents (or press Ctrl+D to exit):\n");

    while (printf("> "), scanf("%d", &monetary_amount) == 1) {
        printf("%d = %s\n", monetary_amount, convert_money_to_words(monetary_amount));
    }

    free_cache();

    printf("\nExiting program. Goodbye!\n");
    return 0;
}