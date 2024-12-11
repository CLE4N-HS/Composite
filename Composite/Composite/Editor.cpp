#include "Editor.h"
#include "RectRenderer.h"
#include "CircleRenderer.h"

#ifdef USING_IMGUI
namespace ig = ImGui;

Editor::Editor()
{
}

Editor::~Editor()
{
}

void Editor::Render(Scene& _scene)
{
	ig::SetNextWindowPos(ImVec2(0.f, 0.f));
	ig::SetNextWindowSize(ImVec2(288.f, 1080.f));

	ig::Begin("Entities");

	ig::Separator();

	for (Entity* entity : _scene.GetEntities())
	{
		if (ig::Selectable(entity->GetName().c_str()))
		{
			m_selectedEntity = entity;
		}
	}

	ig::End();


	ig::SetNextWindowPos(ImVec2(1632.f, 0.f));
	ig::SetNextWindowSize(ImVec2(288.f, 1080.f));

	ig::Begin("Details");

	if (m_selectedEntity)
	{
		char name[50];
		strcpy_s(name, sizeof(name), m_selectedEntity->GetName().c_str());

		if (ig::InputText("##Name", name, 50, ImGuiInputTextFlags_EnterReturnsTrue))
		{
			m_selectedEntity->SetName(name);
		}

		ig::Separator();

		ig::Text("Components :");

		for (Component* component : m_selectedEntity->GetComponents<Component>())
		{
			component->OnImGuiRender();
		}

		ig::Separator();

		if (ig::Button("Add Component"))
		{
			ig::OpenPopup("comp_Popup");
		}

		if (ig::BeginPopup("comp_Popup"))
		{
			ig::BulletText("Components :");

			if (ig::Selectable("RectRenderer"))
			{
				m_selectedEntity->AddComponent<RectRenderer>();
			}
			if (ig::Selectable("CircleRenderer"))
			{
				m_selectedEntity->AddComponent<CircleRenderer>();
			}

			ig::EndPopup();
		}
	}

	ig::End();

}
#endif // USING_IMGUI
