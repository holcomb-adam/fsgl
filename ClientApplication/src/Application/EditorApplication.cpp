#include "EditorApplication.h"



// TEMP:
#include "RLE/UI/ImGuiLayer.h"



////////////////////////////////////////////////////////////////////////////////
// - RLE LIBRARY ENTRANCE ------------------------------------------------------

// RLE engine instance
RLE_INSTANCE(client::EditorApplication)




////////////////////////////////////////////////////////////////////////////////
// - RLE CLIENT BRANCH ---------------------------------------------------------

client::EditorApplication::EditorApplication() : 
	rle::Engine(rle::Window::Properties{
		.title = "RLE Editor Client v0.1.0",
		.w = 640,
		.h = 480 })
{

}

std::size_t client::EditorApplication::init()
{
	push(new rle::ImGuiLayer());
	return 0;
}

void client::EditorApplication::onUpdate(const float delta)
{
}
