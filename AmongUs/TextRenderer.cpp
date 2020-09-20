#include "TextRenderer.h"
#include "Runtime.h"

Il2CppString* TextRenderer::GetText()
{
	auto AssemblyCSharp = Runtime::il2cpp_assembly_get_image("Assembly-CSharp");
	auto TextRendererClass = Runtime::il2cpp_class_from_name(AssemblyCSharp, "", "TextRenderer");
	auto TextField = Runtime::il2cpp_field_from_name(TextRendererClass, "Text");
	return (Il2CppString*)Runtime::GetFieldValue((Il2CppObject*)this, TextField);
}
