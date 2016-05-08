#include"transform.h"

#include"string_utility.h"
/**
	Get inner parentheses,

*/
static char* get_inner_parentheses(char* c){
	char* left_par;
	char* right_par;
    left_par = strstr(c,"(");
    if(!left_par)
        return c;
	//while(left_par = strstr(c,"(")){
		right_par = strstr(left_par,")");
		left_par = rstrstr(c,"(",right_par - c );

		//continue;
	//}
	return left_par;
}


static int get_number_size(const char* express,const char* pos, unsigned int right_handed){
    char* divs;
    char* posit;
    char* negat;
    char* multi;
    char* endpos = NULL;


    if(right_handed){
        pos++;  /*character after the pos*/
        divs = strstr(pos,"/");
        negat = strstr(pos,"-");
        posit = strstr(pos,"+");
        multi = strstr(pos,"-");

        if(endpos < divs)endpos = divs;
        if(endpos < negat)endpos = negat;
        if(endpos < posit)endpos = posit;
        if(endpos < multi)endpos = multi;
    }
    else{
        pos--;
        divs = rstrstr(express,"/",pos - express);
        negat = rstrstr(express,"-",pos - express);
        posit = rstrstr(express,"+",pos - express);
        multi = rstrstr(express,"-",pos - express);
        if(endpos < divs)endpos = divs;
        if(endpos < negat)endpos = negat;
        if(endpos < posit)endpos = posit;
        if(endpos < multi)endpos = multi;
    }
    if(!endpos)
        return endpos = strlen(pos);
    return (endpos - pos);
}

static int transform_arithmetic(char* expression){
    float a,b;
    char symbolbuf[64] = { '\0'};
    char* divs;
    char* posit;
    char* negat;
    char* multi;
    if((divs=strstr(expression,"/"))){
        posit = rstrstr(expression,"+",divs - expression);
        negat = rstrstr(expression,"-",divs - expression);
        multi = rstrstr(expression,"*",divs - expression);


        sprintf(expression,"%d",a / b);
    }
    else if((multi=strstr(expression,"*"))){
        posit = rstrstr(expression,"+",multi - expression);
        negat = rstrstr(expression,"-",multi - expression);

        sprintf(expression,"%d",a * b);
    }
    else{
        posit = strstr(expression,"+");
        negat = strstr(expression,"-");
        if(posit)
            b = atoi(posit + 1);
        else if(negat)
            b = atoi(negat + 1);

        int size_desu = get_number_size(expression,posit,1);

        memcpy(symbolbuf,expression,size_desu);

        a = atoi(symbolbuf);


    }
    sprintf(expression,"%d",a + b);
    //memcpy(expression,symbolbuf,strlen(symbolbuf));

    return 1;
}


int transform_expression(const char* expression, char** trans_express){
	char* inner_pos;
	char arithmetic_buffer[256];
	/** create buffer to perform transformation on*/
	if(!trans_express[0])
        trans_express[0] = (char*)malloc(strlen(expression) * 2);



    /**copy the expression*/
	memcpy(trans_express[0],expression,strlen(expression)+1);

	/*	inner parentheses	*/
	inner_pos = get_inner_parentheses(trans_express[0]);
	if(!inner_pos)
		return 0;	//failure

	/**	perform arithmetic transformation*/

	memcpy(&arithmetic_buffer[0],inner_pos + 1,(int)(strstr(inner_pos,")") -  inner_pos ) - 1);
    arithmetic_buffer[(int)(strstr(inner_pos,")") -  inner_pos ) - 1] = '\0';
    strtrim(arithmetic_buffer);

    transform_arithmetic(arithmetic_buffer);

	/*
		replace old expression with a simplified expression
	*/
	insert_expression(inner_pos,
                   trans_express[0],
                   &arithmetic_buffer[0],
                   (int)(strstr(inner_pos,")") -  inner_pos ));

	/*
		trigonometric transformation
	*/


	return 1;
}


int insert_expression(const char* paranthes_pos, char* express,const char* replace_express,unsigned int orignal_expression_size){

    memset(paranthes_pos,' ',orignal_expression_size+1);
    //memmove(paranthes_pos,express + orignal_expression_size,orignal_expression_size);
    memcpy(paranthes_pos,replace_express,strlen(replace_express));

    return 1;
}



