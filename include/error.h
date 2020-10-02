#ifndef _ERROR_H_
#define _ERROR_H_ 1
#include<core-def.h>
/**
 * Error messages.
 */
#define SCH_OK                  ((int)1)        /*  No error.   */
#define SCH_ERROR_UNKNOWN       ((int)0)        /*  Error unknown.   */
#define SCH_ERROR_INVALID_ARG   ((int)-1)       /*  Invalid argument.   */
#define SCH_ERROR_INVALID_SCH   ((int)-2)       /*  Invalid scheduler object.   */
#define SCH_ERROR_INVALID_STATE ((int)-3)       /*  Scheduler/Pool in bad state.    */
#define SCH_ERROR_INTERNAL      ((int)-4)       /*  Internal error. */
#define SCH_ERROR_POOL_FULL     ((int)-5)       /*  Pool queue is full. */
#define SCH_ERROR_SIGNAL        ((int)-6)       /*  Signal failed.  */
#define SCH_ERROR_SYNC_OBJECT   ((int)-7)       /*  Synchronization object failed.   */


#endif