#include "PlayerPhysics.h"
#include "Runtime.h"
#include <iostream>

void PlayerPhysics::SetSpeed(float value)
{
	auto AssemblyCSharp = Runtime::il2cpp_assembly_get_image("Assembly-CSharp");
	auto PlayerPhysicsClass = Runtime::il2cpp_class_from_name(AssemblyCSharp, "", "PlayerPhysics");
	auto SpeedField = Runtime::il2cpp_field_from_name(PlayerPhysicsClass, "Speed");
	Runtime::SetFieldValue((Il2CppObject*)this, SpeedField, &value);
}

float* PlayerPhysics::GetSpeed()
{
	auto AssemblyCSharp = Runtime::il2cpp_assembly_get_image("Assembly-CSharp");
	auto PlayerPhysicsClass = Runtime::il2cpp_class_from_name(AssemblyCSharp, "", "PlayerPhysics");
	auto SpeedField = Runtime::il2cpp_field_from_name(PlayerPhysicsClass, "Speed");
	return (float*)Runtime::GetFieldValue((Il2CppObject*)this, SpeedField);
}
