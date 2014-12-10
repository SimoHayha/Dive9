#include "stdafx.h"
#include "Node3D.h"

using namespace Dive9;

Node3D::Node3D() :
m_parent(nullptr)
{
}

void Node3D::Update(float time)
{
	UpdateLocal(time);
	UpdateWorld();

	for (auto node : m_nodes)
	{
		if (node)
			node->Update(time);
	}
}

void Node3D::UpdateLocal(float time)
{
}

void Node3D::UpdateWorld()
{
}