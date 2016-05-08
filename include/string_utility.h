
#ifndef _STRING_UTILITY_H_
#define _STRING_UTILITY_H_ 1
#include<string.h>

#ifdef __cplusplus	//	C++ Enviromnets
extern "C"{
#endif


/*
//search for string sequence
*/
extern int strstrsafe(const char* _Str,const char* _Str_comp, char** _Str_find);
/*search referse*/
extern char* rstrstr(const char* _Str,const char* _Str_comp,int pos);
/*	search for compare word*/
extern char* strstword(char* _Str, const char* _Str_comp);

/*	trim c-string	*/
extern void strtrim(char* _Str);
/*	convert string to lowercase letter	*/
extern void strlower(char* _Str);
/*	convert string to uppercase letter	*/
extern void strupper(char* _Str);

extern int strchalength(char* _Str);
extern int strchaspace(char* _Str);
/*	repeting sequence	*/
extern int strsequence(char* _Str,char*_Str_sequence);
/*	repeting word sequence	*/
extern int strrepword(char* _Str, char* _Str_word_sequence);
/*insert text*/
extern int strinsert(char** _Str, char* _Str_insert, int pos);
/*	erase porition of c-string	*/
extern int strerase(char** _Str, int pos, int length);



#ifdef UNICODE

extern int wcsstrsafe(wchar_t* _Wcs, wchar_t* _Wcs_str, wchar_t** _Wcs_find);
/*	trim c-wide-string	*/
extern void wcstrim(wchar_t* _wStr);
/*	convert string to lowercase letter	*/
extern void wcslower(wchar_t* _wStr);
/*	convert string to uppercase letter	*/
extern void wcsupper(wchar_t* _wStr);

extern int wcssequence(wchar_t* _wStr, wchar_t* _wStr_sequence);

extern int wcsrepword(wchar_t* _Str, wchar_t* _Str_word_sequence);

extern int wcsinsert(wchar_t** _Str, wchar_t* _Str_insert, int pos);

extern int wcserase(wchar_t** _Wsc,int pos, int length);

/*
	// conversts 
*/
extern int widetostr(const wchar_t* _Wsc, char* _Str);

extern int strtowide(const char* _Wsc, wchar_t* _Str);
#endif



#ifdef __cplusplus
}
#endif

#endif
