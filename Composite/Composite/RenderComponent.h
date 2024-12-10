#pragma once
#include "Tools.h"
#include "Component.h"

class RenderComponent : public Component
{
public:
	RenderComponent();
	RenderComponent(const sf::Color& _color);
	~RenderComponent();

	virtual void Update() = 0;
	virtual void Render(sf::RenderTarget& _renderTarget) = 0;

	inline void SetColor(sf::Color _newColor) { m_color = _newColor; }

protected:
	sf::Color m_color = sf::Color();

};
