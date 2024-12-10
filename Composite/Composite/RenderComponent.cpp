#include "RenderComponent.h"

RenderComponent::RenderComponent()
{
}

RenderComponent::RenderComponent(const sf::Color& _color) : Component(),
	m_color(_color)
{
}

RenderComponent::~RenderComponent()
{
}
