#pragma once
#include "DynamicArray.h"
#include "Resource.h"
#include <string.h>

template <typename T>

class ResourceManager
{
public:
	ResourceManager() {}
	~ResourceManager() 
	{
		UnloadAllResources();
	}

	T LoadResource(char* szFilename)
	{
		//Check if resource is already loaded.
		//If it is, return it.
		for (int i = 0; i < m_ResourceList.Size(); ++i)
		{
			if (strcmp(m_ResouceList[i]->m_szFilename) == 0)
			{
				return m_ResourceList[i]->m_Data;
			}
		}

		//Resource is not loaded, so load it.
		Resource* pResource = new Resource(szFilename);
		m_ResourceList->PushBack(pResource);
		return pResource;
	}

	//Delete everything.
	void UnloadAllResources()
	{
		for (int i = 0; i < m_ResourceList.size(); ++i)
		{
			delete m_ResourceList[i];
		}

		m_ResourceList.clear();
	}
	DynamicArray<Resource<T>*>
};