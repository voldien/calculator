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
#ifndef _SOLVER_ERROR_H_
#define _SOLVER_ERROR_H_ 1

/**
 * Error messages.
 */
#define SOL_OK ((int)0)					  /*  No error.   */
#define SOL_ERROR_UNKNOWN ((int)-100)	  /*  Error unknown.   */
#define SOL_ERROR_INVALID_ARG ((int)-1)	  /*  Invalid argument.   */
#define SOL_ERROR_INVALID_SCH ((int)-2)	  /*  Invalid scheduler object.   */
#define SOL_ERROR_INVALID_STATE ((int)-3) /*  Scheduler/Pool in bad state.    */
#define SOL_ERROR_INTERNAL ((int)-4)	  /*  Internal error. */
#define SOL_ERROR_POOL_FULL ((int)-5)	  /*  Pool queue is full. */
#define SOL_ERROR_SIGNAL ((int)-6)		  /*  Signal failed.  */
#define SOL_ERROR_SYNC_OBJECT ((int)-7)	  /*  Synchronization object failed.   */

#endif