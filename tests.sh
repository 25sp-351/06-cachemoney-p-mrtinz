#!/bin/bash

if [[ ! -f money_converter.exe && ! -f money_converter ]]; then
    echo "Error: money_converter executable not found. Compile it first using 'make'."
    exit 1
fi

if [[ -f money_converter.exe ]]; then
    EXECUTABLE="./money_converter.exe"
else
    EXECUTABLE="./money_converter"
fi

declare -A TEST_CASES=(
    ["0"]="zero dollars"
    ["1"]="one cent"
    ["10"]="ten cents"
    ["100"]="one dollar"
    ["105"]="one dollar and five cents"
    ["1500"]="fifteen dollars"
    ["122309"]="one thousand two hundred twenty-three dollars and nine cents"
    ["999999"]="nine thousand nine hundred ninety-nine dollars and ninety-nine cents"
)

# Run tests
for INPUT in "${!TEST_CASES[@]}"; do
    EXPECTED_OUTPUT="${TEST_CASES[$INPUT]}"
    
    ACTUAL_OUTPUT=$($EXECUTABLE <<< "$INPUT" | awk -F' = ' '{print $2}' | tr -d '\n' | sed 's/^ *//;s/ *$//')
    
    if [[ "$ACTUAL_OUTPUT" == "$EXPECTED_OUTPUT" ]]; then
        echo "Test Passed: $INPUT -> $EXPECTED_OUTPUT"
    else
        echo "   Test Failed: $INPUT"
        exit 1
    fi
done

echo "All tests passed!"
