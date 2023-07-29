#include "stdlib.h"
#include "stddef.h"
#include "stdio.h"
#include "string.h"

// add your header files here

///////// Define input and output structures ////////////
typedef struct input {
    bool     valid;
    bool     reset;
    unsigned x : 32 ;
} input;

typedef struct output {
    bool    valid;
    int     result[2];
} output;
///////////////////////////////////////////////////////////


//////////////Prototype///////////////
void my_Model(input   in_ports,
              output  *out_ports
             );
//////////////////////////////////////

///////////////////////////////////////Compare model's and environment's outputs////////////////////////////////////////////////////////
void compare(output *out_ports_ref,
             output *out_ports_model
            ){
    int pass=1;

    if(out_ports_ref -> valid != out_ports_model -> valid ){ 
        printf("\nout_ports -> valid failure\tref= %d\tmodel= %d\n", out_ports_ref -> valid , out_ports_model -> valid); 
		pass=0;
    }
    for(int i=0;i<ARR_SIZE;i++){
        if(out_ports_ref -> result[i] != out_ports_model -> result[i]){ 
            printf("\nout_ports_ref -> result failure\tref= %ld\tmodel= %ld\ti=%d\n", out_ports_ref -> result[i] , out_ports_ref[i] -> result,i); 
            pass=0;
        }
    }   

    if(pass==1) printf("\n********************** Test Passed **********************\n");
    else {
        *failed=*failed+1;
        printf("\n********************** Test Failed **********************\n");
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){

    //////////////////* Open File For Reading  *////////////////
    FILE *fptr_in;
    char in_line[350];
    fptr_in=fopen("inputs.log","r");
    if(fptr_in==NULL){
        printf("Error opening input file\n");
        exit(1);
    }

    FILE *fptr_out;
    char out_line [400];
    fptr_out=fopen("outputs.log","r");
    if(fptr_out==NULL){
        printf("Error opening output file\n");
        exit(1);
    }

    input in_ports;
    output out_ports_model, output_ports_ref;

    int case_no=0;
    int failed=0;

    /////////////////* Read Input  Line by Line  *////////////////
    while (fgets(in_line,350,fptr_in) !=NULL && case_no<4572){

        long int temp_token;
        char *token;
        int i=0;
        case_no++;
        printf("\n\n********************** Case # %d **********************\n",case_no);
        int ii=0;
        
        int l=0;
        int m=0;
        
        while ((token = strtok(i ? NULL : in_line, ", ")) != NULL){
            i++;
            if(*token<'A'){
                //temp_token=atol(token);
                //printf("\nii=%d\t tmp_token=%ld\n",ii,temp_token); 
                if      (ii==0 ) in_ports.reset = atoi(token);
                else if (ii==1 ) in_ports.valid = atoi(token);
                
                ii++;
            }
        } 
        if (fgets(out_line,400,fptr_out) !=NULL){
            int j=0;
            int jj=0;
            while ((token = strtok(j ? NULL : out_line, ", ")) != NULL){
                j++;
                if(*token<'A'){
                     //temp_token=atol(token);
                     //printf("\njj=%d\t tmp_token=%ld\n",jj,temp_token); 
                     if     (jj==0)    out_ports_ref.valid          = atoi(token); 
                     else if(jj>=1 && jj<=1+ARR_SIZE){
                         out_ports_ref.result[jj-1] = atoi(token);
                     }

                    jj++;
                }
            }
        }

        My_model(in_ports, &out_ports_model ); 
        compare(&out_ports_ref, &out_ports_model ); 
    
    }
    printf("failed cases= %d", failed); 
    return 0;
}



