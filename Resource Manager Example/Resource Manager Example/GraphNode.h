#pragma once
#include "DynamicArray.h"
#include "Renderer2D.h"
#include "Stack.h"

template <typename T>
class GraphNode
{
public:
	GraphNode() {}

	GraphNode(T data)
	{
		m_Data = data;
	}

	~GraphNode() {}

	void AddConnection(GraphNode<T>* other)
	{
		m_Edges.PushBack(other);
	}

	void RemoveConnection(GraphNode<T>* other)
	{
		//m_Edges.Remove(other)

		for (int i = 0; i < m_Edges.Size(); ++i)
		{
			if (m_Edges[i] == other)
			{

			}
		}
	}

	DynamicArray<GraphNode<T>*> m_Edges;
	T m_Data;
 };