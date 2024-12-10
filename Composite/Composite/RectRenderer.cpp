#include "RectRenderer.h"
#include "Entity.h"

RectRenderer::RectRenderer() : RectRenderer(sf::Color())
{
}

RectRenderer::RectRenderer(const sf::Color& _color) : RenderComponent(_color)
{
	//m_rect.setPosition(this->GetOwner()->transform->GetPos().ToVector2f());
	//m_rect.setSize(this->GetOwner()->transform->GetScale().ToVector2f());
}

RectRenderer::~RectRenderer()
{
}

void RectRenderer::Update()
{
	sf::Vector2f ownerScale = this->GetOwner()->transform->GetScale();
	sf::Vector2f ownerPos = this->GetOwner()->transform->GetPos();

	m_rect.setFillColor(m_color);
	//m_rect.setSize(sf::Vector2f(/*50.f*/ 1.f * ownerScale.x, /*50.f*/ 1.f * ownerScale.y));
	m_rect.setSize(sf::Vector2f(ownerScale.x, ownerScale.y));
	m_rect.setOrigin(m_rect.getSize() * 0.5f);
	m_rect.setPosition(ownerPos);
	m_rect.setRotation(this->GetOwner()->transform->GetRotation());
}

void RectRenderer::Render(sf::RenderTarget& _renderTarget)
{
	//m_rect.setPosition(this->GetOwner()->transform->GetPos().ToVector2f());
	//m_rect.setSize(this->GetOwner()->transform->GetScale().ToVector2f());
	//m_rect.setRotation(this->GetOwner()->transform->GetRotation());
	//m_rect.setFillColor(this->m_color);

	_renderTarget.draw(m_rect);
}
