/*
Simple Template Tests in C++

Written in 2024 by Eunbin Bak

To the extent possible under law, the author(s) have dedicated 
all copyright and related and neighboring rights to this software 
to the public domain worldwide. This software is distributed
without any warranty.

You should have received a copy of the CC0 Public Domain Dedication 
along with this software. If not, see <http://creativecommons.org/publicdomain/zero/1.0/>. 
*/

#pragma once

#include <type_traits>

namespace cpp::math
{
	template <size_t Fact, size_t Limit, size_t Input, class T> requires std::is_floating_point_v <T>
	struct __series
	{
		static T value ()
		{
			return 1 - (static_cast <T> (Input * Input) / Fact / (Fact + 1)) * __series <Fact + 2, Limit, Input, T>::value ();
		}
	};

	template <size_t Limit, size_t Input, class T> requires std::is_floating_point_v <T>
	struct __series <Limit, Limit, Input, T>
	{
		static T value () { return 1.; }
	};
}

namespace cpp::math
{
	template <size_t Input, class T = double> requires std::is_floating_point_v <T>

	struct sin;
	
	template <size_t Input>
	struct sin <Input, float>
	{
		static float value () { return __series <2, 24, Input, float>::value () * Input; }
	};
	
	template <size_t Input>
	struct sin <Input, double>
	{
		static double value () { return __series <2, 36, Input, double>::value () * Input; }
	};
}

namespace cpp::math
{
	template <size_t Input, class T = double> requires std::is_floating_point_v <T>
	struct cos;

	template <size_t Input>
	struct cos <Input, float>
	{
		static float value () { return __series <1, 23, Input, float>::value (); }
	};

	template <size_t Input>
	struct cos <Input, double>
	{
		static double value () { return __series <1, 35, Input, double>::value (); }
	};
}

namespace cpp::math
{
	template <size_t Input, class T = double> requires std::is_floating_point_v <T>
	struct tan;

	template <size_t Input>
	struct tan <Input, float>
	{
		static float value () { return Input * __series <2, 28, Input, float>::value () / __series <1, 27, Input, float>::value (); }
	};

	template <size_t Input>
	struct tan <Input, double>
	{
		static float value () { return Input * __series <2, 38, Input, double>::value () / __series <1, 37, Input, double>::value (); }
	};
}

namespace cpp::math
{
	template <size_t Fact, size_t Limit, size_t Input, class T> requires std::is_floating_point_v <T>
	struct __ex_series
	{
		static T value ()
		{
			return 1. + (static_cast <T> (Input) / Fact) * __ex_series <Fact + 1, Limit, Input, T>::value ();
		}
	};

	template <size_t Limit, size_t Input, class T> requires std::is_floating_point_v <T>
	struct __ex_series <Limit, Limit, Input, T>
	{
		static T value ()
		{
			return 1.;
		}
	};

	template <size_t Input, class T = double> requires std::is_floating_point_v <T>
	struct exp;

	template <size_t Input>
	struct exp <Input, float>
	{
		static float value () { return __ex_series <1, 25, Input, float>::value (); }
	};

	template <size_t Input>
	struct exp <Input, double>
	{
		static double value () { return __ex_series <1, 35, Input, double>::value (); }
	};
}
