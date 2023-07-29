#!/bin/bash
input=$2
i=0


if [ $1 -eq 3 ]
then
    printf "void compare(\t,\t){\n\tint pass=1;\n"
fi

while IFS="," read -r value
 
do
    if [ $1 -eq 1 ]
    then
        if [ $i -eq 0 ]
        then
            printf "if\t(ii==0 ) %-23s\t= atoi(token);\n" $value
        else
            printf "else if (ii==%-2d) %-23s\t= atoi(token);\n" $i $value
        fi
        i=$((i+1))
    elif [ $1 -eq 2 ]
    then
        if [ $i -eq 0 ]
        then
            printf "if\t(jj==0 ) %-23s_ref\t= atoi(token);\n" $value
        else
            printf "else if (jj==%-2d) %-23s\t= atoi(token);\n" $i $value
        fi
        i=$((i+1))
    elif [ $1 -eq 3 ]
    then
        printf "if(%-25s_ref != %-25s){\nprintf(\"%-25s failure\tref= %%d\tmodel= %%d '\\\n' \", %-25s ,  %-25s );\n pass=0;\n}\n" $value $value $value $value $value
        i=$((i+1))
    fi

if [ $1 -eq 3 ]
then
    printf "if (pass) printf(\"***************Test Passed***************\");\n else printf(\"***************Test Failed***************\");"
fi

done < "$input"

