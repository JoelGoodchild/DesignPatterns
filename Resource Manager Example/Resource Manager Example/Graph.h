#pragma once
#include "DynamicArray.h"
#include "Renderer2D.h"
#include "Stack.h"
#include "GraphNode.h"

template <typename T>
class Graph
{
public:
	Graph() {}
	~Graph() {}

	void Insert(T data)
	{
		m_Nodes.PushBack(node);
	}
	void Remove(GraphNode<T>* node);
	void Remove(T data);

	void DrawGraph(aie::Renderer2D* m_2dRenderer)
	{
		Stack<GraphNode<T>*> stack;

		Stack.Push(m_Nodes[0]);

		while (!stack.IsEmpty())
		{
			GraphNode<T>* current = stack.Pop();
			current->m_bTraversed = true;

			for (int i = 0; i < current->m_Edges.Size(); ++i)
			{
				if(!current->m_Edges[i]->m_bTraversed)
				stack.Push(current->m_Edges[i]);
			}
		}
	}

private:
	DynamicArray<GraphNode<T>*> m_Nodes;
};