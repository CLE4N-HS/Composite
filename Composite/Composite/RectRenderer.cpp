#include "RectRenderer.h"
#include "Entity.h"

#ifdef USING_IMGUI
namespace ig = ImGui;
#endif // USING_IMGUI


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

#ifdef USING_IMGUI
void RectRenderer::OnImGuiRender()
{
	if (ig::CollapsingHeader("RectRenderer", ImGuiTreeNodeFlags_DefaultOpen))
	{
		ig::Text("Color :");
	
		//ig::Text("Position :");
		//ig::DragFloat2("##Position", &m_Pos.x, 1.f);
		//ig::Text("Scale :");
		//ig::DragFloat2("##Scale", &m_Scale.x, 0.1f);
		//ig::Text("Rotation :");
		//ig::DragFloat("##Rotation", &m_Rotation, 1.f, 0.f, 360.f);
	}
}
#endif // USING_IMGUi
