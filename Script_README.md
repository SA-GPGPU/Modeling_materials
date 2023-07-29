# InOut Script

- The Script takes two arguments
    - First one is 1 or 2 or 3
        - 1 is to generate input capture
        - 2 is to generate output capture
        - 3 is to generate "compare function"
    - Second argument is input or output file name without quotes

- You have to write file which consists of inputs only and another file for outputs only for example:
```
reset
ready
valid
```
    - script output: 
```c
if(ii==0)   reset =atoi(token);
if(ii==1)   ready =atoi(token);
if(ii==2)   valid =atoi(token);
```

- After Generating the "compare" function, modify the name of one of the compared variables by underscore ref after struct/variable  name and add parameters list
