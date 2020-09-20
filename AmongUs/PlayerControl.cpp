#include "PlayerControl.h"
#include "Runtime.h"
#include <iostream>
#include "DeathReason.h"

PlayerControl* PlayerControl::GetLocalPlayer()
{
	auto AssemblyCSharp = Runtime::il2cpp_assembly_get_image("Assembly-CSharp");
	auto PlayerControlClass = Runtime::il2cpp_class_from_name(AssemblyCSharp, "", "PlayerControl");
	auto LocalPlayerField = Runtime::il2cpp_field_from_name(PlayerControlClass, "LocalPlayer");
	return (PlayerControl*)Runtime::GetStaticFieldValue(LocalPlayerField);
}

Il2CppArray* PlayerControl::GetAllPlayers()
{
	auto AssemblyCSharp = Runtime::il2cpp_assembly_get_image("Assembly-CSharp");
	auto PlayerControlClass = Runtime::il2cpp_class_from_name(AssemblyCSharp, "", "PlayerControl");
	auto AllPlayersField = Runtime::il2cpp_field_from_name(PlayerControlClass, "AllPlayerControls");
	return (Il2CppArray*)Runtime::GetStaticFieldValue(AllPlayersField);
}

PlayerPhysics* PlayerControl::GetPhysics()
{
	auto AssemblyCSharp = Runtime::il2cpp_assembly_get_image("Assembly-CSharp");
	auto PlayerControlClass = Runtime::il2cpp_class_from_name(AssemblyCSharp, "", "PlayerControl");
	auto PlayerPhysicsField = Runtime::il2cpp_field_from_name(PlayerControlClass, "MyPhysics");
	return (PlayerPhysics*)Runtime::GetFieldValue((Il2CppObject*)GetLocalPlayer(), PlayerPhysicsField);
}

void PlayerControl::MurderPlayer(PlayerControl* who)
{
	auto AssemblyCSharp = Runtime::il2cpp_assembly_get_image("Assembly-CSharp");
	auto PlayerControlClass = Runtime::il2cpp_class_from_name(AssemblyCSharp, "", "PlayerControl");
	auto MurderPlayerMethod = Runtime::il2cpp_class_get_method_from_name(PlayerControlClass, "MurderPlayer", 1);
	Runtime::il2cpp_runtime_invoke(MurderPlayerMethod, (Il2CppObject*)PlayerControl::GetLocalPlayer(), new void* [1] { (Il2CppObject*)who });
}

Vector2 PlayerControl::GetTruePosition()
{
	auto AssemblyCSharp = Runtime::il2cpp_assembly_get_image("Assembly-CSharp");
	auto PlayerControlClass = Runtime::il2cpp_class_from_name(AssemblyCSharp, "", "PlayerControl");
	auto GetTruePositionMethod = Runtime::il2cpp_class_get_method_from_name(PlayerControlClass, "GetTruePosition", 0);
	return *(Vector2*)Runtime::il2cpp_runtime_invoke(GetTruePositionMethod, (Il2CppObject*)GetLocalPlayer(), new void* [0]);
}

uint8_t PlayerControl::GetPlayerId()
{
	auto AssemblyCSharp = Runtime::il2cpp_assembly_get_image("Assembly-CSharp");
	auto PlayerControlClass = Runtime::il2cpp_class_from_name(AssemblyCSharp, "", "PlayerControl");
	auto GetPlayerIdField = Runtime::il2cpp_field_from_name(PlayerControlClass, "PlayerId");
	return (uint8_t)Runtime::GetFieldValue((Il2CppObject*)GetLocalPlayer(), GetPlayerIdField);
}

Vector2 PlayerControl::GetTruePosition(PlayerControl* who)
{
	auto AssemblyCSharp = Runtime::il2cpp_assembly_get_image("Assembly-CSharp");
	auto PlayerControlClass = Runtime::il2cpp_class_from_name(AssemblyCSharp, "", "PlayerControl");
	auto GetTruePositionMethod = Runtime::il2cpp_class_get_method_from_name(PlayerControlClass, "GetTruePosition", 0);
	return *(Vector2*)Runtime::il2cpp_runtime_invoke(GetTruePositionMethod, (Il2CppObject*)who, new void* [0]);
}

bool PlayerControl::RpcSendChat(Il2CppString* what)
{
	auto AssemblyCSharp = Runtime::il2cpp_assembly_get_image("Assembly-CSharp");
	auto PlayerControlClass = Runtime::il2cpp_class_from_name(AssemblyCSharp, "", "PlayerControl");
	auto RpcSendChatMethod = Runtime::il2cpp_class_get_method_from_name(PlayerControlClass, "RpcSendChat", 1);
	return (bool)Runtime::il2cpp_runtime_invoke(RpcSendChatMethod, (Il2CppObject*)GetLocalPlayer(), new void* [1] { (Il2CppObject*)what });
}


bool PlayerControl::SendChat(Il2CppString* what)
{
	auto AssemblyCSharp = Runtime::il2cpp_assembly_get_image("Assembly-CSharp");
	auto PlayerControlClass = Runtime::il2cpp_class_from_name(AssemblyCSharp, "", "PlayerControl");
	auto SendChatMethod = Runtime::il2cpp_class_get_method_from_name(PlayerControlClass, "SendChat", 1);
	return (bool)Runtime::il2cpp_runtime_invoke(SendChatMethod, (Il2CppObject*)GetLocalPlayer(), new void* [1]{ (Il2CppObject*)what });
}
