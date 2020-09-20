#pragma once
#include "Runtime.h"
#include "Types.h"

template <typename T>
class List
{
public:
	List(Il2CppArray* arr);

public:
	T& operator[](int index)
	{
		if (index > (int)arrayLength)
		{
			return  *(T*)((((uint8_t*)(arr)) + arrayObjSize) + ((arrayElemSize) * (0)));
		}

		return *(T*)((((uint8_t*)(arr)) + arrayObjSize) + ((arrayElemSize) * (index)));
	}

	uint32_t arrayLength;
private:
	Il2CppArray* arr;
	uint32_t arrayObjTotalSize;
	uint32_t arraySize;
	uint32_t arrayElemSize;
	uint32_t arrayObjSize;
	using lambda_t = void(*)();
};

template <typename T>
List<T>::List(Il2CppArray* arr)
{
	this->arr = arr;

	this->arrayObjTotalSize = Runtime::il2cpp_object_get_size((Il2CppObject*)arr);
	this->arraySize = Runtime::il2cpp_array_get_byte_length(arr);
	this->arrayLength = Runtime::il2cpp_array_get_length(arr);
	this->arrayElemSize = arrayLength ? arraySize / arrayLength : 0;
	this->arrayObjSize = arrayObjTotalSize - arraySize;
}

//Source: https://github.com/GreengrayZ/VRGreen/blob/master/VRGreen/List.hpp (Helped me understand how to use il2cpparrays properly)