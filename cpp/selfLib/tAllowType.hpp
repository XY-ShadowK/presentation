/*
this header depends on official headers below(此头文件依赖于以下官方头文件)
type_traits
this header depends on custom headers below(此头文件依赖于以下自定义头文件)
none
time: 
*/
#pragma once
#ifndef _TALLOWTYPE_HPP_
#define _TALLOWTYPE_HPP_

#include <type_traits>

template<typename Type,bool IsAllow,typename NowType = void,typename... Types>
struct allow_type{};

template<typename Type,typename NowType,typename... Types>
struct allow_type<Type,true,NowType,Types...>{
    using type = Type;
};

template<typename Type,typename NowType,typename... Types>
struct allow_type<Type,false,NowType,Types...>{
    using type = typename allow_type<Type,std::is_same_v<Type,NowType>,Types...>::type;
};

template<typename Type,bool IsAllow,typename NowType,typename... Types>
using allow_type_t = typename allow_type<Type,IsAllow,NowType,Types...>::type;

/*
使用类似如下声明以简化对模板实参类型的限制。
Using statements like the following to simplify the declaration of restrictions on types of template arguments.

template<typaname T,typename = allow_type_t<T,false,allowedTypes...>>
下接类或函数声明。(class or function declarations)

或者 or

template<typename T,typename = allow_type<T,false,allowedTypes...>::type>
下接类或函数声明。(class or function declarations)
*/

#endif