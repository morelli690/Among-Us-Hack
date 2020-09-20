#pragma once
#include "GameData.h"
#include "Runtime.h"
GameData* GameData::GetInstance()
{
	auto assembly = Runtime::il2cpp_assembly_get_image("Assembly-CSharp");
	auto klass = Runtime::il2cpp_class_from_name(assembly, "", "GameData");
	auto field = Runtime::il2cpp_field_from_name(klass, "Instance");
	return (GameData*)Runtime::GetStaticFieldValue(field);
}

PlayerInfo* GameData::GetHost()
{
	auto assembly = Runtime::il2cpp_assembly_get_image("Assembly-CSharp");
	auto klass = Runtime::il2cpp_class_from_name(assembly, "", "GameData");
	auto method = Runtime::il2cpp_class_get_method_from_name(klass, "GetHost", 0);
	return (PlayerInfo*)Runtime::il2cpp_runtime_invoke(method, (Il2CppObject*)GetInstance(), new void* [0]);
}

PlayerInfo* GameData::GetPlayerById(uint8_t Id)
{
	auto assembly = Runtime::il2cpp_assembly_get_image("Assembly-CSharp");
	auto klass = Runtime::il2cpp_class_from_name(assembly, "", "GameData");
	auto method = Runtime::il2cpp_class_get_method_from_name(klass, "GetPlayerById", 0);
	return (PlayerInfo*)Runtime::il2cpp_runtime_invoke(method, (Il2CppObject*)GetInstance(), new void* [1] { (Il2CppObject*)Id });
}