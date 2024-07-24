#include "cstring.h"
#include <malloc.h>
#include <stddef.h>
#include <string.h>
#include <wchar.h>

void initString(CString *string) {
	string->text = NULL;
	string->len = 0;
}

void allocateString(CString *string, const int len) {

	const int charLen = sizeof(char);
	string->text = realloc(string->text, (long)charLen * len);
	string->len = 0;
}

void setString(CString *string, const char *text) {
	allocateString(string, strlen(text) + 1);
	strcpy(string->text, text);
	string->len = strlen(text);
}

void deleteString(CString *string) { free(string->text); }

void setStringN(CString *string, char *text, int numChr) { strncat(string->text, text, numChr); }

void copyString(CString *source, CString *dest) {}

void copyStringN(CString *source, CString *dest, int numChr) {}

char *strString(CString *string, const char *str) {}

char *rstrString(CString *string, const char *str) {}

char *trimString(CString *string) {}

char *strupperString(CString *string) {}

char *strlowerString(CString *string) {}

int insertString(CString *string, const char *str) {}

int changeEncodingString(CString *string, int encoding) {}

/*
#include"string_utility.h"
#include<assert.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int strstrsafe(const char* _Str,const char* _Str_comp, char** _Str_find){
	char* cchar = strstr(_Str,_Str_comp);
	if(cchar)
		*_Str_find = cchar;
	return (int)cchar;
}
char* rstrstr(const char* _Str,const char* _Str_comp,int pos){
	unsigned int j,len,clen; //
	int i;					 //
	if(!_Str || !_Str_comp)
		return NULL;// invalid pointer
	len = strlen(_Str);		  // length of c-strings
	clen = strlen(_Str_comp); // length of c-strings
	if(pos > len)
		return NULL;

	// iterate through all character
	for(i = pos; i >= 0; i--){
		// iterate compare string
		for(j = 0; j < clen; j++){
			if(_Str[i + j] != _Str_comp[j])
				break;// character mismatch
			else if(j == (clen - 1))return (char*)(_Str + i);// return start pointer of search character
		}// compare string
	}// each character
	return NULL;// couldn't find matching c-string
}
char* strstword(char* _Str, const char* _Str_comp){
	char* cpos;
	unsigned int comp_len;
	while(1){
		comp_len = strlen(_Str_comp);
		cpos = (char*)strstr(_Str, _Str_comp);
		if(!cpos)break;// could find compare variable.
		if(!isalpha(cpos[comp_len]) || !(isalpha((cpos - 1))))
			return cpos;
		else
			continue;
	}
}

*/
/*
	// trim c-string
*//*

void strtrim(char* _Str){
	unsigned int len,i,n_space = 0;
	unsigned int num_space = 0;
	char* cpos = _Str;	// pointer
	char* tpos;			// temp pointer
	if(!_Str)
		return;// Invalid Pointer
	len = strlen(_Str);
	while(1){
		cpos = (char*)strchr(cpos,' ');
		if(!cpos)break;// didn't find blankspace
		tpos = cpos; // temp
		while(1){
			if(*cpos++ != ' '){cpos = tpos;break;}//return to pos
			if(*cpos == '\0')return;// end of line.
			n_space++;
		}
		if(!cpos)break;
		num_space += n_space;// addition count. might be removed.
		for(i = 0; i < len - (cpos - _Str); i++){
			cpos[i] = (char)(cpos[i + n_space]);continue;
		}
		n_space = 0; // reset
	}
}
*/
/*
	Trim from left intill it reach first character
*//*

void strtriml(char* _Str){
	unsigned int len;
	unsigned int i;
	len = strlen(_Str);
	for(i = len; i >= 0; i--){
		if(_Str[i] != ' ')break;
		continue;
	}
}
*/
/*
	Trim from right intill it reach first character
*//*

void strtrimr(char* _Str){
	unsigned int len;
	unsigned int i;
	len =strlen(_Str);
	for(i = 0; i < len; i++){
		if(_Str[i]==' ')break;
	}
}
*/
/*
	c-string to lower case character
*//*

void strlower(char* _Str){
	unsigned int len,j;
	len = strlen(_Str);
	for(j = 0; j < len; j++){
		_Str[j] = (char)tolower(_Str[j]);continue;
	}
}
void strupper(char* _Str){
	unsigned int len,j;
	len = strlen(_Str);
	for(j = 0; j < len; j++){
		_Str[j] = (char)toupper(_Str[j]);continue;
	}
}
*/
/*	repeting sequence	*/ /*

 int strsequence(char* _Str,char*_Str_sequence){
	 unsigned int n = 0;	// number of sequence
	 char* cpos = _Str;	//
	 while(1){
		 cpos = strstr(cpos, _Str_sequence);
		 if(!cpos)break;
		 cpos += strlen(_Str_sequence);
		 n++;
	 }
	 return n;
 }
 int strrepword(char* _Str, char* _Str_word_sequence){
	 unsigned int n = 0; //
	 unsigned int len = strlen(_Str_word_sequence);
	 char* cpos = _Str;  //
	 while(1){
		 cpos = strstr(cpos,_Str_word_sequence);
		 if(!cpos)break;// no more identially
		 if(!isalpha(*(cpos - 1)) &&
			!isalpha(*(cpos + len)))
			 n++;
		 cpos += len;// out of scope of current search word
	 }
	 return n;
 }
 int strinsert(char** _Str, char* _Str_insert, int pos){
	 unsigned int insert_len; // str length
	 unsigned int str_len;    // str length
	 char* _tStr = 0;
	 if(!_Str_insert)
		 return -1;// no insert c-string!
	 insert_len = strlen(_Str_insert);
	 str_len = strlen(_Str[0]);

	 _tStr = (char*)malloc(str_len + insert_len + 1);
	 memcpy(_tStr,_Str[0], str_len + 1);
	 free(_Str[0]);
	 _Str[0] = _tStr;

	 memmove((*_Str + pos + insert_len), (*_Str + pos),str_len - insert_len);
	 memcpy((*_Str + pos),_Str_insert, insert_len);
	 return 1;
 }

 int strerase(char** _Str, int pos, int length){
	 unsigned int str_len;    // str length
	 char* _tStr = 0;
	 if(!_Str)
		 return SOL_OK;// Invalid pointer
	 str_len = strlen(_Str[0]);
 }


 */
