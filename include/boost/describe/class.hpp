#ifndef BOOST_DESCRIBE_CLASS_HPP_INCLUDED
#define BOOST_DESCRIBE_CLASS_HPP_INCLUDED

// Copyright 2020 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#include <boost/describe/detail/base_classes.hpp>
#include <boost/describe/detail/data_members.hpp>

namespace boost
{
namespace describe
{

#if defined(_MSC_VER) && !defined(__clang__)

#define BOOST_DESCRIBE_PP_UNPACK(...) __VA_ARGS__

#define BOOST_DESCRIBE_CLASS(C, Bases, PublicData, PrivateData, Functions) \
    friend BOOST_DESCRIBE_BASE_CLASSES(C, BOOST_DESCRIBE_PP_UNPACK Bases) \
    friend BOOST_DESCRIBE_PUBLIC_DATA_MEMBERS(C, BOOST_DESCRIBE_PP_UNPACK PublicData)

#define BOOST_DESCRIBE_STRUCT(C, Bases, Data, Functions) \
    BOOST_DESCRIBE_BASE_CLASSES(C, BOOST_DESCRIBE_PP_UNPACK Bases) \
    BOOST_DESCRIBE_PUBLIC_DATA_MEMBERS(C, BOOST_DESCRIBE_PP_UNPACK Data)

#else

#if defined(__GNUC__) && __GNUC__ >= 8
# define BOOST_DESCRIBE_PP_UNPACK(...) __VA_OPT__(,) __VA_ARGS__
#else
# define BOOST_DESCRIBE_PP_UNPACK(...) , ##__VA_ARGS__
#endif

#define BOOST_DESCRIBE_BASE_CLASSES_(...) BOOST_DESCRIBE_BASE_CLASSES(__VA_ARGS__)
#define BOOST_DESCRIBE_PUBLIC_DATA_MEMBERS_(...) BOOST_DESCRIBE_PUBLIC_DATA_MEMBERS(__VA_ARGS__)

#define BOOST_DESCRIBE_CLASS(C, Bases, PublicData, PrivateData, Functions) \
    friend BOOST_DESCRIBE_BASE_CLASSES_(C BOOST_DESCRIBE_PP_UNPACK Bases) \
    friend BOOST_DESCRIBE_PUBLIC_DATA_MEMBERS_(C BOOST_DESCRIBE_PP_UNPACK PublicData)

#define BOOST_DESCRIBE_STRUCT(C, Bases, Data, Functions) \
    BOOST_DESCRIBE_BASE_CLASSES_(C BOOST_DESCRIBE_PP_UNPACK Bases) \
    BOOST_DESCRIBE_PUBLIC_DATA_MEMBERS_(C BOOST_DESCRIBE_PP_UNPACK Data)

#endif

} // namespace describe
} // namespace boost

#endif // #ifndef BOOST_DESCRIBE_CLASS_HPP_INCLUDED
