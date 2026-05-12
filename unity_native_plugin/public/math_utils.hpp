
#ifndef MATH_UTILS_HPP
#define MATH_UTILS_HPP

#ifdef _WIN32
    //#ifdef MATH_DLL
    #define MATH_API __decltype(dllexport)
//#else
//#define MATH_API __decltype(dllimport)
//#endif
#else
    #define MATH_API
#endif

extern "C"
{
    int MATH_API add_number(int a, int b);
}

#endif