/*
	// UNICODE
*//*

//===========================================
#ifdef UNICODE
*/
/*	trim c-wide-string	*/				   /*
				
				 void wcstrim(wchar_t* _wStr){
					 unsigned int clength,i;
					 unsigned int num_space = 0;
					 wchar_t* cpos = _wStr;
					 clength = wcslen(_wStr);
					 while(1){
						 cpos = (wchar_t*)wcschr(cpos,L' ');
						 if(!cpos)break;
						 num_space++;
						 for(i = clength / 2; i < ((unsigned int)cpos - (unsigned int)_wStr) + 1; i++){
							 cpos[i] = (cpos[i + 1]);continue;
						 }
					 }
				 }
				 */
/*	convert string to lowercase letter	*/ /*

 void wcslower(wchar_t* _wStr){
	 unsigned int l,j;
	 l = wcslen(_wStr);
	 for(j = 0; j < l; j++){
		 _wStr[j] = towlower(_wStr[j]);continue;
	 }
 }
 */
/*	convert string to uppercase letter	*/ /*

 void wcsupper(wchar_t* _wStr){
	 unsigned int l,j;
	 l = wcslen(_wStr);
	 for(j = 0; j < l; j++){
		 _wStr[j] = towupper(_wStr[j]);continue;
	 }
 }

 #ifdef _WIN32
 #include<Windows.h>
 int widetostr(const wchar_t* _Wsc, char* _Str){
	 WideCharToMultiByte(CP_OEMCP,0,_Wsc, -1, _Str,sizeof(char) * wcslen(_Wsc) + sizeof(char), 0,0);
	 return SOL_OK;
 }

 int strtowide(const char*_Str , wchar_t* _Wsc){
	 MultiByteToWideChar(CP_OEMCP,0,_Str,-1,_Wsc, strlen(_Str) + 2);
	 return SOL_OK;
 }
 #endif*/
