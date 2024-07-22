/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2023 Valdemar Lindberg
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 */
#ifndef _ERROR_H_
#define _ERROR_H_ 1

#include <core-def.h>
/**
 * Error messages.
 */
#define SCH_OK ((int)1)					  /*  No error.   */
#define SCH_ERROR_UNKNOWN ((int)0)		  /*  Error unknown.   */
#define SCH_ERROR_INVALID_ARG ((int)-1)	  /*  Invalid argument.   */
#define SCH_ERROR_INVALID_SCH ((int)-2)	  /*  Invalid scheduler object.   */
#define SCH_ERROR_INVALID_STATE ((int)-3) /*  Scheduler/Pool in bad state.    */
#define SCH_ERROR_INTERNAL ((int)-4)	  /*  Internal error. */
#define SCH_ERROR_POOL_FULL ((int)-5)	  /*  Pool queue is full. */
#define SCH_ERROR_SIGNAL ((int)-6)		  /*  Signal failed.  */
#define SCH_ERROR_SYNC_OBJECT ((int)-7)	  /*  Synchronization object failed.   */

#endif