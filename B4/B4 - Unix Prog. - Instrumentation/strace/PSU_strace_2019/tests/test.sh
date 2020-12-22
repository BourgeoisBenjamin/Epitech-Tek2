#!/bin/bash

test_passed=0
test_crashed=0
test_failed=0
nb_test=0

bold=$(tput bold)
normal=$(tput sgr0)
RED='\033[0;31m'
CYAN='\033[0;36m'
GREEN='\033[0;32m'
NC='\033[0m'

# arg1 = file to test
exec_test()
{
    # Display the test and numero
    echo -ne "\n${CYAN}${bold}Test n°$nb_test${NC} ${bold}(Command : $2 | Line : $3)${NC}\n"

    # OBJDUMP TEST
    mkdir -p tests/test_$nb_test/
    if [[ $1 -eq 1 ]]
    then
      ./strace -s $2 2>&1 >/dev/null | grep $3 > "tests/test_$nb_test/got"
      strace $2 2>&1 >/dev/null | grep $3 > "tests/test_$nb_test/expected"
    else
      ./strace $2 2>&1 >/dev/null | grep $3 > "tests/test_$nb_test/got"
      strace -xx $2 2>&1 >/dev/null | grep $3 > "tests/test_$nb_test/expected"
    fi

    result=`diff -EZbwB tests/test_$nb_test/expected tests/test_$nb_test/got`

    if [[ "$result" == "" ]]
    then
        echo -ne "${GREEN}${bold}OK${NC}\n"
        ((test_passed++))
    else
        echo -ne "${RED}${bold}KO${NC}:\n"
        echo "$result"
        echo "See result in : tests/test_$nb_test/"
        ((test_failed++))
    fi
    ((nb_test++))
}

exec_test 1 "ls" "close"
exec_test 1 "ls" "write"
exec_test 1 "ls" "fstat"
exec_test 0 "ls" "write"

exit 0