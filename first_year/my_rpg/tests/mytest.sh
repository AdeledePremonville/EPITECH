#!/bin/bash

declare -i finalres;
finalres=0;
RED='\033[0;31m'
GREEN='\033[0;32m'
ORANGE='\033[0;33m'
BLUE='\033[0;34m'
PURPLE='\033[0;35m'
CYAN='\033[0;36m'
GREY='\033[0;37m'
NC='\033[0m'

echo '_______________________________________________________________________'
echo '                                                                      |'
echo -e ${PURPLE}\
     '                          FUNCTIONNAL-TESTS'${NC}\
     '                         |'
echo -e ${CYAN}\
     '                               projet'${NC}\
     '                               |'
echo '______________________________________________________________________|'
echo ''

echo '_______________________________________________________________________'

./project 1 > tests/res.txt

diff -q tests/res.txt tests/test_1.txt > /dev/null
res=$?

if [ $res == 1 ]
then
    echo ''
    echo -e ${RED}' fail test 1'${NC}
    echo ''
elif [ $res == 0 ]
then
    echo ''
    echo -e ${GREEN}' sucess test 1'${NC}
    echo ''
    ((finalres++))
else
    echo ''
    echo ' error with diff command test 1'
    echo ''
fi

echo '_______________________________________________________________________'

./project 1 > tests/res.txt

diff -q tests/res.txt tests/test_2.txt > /dev/null
res=$?

if [ $res == 1 ]
then
    echo ''
    echo -e ${RED}' fail test 2'${NC}
    echo ''
elif [ $res == 0 ]
then
    echo ''
    echo -e ${GREEN}' sucess test 2'${NC}
    echo ''
    ((finalres++))
else
    echo ''
    echo ' error with diff command test 2'
    echo ''
fi

echo '_______________________________________________________________________'

./project 1 > tests/res.txt

diff -q tests/res.txt tests/test_3.txt > /dev/null
res=$?

if [ $res == 1 ]
then
    echo ''
    echo -e ${RED}' fail test 3'${NC}
    echo ''
elif [ $res == 0 ]
then
    echo ''
    echo -e ${GREEN}' sucess test 3'${NC}
    echo ''
    ((finalres++))
else
    echo ''
    echo ' error with diff command test 3'
    echo ''
fi

echo '_______________________________________________________________________'
echo ''
echo -e ${BLUE}' END OF THE TEST                            ' ${CYAN}\
     '              RESULT'${NC}'': $((finalres))'/3'
echo '_______________________________________________________________________'
echo ''
