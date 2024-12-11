#pragma once
#include "Tools.h"

#ifdef USING_IMGUI
#include "imgui.h"
#include "imgui-SFML.h"
#endif // USING_IMGUI


class Entity;

class Component
{
public:
	Component();
	~Component();

	inline void SetOwner(Entity* _owner) { m_owner = _owner; }
	inline Entity* GetOwner() const { return m_owner; }

	virtual void Update() = 0;

#ifdef USING_IMGUI
	virtual void OnImGuiRender() = 0;
#endif // USING_IMGUI


protected:
	Entity* m_owner = nullptr;

};
