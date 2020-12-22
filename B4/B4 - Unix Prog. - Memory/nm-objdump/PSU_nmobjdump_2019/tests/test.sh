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
    echo -ne "\n${CYAN}${bold}Test n°$nb_test${NC} ${bold}(File : $1)${NC}\n"

    # OBJDUMP TEST
    mkdir -p tests/test_$nb_test/
    objdump -fs $1 > "tests/test_$nb_test/expected.objdump" 2>/dev/null
    ./my_objdump $1 > "tests/test_$nb_test/got.objdump" 2>/dev/null

    result_objdump=`cmp tests/test_$nb_test/expected.objdump tests/test_$nb_test/got.objdump`

    echo -ne "[OBJDUMP] "
    if [[ "$result_objdump" == "" ]]
    then
        echo -ne "${GREEN}${bold}OK${NC}\n"
        ((test_passed++))
    else
        echo -ne "${RED}${bold}KO${NC}:\n"
        echo "$result_objdump"
        echo "See result in : tests/test_$nb_test/"
        ((test_failed++))
    fi

    # NM TEST
    mkdir -p tests/test_$nb_test/
    nm $1 > "tests/test_$nb_test/expected.nm" 2>/dev/null
    ./my_nm $1 > "tests/test_$nb_test/got.nm" 2>/dev/null

    result_nm=`cmp tests/test_$nb_test/expected.nm tests/test_$nb_test/got.nm`
    echo -ne "[NM] "
    if [[ "$result_nm" == "" ]]
    then
        echo -ne "${GREEN}${bold}OK${NC}\n"
        ((test_passed++))
    else
        echo -ne "${RED}${bold}KO${NC}\n"
        echo "$result_nm"
        echo "See result in : tests/test_$nb_test/"
        ((test_failed++))
    fi
    ((nb_test++))
}

exec_test "my_objdump"
exec_test "my_nm"
exec_test "tests/binary/64bits.o"
exec_test "tests/binary/32bits.o"
exec_test "tests/binary/libasm.so"
exec_test "tests/binary/64bits"
exec_test "tests/binary/32bits"
exec_test "tests/binary/truncated64"
exec_test "tests/binary/truncated32"
exec_test "tests/binary/elf-Linux-x64-bash"
exec_test "tests/binary/elf-Linux-x86-bash"
exec_test "Makefile"
exec_test "tests"
exec_test ""
exec_test "my_objdump Makefile my_nm"
exec_test "tests/binary/libmy.a"
exec_test "tests/binary/elf-Linux-ia64-bash"
exec_test "tests/binary/elf-Linux-lib-x64.so"
exec_test "tests/binary/elf-Linux-lib-x86.so"
exec_test "tests/binary/elf-Linux-lib-x86.so"

exit 0