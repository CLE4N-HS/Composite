#pragma once
#include "RenderComponent.h"

class CircleRenderer : public RenderComponent
{
public:
	CircleRenderer();
	CircleRenderer(const sf::Color& _color);
	~CircleRenderer();

	virtual void Update() override;
	virtual void Render(sf::RenderTarget& _renderTarget) override;

private:
	sf::CircleShape m_circ = sf::CircleShape();

};
