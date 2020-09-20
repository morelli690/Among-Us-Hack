#include "PlayerInfo.h"
#include "Runtime.h"
#include "Offsets.h"

PlayerControl* PlayerInfo::GetPlayerObject(PlayerInfo* Instance)
{
	auto AssemblyCSharp = Runtime::il2cpp_assembly_get_image("Assembly-CSharp");
	auto PlayerInfoClass = Runtime::il2cpp_class_from_name(AssemblyCSharp, "", "PlayerInfo");
	auto GetPlayerObject = Runtime::il2cpp_class_get_method_from_name(PlayerInfoClass, "get_Object", 0);
	return (PlayerControl*)Runtime::il2cpp_runtime_invoke(GetPlayerObject, (Il2CppObject*)Instance, new void* [0]);
}