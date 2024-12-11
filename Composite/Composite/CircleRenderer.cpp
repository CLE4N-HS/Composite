#include "CircleRenderer.h"
#include "Entity.h"

CircleRenderer::CircleRenderer() : RenderComponent()
{
}

CircleRenderer::CircleRenderer(const sf::Color& _color) : RenderComponent(_color)
{
}

CircleRenderer::~CircleRenderer()
{
}

void CircleRenderer::Update()
{
	m_circ.setFillColor(m_color);
	m_circ.setPosition(this->GetOwner()->transform->GetPos());
	float radius = this->GetOwner()->transform->GetScale().x;
	m_circ.setRadius(radius);
	m_circ.setOrigin(sf::Vector2f(radius, radius));
	m_circ.setRotation(this->GetOwner()->transform->GetRotation());
}

void CircleRenderer::Render(sf::RenderTarget& _renderTarget)
{
	_renderTarget.draw(m_circ);
}

#ifdef USING_IMGUI
namespace ig = ImGui;

void CircleRenderer::OnImGuiRender()
{
	if (ig::CollapsingHeader("CircleRenderer", ImGuiTreeNodeFlags_DefaultOpen))
	{
		//ig::Text("Position :");
		//ig::DragFloat2("##Position", &m_Pos.x, 1.f);
		//ig::Text("Scale :");
		//ig::DragFloat2("##Scale", &m_Scale.x, 0.1f);
		//ig::Text("Rotation :");
		//ig::DragFloat("##Rotation", &m_Rotation, 1.f, 0.f, 360.f);
	}
}
#endif // USING_IMGUI
