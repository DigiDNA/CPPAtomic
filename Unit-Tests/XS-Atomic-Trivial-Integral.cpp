/*******************************************************************************
 * Copyright (c) 2015, Jean-David Gadina - www.xs-labs.com
 * Distributed under the Boost Software License, Version 1.0.
 * 
 * Boost Software License - Version 1.0 - August 17th, 2003
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ******************************************************************************/

/*!
 * @copyright   (c) 2015 - Jean-David Gadina - www.xs-labs.com
 * @brief       Test case XS::Atomic
 */

/* Disabled warnings for GoogleMock */
#ifdef __clang__
#pragma clang diagnostic ignored "-Wglobal-constructors"
#pragma clang diagnostic ignored "-Wpadded"
#pragma clang diagnostic push
#if __clang_major__ >= 7
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#pragma clang diagnostic ignored "-Wmissing-noreturn"
#pragma clang diagnostic ignored "-Wpadded"
#pragma clang diagnostic ignored "-Wused-but-marked-unused"
#pragma clang diagnostic ignored "-Wdeprecated"
#endif

#include <GoogleMock/GoogleMock.h>

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#include <XS/Atomic.hpp>

using namespace testing;

/*******************************************************************************
 * Common definitions
 ******************************************************************************/

TEST( XS_Atomic_Trivial_Integral, CTOR )
{
    XS::Atomic< int > a;
    
    ASSERT_TRUE( a == 0 );
}

TEST( XS_Atomic_Trivial_Integral, CTOR_V )
{
    XS::Atomic< int > a{ 42 };
    
    ASSERT_TRUE( a == 42 );
}

TEST( XS_Atomic_Trivial_Integral, CCTOR )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ a1 };
    
    ASSERT_TRUE( a1 == 42 );
    ASSERT_TRUE( a2 == 42 );
}

TEST( XS_Atomic_Trivial_Integral, OperatorAssign )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2;
    
    a2 = a1;
    
    ASSERT_TRUE( a1 == 42 );
    ASSERT_TRUE( a2 == 42 );
}

TEST( XS_Atomic_Trivial_Integral, OperatorAssign_V )
{
    XS::Atomic< int > a;
    
    a = 42;
    
    ASSERT_TRUE( a == 42 );
}

TEST( XS_Atomic_Trivial_Integral, OperatorCast )
{
    XS::Atomic< int > a{ 42 };
    
    ASSERT_TRUE( static_cast< int >( a ) == 42 );
}

TEST( XS_Atomic_Trivial_Integral, Load )
{
    XS::Atomic< int > a{ 42 };
    
    ASSERT_TRUE( a == 42 );
}

TEST( XS_Atomic_Trivial_Integral, Store )
{
    XS::Atomic< int > a;
    
    a.Store( 42 );
    
    ASSERT_TRUE( a == 42 );
}

TEST( XS_Atomic_Trivial_Integral, IsLockFree )
{
    XS::Atomic< int > a;
    
    ASSERT_TRUE( a.IsLockFree() );
}

TEST( XS_Atomic_Trivial_Integral, Swap )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 43 };
    
    ASSERT_TRUE( a1 == 42 );
    ASSERT_TRUE( a2 == 43 );
    
    swap( a1, a2 );
    
    ASSERT_TRUE( a1 == 43 );
    ASSERT_TRUE( a2 == 42 );
}

/*******************************************************************************
 * Equality comparable
 ******************************************************************************/

TEST( XS_Atomic_Trivial_Integral, OperatorEqual )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 42 };
    XS::Atomic< int > a3{ 43 };
    
    ASSERT_TRUE(  a1 == a2 );
    ASSERT_FALSE( a1 == a3 );
}

TEST( XS_Atomic_Trivial_Integral, OperatorEqual_V )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 43 };
    
    ASSERT_TRUE(  a1 == 42 );
    ASSERT_FALSE( a1 == 43 );
    ASSERT_TRUE(  a2 == 43 );
    ASSERT_FALSE( a2 == 42 );
}

TEST( XS_Atomic_Trivial_Integral, OperatorNotEqual )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 42 };
    XS::Atomic< int > a3{ 43 };
    
    ASSERT_FALSE( a1 != a2 );
    ASSERT_TRUE(  a1 != a3 );
}

TEST( XS_Atomic_Trivial_Integral, OperatorNotEqual_V )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 43 };
    
    ASSERT_TRUE(  a1 == 42 );
    ASSERT_FALSE( a1 == 43 );
    ASSERT_TRUE(  a2 == 43 );
    ASSERT_FALSE( a2 == 42 );
}

