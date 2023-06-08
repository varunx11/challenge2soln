#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct my_date_t
{
    uint8_t date;       
    uint8_t month;      
    uint16_t year;      
}my_date_t;

typedef enum status_t
{
    SUCCESS,                    
    NULL_PTR,                   
    INCORRECT
}status_t;


status_t string_to_date_converter(char* input_string, my_date_t* result_date){
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(input_string == NULL) return NULL_PTR;
    if(strlen(input_string) != 10 || input_string[2] != '/' || input_string[5] != '/'){
        return INCORRECT;
    }
    int day = atoi(input_string);
    int month = atoi(input_string + 3);
    int year = atoi(input_string + 6);
    if((day < 1 && day > 31) || (month < 1 && month > 12) || (year < 1 && year > 9999)){
        return INCORRECT;
    }
    if(day > days[month-1]) return INCORRECT;
    result_date->date = day;
    result_date->month = month;
    result_date->year = year;
    return SUCCESS;
};

int main(){
    char inp[10];
    scanf("%s", &inp);
    my_date_t my_date;
    status_t status;
    status = string_to_date_converter(inp, &my_date);
    switch (status) {
        case NULL_PTR: 
            printf("Null Pointer Exception\n");
            break;
        case INCORRECT: 
            printf("Incorrect date provided\n");
            break;
        case SUCCESS: 
            printf("Conversion successful\n");
            printf("Date: %d\n", my_date.date);
            printf("Month: %d\n", my_date.month);
            printf("Year: %d\n", my_date.year);
            break;
    }
}
