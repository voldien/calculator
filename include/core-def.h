
#ifndef SOLVER_CORE_DEF_H_
#define SOLVER_CORE_DEF_H_ 1

/**
 * Macro for adding library
 * support.
 */
#ifndef CORE_SOLVER_EXTERN
	#ifndef TASH_SCH_STATIC
		#ifdef _WIN32
			#define TASH_SCH_EXTERN __declspec(dllimport)
		#elif defined(__GNUC__) && __GNUC__ >= 4
			#define TASH_SCH_EXTERN __attribute__((visibility("default")))
		#else
			#define TASH_SCH_EXTERN
		#endif
		#else
			#define TASH_SCH_EXTERN
	#endif
#endif

#endif