/*******************************************************************************
 * Arithmetic
 ******************************************************************************/

TEST( XS_Atomic_Trivial_Integral, OperatorGreater )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 42 };
    XS::Atomic< int > a3{ 43 };
    
    ASSERT_TRUE(  a3 > a1 );
    ASSERT_FALSE( a1 > a2 );
    ASSERT_FALSE( a1 > a3 );
}

TEST( XS_Atomic_Trivial_Integral, OperatorGreater_V )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 43 };
    
    ASSERT_TRUE(  a2 > 42 );
    ASSERT_FALSE( a1 > 42 );
    ASSERT_FALSE( a1 > 43 );
}

TEST( XS_Atomic_Trivial_Integral, OperatorLesser )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 42 };
    XS::Atomic< int > a3{ 43 };
    
    ASSERT_TRUE(  a1 < a3 );
    ASSERT_FALSE( a1 < a2 );
    ASSERT_FALSE( a3 < a1 );
}

TEST( XS_Atomic_Trivial_Integral, OperatorLesser_V )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 43 };
    
    ASSERT_TRUE(  a1 < 43 );
    ASSERT_FALSE( a2 < 43 );
    ASSERT_FALSE( a1 < 42 );
}

TEST( XS_Atomic_Trivial_Integral, OperatorGreaterEqual )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 42 };
    XS::Atomic< int > a3{ 43 };
    
    ASSERT_TRUE(  a3 >= a1 );
    ASSERT_TRUE(  a1 >= a2 );
    ASSERT_FALSE( a1 >= a3 );
}

TEST( XS_Atomic_Trivial_Integral, OperatorGreaterEqual_V )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 43 };
    
    ASSERT_TRUE(  a2 >= 42 );
    ASSERT_TRUE(  a1 >= 42 );
    ASSERT_FALSE( a1 >= 43 );
}

TEST( XS_Atomic_Trivial_Integral, OperatorLesserEqual )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 42 };
    XS::Atomic< int > a3{ 43 };
    
    ASSERT_TRUE(  a1 <= a3 );
    ASSERT_TRUE(  a1 <= a2 );
    ASSERT_FALSE( a3 <= a1 );
}

TEST( XS_Atomic_Trivial_Integral, OperatorLesserEqual_V )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 43 };
    
    ASSERT_TRUE(  a1 <= 43 );
    ASSERT_TRUE(  a1 <= 42 );
    ASSERT_FALSE( a2 <= 42 );
}

TEST( XS_Atomic_Trivial_Integral, OperatorPreIncrement )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2;
    
    a2 = ++a1;
    
    ASSERT_TRUE( a1 == 43 );
    ASSERT_TRUE( a2 == 43 );
}

TEST( XS_Atomic_Trivial_Integral, OperatorPostIncrement )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2;
    
    a2 = a1++;
    
    ASSERT_TRUE( a1 == 43 );
    ASSERT_TRUE( a2 == 42 );
}

TEST( XS_Atomic_Trivial_Integral, OperatorPreDecrement )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2;
    
    a2 = --a1;
    
    ASSERT_TRUE( a1 == 41 );
    ASSERT_TRUE( a2 == 41 );
}

TEST( XS_Atomic_Trivial_Integral, OperatorPostDecrement )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2;
    
    a2 = a1--;
    
    ASSERT_TRUE( a1 == 41 );
    ASSERT_TRUE( a2 == 42 );
}

TEST( XS_Atomic_Trivial_Integral, OperatorPlusEqual )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 10 };
    
    a1 += a2;
    
    ASSERT_TRUE( a1 == 52 );
    ASSERT_TRUE( a2 == 10 );
}

TEST( XS_Atomic_Trivial_Integral, OperatorPlusEqual_V )
{
    XS::Atomic< int > a{ 42 };
    
    a += 10;
    
    ASSERT_TRUE( a == 52 );
}

TEST( XS_Atomic_Trivial_Integral, OperatorMinusEqual )
{
    XS::Atomic< int > a1{ 42 };
    XS::Atomic< int > a2{ 10 };
    
    a1 -= a2;
    
    ASSERT_TRUE( a1 == 32 );
    ASSERT_TRUE( a2 == 10 );
}

TEST( XS_Atomic_Trivial_Integral, OperatorMinusEqual_V )
{
    XS::Atomic< int > a{ 42 };
    
    a -= 10;
    
    ASSERT_TRUE( a == 32 );
}
