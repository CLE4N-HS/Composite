#pragma once
#include "Scene.h"

#ifdef USING_IMGUI
#include "imgui.h"
#include "imgui-SFML.h"

class Editor
{
public:
	Editor();
	~Editor();

	void Render(Scene& _scene);

private:
	Entity* m_selectedEntity = nullptr;

};

#endif // USING_IMGUI
