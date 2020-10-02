
#ifndef _CSTRING_H_
#define _CSTRING_H_ 1

#ifdef __cplusplus /*	C++ Environment	*/
extern "C"{
#endif

/*  Encoding.   */
#define STR_NO_ENCODING 0
#define STR_UTF8        1
#define STR_UTF16       2
#define STR_ASCII       3

typedef struct c_string_t {
	char *text;
	int len;
	int encoding;   //TODO add support for using encoding.
} CString;

//TODO refactor function
extern void initString(CString *string);

extern void allocateString(CString *string, int len);

extern void deleteString(CString *string);

extern void setString(CString *string, char *text);

extern void setStringN(CString *string, char *text, int numChr);

extern void copyString(CString *source, CString *dest);

extern void copyStringN(CString *source, CString *dest, int numChr);

extern char* strString(CString* string, const char* str);
extern char* rstrString(CString* string, const char* str);
extern char* trimString(CString* string);
extern char* strupperString(CString* string);
extern char* strlowerString(CString* string);
extern int insertString(CString* string, const char* str);

extern int changeEncodingString(CString* string, int encoding);

#ifdef __cplusplus /*	C++ Environment	*/
}
#endif

#endif