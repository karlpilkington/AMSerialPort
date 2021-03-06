//
//  AMSDKCompatibility.h
//
//  Created by Nick Zitzmann on 2007-10-22.
//  Copyright (c) 2007-2012 Andreas Mayer. All rights reserved.
//

// AMSerialPort uses types that were introduced with the 10.5 SDK.
// This allows older SDKs to be used.

#import <Foundation/Foundation.h>

#ifndef NSINTEGER_DEFINED
	#ifdef NS_BUILD_32_LIKE_64
		typedef long NSInteger;
		typedef unsigned long NSUInteger;
	#else
		typedef int NSInteger;
		typedef unsigned int NSUInteger;
	#endif
	#define NSIntegerMax    LONG_MAX
	#define NSIntegerMin    LONG_MIN
	#define NSUIntegerMax   ULONG_MAX
	#define NSINTEGER_DEFINED 1
#endif

#ifndef CGFLOAT_DEFINED
	typedef float CGFloat;
	#define CGFLOAT_MIN FLT_MIN
	#define CGFLOAT_MAX FLT_MAX
	#define CGFLOAT_IS_DOUBLE 0
	#define CGFLOAT_DEFINED 1
#endif

#ifndef _SUSECONDS_T
    #define _SUSECONDS_T
    typedef int suseconds_t;
#endif

// __has_feature is new in the 10.7 SDK, define it here if it's not yet defined.
#ifndef __has_feature
    #define __has_feature(x) 0
#endif

// instancetype is new in clang. id is a good replacement elsewhere.
#if !__has_feature(objc_instancetype) && !defined(instancetype)
    #define instancetype id
#endif