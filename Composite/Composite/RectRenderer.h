#pragma once
#include "RenderComponent.h"
#include "Entity.h"

class RectRenderer : public RenderComponent
{
public:
	RectRenderer();
	RectRenderer(const sf::Color& _color);
	~RectRenderer();

	virtual void Update() override;
	virtual void Render(sf::RenderTarget& _renderTarget) override;

protected:
	sf::RectangleShape m_rect = sf::RectangleShape();

};
