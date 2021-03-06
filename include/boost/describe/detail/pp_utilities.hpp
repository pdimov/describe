#ifndef BOOST_DESCRIBE_DETAIL_PP_UTILITIES_HPP_INCLUDED
#define BOOST_DESCRIBE_DETAIL_PP_UTILITIES_HPP_INCLUDED

// Copyright 2021 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#define BOOST_DESCRIBE_PP_EXPAND(x) x

#define BOOST_DESCRIBE_PP_CAT(x, y) BOOST_DESCRIBE_PP_CAT_I(x, y)
#define BOOST_DESCRIBE_PP_CAT_I(x, ...) x ## __VA_ARGS__

#if defined(_MSC_VER) && !defined(__clang__)

#define BOOST_DESCRIBE_PP_FIRST(x) BOOST_DESCRIBE_PP_FIRST_I((x))
#define BOOST_DESCRIBE_PP_FIRST_I(x) BOOST_DESCRIBE_PP_FIRST_II x
#define BOOST_DESCRIBE_PP_FIRST_II(x, ...) x

#else

#define BOOST_DESCRIBE_PP_FIRST(x) BOOST_DESCRIBE_PP_FIRST_I(x)
#define BOOST_DESCRIBE_PP_FIRST_I(x, ...) x

#endif

#define BOOST_DESCRIBE_PP_IS_PAREN_I(x) BOOST_DESCRIBE_PP_CAT(BOOST_DESCRIBE_PP_IS_PAREN_I_, BOOST_DESCRIBE_PP_IS_PAREN_II x)
#define BOOST_DESCRIBE_PP_IS_PAREN_II(...) 0
#define BOOST_DESCRIBE_PP_IS_PAREN_I_0 1,
#define BOOST_DESCRIBE_PP_IS_PAREN_I_BOOST_DESCRIBE_PP_IS_PAREN_II 0,

#define BOOST_DESCRIBE_PP_IS_PAREN(x) BOOST_DESCRIBE_PP_FIRST(BOOST_DESCRIBE_PP_IS_PAREN_I(x))

#define BOOST_DESCRIBE_PP_EMPTY

#define BOOST_DESCRIBE_PP_IS_EMPTY(x) BOOST_DESCRIBE_PP_IS_EMPTY_I(BOOST_DESCRIBE_PP_IS_PAREN(x), BOOST_DESCRIBE_PP_IS_PAREN(x BOOST_DESCRIBE_PP_EMPTY ()))
#define BOOST_DESCRIBE_PP_IS_EMPTY_I(x, y) BOOST_DESCRIBE_PP_IS_EMPTY_II(x, y)
#define BOOST_DESCRIBE_PP_IS_EMPTY_II(x, y) BOOST_DESCRIBE_PP_IS_EMPTY_III(x, y)
#define BOOST_DESCRIBE_PP_IS_EMPTY_III(x, y) BOOST_DESCRIBE_PP_IS_EMPTY_III_ ## x ## y
#define BOOST_DESCRIBE_PP_IS_EMPTY_III_00 0
#define BOOST_DESCRIBE_PP_IS_EMPTY_III_01 1
#define BOOST_DESCRIBE_PP_IS_EMPTY_III_10 0
#define BOOST_DESCRIBE_PP_IS_EMPTY_III_11 0

#define BOOST_DESCRIBE_PP_CALL(F, a, x) BOOST_DESCRIBE_PP_CAT(BOOST_DESCRIBE_PP_CALL_I_, BOOST_DESCRIBE_PP_IS_EMPTY(x))(F, a, x)
#define BOOST_DESCRIBE_PP_CALL_I_0(F, a, x) F(a, x)
#define BOOST_DESCRIBE_PP_CALL_I_1(F, a, x)

#endif // #ifndef BOOST_DESCRIBE_DETAIL_PP_UTILITIES_HPP_INCLUDED
