#pragma once
#include "Tools.h"

class Entity;

class Component
{
public:
	Component();
	~Component();

	inline void SetOwner(Entity* _owner) { m_owner = _owner; }
	inline Entity* GetOwner() const { return m_owner; }

	virtual void Update() = 0;

protected:
	Entity* m_owner = nullptr;

};
